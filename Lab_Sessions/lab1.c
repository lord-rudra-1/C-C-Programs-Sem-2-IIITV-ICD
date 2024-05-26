#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
    int roll_no;
    char name[20];
    struct student *next;
};

void display(struct student *ptr)
{
     while(ptr->next!=NULL)
     {
      printf("Roll No:%d\n",ptr->roll_no);
      printf("Name :%s\n",ptr->name);
      ptr=ptr->next;
      printf("\n");
     }
     printf("Roll No:%d\n",ptr->roll_no);
     printf("Name :%s\n",ptr->name);
     printf("\n");
}

void del(struct student *ptr)
{
    struct student *ptr2;
    printf("enter the roll no. whose data you want to delete");
    int item;
    scanf("%d",&item);
    while(ptr!=NULL)
     {
         if(ptr->roll_no==item){
         ptr2->next=ptr->next;
         printf("delete sucess\n\n");
         break;
         }
      ptr2=ptr;
      ptr=ptr->next;
     }
}

    
struct student* add()
{
    int i,n;
    
    printf("enter the no. of students");
    scanf("%d",&n);
    
    struct student *s[n];

    for(i=0; i<n;i++)
    {
         s[i]=(struct student*)malloc(sizeof(struct student));
    }
    
    for(i=0; i<n;i++)
    {
        printf("enter roll no.");
         scanf("%d",&s[i]->roll_no);
         printf("enter name ");
         scanf("%s",s[i]->name);
         s[i]->next=s[i+1];
    }
        s[n-1]->next = NULL;
        
    return s[0];
}

void search(struct student *ptr)
{
    int rol;
    printf("enter the roll_no for search\n");
    scanf("%d",&rol);
    
    while(ptr!=NULL)
     {
     if(ptr->roll_no==rol)
     {
      printf("Roll No:%d\n",ptr->roll_no);
      printf("Name :%s\n",ptr->name);
      printf("\n");
      break ;
      }
      else{
      printf("not found\n\n");
      }
      ptr=ptr->next;
     }
}

void insert(struct student *ptr)
{
    struct student *ptr2;
    int ind,i;
    struct student *s99=(struct student*)malloc(sizeof(struct student));
    printf("enter the index at which you want to insert\n");
    scanf("%d",&ind);
    printf("enter the name\n");
    scanf("%s",s99->name);
    printf("enter the roll no.\n");
    scanf("%d",&s99->roll_no);
    
    for(i=1;i<ind;i++){
    ptr=ptr->next;
    }
    ptr2=ptr->next;
    ptr->next= s99;
    s99->next= ptr2;
}
    
int main()
{
    
    struct student* ptr = add();
    
    display(ptr);
    
    del(ptr);
    
    display(ptr);
    
    search (ptr);
    
    insert (ptr);
    
    display(ptr);
         
    return 0;
}
