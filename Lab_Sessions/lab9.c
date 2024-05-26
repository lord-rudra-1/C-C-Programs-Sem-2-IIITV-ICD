#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
    struct node *parent;
};
struct tt
{
    struct node *rootval;
};

void inorderwalk(struct node *x);
struct node *BSTminimum(struct node *x);
struct node *BSTsearch(struct node *x, int k);
void BST_insert(struct tt *T, struct node *z);
void BSTtransplant(struct tt *T,struct node *u,struct node *v);
void BSTdelete(struct tt *T, int k);

int main()
{
    struct tt rootc;
    rootc.rootval = NULL;

    int delno;
    char check='y',keyy;
    while (check=='y' || check=='Y')
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        printf("\nENTER THE VALUE TO ADD :  ");
        scanf("%d",&temp->key);
        temp->left = NULL;
        temp->right = NULL;
        BST_insert(&rootc, temp);
        printf("\nTHE INORDER WALK OF THE TREE IS :\n");
        inorderwalk(rootc.rootval);
        printf("\nENTER VALUE AGAIN ? (Y/N):  ");
        scanf(" %c",&check);
    }
    printf("\nTHE INORDER WALK OF THE TREE IS :\n");
    inorderwalk(rootc.rootval);
    
    check='y';
    while (check=='y' || check=='Y')
    {
        printf("\nENTER THE VALUE TO DELETE :  ");
        scanf("%d",&delno);
        BSTdelete(&rootc,delno);
        printf("\nTHE INORDER WALK OF THE TREE IS :\n");
        inorderwalk(rootc.rootval);
        printf("\nDELETE VALUE AGAIN ? (Y/N):  ");
        scanf(" %c",&check);
    } 
    printf("\nTHE INORDER WALK OF THE TREE IS :\n");
    inorderwalk(rootc.rootval);
    printf("\n\n");

    return 0;
}

void inorderwalk(struct node *x)
{
    if (x != NULL)
    {
        inorderwalk(x->left);
        printf("%d\t", x->key);
        inorderwalk(x->right);
    }
}

struct node *BSTminimum(struct node *x)
{
    while (x->left != NULL)
        x = x->left;
    return x;
}

struct node *BSTsearch(struct node *x, int k)
{
    while (x != NULL && x->key != k)
    {
        if (k < x->key)
            x = x->left;
        else
            x = x->right;
    }
    if (x != NULL)
        return x;
    else
    {
        printf("\nNOT FOUND\n");
        return NULL;
    }
}

void BST_insert(struct tt *T, struct node *z)
{
    struct node *x = T->rootval;
    struct node *y = NULL;

    while (x != NULL)
    {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if (y == NULL)
        T->rootval = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;
}

void BSTtransplant(struct tt *T,struct node *u,struct node *v)
{
    if(u->parent==NULL)
        T->rootval=v;
    else if(u==u->parent->left)
        u->parent->left=v;
    else
        u->parent->right=v;
    if(v!=NULL)
    	v->parent=u->parent;
}

void BSTdelete(struct tt *T, int k)
{
    struct node* x = T->rootval;
    struct node *z = BSTsearch(x, k);
    if(z != NULL) 
    {
        if(z->left == NULL)
            BSTtransplant(T, z, z->right);
        else if(z->right == NULL)
            BSTtransplant(T, z, z->left);
        else 
        {
            struct node* y = BSTminimum(z->right);
            if(y->parent != z) 
            {
                BSTtransplant(T, y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            BSTtransplant(T, z, y);
            y->left = z->left;
            y->left->parent = y;
        }
        free(z);
        printf("\nDelete Successful\n");
    } 
    else 
    {
        printf("\nDelete Unsuccessful: Node not found\n");
    }
}
