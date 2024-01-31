#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#undef NULL

#define EOF (-1)
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

#define NULL 0
#define BUFSIZ 1024
#define OPEN_MAX 20

typedef struct _iobuf {
    int cnt;
    char *ptr;
    char *base;
    int flag;
    int fd;
} CustomFILE;

enum CustomFlags {
    CUSTOM_READ = 01,
    CUSTOM_WRITE = 02,
    CUSTOM_UNBUF = 04,
    CUSTOM_EOF = 010,
    CUSTOM_ERR = 020
};

extern CustomFILE custom_iob[OPEN_MAX];

int custom_fillbuf(CustomFILE *fp);
int custom_fflush(CustomFILE *fp);
int custom_fclose(CustomFILE *fp);

int custom_fseek(CustomFILE *fp, long offset, int origin) {
    if (fp == NULL || fp < custom_iob || fp >= custom_iob + OPEN_MAX)
        return EOF;
    else if (origin != SEEK_SET && origin != SEEK_CUR && origin != SEEK_END)
        return EOF;
    else if ((fp->flag & (CUSTOM_READ | CUSTOM_WRITE)) == 0 || (fp->flag & (CUSTOM_READ | CUSTOM_WRITE)) == CUSTOM_READ + CUSTOM_WRITE)
        return EOF;

    if ((fp->flag & CUSTOM_WRITE) == CUSTOM_WRITE) {
        if (custom_fflush(fp) == EOF)
            return EOF;
    } else {
        if (origin != SEEK_SET || custom_fillbuf(fp) == EOF)
            return EOF;
    }

    off_t new_pos = lseek(fp->fd, offset, origin);

    if (new_pos == -1) {
        fp->flag |= CUSTOM_ERR;
        return EOF;
    } else {
        fp->cnt = 0;
        fp->flag &= ~CUSTOM_EOF;
        return 0;
    }
}

int custom_fillbuf(CustomFILE *fp) {
    if ((fp->flag & (CUSTOM_READ | CUSTOM_EOF | CUSTOM_ERR)) != CUSTOM_READ)
        return EOF;

    int bufsize = (fp->flag & CUSTOM_UNBUF) ? 1 : BUFSIZ;

    if (fp->base == NULL)
        if ((fp->base = (char *)malloc(bufsize)) == NULL)
            return EOF;

    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);

    if (--fp->cnt < 0) {
        if (fp->cnt == -1)
            fp->flag |= CUSTOM_EOF;
        else
            fp->flag |= CUSTOM_ERR;

        fp->cnt = 0;
        return EOF;
    }

    return (unsigned char)*fp->ptr++;
}

int custom_fflush(CustomFILE *fp) {
    if (fp == NULL) {
        int result = 0;
        for (int i = 0; i < OPEN_MAX; i++)
            if ((custom_iob[i].flag & CUSTOM_WRITE) == CUSTOM_WRITE && custom_fflush(&custom_iob[i]) == EOF)
                result = EOF;
        return result;
    } else if (fp < custom_iob || fp >= custom_iob + OPEN_MAX)
        return EOF;
    else if ((fp->flag & (CUSTOM_WRITE | CUSTOM_ERR | CUSTOM_READ)) != CUSTOM_WRITE)
        return EOF;

    int bufsize = (fp->flag & CUSTOM_UNBUF) ? 1 : BUFSIZ;

    if (fp->base == NULL) {
        if ((fp->base = (char *)malloc(bufsize)) == NULL) {
            fp->flag |= CUSTOM_ERR;
            return EOF;
        }
    } else {
        int n = fp->ptr - fp->base;
        if (write(fp->fd, fp->base, n) != n) {
            fp->flag |= CUSTOM_ERR;
            return EOF;
        }
    }

    fp->ptr = fp->base;
    fp->cnt = bufsize;

    return 0;
}

int custom_fclose(CustomFILE *fp) {
    int result = 0;

    if (fp == NULL || fp < custom_iob || fp >= custom_iob + OPEN_MAX)
        return EOF;

    if ((fp->flag & CUSTOM_WRITE) == CUSTOM_WRITE)
        result = custom_fflush(fp);

    if (fp->base != NULL)
        free(fp->base);

    if (close(fp->fd) != 0)
        result = EOF;

    fp->cnt = fp->flag = 0;
    fp->fd = -1;
    fp->ptr = fp->base = NULL;

    return result;
}

CustomFILE custom_iob[OPEN_MAX];

int main() {
    CustomFILE *fp = fopen("sample.txt", "r");

    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    custom_fseek(fp

