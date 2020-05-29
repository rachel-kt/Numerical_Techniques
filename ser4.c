#include<stdio.h>
#include<math.h>
#define pi 3.14159
main()
{
	float x,t,sum,f;
	int i;
	FILE *fp=NULL;
	fp=fopen("ser4.txt","w");
	//printf("Enter the value of n\n");
	//scanf("%d",&n);
	for(x=0;x<=1;x+=0.1)
	{
		i=1; 
		t=x;
		sum=t;
		do
		{
			t*=-(x*x*x*x)*pi*pi/(4.*i+1);
			sum+=t;
			i+=1;
		}while(fabs(t/sum)>1.0e-4);
		f=cos(pi*x*x/2.)*sum;
		printf("x= %f, f = %f\n",x,f);
		fprintf(fp,"%f \t %f\n",x,f);
	}

}
