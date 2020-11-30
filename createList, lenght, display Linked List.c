/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *link;
};
struct Node *root = NULL;

void createList ();
int length ();
void display ();

int
main ()
{
  int len;
  createList ();

  len = length ();
  printf ("\nlength is : %d \n", len);

  display ();
  return 0;
}

void
createList ()
{
  struct Node *new, *last;
  while (1)
    {
      new = (struct Node *) malloc (sizeof (struct Node));

      printf ("\nEnter node data : ");
      scanf ("%d", &new->data);

      if (root == NULL)
	{
	  root = new;
	  last = new;
	}
      else
	{
	  last->link = new;
	  last = new;
	}
      printf ("\nDo you want to add another node(y/n) : ");
      if (getche () == 'n')
	{
	  last->link = NULL;
	  break;
	}
    }
}

int
length ()
{
  int count = 0;
  struct Node *node = root;
  while (node)
    {
      ++count;
      node = node->link;
    }
  return count;
}

void
display ()
{
  if (root == NULL)
    {
      printf ("List is Empty\n");
    }
  else
    {
      struct Node *node = root;
      printf ("List elements :\n");
      while (node)
	{
	  printf ("%d \n", node->data);
	  node = node->link;
	}
    }
}
