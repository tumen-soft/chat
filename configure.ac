#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.71])
AC_INIT([Chat], [0.8.10], [blu.eagle@mail.ru])
AC_CONFIG_SRCDIR([main.cpp])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX

AM_INIT_AUTOMAKE

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([peer.h arpa/inet.h sys/socket.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([memset select socket])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
