AC_PREREQ([2.69])
AC_INIT([click4ever], [1.0.1])
AM_INIT_AUTOMAKE([foreign subdir-objects])

AC_CONFIG_SRCDIR([src/click4ever.c])
AC_CONFIG_FILES([Makefile])

AC_PROG_CC

AC_CHECK_HEADER([stdlib.h],, [
	AC_MSG_ERROR([Header file stdlib.h not found. Cannot continue without it.])
])

AC_CHECK_LIB([xdo], [xdo_version])
AC_CHECK_HEADER([xdo.h],, [
	AC_MSG_ERROR([Header file xdo.h not found. Cannot continue without it.])
])

AC_CHECK_HEADER([unistd.h],, [
	AC_MSG_ERROR([Header file unistd.h not found. Cannot continue without it.])
])
AC_CHECK_FUNC([usleep],, [
	AC_MSG_ERROR([Function usleep not found. Cannot continue without it.])
])

AC_OUTPUT
