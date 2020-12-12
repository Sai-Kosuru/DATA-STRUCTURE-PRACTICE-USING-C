#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* link;
};

struct Node* root = NULL;

struct Node* insert(struct Node*, int);
struct Node* newNode(int);
void print(struct Node*);
void Reverse(struct Node*);

int main()
{
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);

	printf("Node elements are: \n");
	print(root);
	
	Reverse(root);
	printf("Node elements are: \n");
	print(root);
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

struct Node* newNode(int ele)
{
	struct Node* node;
	node = (struct Node*)malloc(sizeof(struct Node));
	node->data = ele;
	node->link = NULL;
	return node;
}

void print(struct Node* node)
{
	if(node == NULL)
	{
		return;
	}
	printf("%d\n",node->data);
	print(node->link);
}

void Reverse(struct Node* p)
{
	struct Node* q;
	if(p->link == NULL)
	{
		root = p;
		return;
	}
	Reverse(p->link);
	q = p->link;
	q->link = p;
	p->link = NULL;
}
