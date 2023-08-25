# The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.


## Authors

- [@habibaadam](https://www.github.com/habibaadam)
- [@mukoe2020](https://www.github.com/mukoe2020)


## Requirements

Allowed editors: vi, vim, emacs

All your files should be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=c89

All your files should end with a new line
A README.md file, at the root of the folder of the project is mandatory

Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl

You are allowed to use a maximum of one global variable

No more than 5 functions per file

You are allowed to use the C standard library
The prototypes of all your functions should be included in your header file called monty.h

Don’t forget to push your header file

All your header files should be include guarded.
## Usage/Examples/Compilation

Your code should be compiled this way:

$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty

## Monty Bytecode Files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. 

There can be any number of spaces before or after the opcode and its argument
Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account

## The Monty program

root@a10e0d6b8089:~/monty# cat -e tryingbytecodes/0.monty.

push 1$

push 2$

push 3$

pall

root@a10e0d6b8089:~/monty# ./monty tryingbytecodes/0.m

3

2

1

root@a10e0d6b8089:~/monty#
## Running Tests After Compiling

To run tests, run the following command

```bash
./monty </path/to bytecodefile>
```


## Running With Valgrind

To deploy this project against valgrind to detect memory leaks:

```bash
valgrind ./monty <path/to bytecodefile>
```

