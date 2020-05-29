#include<stdio.h>
#include<math.h>
#define pi 3.14159
main()
{
	float x,t,sum,f;
	int i,n;
	FILE *fp=NULL;
	fp=fopen("ser5.txt","w");
	printf("Enter the value of n\n");
	scanf("%d",&n);
	for(x=0;x<=10;x+=0.01)
	{
		i=2; 
		t=1/(2*sqrt(pi));
		sum=t;
		do
		{
			t*=(x*x)/(i*(i-1)*4*(0.5-i/2));
			sum+=t;
			i+=2;
		}while(fabs(t/sum)>1.0e-4);
		printf("x= %f, sum = %f\n",x,sum);
		fprintf(fp,"%f \t %f\n",x,sum);
	}

}
