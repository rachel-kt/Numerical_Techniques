#include<stdio.h>
#include<math.h>
int gamma(int l)
{
	if(l>0)
	return l*fact(l-1);
	else
	return 1;
}
main()
{
	int n,f;
	printf("Enter the value of n:\n");
	scanf("%d",&n);
	f=fact(n);
	printf("Factorial of %d is %d\n",n,f);
}
