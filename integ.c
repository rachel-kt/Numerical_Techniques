#include<stdio.h>
#include<math.h>
float f(float x)
{
	return (1/((1+x)*(1+x)*(1+x)));
}
main()
{
	float simpson(float a,float b,int n);
	float a,b,integral,n;
	printf("\ninput a,b,n(even)\n");
	scanf("%f	%f	%d",&a,&b,&n);
	integral=simpson(1,2,100);
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
