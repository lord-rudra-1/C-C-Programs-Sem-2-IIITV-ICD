#include <stdio.h>

void push(char* ptr, int* t) {
    *t = *t + 1;
    *(ptr + *t) = '(';
}

void pop(char* pt, int* t) {
    *(pt + *t) = '\0';
    *t = *t - 1;
}

int main() {
    char stack[100];
    char input[100];
    int i = 0, tos = -1;

    printf("Enter the expression: ");
    scanf("%s", input);

    while (input[i] != '\0') {
        if (tos < -1)
            break;

        if (input[i] == '(')
            push(stack, &tos);

        if (input[i] == ')')
            pop(stack, &tos);

        i++;
    }

    if (tos == -1)
        printf("Balanced\n");
    else
        printf("Unbalanced\n");

    return 0;
}
