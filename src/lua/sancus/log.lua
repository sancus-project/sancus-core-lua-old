-- This file is part of sancus-core-lua <http://github.com/amery/sancus-core-lua>
--
-- Copyright (c) 2011, Alejandro Mery <amery@geeks.cl>
--

core = require(... .. ".core")

local setmetatable = setmetatable
local assert, select, type = assert, select, type

module(...)

local _mt = {}
function _mt:log(str, ...)
	if select('#', ...) > 0 then
		str = str:format(...)
	end
	core.write(9, self.name, str)
end

_mt.__call = _mt.log
_mt.__index = _mt

function logger(name)
	assert(name == nil or type(name) == 'string')

	return setmetatable({ name = name }, _mt)
end
