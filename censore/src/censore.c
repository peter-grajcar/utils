#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#define BUFFER_SIZE 256

int main(int argc, char *argv[]) {
    int whitespace = 1;
    char buffer[BUFFER_SIZE];
    size_t read_size;
    while ((read_size = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0) {
        int i;
        for (i = 0; i < read_size; ++i) {
            char ch = buffer[i];
            if (isspace(ch) && !whitespace) {
                whitespace = 1;
                printf("%s", "\x1b[0m");
            } else if (!isspace(ch) && whitespace) {
                whitespace = 0;
                printf("%s", "\x1b[48;2;0;0;0m\x1b[38;2;0;0;0m");
            }
            putchar(ch);
        }
    }
    return 0;
}
