#include <stdio.h>
#include <string.h>

char input[20], stack[50];
int top = -1, i = 0;

int reduce() {
    // id -> E
    if (top >= 1 && stack[top] == 'd' && stack[top - 1] == 'i') {
        stack[top - 1] = 'E';
        top--;
        stack[top + 1] = '\0';
        printf("\tReduce: E->id");
        return 1;
    }
    // (E) -> E
    if (top >= 2 && stack[top] == ')' && stack[top - 1] == 'E' && stack[top - 2] == '(') {
        stack[top - 2] = 'E';
        top -= 2;
        stack[top + 1] = '\0';
        printf("\tReduce: E->(E)");
        return 1;
    }
    // E+E -> E
    if (top >= 2 && stack[top] == 'E' && stack[top - 1] == '+' && stack[top - 2] == 'E') {
        stack[top - 2] = 'E';
        top -= 2;
        stack[top + 1] = '\0';
        printf("\tReduce: E->E+E");
        return 1;
    }
    // E*E -> E
    if (top >= 2 && stack[top] == 'E' && stack[top - 1] == '*' && stack[top - 2] == 'E') {
        stack[top - 2] = 'E';
        top -= 2;
        stack[top + 1] = '\0';
        printf("\tReduce: E->E*E");
        return 1;
    }
    return 0;
}

int main() {
    printf("Enter the input string (use id for identifiers): ");
    scanf("%s", input);

    printf("\nStack\t\tInput\t\tAction");

    while (i < strlen(input)) {
        stack[++top] = input[i++];
        stack[top + 1] = '\0';
        printf("\n%-20s%-20sShift", stack, input + i);

        // keep reducing after every shift if possible
        while (reduce());
    }

    // Final reductions after input is consumed
    while (reduce());

    if (strcmp(stack, "E") == 0)
        printf("\n✅ String Accepted - Valid Expression\n");
    else
        printf("\n❌ String Rejected - Invalid Expression\n");

    return 0;
}