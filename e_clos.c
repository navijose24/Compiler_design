#include <stdio.h>
#include <string.h>

int nStates, nTrans;
int epsilon[20][20];
int closure[20];

void findClosure(int state) {
    if (closure[state]) return;
    closure[state] = 1;

    for (int i = 0; i < nStates; i++) {
        if (epsilon[state][i] && !closure[i])
            findClosure(i);
    }
}

int main() {
    int i, j, from, to;
    char symbol[5];

    printf("Enter number of states: ");
    scanf("%d", &nStates);

    printf("Enter number of transitions: ");
    scanf("%d", &nTrans);

    // Initialize epsilon matrix
    for (i = 0; i < nStates; i++)
        for (j = 0; j < nStates; j++)
            epsilon[i][j] = 0;

    printf("Enter transitions (from symbol to):\n");
    for (i = 0; i < nTrans; i++) {
        scanf("%d %s %d", &from, symbol, &to);
        if (strcmp(symbol, "e") == 0) // only store epsilon transitions
            epsilon[from][to] = 1;
    }

    // Compute epsilon-closure for all states
    for (i = 0; i < nStates; i++) {
        for (j = 0; j < nStates; j++) closure[j] = 0;
        findClosure(i);

        printf("ε-closure(q%d): { ", i);
        for (j = 0; j < nStates; j++)
            if (closure[j]) printf("q%d ", j);
        printf("}\n");
    }

    return 0;
}
