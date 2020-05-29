#include<stdio.h>
#include<math.h>
float f(float t, float x)
{
	return (x*t*t+t*t*sin(pow(t,3)));
}
main()
{
	float t=0,x=1.0,h=0.05,s,ti,tf,k1,k2,k3,k4;
	int i,n;
	FILE *res1;
	res1= fopen("res1.dat","w");
	FILE *res2;
	res2=fopen("res2.dat","w");
	FILE *res3;
	res3=fopen("res3.dat","w");
	ti=0;
	tf=1.0;
	do
	{
		x=x+h*(x*t*t +t*t*sin(pow(t,3)));
		t=t+h;
		fprintf(res1,"%f	%f\n",t,x);	
	}
	while(t<=tf);
	for(t=h;t<tf;t+=h)
	{
		s=-0.3*cos(pow(t,3))- 0.1*sin(pow(t,3))+1.0*exp(0.33*pow(t,3));
	fprintf(res2,"%f	%f\n",t,s);
	}
	n=(tf-ti)/h;
	for(i=1;i<=n;++i)
	{
		k1=h*f(t,x);
		k2=h*f(t+h/2.0,x+k1/2.0);
		k3=h*f(t+h/2.0,x+k2/2.0);
		k4=h*f(t+h,x+k3);
		t+=h;
		x+=(k1+2*k2+2*k3+k4)/6.0;
		fprintf(res3,"%f	%f\n",t,x);
	}
}







