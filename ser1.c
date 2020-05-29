#include<stdio.h>
#include<math.h>
main()
{
	float t,x,sum;
	int n,i;
	FILE *fp=NULL;
	fp=fopen("series1.txt","w");
	printf("Enter the value of n and x \n");
	scanf("%d,%f",&n,&x);
	do
	{
		t=1;
		sum=1;	
		for(i=1;i<n;i++)
		{
			sum+=t;
			t*=(1/x);
		}
		printf("\nx=%6.2f n=%d sum=%12.5e",x,n,sum);
		fprintf(fp,"%d \t %12.5e\n",n,sum);
		n--;
	}while(n>0);
}
