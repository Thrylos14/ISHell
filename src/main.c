#include flags.h;

enum Command
{
  CMD_UNKNOWN;
  CMD_START;
  CMD_STOP;
};

enum Command parseCommand(char *input) {
  if (!strcmp("start", input)) {
    printf("Starting")
  }
}

void launchShellInstance() {
  char defaultPrompt = '❯'
  
  while (TRUE) {
    printf("%c", defaultPrompt)
    char *token = fgets(char *str, 256, stdin)
    parseCommand(token)
  }
}

int main(int argc, char* argv[]) {
  if (argc >= 2) {
      printf("The command %s takes no arguments.\n", argv[0]);
      return 1;
  }
  
  launchShellInstance();
  
  return 0;
}