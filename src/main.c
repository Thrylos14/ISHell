#include <stdio.h>
#include <windows.h>
#include "command.h"
#include "parser.h"

// enum Command
// {
//   CMD_UNKNOWN;
//   CMD_START;
//   CMD_STOP;
// };

// enum Command parseCommand(char *input) {
//   if (!strcmp("start", input)) {
//     printf("Starting")
//   }
// }

char* strip(char *input) {
  if (input == NULL)
    return NULL;

  // 1. Remove leading newlines by advancing the pointer.
  while (*input == '\n' || *input == '\r') {
    input++;
  }

  // 2. Remove trailing newlines by truncating string.
  size_t len = strlen(input);

  while (len > 0 && (input[len - 1] == '\n' || input[len - 1] == '\r')) {
    input[len - 1] = '\0';
    len--;
  }

  return input;
}

void launchShellInstance() {
	char *defaultPrompt = "❯";
	char *token;
	char buffer[256];
	char *argv[256];
	int exitFlag = 0;

  while (!exitFlag) {

  printf("%s ", defaultPrompt);

    token = strip(fgets(buffer, sizeof(buffer), stdin));
    parseCommand(token, argv);

    switch (resolveCommand(argv[0]))
    {
    case CMD_START:
        printf("Start.\n");
        break;
    
    case CMD_STOP:
        printf("Stop.\n");
        break;
    
    case CMD_UNKNOWN:
      printf("Unknown command entered.\n");
      break;
    
    case CMD_EXIT:
      exitFlag = 1;
    }

	}
}

int main(int argc, char* argv[]) {

  // forces windows terminals to use UTF-8 (allows ❯ to render properly)
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);
 
  if (argc >= 2) {
      printf("The command %s takes no arguments.\n", argv[0]);
      return 1;
  }
  
  launchShellInstance();
  
  return 0;
}