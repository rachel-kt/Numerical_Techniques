#include<stdio.h>
#include<math.h>
#include<cp/usr/include/gauss.c> 
float f(float x)
{
	return (1/((+x)*(+x)*(+x)));
}
main()
{
	float simpson(float a,float b,int n);
	float a,b,integral,n;
	printf("\ninput a,b,n(even)\n");
	scanf("%f,%f,%d", &a,&b,&n);
	integral=simpson(a,b,n);
	printf("\nIntegral = %f\n",integral);
}
float simpson(float a,float b, int n)
{
	int i;
	float x,y;
	float h=(b-a)/n;
	float s=f(a)+f(b);
	for(i=1;i<n;i+=2)
	{
		x=a+i*h;
		y=f(x);
		s+=4*f(x);
	}
	for(i=2;i<n;i+=2)
	{
		x=a+i*h;
		y=f(x);
		s+=2*f(x);
	}
	s*=h/3;
	return s;
}
