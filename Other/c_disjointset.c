#include<stdio.h>
#include<stdlib.h>

int arr[10] = {1,2,3,4,5,6,7,8,9,0};

struct set_header;
struct item;

struct set_header
{
	struct item *head;
	struct item *tail;
	int size;	
};

struct item
{
	int value;
	struct set_header *backptr;
	struct item *next;
};

struct set_header *disjointsetDS[10];

struct set_header* make_set(int element)
{
	struct set_header *temp_h = (struct set_header *) malloc(sizeof(struct set_header));
	struct item *temp_i = (struct item *) malloc(sizeof(struct item));
	temp_i->value = element;
	temp_i->next = NULL;
	temp_i->backptr = temp_h;
	temp_h->head = temp_i;
	temp_h->tail = temp_i;
	temp_h->size = 1;
	return temp_h;
}

void displaySet(struct set_header s1)
{
	struct item *temp = s1.head;
	while(temp != NULL)
	{
		printf("\n%d\n",temp->value);
		temp = temp->next;
	}
}

struct item * find_set(struct item i)
{
	struct set_header *temp1 = i.backptr;
	struct item *temp2 = temp1->head;
	return temp2;
}

struct set_header ds_union(struct set_header s1, struct set_header s2)
{
	if(s1.size>=s2.size)
	{
		s1.size +=s2.size;
		s1.tail->next = s2.head;
		s1.tail = s2.tail;
		struct item *temp = s2.head;
		while(temp!=NULL)
		{
			temp->backptr = &s1;
			temp = temp->next;
		}
		return s1;
	}
	else
	{
		s2.size+=s1.size;
		s2.tail->next = s1.head;
		s2.tail = s1.tail;
		struct item *temp = s1.head;
		while(temp!=NULL)
		{
			temp->backptr = &s2;
			temp = temp->next;
		}
		return s2;
	}
}


int main()
{
	int i;
	for(i = 0; i<10; i++)
	{
		disjointsetDS[i] = make_set(arr[i]);
	}
	
	for(i=0;i<10;i++)
	{
		displaySet(*disjointsetDS[i]);
	}
	
	struct item *temp1 = find_set(*(disjointsetDS[2]->head));
	printf("\n%d\n",temp1->value);
	
	printf("\n\nAfter union of s2 and s5");
	struct set_header temp_union_set = ds_union(*disjointsetDS[2], *disjointsetDS[5]);
	
	displaySet(temp_union_set);
	
	set_header temp_union_set = ds_union(*disjointsetDS[2], *disjointsetDS[5]);
		
	return 0;
}
