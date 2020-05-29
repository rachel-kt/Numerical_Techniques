#include<stdio.h>
#include<math.h>
#define pi 3.14159
float u[10],ud[10];
int i,n;
float f(float x,int d)
{	
	u[0]=1;
	u[1]=2*x;
	ud[0]=0;
	ud[1]=2;
	for(i=2;i<=d;i++)
	{
		for(n=1;n<i;n++)
		{
			u[n+1]=2*x*u[n]-u[n-1];
		}
	}
	return(u[d]);
}
main()
{
	float x,xl,xr,xm,acc=0.000001, xinc=0.1,z,min,max,x1,x2;
	int k=0,n,i;
	FILE *fp1;
	FILE *fp2;
	fp1=fopen("bisec1.txt","w");
	fp2=fopen("bisec2.txt","w");
	printf("Enter the range of x\n");
	scanf("%f %f",&min,&max);
	for (x=min;x<=max;x=x+0.1)
	{
		fprintf(fp1,"%f \t %f\n",x,f(x,4));
	}
	for(x=min;x<=(max-xinc);x+=xinc)
	{
		if(f(x,4)*f(x+xinc,4)<0)
			{
				xl=x;
				xr=x+xinc;
				do
				{
					xm=(xl+xr)/2.0;
					if(f(xm,4)*f(xl,4)>0)
					xl=xm;
					else if(f(xm,4)*f(xl,4)<0)
					xr=xm;
					z=fabs((xl-xr)/(xl+xr));
					//fprintf(fp2,"xm=%f f(xm)=%f z=%f acc=%f\n", xm,f(xm),z,acc);
				}
				while((z>acc));
				fprintf(fp2,"\nroot=%f f(xm)=%f z=%f acc=%f\n\n",xm,f(xm,4),z,acc);
				printf("\nroot=%f f(xm)=%f z=%f acc=%f\n\n",xm,f(xm,4),z,acc);
				k++;				
			}
	}
	fprintf(fp2,"The no of roots is %d!",k);
	printf("The no of roots is %d!\n",k);
	fclose(fp1);
	fclose(fp2);
}
