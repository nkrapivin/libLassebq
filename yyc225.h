typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned char    dwfenc;
typedef unsigned int    dword;
typedef long double    longdouble;
typedef long long    longlong;
typedef unsigned long    qword;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned long long    ulonglong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined3;
typedef unsigned int    undefined4;
typedef unsigned long    undefined5;
typedef unsigned long    undefined7;
typedef unsigned long    undefined8;
typedef unsigned short    ushort;
typedef int    wchar_t;
typedef unsigned short    word;
typedef struct CRoom CRoom, *PCRoom;

typedef char * String;

typedef uint TColor;

typedef struct CBackGM CBackGM, *PCBackGM;

typedef struct CViewGM CViewGM, *PCViewGM;

typedef struct CCode CCode, *PCCode;

typedef struct OLinkedList<CInstance> OLinkedList<CInstance>, *POLinkedList<CInstance>;

typedef struct LinkedList<CInstance> LinkedList<CInstance>, *PLinkedList<CInstance>;

typedef struct CInstance CInstance, *PCInstance;

typedef int int32;

typedef struct YYRoom YYRoom, *PYYRoom;

typedef uchar uint8;

typedef struct CPhysicsWorld CPhysicsWorld, *PCPhysicsWorld;

typedef struct cARRAY_STRUCTURE<RTile> cARRAY_STRUCTURE<RTile>, *PcARRAY_STRUCTURE<RTile>;

typedef struct YYRoomTiles YYRoomTiles, *PYYRoomTiles;

typedef struct YYRoomInstances YYRoomInstances, *PYYRoomInstances;

typedef struct LinkedList<CLayer> LinkedList<CLayer>, *PLinkedList<CLayer>;

typedef struct CHashMap<int,CLayer*,7> CHashMap<int,CLayer*,7>, *PCHashMap<int,CLayer*,7>;

typedef struct CHashMap<int,CLayerElementBase*,7> CHashMap<int,CLayerElementBase*,7>, *PCHashMap<int,CLayerElementBase*,7>;

typedef struct CLayerElementBase CLayerElementBase, *PCLayerElementBase;

typedef struct CHashMap<int,CLayerInstanceElement*,7> CHashMap<int,CLayerInstanceElement*,7>, *PCHashMap<int,CLayerInstanceElement*,7>;

typedef struct RToken RToken, *PRToken;

typedef struct RValue RValue, *PRValue;

typedef struct VMBuffer VMBuffer, *PVMBuffer;

typedef struct YYGMLFuncs YYGMLFuncs, *PYYGMLFuncs;

typedef enum eDeleteType {
    eDelete_placementdelete=3,
    eDelete_delete=1,
    eDelete_free=2,
    eDelete_none=0
} eDeleteType;

typedef struct YYObjectBase YYObjectBase, *PYYObjectBase;

typedef enum EJSRetValBool {
    EJSRVB_TRUE=1,
    EJSRVB_FALSE=0,
    EJSRVB_TYPE_ERROR=2
} EJSRetValBool;

typedef longlong int64;

typedef struct CObjectGM CObjectGM, *PCObjectGM;

typedef struct CPhysicsObject CPhysicsObject, *PCPhysicsObject;

typedef struct CSkeletonInstance CSkeletonInstance, *PCSkeletonInstance;

typedef struct tagYYRECT tagYYRECT, *PtagYYRECT;

typedef struct tagYYRECT YYRECT;

typedef struct cInstancePathAndTimeline cInstancePathAndTimeline, *PcInstancePathAndTimeline;

typedef struct SLink SLink, *PSLink;

typedef uint uint32;

typedef struct ContactsStack ContactsStack, *PContactsStack;

typedef struct AggregatedContactResult AggregatedContactResult, *PAggregatedContactResult;

typedef struct b2World b2World, *Pb2World;

typedef struct b2ParticleGroupDef b2ParticleGroupDef, *Pb2ParticleGroupDef;

typedef struct b2ParticleGroup b2ParticleGroup, *Pb2ParticleGroup;

typedef struct CPhysicsDebugRender CPhysicsDebugRender, *PCPhysicsDebugRender;

typedef struct CRunnerContactListener CRunnerContactListener, *PCRunnerContactListener;

typedef struct tCollisionSettings tCollisionSettings, *PtCollisionSettings;

typedef struct RTile RTile, *PRTile;

typedef struct CLayer CLayer, *PCLayer;

typedef struct Element Element, *PElement;


/* WARNING! conflicting data type names: /DWARF/yoyo_unordered_hash.h/CHashMap<int,CLayerElementBase*,7>/Element - /DWARF/yoyo_unordered_hash.h/CHashMap<int,CLayer*,7>/Element */


/* WARNING! conflicting data type names: /DWARF/yoyo_unordered_hash.h/CHashMap<int,CLayerInstanceElement*,7>/Element - /DWARF/yoyo_unordered_hash.h/CHashMap<int,CLayer*,7>/Element */

typedef enum eGML_TYPE {
    eGMLT_DOUBLE=1,
    eGMLT_NONE=0,
    eGMLT_INT32=4,
    eGMLT_STRING=2,
    eGMLT_ERROR=-65536
} eGML_TYPE;

typedef union anon_union_0 anon_union_0, *Panon_union_0;

typedef struct CInstanceBase CInstanceBase, *PCInstanceBase;

typedef struct real_pcre8_or_16 real_pcre8_or_16, *Preal_pcre8_or_16;

typedef struct real_pcre8_or_16 pcre;

typedef struct pcre_extra pcre_extra, *Ppcre_extra;

typedef struct CHashMap<int,RValue*,3> CHashMap<int,RValue*,3>, *PCHashMap<int,RValue*,3>;

typedef struct CHashMap<int,CObjectGM*,2> CHashMap<int,CObjectGM*,2>, *PCHashMap<int,CObjectGM*,2>;

typedef struct CHashMap<unsignedlonglong,CEvent*,3> CHashMap<unsignedlonglong,CEvent*,3>, *PCHashMap<unsignedlonglong,CEvent*,3>;

typedef struct CPhysicsDataGM CPhysicsDataGM, *PCPhysicsDataGM;

typedef struct SLinkedList<CInstance> SLinkedList<CInstance>, *PSLinkedList<CInstance>;

typedef struct b2Body b2Body, *Pb2Body;

typedef struct b2Vec2 b2Vec2, *Pb2Vec2;

typedef struct Hash<CPhysicsObject--b2FixtureContainer> Hash<CPhysicsObject--b2FixtureContainer>, *PHash<CPhysicsObject--b2FixtureContainer>;

typedef struct spAttachment spAttachment, *PspAttachment;

typedef struct spAtlas spAtlas, *PspAtlas;

typedef struct spSkeleton spSkeleton, *PspSkeleton;

typedef struct spSkeletonBounds spSkeletonBounds, *PspSkeletonBounds;

typedef struct spAnimation spAnimation, *PspAnimation;

typedef struct spAnimationState spAnimationState, *PspAnimationState;

typedef enum spEventType {
    SP_ANIMATION_END=2,
    SP_ANIMATION_COMPLETE=3,
    SP_ANIMATION_EVENT=5,
    SP_ANIMATION_START=0,
    SP_ANIMATION_INTERRUPT=1,
    SP_ANIMATION_DISPOSE=4
} spEventType;

typedef struct spTrackEntry spTrackEntry, *PspTrackEntry;

typedef struct spEvent spEvent, *PspEvent;

typedef struct spAnimationStateData spAnimationStateData, *PspAnimationStateData;

typedef struct spSkeletonData spSkeletonData, *PspSkeletonData;

typedef struct SLinkListEx SLinkListEx, *PSLinkListEx;

typedef struct CopyStack<AggregatedContactResult> CopyStack<AggregatedContactResult>, *PCopyStack<AggregatedContactResult>;

