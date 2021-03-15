#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>
#include <err.h>

#define USAGE   fprintf(stderr, "usage: %s [-h] [-t tolerance] file ...\n", basename(argv[0]));

int main(int argc, char *argv[])
{
    long tol = 1000; /* tolerance */
    int opt;
    while ((opt = getopt(argc, argv, "t:h")) != -1) {
        switch (opt) {
            case 't':
                tol = strtol(optarg, (char **)NULL, 10);
                break;
            case 'h':
                USAGE;
                break;
            default:
                USAGE;
                return 1;
       }
    }

    char **files = argv + optind;
    int files_count = argc - optind;

    // TODO: 

    return 0;
}

