#!/bin/sh

list() {
	find "$@" -name '*.lua' | sort -V | tr '\n' ' ' | fmt -w60 | tr '\n' '|' |
		sed -e 's,|$,,' -e 's,|, \\\n\t,g'
}

cd "${0%/*}"
cat <<EOT | tee Makefile.am

nobase_dist_luadata_DATA = \\
	$(list sancus)

luadatadir = @datadir@/lua/5.1
EOT
