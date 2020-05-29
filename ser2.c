#include<stdio.h>
#include<math.h>
#define pi 3.14159
main()
{
	float x,t,sum;
	int i;
	FILE *fp=NULL;
	fp=fopen("cos.txt","w");
	for(x=0;x<=2*pi;x+=0.1)
	{
		i=1; 
		sum=t=1;
		do
		{
			t*=-(x*x)/((2*i-1)*(2*i));
			sum+=t;
			i+=1;
		}while(fabs(t/sum)>1.0e-4);
		printf("x=%f, cos(x) = %f\n",x,sum);
		fprintf(fp,"%f \t %f\n",x,sum);
	}
}

