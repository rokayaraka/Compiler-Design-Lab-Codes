#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_LENGTH 100

// Function to check if the string is a keyword
int is_keyword(const char *word) {
    const char *keywords[] = {
        "int", "char", "float", "double", "return", "if", "else", "while", "for", "void", "switch", "case", "break", "continue", "default", "struct", "union", "typedef", "long", "short", "unsigned", "signed", "const", "volatile", "static", "extern"
    };

    int num_keywords = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < num_keywords; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1; // it's a keyword
        }
    }
    return 0;
}

// Function to tokenize the C program
void tokenize(const char *program) {
    int i = 0;
    char token[MAX_TOKEN_LENGTH];
    int token_index = 0;

    while (program[i] != '\0') {
        // Skip whitespace
        if (isspace(program[i])) {
            i++;
            continue;
        }

        // Handle operators and punctuators
        if (program[i] == '+' || program[i] == '-' || program[i] == '*' || program[i] == '/' || program[i] == '=' ||
            program[i] == '(' || program[i] == ')' || program[i] == '{' || program[i] == '}' || program[i] == ';' ||
            program[i] == ',' || program[i] == '.' || program[i] == '[' || program[i] == ']' || program[i] == '<' ||
            program[i] == '>' || program[i] == '&' || program[i] == '|' || program[i] == '%' || program[i] == '!' ||
            program[i] == '^' || program[i] == '?' || program[i] == ':' || program[i] == '~') {

            printf("Operator/Punctuator: %c\n", program[i]);
            i++;
            continue;
        }

        // Handle numbers (integers or floating-point)
        if (isdigit(program[i])) {
            token_index = 0;
            while (isdigit(program[i]) || program[i] == '.') {
                token[token_index++] = program[i++];
            }
            token[token_index] = '\0';
            printf("Number: %s\n", token);
            continue;
        }

        // Handle identifiers and keywords
        if (isalpha(program[i]) || program[i] == '_') {
            token_index = 0;
            while (isalnum(program[i]) || program[i] == '_') {
                token[token_index++] = program[i++];
            }
            token[token_index] = '\0';

            if (is_keyword(token)) {
                printf("Keyword: %s\n", token);
            } else {
                printf("Identifier: %s\n", token);
            }
            continue;
        }

        // If we encounter an unknown character, we skip it
        i++;
    }
}

int main() {
    // Example C code to tokenize
    const char *program =
        "int main() {\n"
        "    int a = 5;\n"
        "    float b = 3.14;\n"
        "    if (a > 2) {\n"
        "        b = a * 2;\n"
        "    }\n"
        "    return 0;\n"
        "}";

    printf("Tokenizing the program...\n");
    tokenize(program);

    return 0;
}
