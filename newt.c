#include<stdio.h>
#include<math.h>
float f(float x)
{
	return(sin(x)-x*cos(x));
}
float fd(float x)
{
	return(x*sin(x));
}
main()
{
	printf("****************************** NEWTON RAPHSON ************************************\n");
	float x,xl,xr,x3,acc=0.000001, xinc=0.5,z,min,max,x1,x2,xp,h;
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
		printf("\n input your approximation \n");
		scanf("%f",&x1);
		do
		{
			h=-f(x1)/fd(x1);
			x1=x1+h;
			z=fabs(h/x1);
			printf("x=%f f(x)=%f z=%f acc=%f\n", x1,f(x1),z,acc);
		}
		while((z>acc)||(f(x1)==0));
		printf("\nroot=%f f(x)=%f z=%f acc=%f\n\n",x1,f(x1),z,acc);				
	}
}
