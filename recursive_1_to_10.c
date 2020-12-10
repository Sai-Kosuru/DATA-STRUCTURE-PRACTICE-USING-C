#include<stdio.h>

void nums(int);

int main()
{
	nums(1);
	return 0;
}

void nums(int n)
{
	printf("%d\n",n);
	if(n<10)
		nums(n+1);
}
