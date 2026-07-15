#ifndef BUILTIN_H
#define BUILTIN_H

int builtin_cd(int argc, char **argv);
int builtin_pwd(int argc, char **argv);
int builtin_clear(int argc, char **argv);
int builtin_exit(int argc, char **argv);

typedef int (*BuiltinFunc)(int argc, char **argv);

typedef struct {
    const char *name;
    BuiltinFunc func;
} BuiltinCommand;

extern const BuiltinCommand builtins[];
extern const int builtin_count;
#endif