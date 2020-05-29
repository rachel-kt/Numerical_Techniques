#include<stdio.h>
#include<math.h>
main()
{
	float x,t,sum;
	int i;
	float PI=4.0*atan(1.0);
	FILE *fp=NULL;
	fp=fopen("sineseries.txt","w");
	for(x=0;x<=2*PI;x+=0.1)
	{
		i=1; 
		sum=t=x;
		do
		{
			t*=-(x*x)/((2*i)+1)*(2*i);
			sum+=t;
			i+=1;
		}while(fabs(t/sum)>1.0e-4);
		printf("x=%f, sin(x) = %f\n",x,sum);
		fprintf(fp,"%f \t %f\n",x,sum);
	}
}