typedef struct b2Fixture b2Fixture, *Pb2Fixture;

typedef struct b2Manifold b2Manifold, *Pb2Manifold;

typedef struct b2WorldManifold b2WorldManifold, *Pb2WorldManifold;

typedef struct b2BlockAllocator b2BlockAllocator, *Pb2BlockAllocator;

typedef struct b2StackAllocator b2StackAllocator, *Pb2StackAllocator;

typedef struct b2ContactManager b2ContactManager, *Pb2ContactManager;

typedef struct b2Joint b2Joint, *Pb2Joint;

typedef struct b2DestructionListener b2DestructionListener, *Pb2DestructionListener;

typedef struct b2Draw b2Draw, *Pb2Draw;

typedef float float32;

typedef struct b2Profile b2Profile, *Pb2Profile;

typedef struct b2ParticleSystem b2ParticleSystem, *Pb2ParticleSystem;

typedef struct b2Version b2Version, *Pb2Version;

typedef struct b2ParticleColor b2ParticleColor, *Pb2ParticleColor;

typedef struct b2Shape b2Shape, *Pb2Shape;

typedef struct b2Transform b2Transform, *Pb2Transform;

typedef struct b2ContactListener b2ContactListener, *Pb2ContactListener;

typedef struct LinkedList<CLayerElementBase> LinkedList<CLayerElementBase>, *PLinkedList<CLayerElementBase>;

typedef uint Hash;


/* WARNING! conflicting data type names: /DWARF/YYGML.h/RValue/anon_union_0/anon_union_0 - /DWARF/YYGML.h/RValue/anon_union_0 */

typedef uint pcre_uint32;

typedef unsigned short pcre_uint16;

typedef uchar pcre_uint8;


/* WARNING! conflicting data type names: /DWARF/yoyo_unordered_hash.h/CHashMap<int,RValue*,3>/Element - /DWARF/yoyo_unordered_hash.h/CHashMap<int,CLayer*,7>/Element */


/* WARNING! conflicting data type names: /DWARF/yoyo_unordered_hash.h/CHashMap<int,CObjectGM*,2>/Element - /DWARF/yoyo_unordered_hash.h/CHashMap<int,CLayer*,7>/Element */


/* WARNING! conflicting data type names: /DWARF/yoyo_unordered_hash.h/CHashMap<unsignedlonglong,CEvent*,3>/Element - /DWARF/yoyo_unordered_hash.h/CHashMap<int,CLayer*,7>/Element */

typedef struct SLinkedListNode SLinkedListNode, *PSLinkedListNode;

typedef enum b2BodyType {
    b2_staticBody=0,
    b2_dynamicBody=2,
    b2_kinematicBody=1
} b2BodyType;

typedef unsigned short uint16;

typedef struct b2Sweep b2Sweep, *Pb2Sweep;

typedef struct b2JointEdge b2JointEdge, *Pb2JointEdge;

typedef struct b2ContactEdge b2ContactEdge, *Pb2ContactEdge;

typedef struct HashLink<HashNode<CPhysicsObject--b2FixtureContainer>> HashLink<HashNode<CPhysicsObject--b2FixtureContainer>>, *PHashLink<HashNode<CPhysicsObject--b2FixtureContainer>>;

typedef enum spAttachmentType {
    SP_ATTACHMENT_PATH=4,
    SP_ATTACHMENT_CLIPPING=6,
    SP_ATTACHMENT_BOUNDING_BOX=1,
    SP_ATTACHMENT_MESH=2,
    SP_ATTACHMENT_REGION=0,
    SP_ATTACHMENT_POINT=5,
    SP_ATTACHMENT_LINKED_MESH=3
} spAttachmentType;

typedef struct spAttachmentLoader spAttachmentLoader, *PspAttachmentLoader;

typedef struct spAtlasPage spAtlasPage, *PspAtlasPage;

typedef struct spAtlasRegion spAtlasRegion, *PspAtlasRegion;

typedef struct spBone spBone, *PspBone;

typedef struct spSlot spSlot, *PspSlot;

typedef struct spIkConstraint spIkConstraint, *PspIkConstraint;

typedef struct spTransformConstraint spTransformConstraint, *PspTransformConstraint;

typedef struct spPathConstraint spPathConstraint, *PspPathConstraint;

typedef struct spSkin spSkin, *PspSkin;

typedef struct spColor spColor, *PspColor;

typedef struct spBoundingBoxAttachment spBoundingBoxAttachment, *PspBoundingBoxAttachment;

typedef struct spPolygon spPolygon, *PspPolygon;

typedef struct spTimeline spTimeline, *PspTimeline;

typedef struct spEventData spEventData, *PspEventData;

typedef enum spMixBlend {
    SP_MIX_BLEND_REPLACE=2,
    SP_MIX_BLEND_SETUP=0,
    SP_MIX_BLEND_FIRST=1,
    SP_MIX_BLEND_ADD=3
} spMixBlend;

typedef struct spIntArray spIntArray, *PspIntArray;

typedef struct spTrackEntryArray spTrackEntryArray, *PspTrackEntryArray;

typedef struct spBoneData spBoneData, *PspBoneData;

typedef struct spSlotData spSlotData, *PspSlotData;

typedef struct spIkConstraintData spIkConstraintData, *PspIkConstraintData;

typedef struct spTransformConstraintData spTransformConstraintData, *PspTransformConstraintData;

typedef struct spPathConstraintData spPathConstraintData, *PspPathConstraintData;

typedef struct b2FixtureProxy b2FixtureProxy, *Pb2FixtureProxy;

typedef struct b2Filter b2Filter, *Pb2Filter;

typedef struct b2ManifoldPoint b2ManifoldPoint, *Pb2ManifoldPoint;

typedef enum Type {
    e_circles=0,
    e_faceA=1,
    e_faceB=2
} Type;

typedef struct b2Chunk b2Chunk, *Pb2Chunk;

typedef struct b2Block b2Block, *Pb2Block;

typedef struct b2StackEntry b2StackEntry, *Pb2StackEntry;

typedef struct b2BroadPhase b2BroadPhase, *Pb2BroadPhase;

typedef struct b2Contact b2Contact, *Pb2Contact;

typedef struct b2ContactFilter b2ContactFilter, *Pb2ContactFilter;

typedef enum b2JointType {
    e_revoluteJoint=1,
    e_mouseJoint=5,
    e_weldJoint=8,
    e_prismaticJoint=2,
    e_pulleyJoint=4,
    e_frictionJoint=9,
    e_gearJoint=6,
    e_unknownJoint=0,
    e_wheelJoint=7,
    e_distanceJoint=3,
    e_motorJoint=11,
    e_ropeJoint=10
} b2JointType;

typedef struct ParticleBuffer<unsignedint> ParticleBuffer<unsignedint>, *PParticleBuffer<unsignedint>;

typedef struct ParticleBuffer<b2Vec2> ParticleBuffer<b2Vec2>, *PParticleBuffer<b2Vec2>;

typedef struct ParticleBuffer<b2ParticleColor> ParticleBuffer<b2ParticleColor>, *PParticleBuffer<b2ParticleColor>;

typedef struct ParticleBuffer<void*> ParticleBuffer<void*>, *PParticleBuffer<void*>;

typedef struct Proxy Proxy, *PProxy;

typedef struct b2ParticleContact b2ParticleContact, *Pb2ParticleContact;

typedef struct b2ParticleBodyContact b2ParticleBodyContact, *Pb2ParticleBodyContact;

typedef struct Pair Pair, *PPair;

typedef struct Triad Triad, *PTriad;


/* WARNING! conflicting data type names: /DWARF/b2Shape.h/b2Shape/Type - /DWARF/b2Collision.h/b2Manifold/Type */

typedef struct b2Rot b2Rot, *Pb2Rot;

