#include<stdio.h>
#include<stdbool.h>

int queue[10];
int front=-1, rear=-1;

bool empty();
bool full();
void size();
void push_front(int);
void push_back(int);
int pop_front();
int pop_back();
int front_fun();
int back_fun();

int main()
{
	push_back(10);
	push_back(20);
	push_back(30);
	push_back(40);
	push_back(10);
	push_back(20);
	push_back(30);
	push_back(40);
	size();
	
	push_front(5);
	push_front(6);
	push_front(7);
	size();
	
	printf("\nDeleted Item: %d\n",pop_front());
	printf("\nDeleted Item: %d\n",pop_front());
	size();
	printf("\nDeleted Item: %d\n",pop_back());
	printf("\nDeleted Item: %d\n",pop_back());
	printf("\nDeleted Item: %d\n",pop_back());
	printf("\nDeleted Item: %d\n",pop_back());
	size();
	
	printf("\nThe front element of the queue is : %d\n",front_fun());
	printf("\nThe back element of the queue is : %d\n",back_fun());

	return 0;
}

void push_back(int item)
{
	if(full())
	{
		printf("\nThe queue is full!!\n");
		return;
	}
	
	else if(front == rear)	
	{
		if(front ==-1)
		{
			front++;
			rear++;
		}
		else
			rear++;
		queue[rear] = item;
	}
	
	else if(front<rear)
	{
		if(rear < 9)
			rear++;
		else
			rear = 0;
		queue[rear] = item;
	}
	
	else
	{
		rear++;
		queue[rear] = item;
	}
}

void push_front(int item)
{
	if(full())
	{
		printf("\nThe queue is full!!\n");
		return;
	}
	
	else if(front == rear)	
	{
		if(front ==-1)
		{
			front=9;
			rear++;
		}
		else
			front--;
		queue[front] = item;
	}
	
	else if(front<rear)
	{
		if(front == 0)
		front=9;
		else
		front--;
			
		queue[front] = item;
	}
	
	else
	{
		if(front == 0)
		front=9;
		else
		front--;
		
		queue[front] = item;
	}
}

int pop_front()
{
	int temp = front;
	if(empty())
	{
		printf("\nThere is nothing to delete!!\n");
		return -1;
	}
	if(front==rear)
	{
		front = -1;
		rear = -1;
	}
	else
		front = (front+1) % 10;
	return queue[temp];
}

int pop_back()
{
	if(empty())
	{
		printf("\nThere is nothing to delete!!\n");
		return -1;
	}
	
	int temp = rear;
	
	if(front==rear)
	{
		front = -1;
		rear = -1;
	}
	else
	{
		if(rear==0)
		rear=9;
		
		rear--;
	}	
	return queue[temp];
}

int front_fun()
{
	if(empty())
	{
		printf("\nQueue is Empty!!\n");
		return -1;
	}
	return (queue[front]);
}
int back_fun()
{
	if(empty())
	{
		printf("\nQueue is Empty!!\n");
		return -1;
	}
	return (queue[rear]);
}

bool empty()
{
	if(front == -1 && rear == -1)
		return true;
	return false;
}

bool full()
{
	if(front == 0 && rear == 9)
		return true;
	if(rear == front-1)
		return true;
	return false;
}

void size()
{
	int i, num;
	if(front==-1 && rear==-1)
	{
		printf("\nQueue is empty!!\n");
		num=0;
		return;
	}
	if(front<= rear)
	{
		printf("\nThe queue contents are:\n");
		for(i=front;i<=rear;i++)
			printf("%d\t",queue[i]);
		printf("\nfront = %d and rear = %d\n",front,rear);
		num=rear-front+1;
	}
	else
	{
		printf("\nThe queue contents are:\n");
		for(i=front;i<=9;i++)
			printf("%d\t",queue[i]);
			
		for(i=0;i<=rear;i++)
			printf("%d\t",queue[i]);
			
		printf("\nfront = %d and rear = %d\n",front,rear);
		num=9+front-rear;
		
	}
	printf("\nThe total elements in the queue are : %d\n",num);
}

//end
