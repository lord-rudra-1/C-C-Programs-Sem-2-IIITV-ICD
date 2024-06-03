#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

char input[100];

struct item
{
    char bracket;
    struct item *ptr;
};

struct item *top = NULL;
int tp=0;

void push();
void pop();
bool isEmpty(struct item *t);

int main()
{
    printf("\nenter the expression\n");
    scanf(" %s",input);
    
    for(int i=0;input[i]!='\0';i++)
    {
        if(input[i]=='(')
        push();
        if(input[i]==')')
        pop();
    }
    if(isEmpty(top) && tp>=0)
    printf("\nTrue\n");
    else
    printf("\nFalse\n");
        
    return 0;
}

bool isEmpty(struct item *t)
{
    if(t == NULL)
        return true;
    return false;
}

void push()
{
    struct item *temp = (struct item *) malloc(sizeof(struct item));
    if(isEmpty(top))
    {
        temp->ptr = NULL;
    }
    temp->bracket = '(' ;
    temp->ptr = top;
    top = temp;
}

void pop()
{
    if(isEmpty(top))
    {
        tp=-10000;
    }
    else
    top = top->ptr;
}