typedef struct HashNode<CPhysicsObject--b2FixtureContainer> HashNode<CPhysicsObject--b2FixtureContainer>, *PHashNode<CPhysicsObject--b2FixtureContainer>;

typedef enum spAtlasFormat {
    SP_ATLAS_RGBA8888=7,
    SP_ATLAS_RGB565=4,
    SP_ATLAS_RGBA4444=5,
    SP_ATLAS_RGB888=6,
    SP_ATLAS_LUMINANCE_ALPHA=3,
    SP_ATLAS_UNKNOWN_FORMAT=0,
    SP_ATLAS_ALPHA=1,
    SP_ATLAS_INTENSITY=2
} spAtlasFormat;

typedef enum spAtlasFilter {
    SP_ATLAS_MIPMAP_LINEAR_LINEAR=7,
    SP_ATLAS_UNKNOWN_FILTER=0,
    SP_ATLAS_MIPMAP=3,
    SP_ATLAS_NEAREST=1,
    SP_ATLAS_MIPMAP_NEAREST_LINEAR=6,
    SP_ATLAS_LINEAR=2,
    SP_ATLAS_MIPMAP_LINEAR_NEAREST=5,
    SP_ATLAS_MIPMAP_NEAREST_NEAREST=4
} spAtlasFilter;

typedef enum spAtlasWrap {
    SP_ATLAS_CLAMPTOEDGE=1,
    SP_ATLAS_REPEAT=2,
    SP_ATLAS_MIRROREDREPEAT=0
} spAtlasWrap;

typedef struct spVertexAttachment spVertexAttachment, *PspVertexAttachment;

typedef enum spTimelineType {
    SP_TIMELINE_PATHCONSTRAINTSPACING=12,
    SP_TIMELINE_PATHCONSTRAINTPOSITION=11,
    SP_TIMELINE_DRAWORDER=8,
    SP_TIMELINE_EVENT=7,
    SP_TIMELINE_ATTACHMENT=4,
    SP_TIMELINE_PATHCONSTRAINTMIX=13,
    SP_TIMELINE_SHEAR=3,
    SP_TIMELINE_COLOR=5,
    SP_TIMELINE_IKCONSTRAINT=9,
    SP_TIMELINE_TRANSFORMCONSTRAINT=10,
    SP_TIMELINE_DEFORM=6,
    SP_TIMELINE_TWOCOLOR=14,
    SP_TIMELINE_TRANSLATE=1,
    SP_TIMELINE_SCALE=2,
    SP_TIMELINE_ROTATE=0
} spTimelineType;

typedef enum spTransformMode {
    SP_TRANSFORMMODE_NORMAL=0,
    SP_TRANSFORMMODE_NOROTATIONORREFLECTION=2,
    SP_TRANSFORMMODE_NOSCALEORREFLECTION=4,
    SP_TRANSFORMMODE_ONLYTRANSLATION=1,
    SP_TRANSFORMMODE_NOSCALE=3
} spTransformMode;

typedef enum spBlendMode {
    SP_BLEND_MODE_ADDITIVE=1,
    SP_BLEND_MODE_NORMAL=0,
    SP_BLEND_MODE_SCREEN=3,
    SP_BLEND_MODE_MULTIPLY=2
} spBlendMode;

typedef enum spPositionMode {
    SP_POSITION_MODE_FIXED=0,
    SP_POSITION_MODE_PERCENT=1
} spPositionMode;

typedef enum spSpacingMode {
    SP_SPACING_MODE_LENGTH=0,
    SP_SPACING_MODE_FIXED=1,
    SP_SPACING_MODE_PERCENT=2
} spSpacingMode;

typedef enum spRotateMode {
    SP_ROTATE_MODE_CHAIN=1,
    SP_ROTATE_MODE_TANGENT=0,
    SP_ROTATE_MODE_CHAIN_SCALE=2
} spRotateMode;

typedef struct b2AABB b2AABB, *Pb2AABB;

typedef short int16;

typedef union b2ContactID b2ContactID, *Pb2ContactID;

typedef struct b2DynamicTree b2DynamicTree, *Pb2DynamicTree;

typedef struct b2Pair b2Pair, *Pb2Pair;

typedef struct b2FixtureContainer b2FixtureContainer, *Pb2FixtureContainer;

typedef struct b2ContactFeature b2ContactFeature, *Pb2ContactFeature;

typedef struct b2TreeNode b2TreeNode, *Pb2TreeNode;


/* WARNING! conflicting data type names: /DWARF/b2DynamicTree.h/b2TreeNode/anon_union_0 - /DWARF/YYGML.h/RValue/anon_union_0 */

union anon_union_0 {
    int32 v32;
    int64 v64;
    double val;
    union anon_union_0 field_3;
};

struct RValue {
    union anon_union_0 field_0;
    int flags;
    int kind;
};

struct RToken {
    int kind;
    enum eGML_TYPE type;
    int ind;
    int ind2;
    struct RValue value;
    int itemnumb;
    undefined field_0x24;
    undefined field_0x25;
    undefined field_0x26;
    undefined field_0x27;
    struct RToken * items;
    int position;
    undefined field_0x34;
    undefined field_0x35;
    undefined field_0x36;
    undefined field_0x37;
};

struct CCode {
    int (** _vptr$CCode)(void);
    struct CCode * m_pNext;
    int i_kind;
    bool i_compiled;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    String i_str;
    struct RToken i_token;
    struct RValue i_value;
    struct VMBuffer * i_pVM;
    struct VMBuffer * i_pVMDebugInfo;
    char * i_pCode;
    char * i_pName;
    int i_CodeIndex;
    undefined field_0x8c;
    undefined field_0x8d;
    undefined field_0x8e;
    undefined field_0x8f;
    struct YYGMLFuncs * i_pFunc;
    bool i_watch;
    undefined field_0x99;
    undefined field_0x9a;
    undefined field_0x9b;
    int i_offset;
    int i_locals;
    int i_args;
    int i_flags;
    undefined field_0xac;
    undefined field_0xad;
    undefined field_0xae;
    undefined field_0xaf;
};

struct b2Vec2 {
    float32 x;
    float32 y;
};

struct b2AABB {
    struct b2Vec2 lowerBound;
    struct b2Vec2 upperBound;
};

struct b2TreeNode {
    struct b2AABB aabb;
    void * userData;
    union anon_union_0 field_2;
    int32 child1;
    int32 child2;
    int32 height;
};

struct b2Rot {
    float32 s;
    float32 c;
};

struct b2Transform {
    struct b2Vec2 p;
    struct b2Rot q;
};

struct b2ParticleGroup {
    struct b2ParticleSystem * m_system;
    int32 m_firstIndex;
    int32 m_lastIndex;
    uint32 m_groupFlags;
    float32 m_strength;
    struct b2ParticleGroup * m_prev;
    struct b2ParticleGroup * m_next;
    int32 m_timestamp;
    float32 m_mass;
    float32 m_inertia;
    struct b2Vec2 m_center;
    struct b2Vec2 m_linearVelocity;
    float32 m_angularVelocity;
    struct b2Transform m_transform;
    uint m_destroyAutomatically:1;
    uint m_toBeDestroyed:1;
    uint m_toBeSplit:1;
    undefined field_0x59;
    undefined field_0x5a;
    undefined field_0x5b;
    undefined field_0x5c;
    undefined field_0x5d;
    undefined field_0x5e;
    undefined field_0x5f;
    void * m_userData;
};

struct YYGMLFuncs {
    char * pName;
    void (* pFunc)(struct CInstance *, struct CInstance *);
};

struct OLinkedList<CInstance> {
    struct CInstance * m_pFirst;
    struct CInstance * m_pLast;
    int m_Count;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
};

struct b2BlockAllocator {
    struct b2Chunk * m_chunks;
    int32 m_chunkCount;
    int32 m_chunkSpace;
    struct b2Block * m_freeLists[14];
};

