#include <string.h>
#include "parser.h"

int parse_command(char *input, char **argv) 
{
    int argc = 0;
    
    char *token = strtok(input, " \t\r\n"); // replaces first " " with "\0" and returns pointer to the start of input

    while (token && argc < 255) {
        argv[argc++] = token; // assigns the pointer to argv[argc] 
        token = strtok(NULL, " "); // returns pointer from after the previous replacement. works because strtok internally stores nextPosition
    }
    
    // Accounts for accessing argv[0] while it's empty.
    argv[argc] = NULL;
    return argc;
}