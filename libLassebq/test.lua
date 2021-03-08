-- Quicksave/load for KZ.

local obj_libLassebq = { }
local player_hurt = { }

function getDateTime() -- a helper to get formatted datetime from GM
	return GML_date_datetime_string(GML_date_current_datetime())
end

function obj_libLassebq.PressF5(_pSelf, _pOther)
	GML_game_save("temp00")
	GML_window_set_caption("Saved, time: " .. getDateTime())
end

function obj_libLassebq.PressF6(_pSelf, _pOther)
	GML_game_load("temp00")
	GML_window_set_caption("Loaded, time: " .. getDateTime())
end

--[[
	hooker routine:
	if Before defined then
		r = call Before
		if Before returned
			return r
		else
			r = call Original script
			if After defined
				r = call After and provide Original r
				return r
			end
		end
	end

	so by returning from Before, we prevent the original script from executing!
]]--

function player_hurt.Before(_pSelf, _pOther, _args)
	--[[ You can't die, you can't die, you can't die, you can't die, you can't die
	     that would suck, right? sometimes you just *have* to die, your life's over
	     but no, you are still alive, watching how your close relatives and friends die
	     pretty painful, ain't it?
	     welp, I don't have any IRL friends, so not really a problem for me.
	     UHHHHHHHHHHHHHHHH NEVERMIND I'VE GONE TOO FAR.
	     oh, btw, `_args` is an array with the arguments. ]]--
	return 0 -- ????????
end

function player_hurt.After(_pSelf, _pOther, _args, _ret)
	return _ret -- this won't be executed anyway, you don't even need to return
end

return { obj_libLassebq=obj_libLassebq, player_hurt=player_hurt }