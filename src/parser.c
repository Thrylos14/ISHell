#include <string.h>
#include "parser.h"

void parseCommand(char *input, char *argv[]) 
{
    int argc = 0;
  
    char *token = strtok(input, " "); // replaces first " " with "\0" and returns pointer to the start of input

    while (token) {
        argv[argc++] = token; // assigns the pointer to argv[argc] 
        token = strtok(NULL, " "); // returns pointer from after the previous replacement. works because strtok internally stores nextPosition
    }
}