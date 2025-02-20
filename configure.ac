AC_INIT([pongkong], [1.0], [alireza.heidari@posteo.net])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_PROG_CC([gcc])
AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADERS([config.h])

# Check for SDL2 using pkg-config  
PKG_CHECK_MODULES([SDL2], [sdl2 >= 2.0], [have_sdl=yes], [have_sdl=no])
if test "$have_sdl" != yes; then
  AC_MSG_ERROR([SDL2 not found. Make sure SDL2 is installed and pkg-config is working.])
fi

# Substitute SDL2 flags  
AC_SUBST(SDL2_CFLAGS)
AC_SUBST(SDL2_LIBS)

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT
