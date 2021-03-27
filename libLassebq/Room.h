#pragma once
#include "Data.h"

struct YYRoom
{
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

class CTimingSource
{
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
	CLayer* m_pNext;
	CLayer* m_pPrev;
};

class CInstance;
class CLayerInstanceElement : public CLayerElementBase {
	int m_instanceID;
	CInstance* m_pInstance;
};

struct YYRoomTiles {
	int count;
};

struct YYRoomInstances {
	int count;
};

struct RTile
{
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
	unsigned int blend;
	float alpha;
	bool visible;
};

class CBackGM
{
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
	unsigned int blend;
	float alpha;
};

class CViewGM
{
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
	CHashMap<int, CLayer*, 7> m_LayerLookup;
	CHashMap<int, CLayerElementBase*, 7> m_LayerElementLookup;
	CLayerElementBase * m_LastLayerElementLookedUp;
	CHashMap<int, CLayerInstanceElement*, 7> m_LayerInstanceElementLookup;
};

extern CRoom** g_RunRoom;
extern CHash<CInstance>* g_CInstanceHashList;
CInstance* lass_find_CInstance_QUICK(int obj_index);