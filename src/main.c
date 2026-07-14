#include <stdio.h>
#include <windows.h>
#include "parser.h"
#include "builtin.h"

char* strip(char *str) {
    if (str == NULL)
        return NULL;

    // 1. Remove leading newlines by advancing the pointer.
    while (*str == '\n' || *str == '\r') {
        str++;
    }

    // 2. Remove trailing newlines by truncating string.
    size_t len = strlen(str);

    while (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r')) {
        str[len - 1] = '\0';
        len--;
    }

    return str;
}

void launch_shell_instance() {
	
    int command_not_found;
    char *default_prompt = "❯";
	char *token;
    char buffer[256];
	char *argv[256];

    while (1) {

        command_not_found = 1;
        printf("%s ", default_prompt);

        token = strip(fgets(buffer, sizeof(buffer), stdin));
        parse_command(token, argv);

        for (int i = 0; i < builtin_count; i++) {

            if (!strcmp(argv[0], builtins[i].name)) {
                
                int argc = sizeof(argv);
                builtins[i].func(argc, argv);
                
                command_not_found = 0;
                break;
            }
        }

        if (command_not_found)
            printf("\033[1;31mError:\033[0m Command \033[1;33m%s\033[0m not found.\n", argv[0]);
        
    }
}

int main(int argc, char* argv[]) {

    // forces windows terminals to use UTF-8 (allows ❯ to render properly)
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
 
    if (argc > 1) {
        printf("The command %s takes no arguments.\n", argv[0]);
        return 1;
    }
    
    launch_shell_instance();
    
    return 0;
}