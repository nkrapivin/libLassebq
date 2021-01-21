#pragma once
#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <list>

extern HMODULE exeBase;

#define ItoD(integer) (static_cast<double>((integer)))
#define EtoI(e) (static_cast<signed int>((e)))

// Extension func defines.
#define funcR extern "C" __declspec(dllexport) double       __cdecl 
#define funcS extern "C" __declspec(dllexport) const char * __cdecl 
#define funcV extern "C" __declspec(dllexport) void         __cdecl 

const int VALUE_REAL = 0;		// Real value
const int VALUE_STRING = 1;		// String value
const int VALUE_ARRAY = 2;		// Array value
const int VALUE_OBJECT = 6;	// YYObjectBase* value 
const int VALUE_INT32 = 7;		// Int32 value
const int VALUE_UNDEFINED = 5;	// Undefined value
const int VALUE_PTR = 3;			// Ptr value
const int VALUE_VEC3 = 4;		// Vec3 (x,y,z) value (within the RValue)
const int VALUE_VEC4 = 8;		// Vec4 (x,y,z,w) value (allocated from pool)
const int VALUE_VEC44 = 9;		// Vec44 (matrix) value (allocated from pool)
const int VALUE_INT64 = 10;		// Int64 value
const int VALUE_ACCESSOR = 11;	// Actually an accessor
const int VALUE_NULL = 12;	// JS Null
const int VALUE_BOOL = 13;	// Bool value
const int VALUE_ITERATOR = 14;	// JS For-in Iterator
const int VALUE_REF = 15;		// Reference value (uses the ptr to point at a RefBase structure)
#define MASK_KIND_RVALUE	0x0ffffff
const int VALUE_UNSET = MASK_KIND_RVALUE;

struct vec3
{
	float	x, y, z;
};

struct vec4
{
	float	x, y, z, w;
};

struct matrix44
{
	vec4	m[4];
};

const int ERV_None = 0;
const int ERV_Enumerable = (1 << 0);
const int ERV_Configurable = (1 << 1);
const int ERV_Writable = (1 << 2);
const int ERV_Owned = (1 << 3);

#define JS_BUILTIN_PROPERTY_DEFAULT				(ERV_Writable | ERV_Configurable )
#define JS_BUILTIN_LENGTH_PROPERTY_DEFAULT		(ERV_None)

template <typename T > struct _RefThing
{
	T		m_thing;
	int		m_refCount;
	int		m_size;

	void inc(void) {
		++m_refCount;
	} // end Inc

	void dec(void) {
		--m_refCount;
		if (m_refCount == 0) {
			// use the factory to clean it up and give us a default thing to use
			m_size = 0;
			delete this;
		} // end if
	} // end Dec

	T get(void) const { return m_thing; }
	int size(void) const { return m_size; }

	static _RefThing<T>* assign(_RefThing<T>* _other) { if (_other != nullptr) { _other->inc(); } return _other; }
	static _RefThing<T>* remove(_RefThing<T>* _other) { if (_other != nullptr) { _other->dec(); } return nullptr; }
};

typedef _RefThing<const char*> RefString;

struct RValue;
struct DynamicArrayOfRValue
{
	int length;
	RValue* arr;
};

struct RefDynamicArrayOfRValue
{
	int	refcount;
	DynamicArrayOfRValue* pArray;
	void* pOwner;
	int visited;
	int length;
};

#pragma pack( push, 4)
class YYObjectBase;
struct RValue
{
	union {
		int v32;
		long long v64;
		double	val;						// value when real
		union {
			void* ptr;
			RefString* pRefString;
			RefDynamicArrayOfRValue* pRefArray;
			YYObjectBase* pObj;
			vec4* pVec4;
			matrix44* pMatrix44;
		};
	};
	int		flags;							// use for flags (Hijack for Enumerable and Configurable bits in JavaScript)  (Note: probably will need a visibility as well, to support private variables that are promoted to object scope, but should not be seen (is that just not enumerated????) )
	int		kind;							// kind of value

