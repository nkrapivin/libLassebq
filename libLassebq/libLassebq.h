#pragma once
#include "stdafx.h"
#include "pcre\include\pcre.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <list>
#include <memory>

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

#define MASK_KIND_RVALUE (0x0ffffff)
enum RValueType : int {
	VALUE_REAL = 0,
	VALUE_STRING = 1,
	VALUE_ARRAY = 2,
	VALUE_PTR = 3,
	VALUE_VEC3 = 4,
	VALUE_UNDEFINED = 5,
	VALUE_OBJECT = 6,
	VALUE_INT32 = 7,
	VALUE_VEC4 = 8,
	VALUE_MATRIX = 9,
	VALUE_INT64 = 10,
	VALUE_ACCESSOR = 11,
	VALUE_JSNULL = 12,
	VALUE_BOOL = 13,
	VALUE_ITERATOR = 14,
	VALUE_REF = 15,
	VALUE_UNSET = MASK_KIND_RVALUE
};

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

#define JS_BUILTIN_PROPERTY_DEFAULT        (ERV_Writable | ERV_Configurable)
#define JS_BUILTIN_LENGTH_PROPERTY_DEFAULT (ERV_None)

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
typedef _RefThing<void*> RefKeep;

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
	RValue* pOwner;
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
int lassebq_find_runtime(const char* name);

#define VARIABLE_ARRAY_MAX_DIMENSION (32000)
#define ARRAY_INDEX_NO_INDEX         (INT_MIN)
#define POINTER_INVALID              (reinterpret_cast<void *>(-1))
#define POINTER_NULL                 (nullptr)

typedef void(*FREE_RVal_Pre)(RValue* p);
typedef void(*YYSetStr)(RValue* _pVal, const char* _pS);
extern FREE_RVal_Pre FREE_RValue__Pre;
extern YYSetStr YYSetString;

// copies one RValue into another keeping stuff like references and GC in mind.
void COPY_RValue__Post(RValue* _pDest, const RValue* _pSource);
struct RValue
{
	union {
		int v32;
		long long v64 = 0L;
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
	int flags = 0; // use for flags (Hijack for Enumerable and Configurable bits in JavaScript)  (Note: probably will need a visibility as well, to support private variables that are promoted to object scope, but should not be seen (is that just not enumerated????) )
	int kind = 0; // kind of value

	void __localFree(void)
	{
		if (((kind - 1) & (MASK_KIND_RVALUE & (~3))) == 0) {
			FREE_RValue__Pre(this);
		}
	}

	void __localCopy(const RValue& v)
	{
		COPY_RValue__Post(this, &v);
	}

	~RValue()
	{
		//std::cout << "DESTRUCTOR CALLED!" << std::endl;
		__localFree();
	}

	RValue()
	{
		flags = 0;
		kind = VALUE_UNDEFINED;
		v64 = 0L;
	}

	RValue(const RValue& v)
	{
		__localCopy(v);
	}

	RValue(double v)
	{
		flags = 0;
		kind = VALUE_REAL;
		val = v;
	}

	RValue(float v)
	{
		flags = 0;
		kind = VALUE_REAL;
		val = v;
	}

	RValue(int v)
	{
		flags = 0;
		kind = VALUE_REAL;
		val = v;
	}

	RValue(long long v)
	{
		flags = 0;
		kind = VALUE_INT64;
		v64 = v;
	}

	RValue(bool v)
	{
		flags = 0;
		kind = VALUE_REAL;
		val = v ? 1.0 : 0.0;
	}

	RValue(std::nullptr_t)
	{
		flags = 0;
		kind = VALUE_PTR;
		ptr = nullptr;
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
		YYSetString(this, v);
	}

	RValue(std::string v)
	{
		flags = 0;
		YYSetString(this, v.c_str());
	}

	RValue(std::wstring v)
	{
		flags = 0;
		int __size = WideCharToMultiByte(CP_UTF8, 0, v.c_str(), -1, nullptr, 0, nullptr, nullptr);
		LPSTR s = new CHAR[__size];

		WideCharToMultiByte(CP_UTF8, 0, v.c_str(), -1, s, __size, nullptr, nullptr);

		YYSetString(this, s);
		delete[] s;
	}

