# Get_Next_Line
This project intends to mimic the functionality of getline, which reads the line from a source then outputs it. The purpose of this project was to understand how memory works.

There are some difference between getline and get_next_line. getline(3) function uses fopen(3) because it gives`FILE* stream`. However, get_next_line uses open(2) because it gives a file descriptor, and the project requires file descriptor.

# Features
This program reads multiple different files and keeps track of where each file finished reading when a new line occurs.

# Challenges
Reading a file and displaying the output is not too hard. Let's suppose we have file that looks as shown below:
```
AB
CD
EF
```
<table>
  <tr>
    <td>A</td>
    <td>B</td>
    <td>\n</td>
    <td>C</td>
    <td>D</td>
    <td>\n</td>
    <td>E</td>
    <td>F</td>
    <td>\n</td>
  </tr>
# Return Values of get_next_line
get_next_line returns -1, 0, or 1.
+ Returns 1 if a line has been read successfuly.
+ Returns 0 if the program is finished reading the file. This will occur when the last line is read more than once.
+ Returns -1 if the program was unable to read the file.

# Installation - Setting up environemnt
To compile, open `libft` folder and then type the following commands:
```
make fclean
make re
make clean
```
`make fclean` will remove the libft.a static library. `make re` wil recompile the library to create .o and static library. `make clean` will remove the .o files leaving the folder with .c and libft.a static library. This is important because operating systems have different architecture, so the static library has to be created again.

# Running the program

There are three different main files that can be used one at a time to test the program. `main_1file.c` can be replaced with `main_2files.c` to run the program with 2 files.

```
gcc get_next_line.c main_1file.c -I. ./libft/libft.a
./a.out
```
To run the program with command line interface, where the user can enter the file name, use the following commands.

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
Why is it important to check for memory leaks?

Memory is allocated to manipulate the string. Memory allocation takes place at the heap level several times when following functions are called: `ft_strjoin()`, `ft_strsub()`, `ft_strdup()`, and `strjoin_swap()` because all 4 of these functions use `malloc()`. If memory is allocated then once the process is completed, memory has to be deallocated using `free()`, so system knows that memory is free to be used for something else.

# Examples.
+ Program reads from two files.
<img src= "https://github.com/mohammadbutt/42_get_next_line/blob/master/snapshots/output_2files.png">

+ Program running through command line interface.
<img src= "https://github.com/mohammadbutt/42_get_next_line/blob/master/snapshots/output_cli.png">

Above are the snapshots of the program when it reads from valid files. First four lines return 1, containing the text it read from the file, but the last line returns 0 because the program finised reading the file.

+ Program returns -1 because the file is invalid.
<img src="https://github.com/mohammadbutt/42_get_next_line/blob/master/snapshots/output_invalid.png">
