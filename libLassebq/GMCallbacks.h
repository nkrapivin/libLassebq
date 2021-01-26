#pragma once

enum class GML_async_event : int {
	ImageLoaded = 60,
	SoundLoaded = 61,
	HTTP = 62,
	Dialog = 63,
	IAP = 66,
	Cloud = 67,
	Networking = 68,
	Steam = 69,
	Social = 70,
	PushNotification = 71,
	SaveAndLoad = 72,
	AudioRecording = 73,
	AudioPlayback = 74,
	System = 75
};

typedef int DSMap;
typedef void(*GML_create_async_event)(DSMap dsmapindex, GML_async_event event_index);
typedef DSMap(*GML_ds_map_create)(int _num, ...);
typedef bool(*GML_ds_map_add_string)(DSMap _map, const char *_pKey, const char *_pValue);
typedef bool(*GML_ds_map_add_real)(DSMap _map, const char *_pKey, double _value);

extern GML_ds_map_create ds_map_create;
extern GML_ds_map_add_real ds_map_add_real;
extern GML_ds_map_add_string ds_map_add_string;
extern GML_create_async_event create_async_event;