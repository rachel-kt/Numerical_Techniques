#include<stdio.h>
#include<math.h>
float f(float x)
{
	return(sin(x)-x*cos(x));
}

main()
{
	float x,xl,xr,x3,acc=0.000001, xinc=0.5,z,min,max,x1,x2;
	int n,i;
	float f(float x);
	printf("Enter the range of x\n");
	scanf("%f %f",&min,&max);
	for (x=min;x<=max;x=x+0.1)
	{
		printf("%f \t %f\n",x,f(x));
	}
	printf("input no. of roots");
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		printf("\ninput x1, x2\n");
		scanf("%f %f",&x1,&x2);
		for(x=x1;x<=x2;x+=xinc)
		{
			if(f(x)*f(x+xinc)<0)
			{
				xl=x;
				xr=x+xinc;
				do
				{
					x3=(f(x2)*x1-f(x1)*x2);
					x1=x2;
					x2=x3;
					z=fabs((xl-xr)/(xl+xr));
					printf("xm=%f f(xm)=%f z=%f acc=%f\n", xm,f(xm),z,acc);
				}
				while((z>acc));
				printf("\nroot=%f f(xm)=%f z=%f acc=%f\n\n",xm,f(xm),z,acc);				
			}
		}
	}
}
