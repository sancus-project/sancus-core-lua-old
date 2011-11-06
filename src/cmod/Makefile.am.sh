#!/bin/sh

list() {
	ls -1 "$@" | sort -V | tr '\n' ' ' | fmt -w60 | tr '\n' '|' |
		sed -e 's,|$,,' -e 's,|, \\\n\t,g'
}

cd "${0%/*}"
cat <<EOT | tee Makefile.am
AM_LDFLAGS = \$(LUA_LIBS) -module -avoid-version
AM_CFLAGS = \$(LUA_CFLAGS)

nobase_cmod_LTLIBRARIES = sancus.la

sancus_la_SOURCES = \\
	$(list *.c)

cmoddir = @libdir@/lua/5.1
EOT
