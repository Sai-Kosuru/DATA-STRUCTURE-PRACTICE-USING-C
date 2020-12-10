#include<stdio.h>

void abc(int);

int main()
{

	abc(3);
	return 0;
}

void abc(int x)
{
	printf("x: %d\n",x);
	if(x>0)
		abc(x-1);
}
