#include <stdlib.h>
#include <stdnoreturn.h>

noreturn int builtin_exit(int argc, char **argv) {
    (void)argc;
    (void)argv;
    exit(0);
}