struct b2Profile {
    float32 step;
    float32 collide;
    float32 solve;
    float32 solveInit;
    float32 solveVelocity;
    float32 solvePosition;
    float32 broadphase;
    float32 solveTOI;
};

struct b2StackEntry {
    char * data;
    int32 size;
    bool usedMalloc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
};

struct b2StackAllocator {
    char m_data[102400];
    int32 m_index;
    int32 m_allocation;
    int32 m_maxAllocation;
    undefined field_0x1900c;
    undefined field_0x1900d;
    undefined field_0x1900e;
    undefined field_0x1900f;
    struct b2StackEntry m_entries[32];
    int32 m_entryCount;
    undefined field_0x19214;
    undefined field_0x19215;
    undefined field_0x19216;
    undefined field_0x19217;
};

struct b2DynamicTree {
    int32 m_root;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    struct b2TreeNode * m_nodes;
    int32 m_nodeCount;
    int32 m_nodeCapacity;
    int32 m_freeList;
    uint32 m_path;
    int32 m_insertionCount;
    undefined field_0x24;
    undefined field_0x25;
    undefined field_0x26;
    undefined field_0x27;
};

struct b2BroadPhase {
    struct b2DynamicTree m_tree;
    int32 m_proxyCount;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    int32 * m_moveBuffer;
    int32 m_moveCapacity;
    int32 m_moveCount;
    struct b2Pair * m_pairBuffer;
    int32 m_pairCapacity;
    int32 m_pairCount;
    int32 m_queryProxyId;
    undefined field_0x54;
    undefined field_0x55;
    undefined field_0x56;
    undefined field_0x57;
};

struct b2ContactManager {
    struct b2BroadPhase m_broadPhase;
    struct b2Contact * m_contactList;
    int32 m_contactCount;
    undefined field_0x64;
    undefined field_0x65;
    undefined field_0x66;
    undefined field_0x67;
    struct b2ContactFilter * m_contactFilter;
    struct b2ContactListener * m_contactListener;
    struct b2BlockAllocator * m_allocator;
};

struct ParticleBuffer<unsignedint> { /* Original name: ParticleBuffer<unsigned int> */
    uint * data;
    int32 userSuppliedCapacity;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
};

struct ParticleBuffer<void*> { /* Original name: ParticleBuffer<void *> */
    void * * data;
    int32 userSuppliedCapacity;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
};

struct ParticleBuffer<b2ParticleColor> {
    struct b2ParticleColor * data;
    int32 userSuppliedCapacity;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
};

struct ParticleBuffer<b2Vec2> {
    struct b2Vec2 * data;
    int32 userSuppliedCapacity;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
};

struct b2ParticleSystem {
    int32 m_timestamp;
    int32 m_allParticleFlags;
    int32 m_allGroupFlags;
    float32 m_density;
    float32 m_inverseDensity;
    float32 m_gravityScale;
    float32 m_particleDiameter;
    float32 m_inverseDiameter;
    float32 m_squaredDiameter;
    int32 m_count;
    int32 m_internalAllocatedCapacity;
    int32 m_maxCount;
    struct ParticleBuffer<unsignedint> m_flagsBuffer;
    struct ParticleBuffer<b2Vec2> m_positionBuffer;
    struct ParticleBuffer<b2Vec2> m_velocityBuffer;
    float32 * m_accumulationBuffer;
    struct b2Vec2 * m_accumulation2Buffer;
    float32 * m_depthBuffer;
    struct ParticleBuffer<b2ParticleColor> m_colorBuffer;
    struct b2ParticleGroup * * m_groupBuffer;
    struct ParticleBuffer<void*> m_userDataBuffer;
    int32 m_proxyCount;
    int32 m_proxyCapacity;
    struct Proxy * m_proxyBuffer;
    int32 m_contactCount;
    int32 m_contactCapacity;
    struct b2ParticleContact * m_contactBuffer;
    int32 m_bodyContactCount;
    int32 m_bodyContactCapacity;
    struct b2ParticleBodyContact * m_bodyContactBuffer;
    int32 m_pairCount;
    int32 m_pairCapacity;
    struct Pair * m_pairBuffer;
    int32 m_triadCount;
    int32 m_triadCapacity;
    struct Triad * m_triadBuffer;
    int32 m_groupCount;
    undefined field_0xf4;
    undefined field_0xf5;
    undefined field_0xf6;
    undefined field_0xf7;
    struct b2ParticleGroup * m_groupList;
    float32 m_pressureStrength;
    float32 m_dampingStrength;
    float32 m_elasticStrength;
    float32 m_springStrength;
    float32 m_viscousStrength;
    float32 m_surfaceTensionStrengthA;
    float32 m_surfaceTensionStrengthB;
    float32 m_powderStrength;
    float32 m_ejectionStrength;
    float32 m_colorMixingStrength;
    struct b2World * m_world;
};

struct b2World {
    struct b2BlockAllocator m_blockAllocator;
    struct b2StackAllocator m_stackAllocator;
    int32 m_flags;
    undefined field_0x1929c;
    undefined field_0x1929d;
    undefined field_0x1929e;
    undefined field_0x1929f;
    struct b2ContactManager m_contactManager;
    struct b2Body * m_bodyList;
    struct b2Joint * m_jointList;
    int32 m_bodyCount;
    int32 m_jointCount;
    struct b2Vec2 m_gravity;
    bool m_allowSleep;
    undefined field_0x19341;
    undefined field_0x19342;
    undefined field_0x19343;
    undefined field_0x19344;
    undefined field_0x19345;
    undefined field_0x19346;
    undefined field_0x19347;
    struct b2DestructionListener * m_destructionListener;
    struct b2Draw * m_debugDraw;
    float32 m_inv_dt0;
    bool m_warmStarting;
    bool m_continuousPhysics;
    bool m_subStepping;
    bool m_stepComplete;
    struct b2Profile m_profile;
    struct b2ParticleSystem m_particleSystem;
    struct b2Version * m_liquidFunVersion;
    char * m_liquidFunVersionString;
};

struct b2Block {
    struct b2Block * next;
};

struct CHashMap<unsignedlonglong,CEvent*,3> { /* Original name: CHashMap<unsigned long long, CEvent *, 3> */
    int m_curSize;
    int m_numUsed;
    int m_curMask;
    int m_growThreshold;
    struct Element * m_elements;
};

struct YYRoomTiles {
    int32 count;
};

struct cARRAY_STRUCTURE<RTile> {
    int Length;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    struct RTile * Array;
};

struct b2ContactFeature {
    uint8 indexA;
    uint8 indexB;
    uint8 typeA;
    uint8 typeB;
};

union b2ContactID {
    struct b2ContactFeature cf;
    uint32 key;
};

struct b2ManifoldPoint {
    struct b2Vec2 localPoint;
    float32 normalImpulse;
    float32 tangentImpulse;
    union b2ContactID id;
};

struct b2Manifold {
    struct b2ManifoldPoint points[2];
    struct b2Vec2 localNormal;
    struct b2Vec2 localPoint;
    enum Type type;
    int32 pointCount;
};

struct tagYYRECT {
    int32 left;
    int32 top;
    int32 right;
    int32 bottom;
};

struct SLink {
    struct SLink * next;
    struct SLink * prev;
    struct SLinkListEx * list;
};

struct CInstanceBase {
    int (** _vptr$CInstanceBase)(void);
    struct RValue * yyvars;
};

