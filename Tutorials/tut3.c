#include<stdio.h>
#include<stdlib.h>

typedef struct item
{
    int val;
    struct item* next;
}item;

void linkadder(item**head,int n);//add element to singly linked list
void display(item*head);
void concatenation(item**ptr,item**ptr2);// (3)cancatenation of two singly linked list
void reverser(item**head);// (2)reverse of linked list
void circulist(item**head,int n);// (1)create circular linked list
void circudel(item**head);// (1)delete circular linked list

int main()
{
    item * head1=NULL, * head2=NULL, *cirhead=NULL;

    linkadder(&head1,1);
    linkadder(&head1,2);
    linkadder(&head1,3);
    linkadder(&head1,4);
    linkadder(&head1,5);
    linkadder(&head2,6);
    linkadder(&head2,7);
    linkadder(&head2,8);
    linkadder(&head2,9);

    printf("\n1st Linked list : ");
    display(head1);
    printf("\n2st Linked list : ");
    display(head2);

    concatenation(&head1,&head2);
    printf("\nConcatenation of Linked lists : ");
    display(head1);

    reverser(&head1);
    printf("\nReverse Linked list : ");
    display(head1);

    printf("\ncircular linked list elements : ");
    circulist(&cirhead,73);
    circulist(&cirhead,74);
    circulist(&cirhead,75);
    circulist(&cirhead,76);
    display(cirhead);

    circudel(&cirhead);
    printf("\nAfter deleting circular Linkedlist : ");
    display(cirhead);
    printf("\n");

    return 0;
}

void linkadder(item**head,int n)
{
    item*temp=(item*)malloc(sizeof(item));
    temp->val=n;
    temp->next=NULL;
    if(*head==NULL)
        *head=temp;
    else
    {
        item*trav= *head;
        while(trav->next!=NULL)
            trav=trav->next;
        trav->next=temp;
    }
}

void display(item*head)
{
    item*tpr=head;
    while (head!=NULL)
    {
        printf("%d ",head->val);
        head=head->next;
        if(head==tpr)
            break;
    }
    printf("\n");
}

void concatenation(item**ptr1,item**ptr2)
{
    if(*ptr2==NULL)
        return;
    if(*ptr1==NULL)
    {
        *ptr1=*ptr2;
        return;
    }
    item*tmp=*ptr1;
    while(tmp->next!=NULL)
        tmp=tmp->next;
    tmp->next=*ptr2;

    *ptr2=NULL;
}

void reverser(item**head)
{
    if((*head)->next==NULL)
        return;
    item*tp1=*head;
    item*tp2=tp1->next;
    item*tp3=tp2->next;
        while(tp2!=NULL)
        {
            tp2->next=tp1;
            tp1=tp2;
            tp2=tp3;
            if(tp3!=NULL)
                tp3=tp3->next;
        }
    (*head)->next=NULL;
    *head=tp1;
}

void circulist(item**head,int n)
{
    item*temp=(item*)malloc(sizeof(item));
    temp->val=n;
    temp->next=NULL;
    if(*head==NULL)
    {
        *head=temp;
        temp->next=*head;
    }
    else
    {
        item *trav = *head;
        while((trav->next)!=(*head))
            trav=trav->next;
        trav->next=temp;
        temp->next=*head;
    }
}

void circudel(item**head)
{
    item*tphead=*head;
    item*cur=tphead->next;
    item*temp;
    while(cur!=(*head))
    {
        tphead->next=cur->next;
        temp=cur;
        cur=cur->next;
        free(temp);
    }
    *head=NULL;
    free(cur);
}