#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <err.h>

#define USAGE       "usage: %s [file] [file]"
#define BUFFER_SIZE 256

int readline(FILE *stream, char **buffer_ptr, size_t *size_ptr)
{
    char *buffer = *buffer_ptr;
    size_t size = *size_ptr;
    size_t len = 0;
    do {
       if (len == size - 1) {
            size += BUFFER_SIZE;
            *size_ptr = size;
            // TODO: check realloc return value
            buffer = realloc(buffer, size);
            *buffer_ptr = buffer;
       }

       int read_char = getc(stream);
       if (read_char == EOF) {
            return (len);
       }
       *(buffer + len) = read_char;

       ++len;
    } while (*(buffer + len - 1) != '\n');
    
    return (len);
}

int main(int argc, char *argv[])
{
    char *buffer_a = malloc(BUFFER_SIZE);
    char *buffer_b = malloc(BUFFER_SIZE);
    size_t buffer_size_a = BUFFER_SIZE;
    size_t buffer_size_b = BUFFER_SIZE;

    if (!buffer_a || !buffer_b) {
        errx(1, "malloc");
    }

    FILE *fd_a, *fd_b;

    switch (argc) {
        case 1:
            fd_a = fd_b = stdin;
            break;
        case 2:
            fd_a = fopen(argv[1], "r");
            fd_b = stdin;
            break;
        case 3:
            fd_a = fopen(argv[1], "r");
            fd_b = fopen(argv[2], "r");
            break;
        default:
            errx(1, USAGE, argv[0]);
    }

    size_t read_a, read_b;

    while (1) {
        read_a = readline(fd_a, &buffer_a, &buffer_size_a);
        read_b = readline(fd_b, &buffer_b, &buffer_size_b);
        
        if (!read_a && !read_b) {
            break;
        }

        for (size_t i = 0; i < read_a; ++i) {
            printf("%c", buffer_a[i]);
        }
        for (size_t i = 0; i < read_b; ++i) {
            printf("%c", buffer_b[i]);
        }
        for (size_t i = 0; i < (read_a > read_b ? read_a : read_b); ++i) {
            if (i < read_a && i < read_b) {
                printf("%c", buffer_a[i] == buffer_b[i] ? ' ' : '!');
            } else {
                printf("%c", '!');
            }
        }
        printf("\n");
    }

    return (0);
}