	RValue operator-()
	{
		RValue ret;
		ret.kind = kind;
		ret.flags = flags;
		switch ((kind & MASK_KIND_RVALUE)) {
			case VALUE_BOOL:
			case VALUE_REAL: ret.val = -val; break;
			case VALUE_INT32: ret.v32 = -v32; break;
			case VALUE_INT64: ret.v64 = -v64; break;
			default: abort();
		}

		return ret;
	}

	RValue operator+()
	{
		RValue copy(*this);
		return copy;
	}

	RValue& operator=(const RValue& v)
	{
		if (&v != this)
		{
			RValue temp;
			memcpy(&temp, &v, sizeof(RValue));
			bool fIsArray = (temp.kind & MASK_KIND_RVALUE) == VALUE_ARRAY;
			if (fIsArray) ++(temp.pRefArray->refcount);
			__localFree();
			if (fIsArray) --(temp.pRefArray->refcount);
			__localCopy(temp);
		}

		return *this;
	}

	RValue& operator=(double v)
	{
		__localFree();
		kind = VALUE_REAL;
		val = v;
		return *this;
	}

	RValue& operator=(float v)
	{
		__localFree();
		kind = VALUE_REAL;
		val = v;
		return *this;
	}

	RValue& operator=(int v)
	{
		__localFree();
		kind = VALUE_REAL;
		val = v;
		return *this;
	}

	RValue& operator=(long long v)
	{
		__localFree();
		kind = VALUE_INT64;
		v64 = v;
		return *this;
	}

	RValue& operator=(void* v)
	{
		__localFree();
		kind = VALUE_PTR;
		ptr = v;
		return *this;
	}

	RValue& operator=(bool v)
	{
		__localFree();
		kind = VALUE_REAL;
		val = v ? 1.0 : 0.0;
		return *this;
	}

	RValue& operator++()
	{
		switch (kind & MASK_KIND_RVALUE)
		{
			case VALUE_BOOL:
			case VALUE_REAL: ++val; break;
			case VALUE_INT32: ++v32; break;
			case VALUE_INT64: ++v64; break;
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
			case VALUE_BOOL:
			case VALUE_REAL: val--; break;
			case VALUE_INT32: v32--; break;
			case VALUE_INT64: v64--; break;
			default: abort();
		}
		return *this;
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

	const RValue& DoArrayIndex(const int _index) const
	{
		const RValue* pV = nullptr;
		if ((kind & MASK_KIND_RVALUE) == VALUE_ARRAY && (pRefArray != nullptr)) {
			ldiv_t ind = ldiv(_index, VARIABLE_ARRAY_MAX_DIMENSION);
			if (pRefArray->pOwner == nullptr) abort();

			const DynamicArrayOfRValue* pArr = nullptr;
			if ((ind.quot >= 0) && (pRefArray != nullptr) && (ind.quot < pRefArray->length)) {
				pArr = &pRefArray->pArray[ind.quot];
				if ((ind.rem >= 0) && (ind.rem < pArr->length)) {
					pV = &pArr->arr[ind.rem];
				}
				else {
					abort();
				}
			}
			else {
				abort();
			}
		}
		else {
			pV = this;
			abort();
		}

		return *pV;
	}

	const RValue& operator[](const int _index)
	{
		return DoArrayIndex(_index);
	}

	const RValue& operator[](const double _index)
	{
		int _iindex = static_cast<int>(_index);
		return operator[](_iindex);
	}

	std::string asString() const
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
			case VALUE_ARRAY: {
				// WARNING: A VERY VERY VERY HORRIBLE IMPLEMENTATION!!
				typedef std::list<RValue> RValueList;
				void CallRFunction(int id, RValue& ret, const RValueList& args);

				if (this->pRefArray->pArray == nullptr)
					return "{ <empty array pointer> }";
				int arrlen = this->pRefArray->pArray->length;
				if (arrlen <= 0) return "{ <empty array> }";

				std::stringstream ss;

				ss << "{ ";
				for (int i = 0; i < arrlen; i++)
				{
					const RValue& elem = this->DoArrayIndex(i);
					// "i":
					ss << '"' << i << "\": ";
					if ((elem.kind & MASK_KIND_RVALUE) == VALUE_STRING) ss << '"';
					ss << elem.asString();
					if ((elem.kind & MASK_KIND_RVALUE) == VALUE_STRING) ss << '"';
					if (i < arrlen - 1) ss << ", ";
				}
				ss << " }";

				return ss.str();
			}
			case VALUE_BOOL: return (val > 0.5) ? "true" : "false";
			case VALUE_UNSET: return "<unset>"; // ??????????
			case VALUE_UNDEFINED: return "<undefined>";
			case VALUE_STRING: return pRefString->get();
			default: abort();
		}
	}

