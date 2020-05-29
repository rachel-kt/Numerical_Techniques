#include<stdio.h>
#include<math.h>
#define pi 3.14159
main()
{
	float a,b,c,x;
	int n;
	FILE *fp=NULL;
	fp= fopen("circle.txt","w");
	for(x=-(pi);x<=(pi);x=x+0.001*pi)
	{
		a=5+(3*sin(x));
		b=5+(3*cos(x));
		printf("%f \t %f\n",a,b);
		fprintf(fp,"%f \t %f\n",a,b);
	}
	fclose(fp);
}
