#include<stdio.h>
#include<math.h>

float f1(float t,float x, float y, float z)
{
	return (-10*(x-y));
}
float f2(float t,float x, float y, float z, float a)
{
	return (a*x - x*z - y);
}
float f3(float t,float x, float y, float z)
{
	return (x*y - 8*z/3);
}
main()
{
	float t=0,x=0.0,y=1,z=1,h=0.01,tf,k1,k2,k3,k4,m1,m2,m3,m4,p1,p2,p3,p4,a;
	int i,n;
	FILE *fp=NULL;
	fp=fopen("numint.txt","w");
	printf("Enter the value for a:\n");
	scanf("%f",&a);
	tf=20.0;
	do
	{
		k1=h*f1(t,x,y,z);
		m1=h*f2(t,x,y,z,a);		
		p1=h*f3(t,x,y,z);

		k2=h*f1(t+h/2.0,x+k1/2.0,y+m1/2.0,z+p1/2.0);
		m2=h*f2(t+h/2.0,x+k1/2.0,y+m1/2.0,z+p1/2.0,a);
		p2=h*f3(t+h/2.0,x+k1/2.0,y+m1/2.0,z+p1/2.0);

		k3=h*f1(t+h/2.0,x+k2/2.0,y+m2/2.0,z+p2/2.0);
		m3=h*f2(t+h/2.0,x+k2/2.0,y+m2/2.0,z+p2/2.0,a);
		p3=h*f3(t+h/2.0,x+k2/2.0,y+m2/2.0,z+p2/2.0);

		k4=h*f1(t+h,x+k3,y+m3,z+p3);
		m4=h*f2(t+h,x+k3,y+m3,z+p3,a);
		p4=h*f3(t+h,x+k3,y+m3,z+p3);	
		
		t+=h;

		x+=(k1+2*k2+2*k3+k4)/6.0;	
		y+=(m1+2*m2+2*m3+m4)/6.0;
		z+=(p1+2*p2+2*p3+p4)/6.0;
		fprintf(fp,"%f	%f	%f	%f\n",t,x,y,z);
	}while(t<=tf);
	printf("DONE\n");
}
