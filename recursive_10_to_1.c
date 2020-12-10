#include<stdio.h>

void nums(int);

int main()
{
	nums(10);
	return 0;
}

void nums(int n)
{
	printf("%d\n",n);
	if(n>1)
		nums(n-1);
}