	RValue()
	{
		flags = 0;
		kind = VALUE_UNSET;
		ptr = nullptr;
	}

	RValue(double v)
	{
		flags = 0;
		kind = VALUE_REAL;
		val = v;
	}

	RValue(bool v)
	{
		flags = 0;
		kind = VALUE_BOOL;
		val = v ? 1.0 : 0.0;
	}

	RValue(int v)
	{
		flags = 0;
		kind = VALUE_INT32;
		v32 = v;
	}

	RValue(long long v)
	{
		flags = 0;
		kind = VALUE_INT64;
		v64 = v;
	}

	RValue(void* v)
	{
		flags = 0;
		kind = VALUE_PTR;
		ptr = v;
	}

	RValue& operator=(double v)
	{
		kind = VALUE_REAL;
		val = v;
		return *this;
	}

	RValue& operator=(int v)
	{
		kind = VALUE_INT32;
		v32 = v;
		return *this;
	}

	RValue& operator=(long long v)
	{
		kind = VALUE_INT64;
		v64 = v;
		return *this;
	}

	RValue& operator=(void* v)
	{
		kind = VALUE_PTR;
		ptr = v;
		return *this;
	}

	RValue& operator=(bool v)
	{
		kind = VALUE_BOOL;
		val = v ? 1.0 : 0.0;
		return *this;
	}

	RValue& operator++()
	{
		switch (kind & MASK_KIND_RVALUE)
		{
			case VALUE_REAL: val++;
			case VALUE_INT32: v32++;
			case VALUE_INT64: v64++;
			default: abort();
		}
		return *this;
	}

	RValue& operator++(int)
	{
		RValue tmp(*this);
		operator++();
		return tmp;
	}

	RValue& operator--()
	{
		switch (kind & MASK_KIND_RVALUE)
		{
			case VALUE_REAL: val--;
			case VALUE_INT32: v32--;
			case VALUE_INT64: v64--;
			default: abort();
		}
	}

	RValue& operator--(int)
	{
		RValue tmp(*this);
		operator--();
		return tmp;
	}

	std::string asString()
	{
		switch (kind & MASK_KIND_RVALUE)
		{
			case VALUE_REAL: return std::to_string(val);
			case VALUE_INT32: return std::to_string(v32);
			case VALUE_INT64: return std::to_string(v64);
			//case VALUE_PTR: return std::to_string(ptr);
			case VALUE_BOOL: return (val > 0.5) ? "true" : "false";
			case VALUE_UNSET: return "<unset>"; // ??????????
			case VALUE_UNDEFINED: return "<undefined>";
			case VALUE_STRING: return pRefString->get();
			default: abort();
		}
	}

	double asReal()
	{
		switch (kind & MASK_KIND_RVALUE)
		{
			case VALUE_REAL:
			case VALUE_BOOL:  return val;
			case VALUE_UNDEFINED:
			case VALUE_UNSET: return std::nan("");
			case VALUE_INT32: return static_cast<double>(v32);
			case VALUE_INT64: return static_cast<double>(v64);
			case VALUE_PTR:   return static_cast<double>(reinterpret_cast<uintptr_t>(ptr));
			case VALUE_STRING: {
				try {
					return std::stod(pRefString->get());
				}
				catch (std::exception&) {
					return std::nan("");
				}
			}
		}
	}

};

enum eDeleteType : int {
	eDelete_placementdelete = 3,
	eDelete_delete = 1,
	eDelete_free = 2,
	eDelete_none = 0
};

typedef enum EJSRetValBool {
	EJSRVB_TRUE = 1,
	EJSRVB_FALSE = 0,
	EJSRVB_TYPE_ERROR = 2
} EJSRetValBool;

template<class T>
class cARRAY_STRUCTURE {
	int Length;
	T * Array;
};

