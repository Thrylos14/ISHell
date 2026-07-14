#include <direct.h>
#include <stdio.h>

int builtin_cd(int argc, char *argv[]) {
    // chdir returns 0 upon success, which will bypass the if statement
    if (_chdir(argv[1])) {
        perror("cd");
        return 1;
    }

    return 0;    
}