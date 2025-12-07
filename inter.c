#include <stdio.h>
#include <string.h>
int main() {
    char exp[30], temp = 't';
    int i, j;
    char op1, op2;
    printf("Enter the expression (like a=b+c*d): ");
    scanf("%s", exp);
    printf("\nIntermediate Code\tExpression\n");
    // Step 1: Handle * and / first (high precedence)
    for (i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '*' || exp[i] == '/') {
            op1 = exp[i - 1];
            op2 = exp[i + 1];
            printf("%c = %c %c %c\t\t", temp, op1, exp[i], op2);
            exp[i - 1] = temp;   // replace result with temp variable
            exp[i] = '$';
            exp[i + 1] = '$';
            // print updated expression
            for (j = 0; exp[j] != '\0'; j++) {
                if (exp[j] != '$')
                    printf("%c", exp[j]);
            }
            printf("\n");
            temp++;
        }
    }

    // Step 2: Handle + and - (lower precedence)
    for (i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '+' || exp[i] == '-') {
            op1 = exp[i - 1];
            op2 = exp[i + 1];
            printf("%c = %c %c %c\t\t", temp, op1, exp[i], op2);
            exp[i - 1] = temp;
            exp[i] = '$';
            exp[i + 1] = '$';
            for (j = 0; exp[j] != '\0'; j++) {
                if (exp[j] != '$')
                    printf("%c", exp[j]);
            }
            printf("\n");
            temp++;
        }
    }
    // Step 3: Handle assignment (=)
    for (i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '=') {
            printf("%c = %c\n", exp[0], exp[i + 1]);
        }
    }
    return 0;
}