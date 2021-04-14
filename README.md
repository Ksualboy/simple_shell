# Narita Simple Shell
[![Image from game Narita Boy that helped us to disperse in moments of despair](https://github.com/Ksualboy/simple_shell/blob/main/narita.png?raw=true "Image from game Narita Boy that helped us to disperse in moments of despair")](https://github.com/Ksualboy/simple_shell/blob/main/narita.png?raw=true "Image from game Narita Boy that helped us to disperse in moments of despair")

## Description

Narita Simple Shell also known as hsh is a simple shell created as a evaluation project for Holberton School. This shell is a simple command line prompt that runs the basics commands that are present in the bash shell. 

The shell works like the bash and other basic shells.

The NSS have the exact same output as `sh (/bin/sh)` as well as the exact same error output.
The only difference is when print an error, the name of the program must be equivalent to the `argv[0]` 

The shell was compiled and tested with gcc, compiled this way:
`gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`

## Example of how to launch the shell after compiling:
`./hsh`

Output: prompt: `#cisfun$`
## Syntax

This shell works with commands and arguments (if passed) given by the user throgh input. It handles all the programs that are in the operating system. The syntax is the following:
`command_name [arguments]`
This will execute the program "command_name" with the given arguments.

` ls file -la ` This code will run the program "ls", and it will pass the arguments "file" and "-la" to the program.

This shell has two built-in commands that are "exit" and "env". The first one exits the shell, while the other one prints all the enviroment variables. Feel free to check the man file for more information.

## Builtins
We got two builtin you can use programmed in this shell.

`env` - built-in, that prints all of the current environment variables with their values.

`exit` - built-in, that exits the shell.

## Exiting commands and the shell
You can exit out of a command or process of the shell with Control C. `Ctrl+C` stop and abort the proccess you want to terminate. 

`Ctrl+D` will just exit the shell.

If you want to exit the shell, you can type `exit`.

## Files
` README.md` : Current file, contains all the information about this project and the files in this directory
` AUTHORS`  : Contains the authors of this "beautiful" shell
` flowchart.png` : the flowchart image file
` man_1_simple_shell` : man file of this shell
` memory_handler.c` : C file that contains all memory-related functions.
` narita.h` : Header file, contains all prototypes for funcitons used, as well as libriaries
` narita.png` : Image from Narita Boy Game
` path_handler.c` : C file that contains all the functions related to the handling of the $PATH enviroment variable
` simple_shell.c` : C file that contains the shell main function, together with some external functions that are used in the main
` str_handler.c` : C file that contains all the functions that handle strings and arrays.
## Flowchart
The flowchart we do to make this shell
[![Flowchart of NSS](https://github.com/Ksualboy/simple_shell/blob/main/flowchart.png?raw=true "Flowchart of NSS")](https://github.com/Ksualboy/simple_shell/blob/main/flowchart.png?raw=true "Flowchart of NSS")
## Bugs
Probably some ones but we dont find them
## Authors
Daniel Millan - https://github.com/ksualboy
Ignacio Chitnisky - https://github.com/chitny