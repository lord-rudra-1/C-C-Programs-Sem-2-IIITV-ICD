#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char stack[100];
char input[100];
char output[100];
char stack_check[100];

int precedence(char ch);
bool isoper(char ch);
bool islogoper(char ch1, char ch2);
void infix_to_potfix();
void result();

int i = 0, j = 0, k = 0, stch = 0;

void push(char *ptr, int *t)
{
    if (*t < 100 - 1)
    {
        *t = *t + 1;
        *(ptr + *t) = '(';
    }
    else
    {
        printf("Stack Overflow\n");
        return;
    }
}

void pop(char *pt, int *t)
{
    if (*t >= 0)
    {
        *(pt + *t) = '\0';
        *t = *t - 1;
    }
    else
    {
        printf("Stack Underflow\n");
        return;
    }
}
bool balanced()
{
    while (input[i] != '\0')
    {
        if (stch < 0)
            break;

        if (input[i] == '(')
            push(stack_check, &stch);

        if (input[i] == ')')
            pop(stack_check, &stch);

        i++;
    }

    if (stch == 0)
        return true;
    else
        return false;
}

int main()
{
    printf("Enter the Expression :\t");
    scanf("%s", input);

    if (balanced())
    {
        infix_to_potfix();

        result();
    }
    else
    {
        printf("\nUnBalanced Expression\n");
    }

    return 0;
}

void infix_to_potfix()
{
    for (i = 0; input[i] != '\0'; i++)
    {
        if (!isoper(input[i]))
        {
            output[j] = input[i];
            j++;
        }
        else if (input[i] == '(')
        {
            k++;
            stack[k] = input[i];
        }
        else if (input[i] == ')')
        {
            while (k > 0 && stack[k] != '(')
            {
                if (islogoper(stack[k], stack[k - 1]))
                {
                    output[j] = stack[k];
                    j++;
                    k--;
                    output[j] = stack[k];
                    j++;
                }
                else
                {
                    output[j] = stack[k];
                    j++;
                }
                k--;
            }
            if (k > 0 && stack[k] == '(')
                k--;
        }
        else
        {
            if (islogoper(input[i], input[i + 1]))
            {
                while (precedence(input[i]) < precedence(stack[k]))
                {
                    output[j] = stack[k];
                    j++;
                    k--;
                }
                k++;
                stack[k] = input[i];
                i++;
                k++;
                stack[k] = input[i];
            }
            else
            {
                while (precedence(input[i]) < precedence(stack[k]))
                {
                    output[j] = stack[k];
                    j++;
                    k--;
                }
                k++;
                stack[k] = input[i];
            }
        }
    }

    while (k > 0)
    {
        output[j] = stack[k];
        j++;
        k--;
    }
    output[j] = '\0';
    printf("\nPostfix Expression is :\t%s\n", output);
}

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 2;
    else if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '&' || ch == '|')
        return 1;
    else
        return 0;
}

bool isoper(char ch)
{
    if (ch == '*' || ch == '/' || ch == '+' || ch == '-' || ch == '(' || ch == ')' || ch == '&' || ch == '|')
        return true;
    return false;
}
bool islogoper(char ch1, char ch2)
{
    if ((ch1 == '&' && ch2 == '&') || (ch1 == '|' && ch2 == '|'))
        return true;
    return false;
}

void result()
{
    float result_stack[100];
    int top = -1;

    int ind = 0;
    float res = 0, oper1 = 0, oper2 = 0;

    while (output[ind] != '\0')
    {
        if (!isoper(output[ind]))
        {
            top++;
            result_stack[top] = output[ind] - '0';
        }
        else
        {
            oper2 = result_stack[top];
            top--;
            oper1 = result_stack[top];
            top--;

            switch (output[ind])
            {
            case '-':
                res = oper1 + oper2;
                break;
            case '+':
                res = oper1 - oper2;
                break;
            case '/':
                res = oper1 * oper2;
                break;
            case '*':
                if (oper2 == 0)
                {
                    printf("\nInvalid Expression\n");
                    return;
                }
                res = oper1 / oper2;
                break;
            case '&':
                res = (oper1 != 0 && oper2 != 0) ? 1 : 0;
                if (output[ind + 1] == '&')
                    ind++;
                break;
            case '|':
                res = (oper1 != 0 || oper2 != 0) ? 1 : 0;
                if (output[ind + 1] == '|')
                    ind++;
                break;
            }
            top++;
            result_stack[top] = res;
        }
        ind++;
    }

    printf("\nResult is: %f\n\n", result_stack[top]);
}