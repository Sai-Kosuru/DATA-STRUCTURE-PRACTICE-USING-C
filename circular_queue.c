#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int cqueue[SIZE];

int front = -1, rear = -1;

void enqueue(int);
int dequeue(void);
void display(void);
int underflow(void);
int overflow(void);

int main()
{
	int ch,item;
	printf("Circular Queue Operations\n");
	while(1)
	{
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		printf("Enter Your Choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: if(!overflow())
				{
					printf("Enter item to insert:");
					scanf("%d",&item);
					enqueue(item);	
				}
				else
				{
					printf("Queue Is Full\n");
				}
				break;

			case 2: if(!underflow())
				{
					int ele = dequeue();
					printf("Deleted: %d",ele);
				}
				else
				{
					printf("Queue is Empty\n");
				}
				break;

			case 3: if(!underflow())
				{
					printf("The queue is:\n");
					display();
				}
				else
				{
					printf("No elements to Display\n");
				}
				break;
			
			case 4: exit(1);

			default: printf("Invalid Choice\n");
		}
 	}
	return 0;
}

int underflow()
{
	if((front == -1) && (rear == -1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int overflow()
{
	if((front == 0 && rear == SIZE-1) || (front == rear+1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void enqueue(int item)
{
	if((front == -1) && (rear == -1))
	{
		front = 0;
		rear = 0;
	}
	else if(rear == SIZE-1)
	{
		rear = 0;
	}
	else
	{
		rear++;
	}
	cqueue[rear] = item;
	printf("Inserted: %d",item);
}

int dequeue()
{
	int item;
	item = cqueue[front];
	if(front == rear)
	{
		front = -1;
		rear = -1;
	}
	else if(front == SIZE-1)
	{
		front = 0;
	}
	else
	{
		front = front + 1;
	}
	return item;
}

void display()
{
	int i;
	if(front<=rear)
	{
		for(i = front; i <= rear; i++)
		{
			printf("Elements  %d : %d\n",i+1, cqueue[i]);
		}
	}
	else
	{
		for(i = front; i <= SIZE-1; i++)
		{
			printf("Elements %d : %d\n", i+1, cqueue[i]);
		}
		for(i = 0; i <= rear; i++)
		{
			printf("Elements %d : %d\n", i+1, cqueue[i]);
		}
	}
}
