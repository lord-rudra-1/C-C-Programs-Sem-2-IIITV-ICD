#include<stdio.h>
#include<stdlib.h>

typedef struct polyno
{
	int coff;
	int exp;
	struct polyno* next;
}polyno;


void display(polyno* tpp);
void push(int cof,int ex, polyno** tpp);
void add( polyno** tpp1, polyno** tpp2, polyno** tpp3);
void subta(polyno** tpp1, polyno** tpp2, polyno** tpp3);

int main()
{
    polyno *tp1 = NULL, *tp2 = NULL, *tp3 = NULL, *tp4=NULL;

    push(2,3,&tp1);
    push(2,1,&tp1);
    push(3,0,&tp1);
    display(tp1);

    push(5,2,&tp2);
    push(-2,1,&tp2);
    push(-1,0,&tp2);
    display(tp2);

    add(&tp1,&tp2,&tp3);
    display(tp3);

    subta(&tp1,&tp2,&tp4);
    display(tp4);

    return 0;
}
void display(polyno* tpp)
{
    while(tpp!=NULL)
    {
        printf("(%d)x^%d",tpp->coff,tpp->exp);
        if(tpp->next!=NULL)
        printf(" + ");
        tpp=tpp->next;
    }
    printf("\n\n");
}

void push(int cof,int ex, polyno** tpp)
{
    if(cof==0)
        return;

    polyno*temp=(polyno*)malloc(sizeof(polyno));
    temp->coff=cof;
    temp->exp=ex;
    temp->next=NULL;
    if(*tpp==NULL)
    {
        *tpp=temp;
    }
    else
    {
        polyno*temp2=*tpp;
        for(;temp2->next!=NULL;temp2=temp2->next);
        temp2->next=temp;
    }
}

void add(polyno** tpp1, polyno** tpp2, polyno** tpp3)
{
    polyno* te1 = *tpp1;
    polyno* te2 = *tpp2;

    while (te1 != NULL && te2 != NULL)
    {
        if (te1->exp == te2->exp)
        {
            push(te1->coff + te2->coff, te1->exp, tpp3);
            te1 = te1->next;
            te2 = te2->next;
        }
        else if (te1->exp > te2->exp)
        {
            push(te1->coff, te1->exp, tpp3);
            te1 = te1->next;
        }
        else
        {
            push(te2->coff, te2->exp, tpp3);
            te2 = te2->next;
        }
    }

    while (te1 != NULL)
    {
        push(te1->coff, te1->exp, tpp3);
        te1 = te1->next;
    }

    while (te2 != NULL)
    {
        push(te2->coff, te2->exp, tpp3);
        te2 = te2->next;
    }
}

void subta(polyno** tpp1, polyno** tpp2, polyno** tpp4)
{
    polyno* te1 = *tpp1;
    polyno* te2 = *tpp2;

    while (te1 != NULL && te2 != NULL)
    {
        if (te1->exp == te2->exp)
        {
            push(te1->coff - te2->coff, te1->exp, tpp4);
            te1 = te1->next;
            te2 = te2->next;
        }
        else if (te1->exp > te2->exp)
        {
            push(te1->coff, te1->exp, tpp4);
            te1 = te1->next;
        }
        else
        {
            push(-(te2->coff), te2->exp, tpp4);
            te2 = te2->next;
        }
    }

    while (te1 != NULL)
    {
        push(te1->coff, te1->exp, tpp4);
        te1 = te1->next;
    }

    while (te2 != NULL)
    {
        push(-(te2->coff), te2->exp, tpp4);
        te2 = te2->next;
    }
}