#include<stdio.h>
#include<math.h>
float f(float r, float E)
{
	return (1/(r*r*pow(((2*E)+(2/r)-(1/r*r)),0.5)));
}
float quad(float a,float b, float E)
{

	float f(float r, float E);	
	int i,n,k,l,j=100;
	float y,z,x[100],w[100];
	float s;
	for(i=0;i<j;i++)
	{
		z=(a+b)/2.0 + ((b-a)/2.0)*x[i];
		y=f(z,E);
		s+=w[i]*y;
	}
	s*=((b-a)/2.0);
	return s;
}
main()
{
	
	float quad(float a,float b, float E);
	float r0,rm,theta,x[100],w[100],E,R;
	int n=10,k,l;
	#include<gauss.c>
	for(k=5;k<100;k++)
	{
		x[k]=x[k-5];
		w[k]=w[k-5];
	}
	FILE *fp=NULL;
	fp=fopen("quad.txt","w");
	printf("\ninput a,b\n");
	scanf("%f	%f", &r0,&rm);
	printf("\ninput value of E\n");
	scanf("%f",&E);
	
	for(R=r0;R<=rm;R+=0.1)
	{	
		theta=quad(r0,R,E);
		fprintf(fp,"\n%f	%f\n",R,theta);
	}
}