template<class T>
class OLinkedList {
public:
	T* m_pFirst;
	T* m_pLast;
	int m_Count;
};

template<class T>
class LinkedList {
	T* m_pFirst;
	T* m_pLast;
	int m_Count;

};

struct YYRoomTiles {
	int count;
};

struct YYRoomInstances {
	int count;
};

struct RTile {
	float x;
	float y;
	int index;
	int xo;
	int yo;
	int w;
	int h;
	float depth;
	int id;
	float xscale;
	float yscale;
	int blend;
	float alpha;
	bool visible;
};

class CBackGM {
	bool visible;
	bool foreground;
	int index;
	float x;
	float y;
	bool htiled;
	bool vtiled;
	float hspeed;
	float vspeed;
	float xscale;
	float yscale;
	int blend;
	float alpha;
};

class CViewGM {
	bool visible;
	float xview;
	float yview;
	float wview;
	float hview;
	int xport;
	int yport;
	int wport;
	int hport;
	float angle;
	int hborder;
	int vborder;
	int hspeed;
	int vspeed;
	int index;
	int SurfaceID;
	int cameraID;
};

class CTimingSource {
	long long m_elapsed_micros;
	long long m_last_micros;
	bool m_paused;
	double m_fps;
	long long m_delta_micros;
};

class CLayer;

class CLayerElementBase {
	int m_type;
	int m_id;
	bool m_bRuntimeDataInitialised;
	char * m_pName;
	CLayer* m_pLayer;
	CLayerElementBase * m_pNext;
	CLayerElementBase * m_pPrev;
};

class CLayer {
	int m_id;
	int m_depth;
	float m_xoffset;
	float m_yoffset;
	float m_hspeed;
	float m_vspeed;
	bool m_visible;
	bool m_deleting;
	bool m_dynamic;
	char * m_pName;
	int m_beginScriptID;
	int m_endScriptID;
	int m_shaderID;
	CTimingSource m_timer;
	LinkedList<CLayerElementBase> m_elements;
	CLayer * m_pNext;
	CLayer * m_pPrev;
};

class Element {
	int k;
	CLayer * v;
	unsigned int h;
};

//template<class T>
class CHashMap {
	int m_curSize;
	int m_numUsed;
	int m_curMask;
	int m_growThreshold;
	Element* m_elements;
};

template<class T>
struct SLinkedListNode {
	SLinkedListNode* m_pNext;
	SLinkedListNode* m_pPrev;
	T* m_pObj;
};

template<class T>
struct SLinkedList {
	SLinkedListNode<T>* m_pFirst;
	SLinkedListNode<T>* m_pLast;
	int m_Count;
};

class CInstanceBase
{
public:
	RValue*		yyvars;
	virtual ~CInstanceBase() { };
	virtual  RValue& GetYYVarRef(int index) = 0;
};

class YYObjectBase : CInstanceBase {
public:
	YYObjectBase * m_pNextObject;
	YYObjectBase * m_pPrevObject;
	YYObjectBase * m_prototype;
	void * m_pcre;
	void * m_pcreExtra;
	char * m_class;
	void(*m_getOwnProperty)(YYObjectBase *, RValue *, char *);
	void(*m_deleteProperty)(YYObjectBase *, RValue *, char *, bool);
	EJSRetValBool(*m_defineOwnProperty)(YYObjectBase *, char *, RValue *, bool);
	CHashMap* m_yyvarsMap;
	unsigned int m_nvars;
	unsigned int m_flags;
	unsigned int m_capacity;
	unsigned int m_visited;
	unsigned int m_visitedGC;
	int m_GCgen;
	int m_GCcreationframe;
	int m_slot;
	int m_kind;
	int m_rvalueInitType;
	int m_curSlot;
};

struct YYRECT {
	int left;
	int top;
	int right;
	int bottom;
};

struct SLink;

struct SLinkListEx {
	SLink * head;
	SLink * tail;
	int offset;
};

