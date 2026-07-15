#include <string.h>
#include "builtin.h"

const BuiltinCommand builtins[] = {
    {"cd", builtin_cd},
    {"pwd",builtin_pwd},
    {"clear", builtin_clear},
    {"exit", builtin_exit}
};

const int builtin_count = sizeof(builtins) / sizeof(builtins[0]);

