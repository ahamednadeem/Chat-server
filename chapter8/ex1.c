/*  Rewrite the program cat from Chapter 7 using read, write, open and close
instead of their standard library equivalents. */
#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define STDIN 0   //functions descriptors
#define STDOUT 1
#define STDERR 2

void filecopy(int ifd, int ofd)   // copy file ifd to ofd 
{
    int n;
    char buf[BUFSIZ];   

    while ((n = read(ifd, buf, BUFSIZ)) > 0)  // the input from the file or stdin is copied to character array buf
        if (write(ofd, buf, n) != n)          // data from the character array is copied to the stdout
            printf("Write Error\n");
}

int main(int argc, char *argv[])   // cat: concatenate files - read/write/open/close 
{
    int fd;
    if (argc == 1) 
        filecopy(STDIN, STDOUT);
    else
        while (--argc > 0)
            if ((fd = open(*++argv, O_RDONLY, 0)) == -1)   // open returns -1 when there is an error in opening the file
                printf("cant open %s\n", *argv); 
            else 
            {
                filecopy(fd, STDOUT);
                close(fd);
            }
    return 0;
}
