#include<stdio.h>
#include<math.h>
float f(float x)
{
	return(sin(x)-x*cos(x));
}

main()
{
	printf("******************************SECANT METHOD************************************\n");
	float x,xl,xr,x3,acc=0.000001, xinc=0.5,z,min,max,x1,x2,xp;
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
		do
		{
			xp=x2;
			x3=(f(x2)*x1-f(x1)*x2)/(f(x2)-f(x1));
			x1=x2;
			x2=x3;
			z=fabs(xp-x3);
			printf("x3=%f f(x3)=%f z=%f acc=%f\n", x3,f(x3),z,acc);
		}
		while((z>acc)||(f(x3)==0));
		printf("\nroot=%f f(x3)=%f z=%f acc=%f\n\n",x3,f(x3),z,acc);				
	}
}