struct YYObjectBase {
    struct CInstanceBase super_CInstanceBase;
    struct YYObjectBase * m_pNextObject;
    struct YYObjectBase * m_pPrevObject;
    struct YYObjectBase * m_prototype;
    pcre * m_pcre;
    struct pcre_extra * m_pcreExtra;
    char * m_class;
    void (* m_getOwnProperty)(struct YYObjectBase *, struct RValue *, char *);
    void (* m_deleteProperty)(struct YYObjectBase *, struct RValue *, char *, bool);
    EJSRetValBool (* m_defineOwnProperty)(struct YYObjectBase *, char *, struct RValue *, bool);
    struct CHashMap<int,RValue*,3> * m_yyvarsMap;
    uint32 m_nvars;
    uint32 m_flags;
    uint32 m_capacity;
    uint32 m_visited;
    uint32 m_visitedGC;
    int32 m_GCgen;
    int32 m_GCcreationframe;
    int m_slot;
    int m_kind;
    int m_rvalueInitType;
    int m_curSlot;
    undefined field_0x8c;
    undefined field_0x8d;
    undefined field_0x8e;
    undefined field_0x8f;
};

struct CInstance {
    struct YYObjectBase super_YYObjectBase;
    int64 m_CreateCounter;
    struct CObjectGM * m_pObject;
    struct CPhysicsObject * m_pPhysicsObject;
    struct CSkeletonInstance * m_pSkeletonAnimation;
    uint m_Instflags;
    int i_id;
    int i_objectindex;
    int i_spriteindex;
    float i_imageindex;
    float i_imagespeed;
    float i_imagescalex;
    float i_imagescaley;
    float i_imageangle;
    float i_imagealpha;
    uint i_imageblend;
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
    struct cInstancePathAndTimeline * m_pPathAndTimeline;
    struct CCode * i_initcode;
    struct CCode * i_precreatecode;
    struct CObjectGM * m_pOldObject;
    int m_nLayerID;
    int i_maskindex;
    short m_nMouseOver;
    struct CInstance * m_pNext;
    struct CInstance * m_pPrev;
    struct SLink m_collisionLink;
    struct SLink m_dirtyLink;
    struct SLink m_withLink;
    float i_depth;
    float i_currentdepth;
    float i_lastImageNumber;
    uint m_collisionTestNumber;
};

struct spSkeletonData {
    char * version;
    char * hash;
    float width;
    float height;
    int bonesCount;
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    struct spBoneData * * bones;
    int slotsCount;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    struct spSlotData * * slots;
    int skinsCount;
    undefined field_0x3c;
    undefined field_0x3d;
    undefined field_0x3e;
    undefined field_0x3f;
    struct spSkin * * skins;
    struct spSkin * defaultSkin;
    int eventsCount;
    undefined field_0x54;
    undefined field_0x55;
    undefined field_0x56;
    undefined field_0x57;
    struct spEventData * * events;
    int animationsCount;
    undefined field_0x64;
    undefined field_0x65;
    undefined field_0x66;
    undefined field_0x67;
    struct spAnimation * * animations;
    int ikConstraintsCount;
    undefined field_0x74;
    undefined field_0x75;
    undefined field_0x76;
    undefined field_0x77;
    struct spIkConstraintData * * ikConstraints;
    int transformConstraintsCount;
    undefined field_0x84;
    undefined field_0x85;
    undefined field_0x86;
    undefined field_0x87;
    struct spTransformConstraintData * * transformConstraints;
    int pathConstraintsCount;
    undefined field_0x94;
    undefined field_0x95;
    undefined field_0x96;
    undefined field_0x97;
    struct spPathConstraintData * * pathConstraints;
};

struct CLayerElementBase {
    int m_type;
    int m_id;
    bool m_bRuntimeDataInitialised;
    undefined field_0x9;
    undefined field_0xa;
    undefined field_0xb;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    char * m_pName;
    struct CLayer * m_pLayer;
    struct CLayerElementBase * m_pNext;
    struct CLayerElementBase * m_pPrev;
};

struct b2Pair {
    int32 proxyIdA;
    int32 proxyIdB;
};

struct spIkConstraint {
    struct spIkConstraintData * data;
    int bonesCount;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    struct spBone * * bones;
    struct spBone * target;
    int bendDirection;
    int compress;
    int stretch;
    float mix;
};

struct b2Filter {
    uint32 categoryBits;
    uint32 maskBits;
    int16 groupIndex;
    undefined field_0xa;
    undefined field_0xb;
};

struct LinkedList<CLayer> {
    struct CLayer * m_pFirst;
    struct CLayer * m_pLast;
    int m_Count;
    enum eDeleteType m_DeleteType;
};

struct Triad {
    int32 indexA;
    int32 indexB;
    int32 indexC;
    uint32 flags;
    float32 strength;
    struct b2Vec2 pa;
    struct b2Vec2 pb;
    struct b2Vec2 pc;
    float32 ka;
    float32 kb;
    float32 kc;
    float32 s;
};

struct spBoneData {
    int index;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    char * name;
    struct spBoneData * parent;
    float length;
    float x;
    float y;
    float rotation;
    float scaleX;
    float scaleY;
    float shearX;
    float shearY;
    enum spTransformMode transformMode;
    undefined field_0x3c;
    undefined field_0x3d;
    undefined field_0x3e;
    undefined field_0x3f;
};

struct CSkeletonInstance {
    float m_lastFrame;
    int m_lastFrameDir;
    bool m_drawCollisionData;
    bool m_forceUpdate;
    undefined field_0xa;
    undefined field_0xb;
    float m_skeletonScale[2];
    int m_attachmentCount;
    struct spAttachment * * m_ppAttachments;
    struct spAtlas * * m_ppAttachmentAtlases;
    struct spSkeleton * m_skeleton;
    struct spSkeletonBounds * m_skeletonBounds;
    struct spAnimation * m_animation;
    struct spAnimationState * m_animationState;
    struct spAnimationStateData * m_animationStateData;
    struct spSkeletonData * m_skeletonData;
};

struct b2WorldManifold {
    struct b2Vec2 normal;
    struct b2Vec2 points[2];
};

struct spTrackEntryArray {
    int size;
    int capacity;
    struct spTrackEntry * * items;
};

struct CHashMap<int,CLayerInstanceElement*,7> { /* Original name: CHashMap<int, CLayerInstanceElement *, 7> */
    int m_curSize;
    int m_numUsed;
    int m_curMask;
    int m_growThreshold;
    struct Element * m_elements;
};

struct b2Shape {
    int (** _vptr$b2Shape)(void);
    enum Type m_type;
    float32 m_radius;
};

struct spBone {
    struct spBoneData * data;
    struct spSkeleton * skeleton;
    struct spBone * parent;
    int childrenCount;
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    struct spBone * * children;
    float x;
    float y;
    float rotation;
    float scaleX;
    float scaleY;
    float shearX;
    float shearY;
    float ax;
    float ay;
    float arotation;
    float ascaleX;
    float ascaleY;
    float ashearX;
    float ashearY;
    int appliedValid;
    float a;
    float b;
    float worldX;
    float c;
    float d;
    float worldY;
    int sorted;
};

struct SLinkedListNode {
    struct SLinkedListNode * m_pNext;
    struct SLinkedListNode * m_pPrev;
    struct CInstance * m_pObj;
};

struct Hash<CPhysicsObject--b2FixtureContainer> { /* Original name: Hash<CPhysicsObject::b2FixtureContainer> */
    struct HashLink<HashNode<CPhysicsObject--b2FixtureContainer>> * m_pHashingTable;
    int m_HashingMask;
    int m_Count;
};

struct CBackGM {
    bool visible;
    bool foreground;
    undefined field_0x2;
    undefined field_0x3;
    int index;
    float x;
    float y;
    bool htiled;
    bool vtiled;
    undefined field_0x12;
    undefined field_0x13;
    float hspeed;
    float vspeed;
    float xscale;
    float yscale;
    int blend;
    float alpha;
};

struct b2ParticleContact {
    int32 indexA;
    int32 indexB;
    uint32 flags;
    float32 weight;
    struct b2Vec2 normal;
};

struct spAnimation {
    char * name;
    float duration;
    int timelinesCount;
    struct spTimeline * * timelines;
};

