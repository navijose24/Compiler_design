#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int n;
    printf("Enter number of 3-address expressions: ");
    scanf("%d", &n);

    char op[20][5], arg1[20][10], arg2[20][10], res[20][10];
    int remove[20] = {0}; // mark instructions to remove

    for (int i = 0; i < n; i++) {
        scanf("%s %s %s %s", op[i], arg1[i], arg2[i], res[i]);
    }

    for (int i = 0; i < n; i++) {
        // Detect constant assignment like (= 3 - a)
        int isConst = 1;
        for (int k = 0; arg1[i][k]; k++)
            if (!isdigit(arg1[i][k])) isConst = 0;

        if (strcmp(op[i], "=") == 0 && isConst) {
            for (int j = i + 1; j < n; j++) {
                if (strcmp(arg1[j], res[i]) == 0)
                    strcpy(arg1[j], arg1[i]);
                if (strcmp(arg2[j], res[i]) == 0)
                    strcpy(arg2[j], arg1[i]);
            }
            remove[i] = 1; // mark it for removal
        }
    }

    printf("\nOptimized Code:\n");
    for (int i = 0; i < n; i++) {
        if (!remove[i])
            printf("%s %s %s %s\n", op[i], arg1[i], arg2[i], res[i]);
    }

    return 0;
}