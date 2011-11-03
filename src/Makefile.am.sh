#!/bin/sh

list() {
	ls -1 "$@" | sort -V | tr '\n' ' ' | fmt -w60 | tr '\n' '|' |
		sed -e 's,|$,,' -e 's,|, \\\n\t,g'
}

cd "${0%/*}"
cat <<EOT | tee Makefile.am
AM_LDFLAGS = \$(LUA_LIBS) -module -avoid-version
AM_CFLAGS = \$(LUA_CFLAGS)

lib_LTLIBRARIES = core.la

core_la_SOURCES = \\
	$(list *.c)

libdir = @libdir@/lua/5.1/sancus
EOT
