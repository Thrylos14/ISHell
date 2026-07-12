#include <stdio.h>
#include <string.h>

enum Command 
{
  CMD_UNKNOWN,
  CMD_START,
  CMD_STOP,
  CMD_EXIT
};

enum Command resolveCommand(char *input) {
  if (!strcmp("start", input))
    return CMD_START;
  
  if (!strcmp("stop", input))
    return CMD_STOP;
  
  if (!strcmp("exit", input))
    return CMD_EXIT;
  return CMD_UNKNOWN;
}