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
