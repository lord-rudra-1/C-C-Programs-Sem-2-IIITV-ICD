#include <stdio.h>
#include <stdbool.h>

int queue[10];
int *ptr1 = queue;
int queue2[10];
int *ptr2 = queue2;

int front = -1, rear = -1;
int front2 = -1, rear2 = -1;

void push(int);
int pop();

void insert(int, int *, int *, int **);
int myDelete(int *, int *, int **);
bool isEmpty(int *f, int *r);
bool isFull(int *f, int *r);
void display();

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    display();

    printf("\nDeleted Item: %d\n", pop());
    printf("\nDeleted Item: %d\n", pop());
    printf("\nDeleted Item: %d\n", pop());
    display();

    push(70);
    push(80);
    display();

    return 0;
}

void push(int item)
{
    insert(item, &rear, &front, &ptr1);
}

int pop()
{
    while (front != rear)
        insert(myDelete(&front, &rear, &ptr1), &rear2, &front2, &ptr2);

    int temp = myDelete(&front, &rear, &ptr1);
    while (front2 != -1)
        insert(myDelete(&front2, &rear2, &ptr2), &rear, &front, &ptr1);

    return temp;
}

void insert(int item, int *r, int *f, int **qptr)
{
    int *quept = *qptr;
    if (isFull(f, r))
    {
        printf("\nThe queue is full!!\n");
        return;
    }
    else if (*f == *r)
    {
        if (*f == -1)
        {
            *f = *f + 1;
            *r = *r + 1;
        }
        else
            *r = *r + 1;
        *(quept + (*r)) = item;
    }
    else if (*f < *r)
    {
        if (*r < 9)
            *r = *r + 1;
        else
            *r = 0;
        *(quept + (*r)) = item;
    }
    else
    {
        *r = *r + 1;
        *(quept + (*r)) = item;
    }
}

int myDelete(int *f, int *r, int **quept)
{
    int *qupt = *quept;
    int temp = *f;
    if (isEmpty(f, r))
    {
        printf("\nThere is nothing to delete!!\n");
        return -1;
    }
    if (*f == *r)
    {
        *f = -1;
        *r = -1;
    }
    else
        *f = (*f + 1) % 10;
    return *(qupt + temp);
}

bool isEmpty(int *f, int *r)
{
    if (*f == -1 && *r == -1)
        return true;
    return false;
}

bool isFull(int *f, int *r)
{
    if (*f == 0 && *r == 9)
        return true;
    if (*r == *f - 1)
        return true;
    return false;
}

void display()
{
    int i;
    if (isEmpty(&front, &rear))
        return;
    if (front <= rear)
    {
        printf("The stack contents are:\n");
        for (i = front; i <= rear; i++)
            printf("%d\t", queue[i]);
        printf("\nfront = %d and rear = %d\n", front, rear);
    }
    else
    {
        printf("The stack contents are:\n");
        for (i = front; i <= 9; i++)
            printf("%d\t", queue[i]);

        for (i = 0; i <= rear; i++)
            printf("%d\t", queue[i]);

        printf("\nfront = %d and rear = %d\n", front, rear);
    }
}