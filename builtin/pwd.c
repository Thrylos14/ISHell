#include <limits.h>
#include <direct.h>
#include <stdio.h>

int builtin_pwd(int argc, char **argv) {
    (void)argc;
    (void)argv;
    
    char cwd[PATH_MAX];
    
    if (!_getcwd(cwd, sizeof(cwd))) {
        perror("pwd");
        return 1;
    }

    printf("%s\n", cwd);
    return 0;
}