#pragma once
#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <list>

extern HMODULE exeBase;

#define ItoD(integer) (static_cast<double>((integer)))
#define EtoI(e) (static_cast<signed int>((e)))
#define EtoD(e) (static_cast<double>((e)))

// Extension func defines.
#define funcR extern "C" __declspec(dllexport) double       __cdecl 
#define funcS extern "C" __declspec(dllexport) const char * __cdecl 
#define funcV extern "C" __declspec(dllexport) void         __cdecl 

enum class GML_async_event : int {
	AsyncImageLoaded = 60,
	AsyncSoundLoaded = 61,
	AsyncHTTP = 62,
	AsyncDialog = 63,
	AsyncIAP = 66,
	AsyncCloud = 67,
	AsyncNetworking = 68,
	AsyncSteam = 69,
	AsyncSocial = 70,
	AsyncPushNotification = 71,
	AsyncSaveAndLoad = 72,
	AsyncAudioRecording = 73,
	AsyncAudioPlayback = 74,
	AsyncSystem = 75
};

typedef void(*GML_create_async_event)(int dsmapindex, int event_index);
typedef int(*GML_ds_map_create)(int _num, ...);
typedef bool(*GML_ds_map_add_string)(int _map, const char *_pKey, const char *_pValue);
typedef bool(*GML_ds_map_add_real)(int _map, const char *_pKey, double _value);

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
		v64 = 0L;
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

	RValue(const char* v)
	{
		flags = 0;
		kind = VALUE_STRING;
		pRefString = new RefString();
		pRefString->m_thing = v;
		pRefString->m_size = strlen(v) + 1;
		pRefString->inc();
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

	inline bool operator==(const RValue& rhs)
	{
		int lhsType = kind & MASK_KIND_RVALUE;
		int rhsType = rhs.kind & MASK_KIND_RVALUE;

		if (lhsType == VALUE_STRING && rhsType == VALUE_STRING)
			return strcmp(pRefString->get(), rhs.pRefString->get()) == 0;

		double lhsD = this->asReal();
		double rhsD = 0.0;
		switch (rhsType)
		{
			case VALUE_REAL:
			case VALUE_BOOL: rhsD = rhs.val; break;
			case VALUE_INT32: rhsD = static_cast<double>(rhs.v32); break;
			case VALUE_INT64: rhsD = static_cast<double>(rhs.v64); break;
			case VALUE_PTR: rhsD = static_cast<double>(reinterpret_cast<uintptr_t>(ptr)); break;
			case VALUE_UNSET:
			case VALUE_UNDEFINED: rhsD = std::nan(""); break;
			default: abort(); break;
		}

		return lhsD == rhsD;
	}

	inline bool operator!=(const RValue& rhs)
	{
		return (!(operator==(rhs)));
	}

	std::string asString()
	{
		switch (kind & MASK_KIND_RVALUE)
		{
			case VALUE_REAL: return std::to_string(val);
			case VALUE_INT32: return std::to_string(v32);
			case VALUE_INT64: return std::to_string(v64);
			case VALUE_PTR: {
				char buf[32] = { '\0' };
				memset(buf, 0, sizeof(buf));
				std::snprintf(buf, sizeof(buf), "%p", ptr);
				return std::string(buf);
			}
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
			default: abort();
		}
	}

};

#define FREE_RValue(rvp) \
	do                                                           \
	{                                                            \
		RValue *__p = ((rvp));                                   \
		if ( ( (__p->kind - 1) & (MASK_KIND_RVALUE & ~3) ) == 0) \
		{                                                        \
			FREE_RValue__Pre(__p);                               \
		}                                                        \
		__p->flags = 0;                                          \
		__p->kind = VALUE_UNDEFINED;                             \
		__p->ptr = nullptr;                                      \
	}                                                            \
	while (false);                                                   



enum eDeleteType : int {
	eDelete_placementdelete = 3,
	eDelete_delete = 1,
	eDelete_free = 2,
	eDelete_none = 0
};

enum EJSRetValBool {
	EJSRVB_TRUE = 1,
	EJSRVB_FALSE = 0,
	EJSRVB_TYPE_ERROR = 2
};

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

class CInstance;
class CLayerInstanceElement : public CLayerElementBase {
	int m_instanceID;
	CInstance* m_pInstance;
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
	CLayer* m_pNext;
	CLayer* m_pPrev;
};

template<typename T>
class HashNode {
public:
	HashNode<T>* m_pPrev;
	HashNode<T>* m_pNext;
	unsigned int m_ID;
	T* m_pObj;
};

template<typename T>
class HashLink {
public:
	T* m_pFirst;
	T* m_pLast;
};

template<typename T>
class CHash {
public:
	HashLink<HashNode<T>> *m_pHashingTable;
	int m_HashingMask;
	int m_Count;
};

typedef unsigned int Hash;

template<class K, class V, int I>
class Element {
public:
	V v; // Value
	K k; // Key
	Hash hash; // Hash
};

