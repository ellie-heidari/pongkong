# pongkong

pongkong is licensed under the GNU General Public License version 3 (GPLv3).
You can find the full license in the `LICENSE` file distributed with 
this source code, or at https://www.gnu.org/licenses/gpl-3.0.en.html.

## About 

- This is a simple pong game written in C using the sdl2 library.
- It will evolve over time to add more features.
- It is only built and tested in a Linux system.

## Building 

- Use the Makefile to build the executable: `make TARGET`
- To get a list of all options for TARGET: `make help` 

## Generating compile-command.json[Optional]

using the `bear` tool in the `scan-build` package one can generate 
the compile-commands.json file.

```
pip install scan-build

```

Then do `make clean` before using the `bear` as follows:  

```
bear -- make

```

## Playing

- To run the game(in terminal): ./pongkong.out
- To start the game use the space key. 
- Left Player: Up(W), Down(S)
- Right Player: Up(U), Down(J)

## - TODO:  <19-09-24, Alireza Heidari> -

- Factor draw.c file and break it into smaller modules.
- Add descriptions for the interfaces in header files.

### Disclaimer

This software is provided "as is", without any express or implied warranties. 
In no event shall the authors be liable for any damages arising from the use 
of this software.

