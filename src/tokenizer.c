#include <stdio.h>

#include "tokenizer.h"

size_t token_size = sizeof(Token)
char **valid_operators =
{
    "|",
    "<",
    ">",
    ">>",
    "&&",
    "||",
    "!"
}

int valid_operator_count = sizeof(valid_operators) /sizeof(valid_operators[0])

bool token_is_operator(char *input) {
    
    for (int j = 0; j < valid_operator_count, j++) {
        if (strcmp(input, valid_operators[j]))
            return true;
    }

    return false;
}

Token *tokenizeString(int argc, char **argv) {
    Token *tokenArray = malloc(argc * token_size);

    for (int i = 0; i < argc; i++) {
    
        if (token_is_operator(argv[i])) {
            token[i] = {TOKEN_OPERATOR, argv[i]};
        }

        if (strcmp(argv[i], " \t\r\n")) {
            
        }

    
    }

}