struct YYRoomInstances {
    int32 count;
};

struct spSkeletonBounds {
    int count;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    struct spBoundingBoxAttachment * * boundingBoxes;
    struct spPolygon * * polygons;
    float minX;
    float minY;
    float maxX;
    float maxY;
};

struct pcre_extra {
    ulong flags;
    void * study_data;
    ulong match_limit;
    void * callout_data;
    uchar * tables;
    ulong match_limit_recursion;
    uchar * * mark;
    void * executable_jit;
};

struct b2ContactEdge {
    struct b2Body * other;
    struct b2Contact * contact;
    struct b2ContactEdge * prev;
    struct b2ContactEdge * next;
};

struct b2Draw {
    int (** _vptr$b2Draw)(void);
    uint32 m_drawFlags;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
};

struct CHashMap<int,CLayer*,7> { /* Original name: CHashMap<int, CLayer *, 7> */
    int m_curSize;
    int m_numUsed;
    int m_curMask;
    int m_growThreshold;
    struct Element * m_elements;
};

struct LinkedList<CInstance> {
    struct CInstance * m_pFirst;
    struct CInstance * m_pLast;
    int m_Count;
    enum eDeleteType m_DeleteType;
};

struct CHashMap<int,CLayerElementBase*,7> { /* Original name: CHashMap<int, CLayerElementBase *, 7> */
    int m_curSize;
    int m_numUsed;
    int m_curMask;
    int m_growThreshold;
    struct Element * m_elements;
};

struct CRoom {
    int r_lasttile;
    struct CRoom * instance_handle;
    String r_caption;
    int r_speed;
    int r_width;
    int r_height;
    bool r_persistent;
    TColor r_color;
    bool r_showcolor;
    struct CBackGM * r_background[8];
    bool r_enableviews;
    bool r_clearscreen;
    bool r_cleardisplaybuffer;
    struct CViewGM * r_view[8];
    String r_code;
    struct CCode * r_codeCode;
    bool r_physicsWorld;
    int r_physicsGravityX;
    int r_physicsGravityY;
    float r_physicsPixToMeters;
    struct OLinkedList<CInstance> m_Active;
    struct LinkedList<CInstance> m_Deactive;
    struct CInstance * m_pMarkedFirst;
    struct CInstance * m_pMarkedLast;
    int32 * m_pCreationOrderList;
    int32 m_CreationOrderListSize;
    struct YYRoom * m_pRoom;
    uint8 * m_pBase;
    struct CPhysicsWorld * m_pPhysicsWorld;
    int r_tnumb;
    struct cARRAY_STRUCTURE<RTile> r_tile;
    struct YYRoomTiles * r_pTiles;
    struct YYRoomInstances * r_pInstances;
    char * m_pName;
    bool m_isDuplicate;
    struct LinkedList<CLayer> m_Layers;
    struct CHashMap<int,CLayer*,7> m_LayerLookup;
    struct CHashMap<int,CLayerElementBase*,7> m_LayerElementLookup;
    struct CLayerElementBase * m_LastLayerElementLookedUp;
    struct CHashMap<int,CLayerInstanceElement*,7> m_LayerInstanceElementLookup;
};

struct spColor {
    float r;
    float g;
    float b;
    float a;
};

struct b2Chunk {
    int32 blockSize;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    struct b2Block * blocks;
};

struct HashNode<CPhysicsObject--b2FixtureContainer> { /* Original name: HashNode<CPhysicsObject::b2FixtureContainer> */
    struct HashNode<CPhysicsObject--b2FixtureContainer> * m_pPrev;
    struct HashNode<CPhysicsObject--b2FixtureContainer> * m_pNext;
    uint m_ID;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    struct b2FixtureContainer * m_pObj;
};

struct spAnimationStateData {
    struct spSkeletonData * skeletonData;
    float defaultMix;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    void * entries;
};

struct spSkeleton {
    struct spSkeletonData * data;
    int bonesCount;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    struct spBone * * bones;
    struct spBone * root;
    int slotsCount;
    undefined field_0x24;
    undefined field_0x25;
    undefined field_0x26;
    undefined field_0x27;
    struct spSlot * * slots;
    struct spSlot * * drawOrder;
    int ikConstraintsCount;
    undefined field_0x3c;
    undefined field_0x3d;
    undefined field_0x3e;
    undefined field_0x3f;
    struct spIkConstraint * * ikConstraints;
    int transformConstraintsCount;
    undefined field_0x4c;
    undefined field_0x4d;
    undefined field_0x4e;
    undefined field_0x4f;
    struct spTransformConstraint * * transformConstraints;
    int pathConstraintsCount;
    undefined field_0x5c;
    undefined field_0x5d;
    undefined field_0x5e;
    undefined field_0x5f;
    struct spPathConstraint * * pathConstraints;
    struct spSkin * skin;
    struct spColor color;
    float time;
    float scaleX;
    float scaleY;
    float x;
    float y;
    undefined field_0x94;
    undefined field_0x95;
    undefined field_0x96;
    undefined field_0x97;
};

struct HashLink<HashNode<CPhysicsObject--b2FixtureContainer>> { /* Original name: HashLink<HashNode<CPhysicsObject::b2FixtureContainer> > */
    struct HashNode<CPhysicsObject--b2FixtureContainer> * m_pFirst;
    struct HashNode<CPhysicsObject--b2FixtureContainer> * m_pLast;
};

struct spSlot {
    struct spSlotData * data;
    struct spBone * bone;
    struct spColor color;
    struct spColor * darkColor;
    struct spAttachment * attachment;
    int attachmentVerticesCapacity;
    int attachmentVerticesCount;
    float * attachmentVertices;
};

struct b2ParticleColor {
    uint8 r;
    uint8 g;
    uint8 b;
    uint8 a;
};

struct b2ContactFilter {
    int (** _vptr$b2ContactFilter)(void);
};

struct spAtlas {
    struct spAtlasPage * pages;
    struct spAtlasRegion * regions;
    void * rendererObject;
};

struct spTrackEntry {
    struct spAnimation * animation;
    struct spTrackEntry * next;
    struct spTrackEntry * mixingFrom;
    struct spTrackEntry * mixingTo;
    void (* listener)(struct spAnimationState *, enum spEventType, struct spTrackEntry *, struct spEvent *);
    int trackIndex;
    int loop;
    int holdPrevious;
    float eventThreshold;
    float attachmentThreshold;
    float drawOrderThreshold;
    float animationStart;
    float animationEnd;
    float animationLast;
    float nextAnimationLast;
    float delay;
    float trackTime;
    float trackLast;
    float nextTrackLast;
    float trackEnd;
    float timeScale;
    float alpha;
    float mixTime;
    float mixDuration;
    float interruptAlpha;
    float totalAlpha;
    enum spMixBlend mixBlend;
    struct spIntArray * timelineMode;
    struct spTrackEntryArray * timelineHoldMix;
    float * timelinesRotation;
    int timelinesRotationCount;
    undefined field_0x9c;
    undefined field_0x9d;
    undefined field_0x9e;
    undefined field_0x9f;
    void * rendererObject;
    void * userData;
};

struct b2ContactListener {
    int (** _vptr$b2ContactListener)(void);
};

struct CRunnerContactListener {
    struct b2ContactListener super_b2ContactListener;
    struct CPhysicsWorld * m_pPhysicsWorld;
};

struct LinkedList<CLayerElementBase> {
    struct CLayerElementBase * m_pFirst;
    struct CLayerElementBase * m_pLast;
    int m_Count;
    enum eDeleteType m_DeleteType;
};

