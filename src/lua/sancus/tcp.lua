-- This file is part of sancus-core-lua <http://github.com/amery/sancus-core-lua>
--
-- Copyright (c) 2011, Alejandro Mery <amery@geeks.cl>
--

local setmetatable = setmetatable

module(...)

local index = {}

local tcp_mt = {
	__index = index,
	}

function index:listen(port)
end

function create_server(t)
	return setmetatable({}, tcp_mt)
end
