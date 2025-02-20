bin_PROGRAMS = pongkong 
pongkong_SOURCES = main.c draw.c input.c init.c init_objs.c 
# If you have additional modules, list them here.

# Include SDL2 compile flags and link libraries
pongkong_CPPFLAGS = $(SDL2_CFLAGS) -I$(top_srcdir)/include
pongkong_LDADD    = $(SDL2_LIBS)