struct SLink {
	SLink * next;
	SLink * prev;
	SLinkListEx * list;
};

class cInstancePathAndTimeline {
public:
	int i_pathindex;
	float i_pathposition;
	float i_pathpositionprevious;
	float i_pathspeed;
	float i_pathscale;
	float i_pathorientation;
	int i_pathend;
	float i_pathxstart;
	float i_pathystart;
	int i_timelineindex;
	float i_timelineprevposition;
	float i_timelineposition;
	float i_timelinespeed;
};

struct CPhysicsDataGM {
	float * m_physicsVertices;
	bool m_physicsObject;
	bool m_physicsSensor;
	bool m_physicsAwake;
	bool m_physicsKinematic;
	int m_physicsShape;
	int m_physicsGroup;
	float m_physicsDensity;
	float m_physicsRestitution;
	float m_physicsLinearDamping;
	float m_physicsAngularDamping;
	float m_physicsFriction;
	int m_physicsVertexCount;
};

class CInstance;

struct CObjectGM {
	char * m_pName;
	CObjectGM * m_pParent;
	CHashMap * m_childrenMap;
	CHashMap * m_eventsMap;
	CPhysicsDataGM m_physicsData;
	SLinkedList<CInstance> m_Instances;
	SLinkedList<CInstance> m_Instances_Recursive;
	unsigned int m_Flags;
	int m_spriteindex;
	int m_depth;
	int m_parent;
	int m_mask;
	int m_ID;
};

class CInstance : YYObjectBase {
public:
	long long m_CreateCounter;
	CObjectGM * m_pObject;
	struct CPhysicsObject * m_pPhysicsObject;
	struct CSkeletonInstance * m_pSkeletonAnimation;
	unsigned int m_Instflags;
	int i_id;
	int i_objectindex;
	int i_spriteindex;
	float i_imageindex;
	float i_imagespeed;
	float i_imagescalex;
	float i_imagescaley;
	float i_imageangle;
	float i_imagealpha;
	unsigned int i_imageblend;
	float i_x;
	float i_y;
	float i_xstart;
	float i_ystart;
	float i_xprevious;
	float i_yprevious;
	float i_direction;
	float i_speed;
	float i_friction;
	float i_gravitydir;
	float i_gravity;
	float i_hspeed;
	float i_vspeed;
	YYRECT i_bbox;
	int i_timer[12];
	cInstancePathAndTimeline * m_pPathAndTimeline;
	void * i_initcode;
	void * i_precreatecode;
	CObjectGM * m_pOldObject;
	int m_nLayerID;
	int i_maskindex;
	short m_nMouseOver;
	CInstance * m_pNext;
	CInstance * m_pPrev;
	SLink m_collisionLink;
	SLink m_dirtyLink;
	SLink m_withLink;
	float i_depth;
	float i_currentdepth;
	float i_lastImageNumber;
	unsigned int m_collisionTestNumber;
};

struct YYRoom {
	unsigned int pName;
	unsigned int pCaption;
	int width;
	int height;
	int speed;
	int persistent;
	int colour;
	int showColour;
	unsigned int pCode;
	int enableViews;
	unsigned int pBackgrounds;
	unsigned int pViews;
	unsigned int pInstances;
	unsigned int pTiles;
	int physicsWorld;
	int physicsWorldTop;
	int physicsWorldLeft;
	int physicsWorldRight;
	int physicsWorldBottom;
	float physicsWorldGravityX;
	float physicsWorldGravityY;
	float physicsWorldPixToMeters;
};

