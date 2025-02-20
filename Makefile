#/* 
# * This file is part of pongkong. 
# * 
# * pongkong is free software: you can redistribute it and/or modify
# * it under the terms of the GNU General Public License as published by
# * the Free Software Foundation, either version 3 of the License, or
# * (at your option) any later version.
# * 
# * pongkong is distributed in the hope that it will be useful,
# * but WITHOUT ANY WARRANTY; without even the implied warranty of
# * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# * GNU General Public License for more details.
# * 
# * You should have received a copy of the GNU General Public License
# * along with pongkong.  If not, see <http://www.gnu.org/licenses/>.
# */

#------------------------------------------------------------------------------
## Use: make [TARGET] 
## Build Targets:
##      all: compiles all source files without linking them.
##      clean: removes all generated files.
##      variables: Print variables.
##      help: shows all TARGET options.
#------------------------------------------------------------------------------

# set the  compiler variable
CC = gcc 

# set the compiler flags var
#
# -fsanitize=address is used to detect leaks
#  pkg-config sdl2 --libs --cflags 

CFLAGS = `pkg-config sdl2 --libs --cflags` -g -O0 --std=c99 -Wall -Werror

# add source files here
SRCS = ./src/main.c ./src/init.c ./src/init_objs.c ./src/input.c ./src/draw.c

# generate name of object files
OBJS = $(SRCS:.c=.o)

# name of executable
EXEC = pongkong

# default recipe
.PHONY : all
all: $(EXEC)

# recipe for building the final exe
$(EXEC): $(OBJS)  
	$(CC) $(OBJS) $(CFLAGS) -o ./build/$@
	mv ./src/*.o ./build/artifacts/

# variables: Print variables.
.PHONY: variables
variables:
	@echo SOURCE_FILES: $(SRCS)
	@echo OBJ_FILES: $(OBJS)

# clean the workspace
.PHONY: clean
clean: 
	rm -f ./build/artifacts/*.o
	rm -f compile_commands.json 
	rm -f ./build/$(EXEC)

.PHONY: help
help: Makefile
		@sed -n 's/^##//p' $<

