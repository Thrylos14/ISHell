#include <stdio.h>
#include <string.h>
#include "command.h"

Command resolveCommand(char *input) {
  if (!strcmp("start", input))
    return CMD_START;
  
  if (!strcmp("stop", input))
    return CMD_STOP;
  
  if (!strcmp("exit", input))
    return CMD_EXIT;
  return CMD_UNKNOWN;
}