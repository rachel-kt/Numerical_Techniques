#include<stdio.h>
#include<math.h>
float f(float x, float y)
{
	return (x+y);
}
main()
{
	float x=1.0,xi,xf,y=1,h,a,k1,k2,k3,k4;
	int i,n;
	FILE *fp=NULL;
	FILE *fp1=NULL;
	fp1=fopen("diffall.txt","w");
	fp=fopen("diff1.txt","w");
	printf("Enter the step size:\n");
	scanf("%f",&h);

//********** EULER'S METHOD ************

	xi=1.0;
	xf=5.0;
	do
	{
		y=y+h*(x+y);
		a=-x-1+exp(x);
		x+=h;
		fprintf(fp,"%f	%f	%f\n",x,y,a);
	}while(x<=xf);
	printf("DONE!");

//************ RUNGE KUTTA METHOD *********

	n=(xf-xi)/h;
	for(i=1;i<=n;++i)
	{
		k1=h*f(x,y);
		k2=h*f(x+h/2.0,y+k1/2.0);
		k3=h*f(x+h/2.0,y+k2/2.0);
		k4=h*f(x+h,y+k3);
		x+=h;
		y+=(k1+2*k2+2*k3+k4)/6.0;
		fprintf(fp1,"%f	%f\n",x,y);
	}
}
