#include<stdio.h>
#include<math.h>
#define pi 3.14159
main()
{
	float x,y,t,A,d,n;
	FILE *fp=NULL;
	fp= fopen("nplt.txt","w");
	printf("Please provide the following constants: A, d(provide multiple of pi), n\n");
	scanf("%f,%f,%f",&A,&d,&n);
	for(t=0;t<=(4*pi);t=t+0.001*pi)
	{
		x=sin(t);
		y=A*sin((n*t)+(d*pi));	
		fprintf(fp,"%f \t %f\n",x,y);
	}
	fclose(fp);
}