	double asReal() const
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

	bool isNumber() const
	{
		int mKind = kind & MASK_KIND_RVALUE;
		return (mKind == VALUE_REAL || mKind == VALUE_INT32 || mKind == VALUE_INT64 || mKind == VALUE_BOOL);
	}
};

void COPY_RValue__Post(RValue* _pDest, const RValue* _pSource)
{
	_pDest->kind = _pSource->kind;
	_pDest->flags = _pSource->flags;

	switch (_pSource->kind & MASK_KIND_RVALUE) {
	case VALUE_BOOL:
	case VALUE_REAL:
		_pDest->val = _pSource->val;
		break;
	case VALUE_INT32:
		_pDest->v32 = _pSource->v32;
		break;
	case VALUE_INT64:
		_pDest->v64 = _pSource->v64;
		break;
	case VALUE_PTR:
	case VALUE_ITERATOR:
		_pDest->ptr = _pSource->ptr;
		break;
	case VALUE_ARRAY:
		_pDest->pRefArray = _pSource->pRefArray;
		if (_pDest->pRefArray != nullptr) {
			++_pDest->pRefArray->refcount;
			if (_pDest->pRefArray->pOwner == nullptr) {
				_pDest->pRefArray->pOwner = const_cast<RValue*>(_pSource);
			}
		}
		break;
	case VALUE_STRING:
		_pDest->pRefString = RefString::assign(_pSource->pRefString);
		break;
	case VALUE_OBJECT:
		_pDest->pObj = _pSource->pObj;

		if (_pDest->pObj != nullptr) {
			// TODO!!
			abort();
		}
		break;
	}
}

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

class cARRAY_OF_POINTERS {
	int Length;
	int m_slotsUsed;
	int m_reserveSize;
	void** Array;

	~cARRAY_OF_POINTERS() {
		if (this->Length != 0) {
			this->Array = nullptr;
			delete this;
		}
	}
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

struct DynamicArrayOfInteger {
	int length;
	//char pad[sizeof(int)];
	int* arr;
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
	pcre* m_pcre;
	pcre_extra* m_pcreExtra;
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
extern DynamicArrayOfInteger* g_ObjectHasEvent;
extern int* g_ObjectNumEvent;
extern int* g_CurrentRoom;

typedef void(*GML_ObjectEvent)(CInstance* _pSelf, CInstance* _pOther);
typedef RValue&(*GML_Script)(CInstance* _pSelf, CInstance* _pOther, RValue& _result, int _count, const RValue** _args);
typedef void(*TRoutine)(RValue& _result, CInstance* _pSelf, CInstance* _pOther, int _argc, RValue *_args);


struct RFunction {
	char f_name[64];
	TRoutine f_routine;
	int f_argnumb;
	unsigned int m_UsageCount;
	int f_FFFFFFFF; // always 0xFFFFFFFF
};

extern int* g_RFunctionTableLen;
extern RFunction** g_RFunctionTable;

typedef std::list<RValue> RValueList;
void CallRFunction(int id, RValue& ret, const RValueList& args)
{
	if (id < 0) abort();

	RFunction RFunc = (*g_RFunctionTable)[id];
	int i = 0;
	int argc = args.size();

	// allocate arguments **on the stack!** because GameMaker is stupid.
	RValue Rargs[16]{ 0.0 };
	for (const auto& rv : args) {
		if (i >= sizeof(Rargs)) abort();
		Rargs[i] = rv; i++;
	}

	RFunc.f_routine(ret, g_Self, nullptr, argc, Rargs);
}

void CallGMLFunction(int id, RValue& ret, const RValueList& args)
{
	if (id < 0) abort();

	// do the magic.
	CallRFunction(g_BuiltinFuncs[id]->val, ret, args);
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
		reinterpret_cast<GML_Script>(myFunc.ptr)(g_Self, nullptr, ret, args.size(), Arguments);

		// clean up.
		if (Arguments != nullptr) delete[] Arguments;
	}
}