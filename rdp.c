#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char input[20];
int i = 0;

// Function declarations
void E();
void Eprime();
void T();
void Tprime();
void F();

void error() {
    printf("❌ Error at position %d\n", i + 1);
    printf("String rejected.\n");
    exit(0);
}

// E → T E'
void E() {
    T();
    Eprime();
}

// E' → + T E' | ε
void Eprime() {
    if (input[i] == '+') {
        i++;
        T();
        Eprime();
    }
}

// T → F T'
void T() {
    F();
    Tprime();
}

// T' → * F T' | ε
void Tprime() {
    if (input[i] == '*') {
        i++;
        F();
        Tprime();
    }
}

// F → (E) | id
void F() {
    if (input[i] == '(') {
        i++;
        E();
        if (input[i] == ')')
            i++;
        else
            error();
    }
    else if (input[i] == 'i' && input[i + 1] == 'd') {
        i += 2; // match 'id'
    }
    else
        error();
}

int main() {
    printf("Enter the input string (use id for identifiers): ");
    scanf("%s", input);

    E();

    if (input[i] == '\0')
        printf("✅ String Accepted - Valid Expression\n");
    else
        printf("❌ String Rejected - Invalid Expression\n");

    return 0;
}
        