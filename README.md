# So_long

A minigame done with the minilibx. The goal is to get every collectible on the map and then quit the map by going on the exit door.


## How to get it work

Clone the repository and go to it's root folder, you will need any mlx required depedencies to make the game run such as X11

```bash
  $ cd mlx_linux
```
```bash
  $ chmod 777 ./configure
```
```bash
  $ cd ..
```
```bash
  $ make
```
```bash
  ./so_long <name_of_map>
```
Playable maps and their names are located into /maps folder.    

 You can change the size of the maps and add different elements such as more collectibles or more walls, as long as it fits the conditions of the map playability.  

## Movements
Keys to move your character

[W] (up)  
[A] (left)  
[S] (down)  
[D] (right)  

You can quit the game by pressing the [ESC] key

## Documentation 
by Harm Smits

[MinilibX](https://harm-smits.github.io/42docs/libs/minilibx)

## Making it run on WSL (Windows Subsystem for Linux)

As you need X11 to make the game run, you'll need some packages to install.

first
```bash
  $ sudo apt update
  $ sudo apt upgrade
```
Then
```bash
  $ sudo apt install libxext-dev
  $ sudo apt install libbsd-dev
```
