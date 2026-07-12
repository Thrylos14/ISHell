#ifndef COMMAND_H
#define COMMAND_H

typedef enum  {
  CMD_UNKNOWN,
  CMD_START,
  CMD_STOP,
  CMD_EXIT
} Command;

Command resolveCommand(char *input);

#endif
