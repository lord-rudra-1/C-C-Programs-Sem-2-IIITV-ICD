#include<stdio.h>
#include<stdbool.h>
int stack1[100000];
int stack2[100000];

int tp1=0,tp2=0;

bool isempty(int);
bool isfull(int);
void pushQ(int item);
int popQ();
void disp();

int main()
{
    int q, type, value;
    scanf("%d", &q);

    while (q--) {
        scanf("%d", &type);
        switch (type) {
            case 1:
                scanf("%d", &value);
                pushQ(value);
                break;
            case 2:
                popQ();
                break;
            case 3:
                disp();
                break;
            default:
                printf("Invalid operation type!\n");
                break;
        }
    }

    return 0;
}

bool isempty(int top)
{
    if(top<=0)
        return true;
    return false;
}

bool isfull(int top)
{
    if(top==100000)
        return true;
    return false;
}

void pushQ(int item)
{
    if(isfull(tp1))
    {
        printf("\nQueue is full!!\n");
        return;
    }
    stack1[tp1]=item;
    tp1++;
}

int popQ()
{
    if(isempty(tp1) && isempty(tp2))
    {
        printf("\nQueue is empty!!\n");
        return -1;
    }

    if(tp2==0)
    {
        while(tp1>0)
        {
            tp1--;
            stack2[tp2]=stack1[tp1];
            tp2++;
        }
    }
    tp2--;
    return stack2[tp2];
}

void disp()
{
    int i;
    for(i=tp2-1;i>=0;i--){
        printf("%d\n",stack2[i]);
        return;}
    for(i=0;i<tp1;i++){
        printf("%d\n",stack1[i]);
        return;}
}
