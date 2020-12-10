#include<stdio.h>

int fact(int);

int main()
{
	int res;
	res = fact(4);
	printf("the factorial is: %d\n",res);
	return 0;
}

int fact(int n)
{
	if(n == 0)
		return 1;
	else
		return n*fact(n-1);
}
