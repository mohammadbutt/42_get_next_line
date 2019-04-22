# Project status - Finished Code - Readme in progress
# Get_Next_Line
This project intends to mimic the functionality of getline, which reads the line from a source then outputs it. The purpose of thie project was to understand how memory works.

# Features
This program reads multiple different files and keeps track of where each file finished reading when a new line occurs.

RETURN VALUES:
+ If a file is not read successfully or file name is invalid, then the program returns a valus of -1.
+ If a file is read successfully then 1 is returned.
+ If the program is done reading a file and the last line is read again then the program will return 0.
+ Open will not assign a file descriptor of 0 (Standard input), 1(Standard output), and 2(Standard error).

Flag has the following access modes: O_RDONLY, O_WRONLY, O_RDWR.

O_RDONLY stands for read only. O_WRONLY stands for write only. O_RDWR stands for read/write.

To compile, include libft library as shown below:
```
gcc get_next_line.c -I. ./libft/libft.a
```
Wall Wextra Werror flag can be used to compile, which is helpful in raising warnings if a variable is left uninitalized:
```
gcc -Wall -Wextra -Werror get_next_line.c -I. ./libft/libft.a
```
# Return Value of get_next_line
get_next_line returns -1, 0, or 1.
+ Returns 1 if a line has been read successfuly.
+ Returns 0 if the program is finished reading the file. This will occur when the last line is read more than once.
+ Returns -1 if the program was unable to read the file.

# Memory allocation
Memory is allocated to manipulate the string. The memory allocation takes place at the heap level several times when following functions are called: `ft_strjoin()`, `ft_strsub()`, `ft_strdup()` because all 3 of these functions use `malloc()`. If memory is allocated then once the process is complete, memory has to be deallocated using `free()`. However, freeing memory is a rather complexed. Valgrind is a tool that can be used to check for memory leaks.

# Checking memory leaks using Valgrind
First Valgrind would have be installed if it is already not installed on a system. Following commands installs Valgrind on linux:
```
sudo apt-get install valgrind
```
Once Valgrind has been installed, following commands can be used to compile a program and then run valgrind on `./a.out` to check for memory leaks:
```
gcc -Wall -Wextra -Werror get_next_line.c -I. ./libft/libft.a
valgrind ./a.out
```
There are other ways to see memory leaks and a log of memory leaks can be stored in a file, but the above commands will just show the memory leaks on the screen without any additionals steps.
