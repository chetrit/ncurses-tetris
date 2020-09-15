# ncurses-tetris

> This project is basically the game tetris, recoded in C with ncurses library, It includes a debug mode that allows you to customize your tetriminos and start to a special state of the game (levelwise) ...

# Installation, compilation and utilization
#### Installation
After cloning the repository, you have nothing else to install since it is in C and without external libraries (ncurses is preinstalled on unix distributions) !
    
#### Compilation
Compilation of binary using Makefile:
```
make
```

#### Utilization
Launch the normal game with no options:
```
./tetris
```
To launch the game with options and / or debug mode and to display the rules, all will be in the usage:
```
./tetris --help
```

All tetriminos are in ``tetriminos`` folder, and you can add your own ones and delete the ones you don't like, wich makes it a completely customizable version of tetris !
