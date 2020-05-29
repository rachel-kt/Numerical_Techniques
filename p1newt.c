#include<stdio.h>
#include<math.h>
float f(float x, float a, float b)
{
	return(exp(a*x)-b*x*x);
}
float fd(float x, float a, float b)
{
	return(a*exp(a*x)-2*b*x);
}
main()
{
	printf("****************************** NEWTON RAPHSON ************************************\n");
	float x,xl,xr,x3,acc=0.000001, xinc=0.5,z,min,max,x1,x2,xp,h,A,B;
	int n,i;
	printf("Enter the range of x and the values of a nad b:\n");
	scanf("%f %f %f %f",&min,&max,&A,&B);
	for (x=min;x<=max;x=x+0.1)
	{
		printf("%f \t %f\n",x,f(x,A,B));
	}
	printf("input no. of roots");
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		printf("\ninput your approximation\n");
		scanf("%f",&x1);
		do
		{
			h=-f(x1,A,B)/fd(x1,A,B);
			x1=x1+h;
			z=fabs(h/x1);
			printf("x=%f f(x)=%f z=%f acc=%f\n", x1,f(x1,A,B),z,acc);
		}
		while((z>acc)||(f(x1,A,B)==0));
		printf("\nroot=%f f(x)=%f z=%f acc=%f\n\n",x1,f(x1,A,B),z,acc);				
	}
}
