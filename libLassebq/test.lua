-- Quicksave/load for KZ.

local obj_libLassebq = { }
local player_hurt = { }
local generate_hash = { }

function getDateTime() -- a helper to get formatted datetime from GM
	return GML_date_datetime_string(GML_date_current_datetime())
end

function obj_libLassebq.PressF5(_pSelf, _pOther)
	GML_game_save("temp00")
	GML_window_set_caption("Saved, time: " .. getDateTime())
	local x = GMLua_inst(_pSelf.id)
end

function obj_libLassebq.PressF6(_pSelf, _pOther)
	GML_game_load("temp00")
	GML_window_set_caption("Loaded, time: " .. getDateTime())
end

return { obj_libLassebq=obj_libLassebq }