#include <stdio.h>
#include <string.h>

int main() {
    int n;
    printf("Enter number of 3-address instructions: ");
    scanf("%d", &n);
    getchar();  // consume newline

    char line[50], res[10], arg1[10], op[5], arg2[10];

    printf("Enter instructions (e.g., T1 = A + B):\n");

    for (int i = 0; i < n; i++) {
        fgets(line, sizeof(line), stdin);

        // Parse the line like: result = arg1 op arg2
        sscanf(line, "%s = %s %s %s", res, arg1, op, arg2);

        printf("\nAssembly Code for: %s", line);
        printf("MOV R0, %s\n", arg1);

        if (strcmp(op, "+") == 0)
            printf("ADD R0, %s\n", arg2);
        else if (strcmp(op, "-") == 0)
            printf("SUB R0, %s\n", arg2);
        else if (strcmp(op, "*") == 0)
            printf("MUL R0, %s\n", arg2);
        else if (strcmp(op, "/") == 0)
            printf("DIV R0, %s\n", arg2);

        printf("MOV %s, R0\n", res);
    }

    return 0;
}
