*This activity has been created as part of the 42 curriculum by aalbess.*

## Description

get_next_line is a C function that reads from a file descriptor one line at a time.  
Each call returns the next line until the end of file is reached.  

The goal is to practice  
- static variables  
- file descriptor handling  
- dynamic memory allocation  
- buffer based input  

The function must work with files and standard input.  
It must support multiple file descriptors at the same time.  

## Instructions

### Compilation

Compile with BUFFER_SIZE defined at compile time  

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c

### Files

- get_next_line.c  
- get_next_line_utils.c  
- get_next_line.h  

### Prototype

char *get_next_line(int fd)

### Execution

Call the function in a loop.  
Free the returned line after each call.  

Example  

int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)))
{
    write(1, line, ft_strlen(line));
    free(line);
}
close(fd);

## Algorithm Explanation

The algorithm relies on data persistence between function calls.  

A static variable stores leftover data that was read but not yet returned.  
This prevents data loss between calls.  

Steps  

- Read from the file descriptor using read  
- Append the read buffer to the static storage  
- Search the storage for a newline character  
- If a newline is found  
  - Extract the line up to and including the newline  
  - Store the remaining data for the next call  
- If no newline is found  
  - Continue reading until one appears or EOF is reached  

Justification  

- read works on fixed size buffers, not lines  
- BUFFER_SIZE limits how much data is read at once  
- Static storage allows continuation across calls  
- This method supports very long lines  
- This method works with multiple file descriptors  

Memory is allocated only when needed.  
All allocated memory is freed either internally or by the caller.  

## Edge Cases

- Empty file  
- File without newline at the end  
- Very long lines  
- BUFFER_SIZE equal to 1  
- Large BUFFER_SIZE values  
- Multiple file descriptors  
- Reading from stdin  

## Resources

- man 2 read  
- man 3 malloc  
- man 3 free  
- youtube 
- 42 get_next_line subject  

AI usage  

AI was used to  
- review the README structure  
- check compliance with 42 requirements  
- improve clarity of explanations  
