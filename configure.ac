AC_INIT(sancus-core-lua, 0.0, amery@geeks.cl)

AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([foreign dist-bzip2 -Wall -Werror])

AC_CONFIG_MACRO_DIR([m4])

AC_DISABLE_STATIC
LT_INIT

#
# Check for programs
#

AC_PROG_CC_C99

#
# Check for libraries
#

PKG_CHECK_MODULES(SANCUS_CORE, [sancus-core])
PKG_CHECK_MODULES(LUA, [lua5.1])

AC_CONFIG_FILES([Makefile
		 doc/Makefile
		 src/cmod/Makefile
		 src/lua/Makefile
		 src/Makefile])
AC_OUTPUT
