#include<stdio.h>
#include<math.h>
float f(float x, float a, float b)
{
	return(exp(a*x)-b*x*x);
}

main()
{
	float x,xl,xr,xm,acc=0.000001, xinc=0.5,z,min,max,x1,x2,a1,b1;
	int n,i;
	float f(float x, float a, float b);
	printf("Enter the range of x\n");
	scanf("%f %f",&min,&max);
	printf("Enter the values for a and b:\n");
	scanf("%f %f",&a1,&b1);
	for (x=min;x<=max;x=x+0.1)
	{
		printf("%f \t %f\n",x,f(x,a1,b1));
	}
	printf("input no. of roots");
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		printf("\ninput x1, x2\n");
		scanf("%f %f",&x1,&x2);
		for(x=x1;x<=x2;x+=xinc)
		{
			if(f(x,a1,b1)*f(x+xinc,a1,b1)<0)
			{
				xl=x;
				xr=x+xinc;
				do
				{
					xm=(xl+xr)/2.0;
					if(f(xm,a1,b1)*f(xl,a1,b1)>0)
					xl=xm;
					else if(f(xm,a1,b1)*f(xl,a1,b1)<0)
					xr=xm;
					z=fabs((xl-xr)/(xl+xr));
					printf("xm=%f f(xm)=%f z=%f acc=%f\n", xm,f(xm,a1,b1),z,acc);
				}
				while((z>acc));
				printf("\nroot=%f f(xm)=%f z=%f acc=%f\n\n",xm,f(xm,a1,b1),z,acc);				
			}
		}
	}
}
