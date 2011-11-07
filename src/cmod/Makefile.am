AM_LDFLAGS = $(SANCUS_LIBS) $(LUA_LIBS) -module -avoid-version
AM_CFLAGS = $(SANCUS_CFLAGS) $(LUA_CFLAGS)

nobase_cmod_LTLIBRARIES = sancus.la

sancus_la_SOURCES = \
	sancus.c

cmoddir = @libdir@/lua/5.1
