/*
 * This file is part of sancus-core-lua <http://github.com/amery/sancus-core-lua>
 *
 * Copyright (c) 2011, Alejandro Mery <amery@geeks.cl>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of the author nor the names of its contributors may
 *     be used to endorse or promote products derived from this software
 *     without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdbool.h>

#define LUA_LIB
#include "lua.h"
#include "lauxlib.h"

#define LUA_MOD_NAME	"sancus.tcp.core"
#define MT_SERVER	"sancus.tcp.server"

#include <ev.h>

#include <sancus_list.h>
#include <sancus_server.h>

#include <sancus_common.h>
#include <sancus_log.h>

#define LOG_PREFIX	LUA_MOD_NAME

#define checkserver(L)	luaL_checkudata(L, 1, MT_SERVER)
/*
 */
static int l_create_server(lua_State *L)
{
	struct sancus_tcp_server *server;

	server = lua_newuserdata(L, sizeof(*server));
	sancus_tcp_server_init(server);

	luaL_getmetatable(L, MT_SERVER);
	lua_setmetatable(L, -2);

	debugf("server=%p", (void*)server);
	return 1;
}

static int l_destroy_server(lua_State *L)
{
	struct sancus_tcp_server *server = checkserver(L);

	if (server) {
		debugf("server=%p", (void*)server);
	}

	return 0;
}

/*
 */
static const struct luaL_Reg core[] = {
	{"create_server", l_create_server},
	{NULL, NULL} /* sentinel */
};

static const struct luaL_Reg server_m[] = {
	{"__gc", l_destroy_server},
	{NULL, NULL} /* sentinel */
};

int luaopen_sancus_tcp_core(lua_State *L)
{
	luaL_newmetatable(L, MT_SERVER);
	lua_pushvalue(L, -1);
	lua_setfield(L, -2, "__index");
	luaL_register(L, NULL, server_m);

	luaL_register(L, LUA_MOD_NAME, core);
	return 1;
}
