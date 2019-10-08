# 0x15. C - Simple Shell <br />

Year 1 - Low-level programming & Algorithm ― Linux and Unix system programming

Team:  [Cynthia Dominguez](https://github.com/cynergist), [Brendan Eliason](https://github.com/zinczar)

## Compilation <br />
Our shell is compiled this way: <br />
`gcc -Wall -Werror -Wextra -pedantic simple_shell.c simple_helpers.c pathfinder.c built_ins.c -o sh` <br />
`./sh` <br />
<br />

## Makefile <br />
You can also run the Makefile: <br />
`make` <br />
`./simple_shell` <br />
<br />

## Commands <br />
At minimum, this shell handles the following commands to display file contents on the command line: <br />
`cat`: Concatenates the file and gives output on standard output. <br />
`less`: View files instead of opening the file. Allows backward and forward movement. <br />
`more`: Page through text one screenful at a time. <br />
<br />
This shell handles the following file and directory manipulation commands: <br />
`mkdir`: Creates a directory and accepts directory name as next parameter. <br />
`rm` and `rm -r`: Used to delete files and directories. <br />
`touch`: Creates a file or updates a file. <br />
<br />
And the following basic command line navigation commands: <br />
`ls`: Displays list of all files and folders in the current directory. <br />
`cd`: Changes the directory. <br />
`du`: Shows disk usage. <br />
`pwd`: Shows the present working directory. <br />
`man` + `cmd`: Shows the manual entry for any given command. <br />
`exit`: Quits the simple_shell program. <br />
# Resources <br />

[Unix shell wiki](https://en.wikipedia.org/wiki/Unix_shell) <br />
[Thompson shell wiki](https://en.wikipedia.org/wiki/Thompson_shell) <br />
[Ken Thompson wiki](https://en.wikipedia.org/wiki/Ken_Thompson) <br />
[Everything you need to know to start coding your own shell (Holberton Intranet)](https://intranet.hbtn.io/concepts/64) <br />
[Understanding fork() system call for new process creation](https://youtu.be/PwxTbksJ2fo) <br />
[Linux fork() Introduction](https://youtu.be/9seb8hddeK4) <br />
[Tutorial - Write a Shell in C (Stephen Brennan)](https://brennan.io/2015/01/16/write-a-shell-in-c/) <br />
[The getline() Function](https://c-for-dummies.com/blog/?p=1112) <br />
[Input/Output on Streams](http://kirste.userpage.fu-berlin.de/chemnet/use/info/libc/libc_7.html) <br />
[Writing a Unix Shell (Cracking The Code) Part I](https://indradhanush.github.io/blog/writing-a-unix-shell-part-1/) <br />
[Writing a Unix Shell (Cracking The Code) Part II](https://indradhanush.github.io/blog/writing-a-unix-shell-part-2/) <br />
[Making your own Linux Shell in C (GeeksForGeeks)](https://www.geeksforgeeks.org/making-linux-shell-c/) <br />
[C library function - strtok()](https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm) <br />


# Learning Objectives <br />
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

## General <br />
- Who designed and implemented the original Unix operating system
- Who wrote the first version of the UNIX shell
- Who invented the B programming language (the direct predecessor to the C programming language)
- Who is Ken Thompson
- How does a shell work
- What is a pid and a ppid
- How to manipulate the environment of the current process
- What is the difference between a function and a system call
- How to create processes
- What are the three prototypes of main
- How does the shell use the PATH to find the programs
- How to execute another program with the execve system call
- How to suspend the execution of a process until one of its children terminates
- What is EOF / “end-of-file”?

# Requirements <br />

## General <br />

- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 14.04 LTS
- Your C programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to (why?)

# More Info <br />

## Output <br />
- Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
- The only difference is when you print an error, the name of the program must be equivalent to your argv[0] (See below)

Example of error with sh: <br />

Example of same error with our program hsh: <br />

## List of allowed functions and system calls <br />
List of allowed functions and system calls
- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- _exit (man 2 _exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (__xstat) (man 2 stat)
- lstat (__lxstat) (man 2 lstat)
- fstat (__fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)

## Task Instructions <br />
0. README, man, AUTHORS mandatory. // A README and man page is written for our shell. AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository.
- Repo: GitHub repository: simple_shell
- File: README.md, man_1_simple_shell, AUTHORS

1. Betty would be proud. // Write beautiful code that passes the Betty (linter) checks.

- Repo: GitHub repository: simple_shell

2. Simple shell 0.1 mandatory. // Write a UNIX command line interpreter.

- Usage: simple_shell

Your Shell should:

- Display a prompt and wait for the user to type a command. A command line always ends with a new line.
- The prompt is displayed again each time a command has been executed.
- The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
- The command lines are made only of one word. No arguments will be passed to programs.
- If an executable cannot be found, print an error message and display the prompt again.
- Handle errors.
- You have to handle the “end of file” condition (Ctrl+D)

You don’t have to:

- use the PATH
- implement built-ins
- handle special characters : ", ', `, \, *, &, #
- be able to move the cursor
- handle commands with arguments

- Repo: GitHub repository: simple_shell

3. Simple shell 0.2 mandatory // Simple shell 0.1 +

- Handle command lines with arguments

- Repo: GitHub repository: simple_shell

4. Simple shell 0.3 mandatory
Simple shell 0.2 +

- Handle the PATH
- Repo: GitHub repository: simple_shell

5. Simple shell 0.4 mandatory
Simple shell 0.3 +

- Implement the exit built-in, that exits the shell
- Usage: exit
- You don’t have to handle any argument to the built-in exit
- Repo: GitHub repository: simple_shell

6. Simple shell 1.0 mandatory
Simple shell 0.4 +

- Implement the env built-in, that prints the current environment

- Repo: GitHub repository: simple_shell

7. What happens when you type ls -l in the shell mandatory
[Blog post](https://.........)
