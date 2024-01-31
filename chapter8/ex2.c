/* fopen and _fillbuf with fields instead of explicit bit operations. */

#include <stdlib.h>
#define BUFSIZE 1024
#include <fcntl.h>
#include <unistd.h>
#define PERMS 0666   //permission for everyone

#define EOF (-1)  // EOF comes under stadio.h, we have not used it here
#define OPEN_MAX 20

typedef struct _iobuf {
	int cnt;
	char *ptr;
	char *base;
	int read;
	int write;
	int unbuf;
	int eof;
	int err;
	int fd;
} FILE;
FILE _iob[OPEN_MAX];

#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

FILE *fopen(char *name, char *mode);
int _fillbuf(FILE *);


#define getc(p) (--(p)->cnt >= 0 ? (unsigned char)*(p)->ptr++ : _fillbuf(p))
#define putc(x, p) write(p->fd, &x, 1);
#define putchar(x) putc(x, stdout)





FILE *fopen(char *name, char *mode)
{
	int fd;
	FILE *fp;

	if (*mode != 'r' && *mode != 'w' && *mode != 'a')  
		return NULL;                    // invalid mode
		
	for (fp = _iob; fp < _iob + OPEN_MAX; fp++) 
		if (!fp->read && !fp->write)    // found free slot 
			break;
	if (fp >= _iob + OPEN_MAX)             // no free slots
		return NULL;
		
	if (*mode == 'w')
		fd = creat(name, PERMS);
		
	else if (*mode == 'a') 
	{
		if ((fd = open(name, O_WRONLY, 0)) == -1)
			fd = creat(name, PERMS);
		lseek(fd, 0L, 2);
	} 
	else 
		fd = open(name, O_RDONLY, 0);
	if (fd == -1)
		return NULL;
	fp->fd = fd;
	fp->cnt = 0;
	fp->base = NULL;
	fp->read = (*mode == 'r');
	fp->write = !fp->read;
	fp->unbuf = fp->eof = fp->err = 0;
	return fp;
}




int _fillbuf(FILE *fp)    //Fills the buffer
{
	int bufsize;

	if (!fp->read || fp->eof || fp->err)
		return EOF;
	bufsize = fp->unbuf ? 1 : BUFSIZE;   // if no space in buffer
	if (fp->base == NULL)
		if ((fp->base = (char *)malloc(bufsize)) == NULL)
			return EOF;
	fp->ptr = fp->base;
	fp->cnt = read(fp->fd, fp->ptr, bufsize);
	if (--fp->cnt < 0) 
	{
		if (fp->cnt == -1)
			fp->eof = 1;
		if (fp->cnt == -2)
			fp->err = 1;
		fp->cnt = 0;
		return EOF;
	}
	return (unsigned char)*fp->ptr++;
}



FILE _iob[OPEN_MAX] = { { 0, (char *)0, (char *)0, 1, 0, 0, 0, 0, 0 },   //stdin
			{ 0, (char *)0, (char *)0, 0, 1, 0, 0, 0, 1 },    //stdout
			{ 0, (char *)0, (char *)0, 0, 1, 1, 0, 0, 2 } };  //stderr


int main(int argc, char *argv[])
{
	FILE *fp;
	int c;

	while (--argc > 0)
		if ((fp = fopen(*++argv, "r")) == NULL)
			return 1;
		else
			while ((c = getc(fp)) != EOF)
				putchar(c);
	return 0;
}