template<class K, class V, int I = 3>
class CHashMap {
public:
	int m_curSize;
	int m_numUsed;
	int m_curMask;
	int m_growThreshold;
	Element<K, V, I>* m_elements;
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
	RValue& GetYYVarRef(int index)
	{
		// TODO: it's a bit more complicated than that?
		return yyvars[index];
	}
};

class YYObjectBase : public CInstanceBase {
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
	CHashMap<int,RValue*,3>* m_yyvarsMap;
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
	char* m_pStackTrace;
	//char* m_pVMStackTrace;
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

enum eGML_TYPE : unsigned int {
	eGMLT_ERROR = 0xffff0000,
	eGMLT_NONE = 0x0,
	eGMLT_DOUBLE = 0x1,
	eGMLT_STRING = 0x2,
	eGMLT_INT32 = 0x4
};

struct RToken {
	int kind;
	eGML_TYPE type;
	int ind;
	int ind2;
	RValue value;
	int itemnumb;
	RToken* items;
	int position;
};

class CCode {
	virtual ~CCode() { };
public:
	CCode* m_pNext;
	int i_kind;
	bool i_compiled;
	char* i_str;
	RToken i_token;
	RValue i_value;
	void* i_pVM;
	void* i_pVMDebugInfo;
	char* i_pCode;
	char* i_pName;
	int i_CodeIndex;
	YYGMLFunc* i_pFunc;
	bool i_watch;
	int i_offset;
	int i_locals;
	int i_args;
	int i_flags;
};

int a = sizeof(CCode);

class CEvent {
public:
	//void* _vptr_pointer;
	CCode* e_code;
	int m_OwnerObjectID;

	CEvent()
	{
		this->e_code = nullptr;
		this->m_OwnerObjectID = 0;
	}

	~CEvent()
	{

	}

	void Clear()
	{
		return;
	}

	bool Compile()
	{
		return true;
	}

	void Execute(CInstance* _self, CInstance* _other)
	{

	}
};

//int a = sizeof(CEvent);

class CObjectGM {
public:
	char * m_pName;
	CObjectGM * m_pParent;
	CHashMap<int,CObjectGM*,2> * m_childrenMap;
	CHashMap<unsigned long long, CEvent*, 3> * m_eventsMap;
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

class CInstance : public YYObjectBase {
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
	CCode * i_initcode;
	CCode * i_precreatecode;
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
	CHashMap<int,CLayer*,7> m_LayerLookup;
	CHashMap<int,CLayerElementBase*,7> m_LayerElementLookup;
	CLayerElementBase * m_LastLayerElementLookedUp;
	CHashMap<int,CLayerInstanceElement*,7> m_LayerInstanceElementLookup;
};

#pragma pack(pop)

extern YYVAR** g_BuiltinFuncs;
extern YYGMLFunc* g_GMLScripts;
extern YYVAR** g_Variables;
extern CRoom** g_RunRoom;
extern CInstance* g_Self;
extern CHash<CObjectGM>** g_ObjectHashTable;
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
	int f_argnumb;
	unsigned int m_UsageCount;
	int f_FFFFFFFF; // always 0xFFFFFFFF
};

extern int* g_RFunctionTableLen;
extern RFunction** g_RFunctionTable;

void CallRFunction(int id, RValue& ret, const std::list<RValue>& args)
{
	if (id < 0) abort();

	RFunction RFunc = (*g_RFunctionTable)[id];
	int i = 0;
	int argc = args.size();

	// allocate arguments **on the stack! right here!!!**
	RValue* ptr = reinterpret_cast<RValue*>(alloca(argc * sizeof(RValue)));
	// we want to *copy* the arguments, not pass-by-ref.
	for (RValue rv : args) {
		ptr[i] = rv; i++;
	}

	RFunc.f_routine(ret, g_Self, nullptr, argc, ptr);
}

void CallGMLFunction(int id, RValue& ret, const std::list<RValue>& args)
{
	if (id < 0) abort();

	// do the magic.
	CallRFunction(g_BuiltinFuncs[id]->val, ret, args);
}

void CallScriptFunction(int id, RValue& ret, const std::list<RValue>& args, bool isEvent = false)
{
	if (id < 0) abort();

	// do the magic.
	YYGMLFunc myFunc = g_GMLScripts[id];
	if (isEvent)
	{
		// call
		reinterpret_cast<GML_ObjectEvent>(myFunc.ptr)(g_Self, nullptr);
	}
	else
	{
		// prepare argument memory.
		RValue **Arguments = nullptr;
		if (args.size() > 0)
		{
			Arguments = new RValue*[args.size()];
			int i = 0;
			for (const RValue& arg : args) { Arguments[i] = const_cast<RValue*>(&arg); i++; }
		}

		// call
		reinterpret_cast<GML_Script>(myFunc.ptr)(g_Self, nullptr, ret, args.size(), Arguments);

		// clean up.
		if (Arguments != nullptr) delete[] Arguments;
	}
}