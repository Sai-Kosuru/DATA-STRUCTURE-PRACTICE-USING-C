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
void display ();
int lenght ();


int
main ()
{
  int len, ch;
  while (1)
    {
      printf ("1. Append\n");
      printf ("2. lenght\n");
      printf ("3. display\n");
      printf ("4. exit\n");

      printf ("enter your choice");
      scanf ("%d", &ch);

      switch (ch)
	{
	case 1:
	  append ();
	  break;

	case 2:
	  len = lenght ();
	  printf ("the lenght is %d", len);
	  break;

	case 3:
	  display ();
	  break;

	case 4:
	  exit (1);

	default:
	  printf ("invalid choice\n");
	}

    }
  return 0;
}

void
append ()
{

  struct Node *new;
  new = (struct Node *) malloc (sizeof (struct Node));

  printf ("enter node data\n");
  scanf ("%d", &new->data);

  new->link = NULL;

  if (root == NULL)
    {
      root = new;

    }
  else
    {
      struct Node *last = root;
      while (last->link != NULL)
	{
	  last = last->link;

	}
      last->link = new;
    }

}

int
lenght ()
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
      printf ("list is empty");

    }
  else
    {
      struct Node *node = root;
      while (node)
	{
	  printf ("%d\n", node->data);
	  node = node->link;
	}
    }
}
