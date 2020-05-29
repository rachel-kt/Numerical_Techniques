/* trigtable.c - Program to tabulate values of sinx cosx and tanx */
#include<stdio.h>
#include<math.h>
#define pi 3.14159
main()
{
	float x,s,c,t;
	FILE *fp = NULL;
	fp=fopen("trigt.txt","w");
	for(x=-2*pi;x<2*pi;x+=0.02)
	{
	  	s = sin(x);
		c = cos(x);
		t = tan(x);
		printf("%f \t %f \t %f \t %f\n",x,s,c,t);
		fprintf(fp,"%f \t %f \t %f \t %f\n",x,s,c,t);
	}
fclose(fp);
}
