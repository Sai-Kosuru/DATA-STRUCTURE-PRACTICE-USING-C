/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *link;
};
struct Node *root = NULL;

void append ();
void addFirst ();
int lenght ();
void display ();


int
main ()
{
  int ch, len;
  while (1)
    {
      printf ("1. Append\n");
      printf ("2. Add First\n");
      printf ("3. Lenght\n");
      printf ("4. Display\n");
      printf ("5. Quit\n");

      printf ("Enter your choice\n");
      scanf ("%d", &ch);

      switch (ch)
	{
	case 1:
	  append ();
	  break;

	case 2:
	  addFirst ();
	  break;

	case 3:
	  len = lenght ();
	  printf ("The lenght is %d\n", len);
	  break;

	case 4:
	  display ();
	  break;

	case 5:
	  exit (1);
	  break;

	default:
	  printf ("invalid choice\n");
	}
    }

  return 0;
}

void
append ()
{
  struct Node *node;
  node = (struct Node *) malloc (sizeof (struct Node));

  printf ("Enter data\n");
  scanf ("%d", &node->data);
  node->link = NULL;

  if (root == NULL)
    {
      root = node;
    }
  else
    {
      struct Node *new = root;
      while (new->link)
	{
	  new = new->link;
	}
      new->link = node;
    }
}

void
addFirst ()
{
  struct Node *node;
  node = (struct Node *) malloc (sizeof (struct Node));

  printf ("Enter node data\n");
  scanf ("%d", &node->data);
  node->link = root;
  root = node;
}

int
lenght ()
{
  struct Node *node = root;
  int count = 0;
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
  struct Node *node;
  if (root == NULL)
    {
      printf ("List is Empty\n");
    }
  else
    {
      node = root;
      while (node)
	{
	  printf ("%d", node->data);
	  node = node->link;
	}
    }
}
