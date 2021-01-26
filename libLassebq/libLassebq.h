#pragma once
#include "stdafx.h"
#include "pcre\include\pcre.h"
#include "RValue.h"
#include "GMCallbacks.h"
#include "SYYStackTrace.h"
#include <vector>
#include <iostream>
#include <list>
#include <memory>

#define ItoD(integer) (static_cast<double>((integer)))
#define EtoI(e) (static_cast<signed int>((e)))
#define EtoD(e) (static_cast<double>((e)))

// Extension func defines.
#define funcR extern "C" __declspec(dllexport) double       __cdecl 
#define funcS extern "C" __declspec(dllexport) const char * __cdecl 
#define funcV extern "C" __declspec(dllexport) void         __cdecl 

funcR lassebq_init();
funcR lassebq_shutdown();
funcV RegisterCallbacks(GML_create_async_event cae, GML_ds_map_create dmc, GML_ds_map_add_real dmar, GML_ds_map_add_string dmas);

enum YYOBJECTBASE_KIND : int {
	YYOBJECTBASE = 0,
	CINSTANCE = 1,
	ACCESSOR = 2,
	SCRIPTREF = 3
};

enum YYVAR_ACCESSOR_KIND : int {
	YYVAR_ACCESSOR_GET = 0,
	YYVAR_ACCESSOR_SET = 1
};

enum ERV_KIND {
	ERV_None = 0,
	ERV_Enumerable = (1 << 0),
	ERV_Configurable = (1 << 1),
	ERV_Writable = (1 << 2),
	ERV_Owned = (1 << 3)
};

#define JS_BUILTIN_PROPERTY_DEFAULT        (ERV_Writable | ERV_Configurable)
#define JS_BUILTIN_LENGTH_PROPERTY_DEFAULT (ERV_None)

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

typedef void(*GMMMSetLength)(void **buf, size_t new_length, char* _pFile, int _line);
extern GMMMSetLength MMSetLength;

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

enum EHasInstanceRetVal {
	E_FALSE = 0x0,
	E_TRUE = 0x1,
	E_TYPE_ERROR = 0x2
};

enum EObjectBaseFlags {
	EOBF_NONE = 0x0,
	EOBF_EXTENSIBLE = 0x1,
	EOBF_HAVE_RUN_DISPOSE = 0x2
};

template<class T>
class cARRAY_STRUCTURE {
	int Length;
	T * Array;
};

class cARRAY_OF_POINTERS {
	int Length;
	int m_slotsUsed;
	int m_reserveSize;
	void** Array;
};

template<class T>
class OLinkedList {
public:
	T* m_pFirst;
	T* m_pLast;
	int m_Count;
	eDeleteType m_DeleteType;
};

template<class T>
class LinkedList {
	T* m_pFirst;
	T* m_pLast;
	int m_Count;
	eDeleteType m_DeleteType;
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

	int GetIdealPosition(Hash _h)
	{
		return this->m_curMask & _h;
	}
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
	//eDeleteType m_DeleteType;
};

struct DynamicArrayOfInteger {
	int length;
	int* arr;

	int Grow(int growBy = 5)
	{
		length += growBy;
		MMSetLength(reinterpret_cast<void**>(&arr), length * sizeof(*arr), "Files\\Code\\Code_Function.cpp", 71);
		return length;
	}
};


class CInstanceBase
{
public:
	RValue*		yyvars;
	virtual ~CInstanceBase() { };
	virtual RValue& InternalGetYYVarRef(int index) = 0;
};

typedef void(*GetOwnPropertyFunc)(YYObjectBase* object, RValue* res, char* name);
typedef void(*DeletePropertyFunc)(YYObjectBase* object, RValue* res, char* name, bool flag);
typedef EJSRetValBool(*DefineOwnPropertyFunc)(YYObjectBase* object, char* name, RValue* res, bool flag);


class YYObjectBase : public CInstanceBase {
	YYObjectBase* m_pNextObject;
	YYObjectBase* m_pPrevObject;
	YYObjectBase* m_prototype;
	pcre* m_pcre;
	pcre_extra* m_pcreExtra;
	char* m_class;
	GetOwnPropertyFunc m_getOwnProperty;
	DeletePropertyFunc m_deleteProperty;
	DefineOwnPropertyFunc m_defineOwnProperty;
public:
	CHashMap<int, RValue*, 3>* m_yyvarsMap;
	unsigned int m_nvars;
	unsigned int m_flags;
	unsigned int m_capacity;
	unsigned int m_visited;
	unsigned int m_visitedGC;
	int m_GCGen;
	int m_GCcreationframe;
	int m_slot;
	int m_kind;
	int m_rvalueInitType;
	int m_curSlot;
	int m_unused;
public:
	virtual ~YYObjectBase() { };
	virtual RValue& InternalGetYYVarRef(int index) = 0;
};

typedef bool(*VarGetValDirect)(YYObjectBase *inst, int var_ind, int array_ind, RValue *res);
extern VarGetValDirect Variable_GetValue_Direct;
typedef int(*FindRValSlot)(YYObjectBase* object, const char* name);
extern FindRValSlot FindRValueSlot;

