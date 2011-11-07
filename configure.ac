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

PKG_CHECK_MODULES(SANCUS, [sancus-core])
PKG_CHECK_MODULES(LUA, [lua5.1])

#
# Options
#

# --enable-debug
#
AC_MSG_CHECKING([wheter to build with debug information])
AC_ARG_ENABLE([debug],
	[AS_HELP_STRING([--enable-debug], [enable debug data generation (def=almost)])],
	[debugit="$enableval"],
	[debugit=almost])
AC_MSG_RESULT([$debugit])

# CFLAGS
if test x"$debugit" = x"yes"; then
	AC_DEFINE([DEBUG],[],[Debug Mode])
	CFLAGS="-g -O0"
elif test x"$debugit" = x"no"; then
	AC_DEFINE([NDEBUG],[],[No-debug Mode])
	CFLAGS="-O3"
fi
CFLAGS="$CFLAGS -Wall -Wextra -pedantic -Winline"

AC_CONFIG_FILES([Makefile
		 doc/Makefile
		 src/cmod/Makefile
		 src/lua/Makefile
		 src/Makefile])
AC_OUTPUT
