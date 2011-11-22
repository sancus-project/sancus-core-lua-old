-- This file is part of sancus-core-lua <http://github.com/amery/sancus-core-lua>
--
-- Copyright (c) 2011, Alejandro Mery <amery@geeks.cl>
--

core = require(... .. ".core")

local setmetatable = setmetatable
local assert, type = assert, type

module(...)

local _mt = {
	__index = {},
}

function _mt.__index:log(str)
	core.write(9, self.name, str)
end

function logger(name)
	assert(name == nil or type(name) == 'string')

	return setmetatable({ name = name }, _mt)
end
