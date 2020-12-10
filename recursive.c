#include<stdio.h>

void recur();

int main()
{
	recur();
	return 0;
}

void recur()
{
	printf("Start\n");
	recur();
	printf("End\n");
}