struct CLayer {
    int m_id;
    int m_depth;
    float m_xoffset;
    float m_yoffset;
    float m_hspeed;
    float m_vspeed;
    bool m_visible;
    bool m_deleting;
    bool m_dynamic;
    undefined field_0x1b;
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    char * m_pName;
    int m_beginScriptID;
    int m_endScriptID;
    int m_shaderID;
    undefined field_0x34;
    undefined field_0x35;
    undefined field_0x36;
    undefined field_0x37;
    struct LinkedList<CLayerElementBase> m_elements;
    struct CLayer * m_pNext;
    struct CLayer * m_pPrev;
};

struct b2Sweep {
    struct b2Vec2 localCenter;
    struct b2Vec2 c0;
    struct b2Vec2 c;
    float32 a0;
    float32 a;
    float32 alpha0;
};

struct tCollisionSettings {
    int objectIndex;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    ulong categoryBits;
    ulong maskBits;
};

struct CHashMap<int,CObjectGM*,2> { /* Original name: CHashMap<int, CObjectGM *, 2> */
    int m_curSize;
    int m_numUsed;
    int m_curMask;
    int m_growThreshold;
    struct Element * m_elements;
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
    undefined field_0x35;
    undefined field_0x36;
    undefined field_0x37;
};

struct SLinkListEx {
    struct SLink * head;
    struct SLink * tail;
    int offset;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
};

struct b2DestructionListener {
    undefined field_0x0;
    undefined field_0x1;
    undefined field_0x2;
    undefined field_0x3;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
};