struct YYRECT {
	int bbox_left;
	int bbox_top;
	int bbox_right;
	int bbox_bottom;
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
	int i_path_index;
	float i_path_position;
	float i_path_positionprevious;
	float i_path_speed;
	float i_path_scale;
	float i_path_orientation;
	int i_path_end;
	float i_path_xstart;
	float i_path_ystart;
	int i_timeline_index;
	float i_timeline_prevposition;
	float i_timeline_position;
	float i_timeline_speed;
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

class CEvent {
public:
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
	CObjectGM* m_pObject;
	struct CPhysicsObject * m_pPhysicsObject;
	struct CSkeletonInstance * m_pSkeletonAnimation;
	unsigned int m_Instflags;
	int i_id;
	int i_object_index;
	int i_sprite_index;
	float i_image_index;
	float i_image_speed;
	float i_image_scalex;
	float i_image_scaley;
	float i_image_angle;
	float i_image_alpha;
	unsigned int i_image_blend;
	float i_x;
	float i_y;
	float i_xstart;
	float i_ystart;
	float i_xprevious;
	float i_yprevious;
	float i_direction;
	float i_speed;
	float i_friction;
	float i_gravity_direction;
	float i_gravity;
	float i_hspeed;
	float i_vspeed;
	YYRECT i_bbox;
	int i_timer[12];
	cInstancePathAndTimeline* m_pPathAndTimeline;
	CCode* i_initcode;
	CCode* i_precreatecode;
	CObjectGM * m_pOldObject;
	int i_layer;
	int i_mask_index;
	short i_nMouseOver;
	CInstance * m_pNext;
	CInstance * m_pPrev;
	SLink m_collisionLink;
	SLink m_dirtyLink;
	SLink m_withLink;
	float i_depth;
	float i_currentdepth;
	float i_lastImageNumber;
	unsigned int i_collisionTestNumber;
	virtual ~CInstance() { /**/ };
	RValue& GetRVRef(int index)
	{
		if (this->yyvars != nullptr)
			return this->yyvars[index];
		else
		{
			Hash hash = static_cast<Hash>(index) * 0x9E3779B1u + 1u;
			unsigned int mask = this->m_yyvarsMap->m_curMask;
			unsigned int size = this->m_yyvarsMap->m_curSize;
			unsigned int position = mask & hash & 0x7fffffffU;
			auto* elem = this->m_yyvarsMap->m_elements;
			Hash ehash = elem[position].hash;
			if (ehash != 0)
			{
				unsigned int i = -1;
				do
				{
					unsigned int pos = position;
					if (ehash == (hash & 0x7fffffffu))
					{
						if ((pos != UINT_MAX) && (elem[pos].v != nullptr))
						{
							return *elem[pos].v;
						}
						break;
					}

					i++;
					if (((pos - (ehash & mask)) + size & mask) < i) break;
					ehash = (pos + 1U) & mask;
					position = ehash;
					ehash = elem[ehash].hash;
				} while (ehash != 0);
			}

			return *new RValue(-1337.0);
		}
	}
};

struct YYRoom {
	const char* pName;
	const char* pCaption;
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

extern YYGMLFunc* g_GMLScripts;
extern YYVAR** g_Variables;
extern CRoom** g_RunRoom;
extern CInstance* g_Self;
extern CInstance* g_Other;
extern CHash<CObjectGM>** g_ObjectHashTable;

typedef void(*GML_ObjectEvent)(CInstance* _pSelf, CInstance* _pOther);
typedef RValue&(*GML_Script)(CInstance* _pSelf, CInstance* _pOther, RValue& _result, int _count, const RValue** _args);
typedef void(*TRoutine)(RValue& _result, CInstance* _pSelf, CInstance* _pOther, int _argc, RValue *_args);


struct RFunction {
	char f_name[64];
	TRoutine f_routine;
	int f_argnumb;
	unsigned int m_UsageCount;
	int f_maxargnumb; // always 0xFFFFFFFF
};

extern int* g_RFunctionTableLen;
extern RFunction** g_RFunctionTable;

#define RUNTIME_MAX_ARGS (0x10)

typedef std::list<RValue> RValueList;
void CallRFunction(int id, RValue& ret, const RValueList& args)
{
	if (id < 0) abort();

	RFunction RFunc = (*g_RFunctionTable)[id];
	int i = 0;
	int argc = static_cast<int>(args.size());

	// allocate arguments **on the stack!** because GameMaker is stupid.
	RValue Rargs[RUNTIME_MAX_ARGS]{ /* will execute the default constructor */ };
	for (const auto& rv : args) {
		if (i >= sizeof(Rargs)) abort();
		Rargs[i] = rv; i++;
	}

	RFunc.f_routine(ret, g_Self, g_Other, argc, Rargs);
}

void CallScriptFunction(int id, RValue& ret, const RValueList& args, bool isEvent = false)
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
		const RValue **Arguments = nullptr;
		if (args.size() > 0)
		{
			Arguments = const_cast<const RValue**>(new RValue*[args.size()]);
			int i = 0;
			for (const auto& arg : args) { Arguments[i] = &arg; i++; }
		}

		// call
		reinterpret_cast<GML_Script>(myFunc.ptr)(g_Self, g_Other, ret, static_cast<int>(args.size()), Arguments);

		// clean up.
		if (Arguments != nullptr) delete[] Arguments;
	}
}