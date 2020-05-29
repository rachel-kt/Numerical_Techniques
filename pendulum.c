#include<stdio.h>
#include<math.h>


float f1(float z, float th)
{
	return (z);
}
float f2(float z, float th)
{
	return (-sin(th));
}
main()
{
	float t=0,h=0.0005,a,k1,k2,k3,k4,m1,m2,m3,m4,z=0,th,tf,y,pi;
	int i,n;
	FILE *fp=NULL;
	fp=fopen("pendulum.txt","w");
	printf("Enter the intial value for angular displacement:\n");
	scanf("%f",&th);
	pi=4.0*atan(1.0);
	tf=8*pi;
	do
	{
		k1=h*f1(z,th);
		m1=h*f2(z,th);

		k2=h*f1(z+k1/2.0, th+m1/2.0);
		m2=h*f2(z+k1/2.0, th+m1/2.0);

		k3=h*f1(z+k2/2.0, th+m2/2.0);
		m3=h*f2(z+k2/2.0, th+m2/2.0);

		k4=h*f1(z+k3,th+m3);
		m4=h*f2(z+k3,th+m3);	

		th+=(k1+2*k2+2*k3+k4)/6.0;	
		z+=(m1+2*m2+2*m3+m4)/6.0;

		t+=h;
		fprintf(fp,"%f	%f\n",t,th);
	}while(t<=8*pi);
	printf("DONE\n");
}
