#include<stdio.h>
#include<stdlib.h>

int stack[5], top=-1, size=5;

int main()
{

int ch,ele;

while(1)
{
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Peek\n");
	printf("4. Traverse\n");
	printf("5. Quit\n");

	printf("Enter Chioce\n");
	scanf("%d",&ch);

	if(ch==1)
	{
		printf("Enter element: ");
		scanf("%d",&ele);
	}

	switch(ch)
	{
		case 1: if(top==size-1)
		printf("Stack is OverFlow\n\n");
		else
		{
			stack[++top]=ele;
			printf("Element pushed onto stack\n\n");
		}
		break;

		case 2: if(top==-1)
			{
				printf("stack Underflow");
			}
			else
			{
				printf("Popped item is: %d\n\n", stack[top--]);
			}
			break;

		case 3: if(top==-1)
			{
				printf("Stack is Underflow\n\n");
			}
			else
			{
				printf("Peek element is %d\n\n",stack[top]);
			}
			break;
			
		case 4: if(top==-1)
			{
				printf("Stack has no Elements\n");
			}
			else
			{
				int i;
				printf("Stack elements:\n");
				for(i=top;i>=0;i--)
					printf("%d\n",stack[i]);
			}
			break;
			
			case 5: exit(1);

			default: printf("invalid choice\n");
			}
		}
return 0;
}
