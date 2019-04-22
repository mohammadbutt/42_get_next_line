# Project status - Finished Code - Readme in progress
# Get_Next_Line
This project intends to mimic the functionality of getline, which reads the line from a source then outputs it. The purpose of thie project was to understand how memory works.

# Features
This program reads multiple different files and keeps track of where each file finished reading when a new line occurs.

# Return Value of get_next_line
get_next_line returns -1, 0, or 1.
+ Returns 1 if a line has been read successfuly.
+ Returns 0 if the program is finished reading the file. This will occur when the last line is read more than once.
+ Returns -1 if the program was unable to read the file.

/* Delete Below
RETURN VALUES:
+ If a file is not read successfully or file name is invalid, then the program returns a valus of -1.
+ If a file is read successfully then 1 is returned.
+ If the program is done reading a file and the last line is read again then the program will return 0.
+ Open will not assign a file descriptor of 0 (Standard input), 1(Standard output), and 2(Standard error).

Flag has the following access modes: O_RDONLY, O_WRONLY, O_RDWR.

O_RDONLY stands for read only. O_WRONLY stands for write only. O_RDWR stands for read/write.

*/ Delete above


# Installation - Setting up environemnt
To compile, open `libft` folder and then type the following commands: include libft library as shown below:
```
make fclean
make re
make clean
```
`make fclean` will remove the libft.a static library. `make re` wil recompile the library to create .o and static library. `make clean` will remove the .o files leaving the folder with .c and libft.a static file. This is important because operating systems have different architecture, so the static library has to be created again.

# Running the program

There are three different main files that can be used one at a time to test the program. `main_1file.c` can be replaced with `main_2files.c` to run the program with 2 files.

```
gcc get_next_line.c main_1file.c -I. ./libft/libft.a
./a.out
```
To run the program with command line interface, where the user can enter the file name on the command line, use the following commands.

```
gcc get_next_line.c main_cli.c -I. ./libft/libft.a
./a.out "file_name.txt"
```
# Optional Installation - Valgrind
To check for memory leaks, valgrind can be installed if it is already not installed on the system. Following commands install valgrind on linux and runs the program to check for memory leaks:
```
sudo apt-get install valgrind
gcc get_next_line.c main_2files.c -I. ./libft/libft.a
valgrind ./a.out
```
# Why it is important to check for memory leaks?
Memory is allocated to manipulate the string. Memory allocation takes place at the heap level several times when following functions are called: `ft_strjoin()`, `ft_strsub()`, `ft_strdup()`, and strjoin_swap() because all 4 of these functions use `malloc()`. If memory is allocated then once the process is completed, memory has to be deallocated using `free()`, so system knows that memory is free to be used for something else.
