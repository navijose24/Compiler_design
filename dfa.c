#include <stdio.h>
#include <string.h>

int main() {
    int nStates, nSymbols, nFinal, finalStates[20];
    int transition[20][20]; 
    int i, j, currState, symbol, len;
    char input[100], alphabet[20];

    // Number of states and input symbols
    printf("Enter number of states: ");
    scanf("%d", &nStates);

    printf("Enter number of input symbols: ");
    scanf("%d", &nSymbols);

    printf("Enter input symbols: ");
    for (i = 0; i < nSymbols; i++)
        scanf(" %c", &alphabet[i]);

    // Transition table
    printf("Enter transition table (next state for each state-symbol):\n");
    for (i = 0; i < nStates; i++) {
        for (j = 0; j < nSymbols; j++) {
            printf("δ(q%d, %c) = ", i, alphabet[j]);
            scanf("%d", &transition[i][j]);
        }
    }

    // Final states
    printf("Enter number of final states: ");
    scanf("%d", &nFinal);
    printf("Enter final states: ");
    for (i = 0; i < nFinal; i++)
        scanf("%d", &finalStates[i]);

    // Input string
    printf("Enter input string: ");
    scanf("%s", input);
    len = strlen(input);

    // Simulation
    currState = 0; // start state is q0
    for (i = 0; i < len; i++) {
        symbol = -1;
        for (j = 0; j < nSymbols; j++) {
            if (input[i] == alphabet[j]) {
                symbol = j;
                break;
            }
        }
        if (symbol == -1) {
            printf("Invalid input symbol: %c\n", input[i]);
            return 0;
        }
        currState = transition[currState][symbol];
    }

    // Check acceptance
    int accepted = 0;
    for (i = 0; i < nFinal; i++) {
        if (currState == finalStates[i]) {
            accepted = 1;
            break;
        }
    }

    if (accepted)
        printf("String accepted.\n");
    else
        printf("String rejected.\n");

    return 0;
}