class CRoom {
public:
	int r_lasttile;
	CRoom* instance_handle;
	char* r_caption;
	int r_speed;
	int r_width;
	int r_height;
	bool r_persistent;
	unsigned int r_color;
	bool r_showcolor;
	CBackGM* r_background[8];
	bool r_enableviews;
	bool r_clearscreen;
	bool r_cleardisplaybuffer;
	CViewGM* r_view[8];
	char* r_code;
	void* r_codeCode;
	bool r_physicsWorld;
	int r_physicsGravityX;
	int r_physicsGravityY;
	float r_physicsPixToMeters;
	OLinkedList<CInstance> m_Active;
	LinkedList<CInstance> m_Deactive;
	CInstance* m_pMarkedFirst;
	CInstance* m_pMarkedLast;
	int * m_pCreationOrderList;
	int m_CreationOrderListSize;
	YYRoom* m_pRoom;
	unsigned char * m_pBase;
	void* m_pPhysicsWorld;
	int r_tnumb;
	cARRAY_STRUCTURE<RTile> r_tile;
	YYRoomTiles * r_pTiles;
	YYRoomInstances * r_pInstances;
	char * m_pName;
	bool m_isDuplicate;
	LinkedList<CLayer> m_Layers;
	CHashMap m_LayerLookup;
	CHashMap m_LayerElementLookup;
	CLayerElementBase * m_LastLayerElementLookedUp;
	CHashMap m_LayerInstanceElementLookup;
};

#pragma pack(pop)

struct YYVAR
{
	const char* pName;
	int val;
};

struct YYGMLFunc
{
	const char* pName;
	void* ptr;
};

extern YYVAR** g_BuiltinFuncs;
extern YYGMLFunc* g_GMLScripts;
extern YYVAR** g_Variables;
extern CRoom** g_RunRoom;
extern CInstance* g_Self;
extern const char** g_WorkingDirectory;
extern const char** g_GameName;
extern const char** g_CommandLine;
extern int* g_CurrentRoom;

typedef RValue&(*GML_CallLegacyFunction)(CInstance* _pSelf, CInstance* _pOther, RValue &_result, int _argc, int _id, RValue **_args);
typedef void(*GML_ObjectEvent)(CInstance* _pSelf, CInstance* _pOther);
typedef RValue&(*GML_Script)(CInstance* _pSelf, CInstance* _pOther, RValue& _result, int _count, RValue** _args);
typedef void(*TRoutine)(RValue& _result, CInstance* _pSelf, CInstance* _pOther, int _argc, RValue *_args);
extern GML_CallLegacyFunction call;


struct RFunction {
	char f_name[64];
	TRoutine f_routine;
	int f_dummy;
	int f_argnumb;
	unsigned int m_UsageCount;
};

extern int* g_RFunctionTableLen;
extern RFunction* g_RFunctionTable;

void CallGMLFunction(int id, RValue& ret, std::list<RValue>& args)
{
	if (id < 0) abort();

	// do the magic.
	YYVAR* myFunc = g_BuiltinFuncs[id];
	RFunction RFunc = g_RFunctionTable[myFunc->val];
	TRoutine TR = RFunc.f_routine;
	int i = 0;
	int argc = args.size();

	// prepare return memory.
	RValue Result(0.0);
	
	// allocate arguments **on the stack! right here!!!**
	RValue* ptr = reinterpret_cast<RValue*>(alloca(argc * sizeof(RValue)));
	for (RValue rv : args) {
		ptr[i] = rv; i++;
	}

	// call the routine
	TR(ret, g_Self, nullptr, argc, ptr);
}

void CallScriptFunction(int id, RValue& ret, std::list<RValue>& args, bool isEvent = false)
{
	if (id < 0) abort();

	// prepare argument memory.
	RValue **Arguments = new RValue*[args.size()];
	for (RValue& arg : args) { Arguments[0] = &arg; }

	// do the magic.
	YYGMLFunc myFunc = g_GMLScripts[id];
	if (isEvent)
	{
		reinterpret_cast<GML_ObjectEvent>(myFunc.ptr)(g_Self, g_Self);
	}
	else
	{
		reinterpret_cast<GML_Script>(myFunc.ptr)(g_Self, g_Self, ret, args.size(), Arguments);
	}

	// clean up.
	delete[] Arguments;
	Arguments = nullptr;
}