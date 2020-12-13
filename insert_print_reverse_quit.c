#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* link;
};

struct Node* root = NULL;

void reverse(struct Node*);
struct Node* insert(struct Node*, int);
struct Node* newNode(int);
void print_forward(struct Node*);
void print(struct Node*);
void print_backward(struct Node*);
void print_reverse(struct Node*);

int main()
{
	int ch,ele;
	while(1)
	{
		printf("1. Insert\n");
		printf("2. Print Forward\n");
		printf("3. Print Backward\n");
		printf("4. Quit\n");
		printf("Enter Your Choice\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: printf("Enter element\n");
				scanf("%d",&ele);
				root = insert(root, ele);
				break;

			case 2: print_forward(root);
				break;
	
			case 3: print_backward(root);
				break;

			case 4: exit(1);
			
			default: printf("Invalid choice\n\n");
		}
	}
	return 0;
}	

struct Node* insert(struct Node* node, int ele)
{
	if(node == NULL)
	{
		return newNode(ele);
	}
	else
	{
		node->link = insert(node->link, ele);
	}
	return node;
}

struct Node* newNode(int data)
{
	struct Node* node;
	node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->link = NULL;
	return node;
}

void print_forward(struct Node* node)
{
	if(node == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		print(node);
	}
}

void print(struct Node* node)
{
	if(node == NULL)
	{
		return;
	}
	printf("%d\t",node->data);
	print(node->link);
}
				
void print_backward(struct Node* node)
{
	if(node == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		reverse(node);
	}
}

void reverse(struct Node* node)
{
	if(node == NULL)
	{
		return;
	}
		reverse(node->link);
		printf("%d\t",node->data);
}	





