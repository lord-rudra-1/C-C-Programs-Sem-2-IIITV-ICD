#include <stdio.h>
#include <stdlib.h>

typedef struct polyno
{
    int coff;
    int exp;
    struct polyno *next;
} polyno;

void display(polyno *tpp);
void push(int cof, int ex, polyno **tpp);
void add(polyno **tpp1, polyno **tpp2);
polyno *aux_add();
void aux_pick(polyno **poi, int n);
polyno *auxpt = NULL;

int main()
{
    polyno *tp1 = NULL, *tp2 = NULL;

    push(2, 3, &tp1);
    push(2, 1, &tp1);
    push(3, 0, &tp1);
    printf("\npolynomial 1 : ");
    display(tp1);

    push(5, 2, &tp2);
    push(-2, 1, &tp2);
    push(-1, 0, &tp2);
    printf("\npolynomial 2 : ");
    display(tp2);

    add(&tp1, &tp2);
    printf("\nadd / polynomial 1 : ");
    display(tp1);
    printf("\npolynomial 2 : ");
    display(tp2);
    printf("\naux :");
    display(auxpt);

    push(5, 2, &tp2);
    push(-2, 1, &tp2);
    push(-1, 0, &tp2);
    printf("\npolynomial 2 : ");
    display(tp2);
    printf("\naux : ");
    display(auxpt);

    return 0;
}

void display(polyno *tpp)
{
    while (tpp != NULL)
    {
        printf("(%d)x^%d", tpp->coff, tpp->exp);
        if (tpp->next != NULL)
            printf(" + ");
        tpp = tpp->next;
    }
    printf("\n\n");
}

void add(polyno **tpp1, polyno **tpp2)
{
    polyno *te1 = *tpp1;
    polyno *te2 = *tpp2;

    while (te1 != NULL && te2 != NULL)
    {
        if (te1->exp == te2->exp)
        {
            te1->coff += te2->coff;
            te1 = te1->next;
            te2 = te2->next;
        }
        else if (te1->exp > te2->exp)
        {
            te1 = te1->next;
        }
        else
        {
            push(te2->coff, te2->exp, tpp1);
            te2 = te2->next;
        }
    }

    while (te2 != NULL)
    {
        push(te2->coff, te2->exp, tpp1);
        te2 = te2->next;
    }
    aux_pick(tpp1, 1);
    aux_pick(tpp2, 0);
}

void push(int cof, int ex, polyno **tpp)
{
    if (cof == 0)
        return;

    polyno *temp = aux_add();
    temp->coff = cof;
    temp->exp = ex;
    temp->next = NULL;
    if (*tpp == NULL)
    {
        *tpp = temp;
    }
    else
    {
        polyno *temp2 = *tpp;
        for (; temp2->next != NULL; temp2 = temp2->next)
            ;
        temp2->next = temp;
    }
}

void aux_pick(polyno **poi, int n)
{
    if (n == 1)
    {
        polyno *curr = *poi;
        polyno *prev = NULL;

        while (curr != NULL)
        {
            if (curr->coff == 0)
            {
                if (auxpt == NULL)
                {
                    auxpt = curr;
                    *poi = curr->next;
                    curr = curr->next;
                    auxpt->next = NULL;
                }
                else
                {
                    while (auxpt->next != NULL)
                        auxpt = auxpt->next;
                    auxpt->next = curr;
                    prev->next = curr->next;
                    curr = curr->next;
                    auxpt = auxpt->next;
                    auxpt->next = NULL;
                }
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
    }
    else
    {
        while (auxpt->next != NULL)
            auxpt = auxpt->next;
        auxpt->next = *poi;
        *poi = NULL;
    }
}

polyno *aux_add()
{
    polyno *temp;
    if (auxpt == NULL)
        temp = (polyno *)malloc(sizeof(polyno));
    else
    {
        temp = auxpt;
        auxpt = auxpt->next;
        temp->next = NULL;
    }
    return temp;
}