# simple_shell

**simple_shell** is a basic UNIX-style command-line interpreter written in C. It replicates some of the core functionalities of the standard Unix shell, including executing built-in and external commands, input/output redirection, and piping.

## Features

- Execute built-in commands (`exit`, `env`)
- Execute external commands in the system’s `$PATH`
- Support for input (`<`) and output (`>`) redirection
- Simple piping (`|`) between commands
- Works in both interactive and non-interactive modes

## Prerequisites

- GCC (GNU Compiler Collection)
- A UNIX-like operating system (Linux, macOS, etc.)

## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/sanzamcmillian/simple_shell.git

2. Navigate into the project directory:

  ```bash
  cd simple_shell

3. Compile the shell:

  ```bash
  gcc -Wall -Werror -Wextra -pedantic *.c -o hsh


## Usage

- To start the shell, run:
  ```bash
  ./hsh

- Then you can start typing commands, for example:

  ```bash
  $ ls -la
  $ echo "Hello, World!"
  $ cat input.txt > output.txt
  $ grep "word" file.txt | sort

- To exit the shell, use:

  ```bash
  exit

## Built-in Commands
 - `exit`: Exit the shell
 - `env`: Print environment variables


## File Structure

 - `main.c`: Entry point, main loop
 - `builtin.c`: Built-in command implementations
 - `getline.c`: Custome `getline` implementation
 - `init.c`: initialization logic
 - `non_inter.c`: Non-interactive mode handler
 - `util.c`: Helper and utility functions
 - `shell.h`: Header file with funtction declarations and macros

## Author

Sanele Skhosana

## License

This project is open-source and available under MIT License.