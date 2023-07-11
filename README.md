# 42get_next_line

This homework submission (made in July 2023) is heavily borrowed from the followig sources:-

https://github.com/jdecorte-be/42-Get-next-line.git \n
https://github.com/constantinWho/minishell/blob/main/lib/libft/src/get_next_line.c

I also rely heavily on francinette for testing.

For me, the following were the particularly bumpy points in my journey.

(1) One needs to have a background understanding of the open() and close() functions, as well as file descriptors.

To put it shortly, under the Linux OS, fd 0 is standard input, fd 1 is standard output, and fd 3 is standard error.

When you use the open() function to open a file, the fd assigned to the file will usually be fd 3.

(2) Using calloc is a good idea.  It saves me from expressly checking whether malloc fails each time, and also saves me from having to add an extra null character to the end of the string each time.

(3) Static variables need not be initiated in the funciton where it is called.  In fact it realy should not be initiated, as to iniate it each time it is called would be to defeat the point of a static variable altogether.

(4) The hardest part for me (and I only got it after flailing for days and peeking at someone else's homework for the answer) was the memory management for the read_file function.  The key insight is that the situation is radically different for the first time you read into the buffer and subsequent times.  (1) The first time there would be no need to append the bytes read after anything.  (2) All the subsequent times, you need to so append.

The solution in this code is to collape everything to sitaution (2).  For the first pass, you artificially initiate an empty string, and then immedidately append and free it to the bytes that are read.

(5) Tiny small trick: it is easier to use the equivalent numbers to the ASCII characters for '\0' (i.e. 0) and '\n' (i.e. 10) than typing  '\0' and '\n' each time (see the table at man ASCII).  There is a sacrifice in readability, but I think it is worth it.
