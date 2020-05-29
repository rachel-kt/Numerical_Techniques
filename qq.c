#include<stdio.h>
#include<math.h>
int fact(int l)
{
	if(l!=0)
	l=l*fact(l-1);
	return(l);
}
main()
{
	float x,t,sum,j;
	int i,n;
//	FILE *fp=NULL;
//	fp=fopen("ser3.txt","w");
//	printf("Enter the value of n\n");
	scanf("%d",&n);printf("ok");
		i=1; 
		t=1/fact(n);
		sum=1;
}
