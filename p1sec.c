#include<stdio.h>
#include<math.h>
float f(float x, float a, float b)
{
	return(exp(a*x)-b*x*x);
}
main()
{
	printf("******************************SECANT METHOD************************************\n");
	float x,xl,xr,x3,acc=0.000001, xinc=0.5,z,min,max,x1,x2,xp,A,B;
	int n,i;
	float f(float x, float a, float b);
	printf("Enter the range of x and values of a and b:\n");
	scanf("%f %f %f %f",&min,&max,&A,&B);
	for (x=min;x<=max;x=x+0.1)
	{
		printf("%f \t %f\n",x,f(x,A,B));
	}
	printf("input no. of roots\n");
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		printf("\ninput x1, x2\n");
		scanf("%f %f",&x1,&x2);
		do
		{
			xp=x2;
			x3=(f(x2,A,B)*x1-f(x1,A,B)*x2)/(f(x2,A,B)-f(x1,A,B));
			x1=x2;
			x2=x3;
			z=fabs(xp-x3);
			printf("x3=%f f(x3)=%f z=%f acc=%f\n", x3,f(x3,A,B),z,acc);
		}
		while((z>acc)||(f(x3,A,B)==0));
		printf("\nroot=%f f(x3)=%f z=%f acc=%f\n\n",x3,f(x3,A,B),z,acc);				
	}
}
