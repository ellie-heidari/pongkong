# pongkong

pongkong is licensed under the GNU General Public License version 3 (GPLv3).
You can find the full license in the `LICENSE` file distributed with 
this source code, or at https://www.gnu.org/licenses/gpl-3.0.en.html.

## About 

This is a simple pong game written in C using the sdl2 library.
It will evolve over time to add more features.
It is only built and tested in a Linux system.

## Building 

To build the game inside the build direcotry you can do:

```
cmake ..
make
```

## Generating compile-command.json[Optional]

```bash
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=YES ..
```

## Playing

Currently following holds:

- To run the game: `./pongkong.out`
- To start the game use the space key. 
- Left Player: r >> Up, h >> Down
- Right Player: u >> Up, e >> Down

## - TODO:  <19-09-24, Alireza Heidari> -

- Factor draw.c file and break it into smaller modules.
- Add descriptions for the interfaces in header files.

### Disclaimer

This software is provided "as is", without any express or implied warranties. 
In no event shall the authors be liable for any damages arising from the use 
of this software.