struct CViewGM {
    bool visible;
    undefined field_0x1;
    undefined field_0x2;
    undefined field_0x3;
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

struct b2FixtureContainer {
    undefined field_0x0;
};

struct spTransformConstraintData {
    char * name;
    int order;
    int bonesCount;
    struct spBoneData * * bones;
    struct spBoneData * target;
    float rotateMix;
    float translateMix;
    float scaleMix;
    float shearMix;
    float offsetRotation;
    float offsetX;
    float offsetY;
    float offsetScaleX;
    float offsetScaleY;
    float offsetShearY;
    int relative;
    int local;
};

struct spEventData {
    char * name;
    int intValue;
    float floatValue;
    char * stringValue;
    char * audioPath;
    float volume;
    float balance;
};

struct real_pcre8_or_16 {
    pcre_uint32 magic_number;
    pcre_uint32 size;
    pcre_uint32 options;
    pcre_uint32 flags;
    pcre_uint32 limit_match;
    pcre_uint32 limit_recursion;
    pcre_uint16 first_char;
    pcre_uint16 req_char;
    pcre_uint16 max_lookbehind;
    pcre_uint16 top_bracket;
    pcre_uint16 top_backref;
    pcre_uint16 name_table_offset;
    pcre_uint16 name_entry_size;
    pcre_uint16 name_count;
    pcre_uint16 ref_count;
    pcre_uint16 dummy1;
    pcre_uint16 dummy2;
    pcre_uint16 dummy3;
    pcre_uint8 * tables;
    void * nullpad;
};

struct b2FixtureProxy {
    struct b2AABB aabb;
    struct b2Fixture * fixture;
    int32 childIndex;
    int32 proxyId;
};

struct b2ParticleGroupDef {
    uint32 flags;
    uint32 groupFlags;
    struct b2Vec2 position;
    float32 angle;
    struct b2Vec2 linearVelocity;
    float32 angularVelocity;
    struct b2ParticleColor color;
    float32 strength;
    struct b2Shape * shape;
    bool destroyAutomatically;
    undefined field_0x31;
    undefined field_0x32;
    undefined field_0x33;
    undefined field_0x34;
    undefined field_0x35;
    undefined field_0x36;
    undefined field_0x37;
    void * userData;
};

struct CopyStack<AggregatedContactResult> {
    struct AggregatedContactResult * m_stack;
    int m_stackTop;
    int m_stackSize;
};

struct ContactsStack {
    struct CopyStack<AggregatedContactResult> m_contactsStack;
};

struct CPhysicsWorld {
    struct ContactsStack m_contactsStack;
    struct AggregatedContactResult * m_pCurrentContact;
    struct b2World * m_pWorld;
    struct b2ParticleGroupDef m_particleGroupDef;
    struct b2ParticleGroup * * m_ppParticleGroups;
    int m_particleGroupCount;
    undefined field_0x6c;
    undefined field_0x6d;
    undefined field_0x6e;
    undefined field_0x6f;
    struct CPhysicsDebugRender * m_pDebugRenderer;
    struct CRunnerContactListener * m_pContactListener;
    int m_updateSpeed;
    int m_updateIterations;
    float m_pixelToMetreScale;
    bool m_paused;
    undefined field_0x8d;
    undefined field_0x8e;
    undefined field_0x8f;
    struct tCollisionSettings m_objectToCollisionCategory[32];
};

struct spIkConstraintData {
    char * name;
    int order;
    int bonesCount;
    struct spBoneData * * bones;
    struct spBoneData * target;
    int bendDirection;
    int compress;
    int stretch;
    int uniform;
    float mix;
    undefined field_0x34;
    undefined field_0x35;
    undefined field_0x36;
    undefined field_0x37;
};

struct spEvent {
    struct spEventData * data;
    float time;
    int intValue;
    float floatValue;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    char * stringValue;
    float volume;
    float balance;
};

struct spSlotData {
    int index;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    char * name;
    struct spBoneData * boneData;
    char * attachmentName;
    struct spColor color;
    struct spColor * darkColor;
    enum spBlendMode blendMode;
    undefined field_0x3c;
    undefined field_0x3d;
    undefined field_0x3e;
    undefined field_0x3f;
};

struct spAtlasPage {
    struct spAtlas * atlas;
    char * name;
    enum spAtlasFormat format;
    enum spAtlasFilter minFilter;
    enum spAtlasFilter magFilter;
    enum spAtlasWrap uWrap;
    enum spAtlasWrap vWrap;
    undefined field_0x24;
    undefined field_0x25;
    undefined field_0x26;
    undefined field_0x27;
    void * rendererObject;
    int width;
    int height;
    struct spAtlasPage * next;
};

struct CHashMap<int,RValue*,3> { /* Original name: CHashMap<int, RValue *, 3> */
    int m_curSize;
    int m_numUsed;
    int m_curMask;
    int m_growThreshold;
    struct Element * m_elements;
};

struct spTimeline {
    enum spTimelineType type;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    void * vtable;
};

struct b2JointEdge {
    struct b2Body * other;
    struct b2Joint * joint;
    struct b2JointEdge * prev;
    struct b2JointEdge * next;
};

struct AggregatedContactResult {
    int m_manifoldCount;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    struct b2Fixture * fixture1;
    struct b2Fixture * fixture2;
    struct b2Manifold manifolds[8];
    struct b2WorldManifold worldManifolds[8];
};

struct spAttachment {
    char * name;
    enum spAttachmentType type;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    void * vtable;
    struct spAttachmentLoader * attachmentLoader;
};

struct spPathConstraint {
    struct spPathConstraintData * data;
    int bonesCount;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    struct spBone * * bones;
    struct spSlot * target;
    float position;
    float spacing;
    float rotateMix;
    float translateMix;
    int spacesCount;
    undefined field_0x34;
    undefined field_0x35;
    undefined field_0x36;
    undefined field_0x37;
    float * spaces;
    int positionsCount;
    undefined field_0x44;
    undefined field_0x45;
    undefined field_0x46;
    undefined field_0x47;
    float * positions;
    int worldCount;
    undefined field_0x54;
    undefined field_0x55;
    undefined field_0x56;
    undefined field_0x57;
    float * world;
    int curvesCount;
    undefined field_0x64;
    undefined field_0x65;
    undefined field_0x66;
    undefined field_0x67;
    float * curves;
    int lengthsCount;
    undefined field_0x74;
    undefined field_0x75;
    undefined field_0x76;
    undefined field_0x77;
    float * lengths;
    float segments[10];
};

struct spVertexAttachment {
    struct spAttachment super;
    int bonesCount;
    undefined field_0x24;
    undefined field_0x25;
    undefined field_0x26;
    undefined field_0x27;
    int * bones;
    int verticesCount;
    undefined field_0x34;
    undefined field_0x35;
    undefined field_0x36;
    undefined field_0x37;
    float * vertices;
    int worldVerticesLength;
    int id;
};

struct b2Fixture {
    float32 m_density;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    struct b2Fixture * m_next;
    struct b2Body * m_body;
    struct b2Shape * m_shape;
    float32 m_friction;
    float32 m_restitution;
    struct b2FixtureProxy * m_proxies;
    int32 m_proxyCount;
    struct b2Filter m_filter;
    bool m_isSensor;
    undefined field_0x41;
    undefined field_0x42;
    undefined field_0x43;
    undefined field_0x44;
    undefined field_0x45;
    undefined field_0x46;
    undefined field_0x47;
    void * m_userData;
};

struct Element {
    struct CLayer * v;
    int k;
    Hash h;
};

struct b2Body {
    enum b2BodyType m_type;
    uint16 m_flags;
    undefined field_0x6;
    undefined field_0x7;
    int32 m_islandIndex;
    struct b2Transform m_xf;
    struct b2Transform m_xf0;
    struct b2Sweep m_sweep;
    struct b2Vec2 m_linearVelocity;
    float32 m_angularVelocity;
    struct b2Vec2 m_force;
    float32 m_torque;
    struct b2World * m_world;
    struct b2Body * m_prev;
    struct b2Body * m_next;
    struct b2Fixture * m_fixtureList;
    int32 m_fixtureCount;
    undefined field_0x8c;
    undefined field_0x8d;
    undefined field_0x8e;
    undefined field_0x8f;
    struct b2JointEdge * m_jointList;
    struct b2ContactEdge * m_contactList;
    float32 m_mass;
    float32 m_invMass;
    float32 m_I;
    float32 m_invI;
    float32 m_linearDamping;
    float32 m_angularDamping;
    float32 m_gravityScale;
    float32 m_sleepTime;
    void * m_userData;
};

struct spAnimationState {
    struct spAnimationStateData * data;
    int tracksCount;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    struct spTrackEntry * * tracks;
    void (* listener)(struct spAnimationState *, enum spEventType, struct spTrackEntry *, struct spEvent *);
    float timeScale;
    undefined field_0x24;
    undefined field_0x25;
    undefined field_0x26;
    undefined field_0x27;
    void * rendererObject;
    void * userData;
};

struct Proxy {
    int32 index;
    uint32 tag;
};

struct CPhysicsObject {
    struct b2Body * m_pBody;
    struct b2Vec2 m_visualOffset;
    struct b2Vec2 m_previousPosition;
    int m_collisionCategory;
    uint m_nextFixtureIndex;
    struct Hash<CPhysicsObject--b2FixtureContainer> * m_pFixtureMap;
};

struct cInstancePathAndTimeline {
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

struct spPolygon {
    float * vertices;
    int count;
    int capacity;
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

struct spBoundingBoxAttachment {
    struct spVertexAttachment super;
};

struct Pair {
    int32 indexA;
    int32 indexB;
    uint32 flags;
    float32 strength;
    float32 distance;
};

struct SLinkedList<CInstance> {
    struct SLinkedListNode * m_pFirst;
    struct SLinkedListNode * m_pLast;
    int m_Count;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
};

struct CObjectGM {
    char * m_pName;
    struct CObjectGM * m_pParent;
    struct CHashMap<int,CObjectGM*,2> * m_childrenMap;
    struct CHashMap<unsignedlonglong,CEvent*,3> * m_eventsMap;
    struct CPhysicsDataGM m_physicsData;
    undefined field_0x4c;
    undefined field_0x4d;
    undefined field_0x4e;
    undefined field_0x4f;
    struct SLinkedList<CInstance> m_Instances;
    struct SLinkedList<CInstance> m_Instances_Recursive;
    uint32 m_Flags;
    int m_spriteindex;
    int m_depth;
    int m_parent;
    int m_mask;
    int m_ID;
};

struct b2Joint {
    int (** _vptr$b2Joint)(void);
    enum b2JointType m_type;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    struct b2Joint * m_prev;
    struct b2Joint * m_next;
    struct b2JointEdge m_edgeA;
    struct b2JointEdge m_edgeB;
    struct b2Body * m_bodyA;
    struct b2Body * m_bodyB;
    int32 m_index;
    bool m_islandFlag;
    bool m_collideConnected;
    undefined field_0x76;
    undefined field_0x77;
    void * m_userData;
};

struct spIntArray {
    int size;
    int capacity;
    int * items;
};

struct spTransformConstraint {
    struct spTransformConstraintData * data;
    int bonesCount;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    struct spBone * * bones;
    struct spBone * target;
    float rotateMix;
    float translateMix;
    float scaleMix;
    float shearMix;
};

struct b2Contact {
    int (** _vptr$b2Contact)(void);
    uint32 m_flags;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    struct b2Contact * m_prev;
    struct b2Contact * m_next;
    struct b2ContactEdge m_nodeA;
    struct b2ContactEdge m_nodeB;
    struct b2Fixture * m_fixtureA;
    struct b2Fixture * m_fixtureB;
    int32 m_indexA;
    int32 m_indexB;
    struct b2Manifold m_manifold;
    int32 m_toiCount;
    float32 m_toi;
    float32 m_friction;
    float32 m_restitution;
    float32 m_tangentSpeed;
    undefined field_0xcc;
    undefined field_0xcd;
    undefined field_0xce;
    undefined field_0xcf;
};

struct CPhysicsDebugRender {
    struct b2Draw super_b2Draw;
    struct CPhysicsWorld * m_pWorld;
};

struct spAttachmentLoader {
    char * error1;
    char * error2;
    void * vtable;
};

struct VMBuffer {
    int (** _vptr$VMBuffer)(void);
    int m_size;
    int m_numLocalVarsUsed;
    int m_numArguments;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    uint8 * m_pBuffer;
    void * * m_pConvertedBuffer;
    int * m_pJumpBuffer;
};

struct b2Version {
    int32 major;
    int32 minor;
    int32 revision;
};

struct spSkin {
    char * name;
};

struct spAtlasRegion {
    char * name;
    int x;
    int y;
    int width;
    int height;
    float u;
    float v;
    float u2;
    float v2;
    int offsetX;
    int offsetY;
    int originalWidth;
    int originalHeight;
    int index;
    int rotate;
    int flip;
    undefined field_0x44;
    undefined field_0x45;
    undefined field_0x46;
    undefined field_0x47;
    int * splits;
    int * pads;
    struct spAtlasPage * page;
    struct spAtlasRegion * next;
};

struct YYRoom {
    uint32 pName;
    uint32 pCaption;
    int width;
    int height;
    int speed;
    int persistent;
    int colour;
    int showColour;
    uint32 pCode;
    int enableViews;
    uint32 pBackgrounds;
    uint32 pViews;
    uint32 pInstances;
    uint32 pTiles;
    int physicsWorld;
    int physicsWorldTop;
    int physicsWorldLeft;
    int physicsWorldRight;
    int physicsWorldBottom;
    float physicsWorldGravityX;
    float physicsWorldGravityY;
    float physicsWorldPixToMeters;
};

struct spPathConstraintData {
    char * name;
    int order;
    int bonesCount;
    struct spBoneData * * bones;
    struct spSlotData * target;
    enum spPositionMode positionMode;
    enum spSpacingMode spacingMode;
    enum spRotateMode rotateMode;
    float offsetRotation;
    float position;
    float spacing;
    float rotateMix;
    float translateMix;
};

struct b2ParticleBodyContact {
    int32 index;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    struct b2Body * body;
    float32 weight;
    struct b2Vec2 normal;
    float32 mass;
};

