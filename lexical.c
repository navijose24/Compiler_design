#include <stdio.h>
#include <string.h>
#include <ctype.h>

char keywords[32][10] = {
    "auto","break","case","char","const","continue","default","do","double",
    "else","enum","extern","float","for","goto","if","int","long","register",
    "return","short","signed","sizeof","static","struct","switch","typedef",
    "union","unsigned","void","volatile","while"
};

int isKeyword(char *word) {
    for (int i = 0; i < 32; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char input[200];
    printf("Enter the code:\n");
    fgets(input, sizeof(input), stdin);

    int i = 0;
    char token[50];
    int j = 0;

    while (input[i] != '\0') {

        // Skip spaces and newlines
        if (isspace(input[i])) {
            i++;
            continue;
        }

        // Skip comments
        if (input[i] == '/' && input[i + 1] == '/') break; // Single-line
        if (input[i] == '/' && input[i + 1] == '*') {      // Multi-line
            i += 2;
            while (!(input[i] == '*' && input[i + 1] == '/') && input[i] != '\0') i++;
            i += 2;
            continue;
        }

        // Identifiers and keywords
        if (isalpha(input[i]) || input[i] == '_') {
            j = 0;
            while (isalnum(input[i]) || input[i] == '_') {
                token[j++] = input[i++];
            }
            token[j] = '\0';
            if (isKeyword(token))
                printf("Keyword: %s\n", token);
            else
                printf("Identifier: %s\n", token);
            continue;
        }

        // Numbers
        if (isdigit(input[i])) {
            j = 0;
            while (isdigit(input[i])) {
                token[j++] = input[i++];
            }
            token[j] = '\0';
            printf("Number: %s\n", token);
            continue;
        }

        // Multi-character operators
        if ((input[i] == '=' && input[i + 1] == '=') ||
            (input[i] == '!' && input[i + 1] == '=') ||
            (input[i] == '<' && input[i + 1] == '=') ||
            (input[i] == '>' && input[i + 1] == '=') ||
            (input[i] == '+' && input[i + 1] == '+') ||
            (input[i] == '-' && input[i + 1] == '-')) {
            printf("Operator: %c%c\n", input[i], input[i + 1]);
            i += 2;
            continue;
        }

        // Single-character operators and symbols
        if (strchr("+-*/=<>%&|^!", input[i])) {
            printf("Operator: %c\n", input[i]);
        } else if (strchr("(){}[],;:", input[i])) {
            printf("Special symbol: %c\n", input[i]);
        }

        i++;
    }

    return 0;
}