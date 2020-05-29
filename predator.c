#include<stdio.h>
#include<math.h>

float g1=0.25,g2=0.01,g4=0.01;

float py(float t1,float x, float y1)
{
	return (g1*x-g2*x*y1);
}
float pd(float t1,float x, float y1)
{
	return (-y1+g4*x*y1);
}
main()
{
	float x=100,ti,tf,y,h=0.05,a,k1,k2,k3,k4,m1,m2,m3,m4,z,t=0;
	int i,n;
	FILE *fp=NULL;
	fp=fopen("prey.txt","w");
	printf("Enter the intial value for predator y(0):\n");
	scanf("%f",&y);
	do
	{
		k1=h*py(t,x,y);
		m1=h*pd(t,x,y);

		k2=h*py(t+h/2.0,x+k1/2.0,y+m1/2.0);
		m2=h*pd(t+h/2.0,x+k1/2.0,y+m1/2.0);

		k3=h*py(t+h/2.0,x+k2/2.0,y+m2/2.0);
		m3=h*pd(t+h/2.0,x+k2/2.0,y+m2/2.0);

		k4=h*py(t+h,x+k3,y+m3);
		m4=h*pd(t+h,x+k3,y+m3);	
		
		t+=h;

		x+=(k1+2*k2+2*k3+k4)/6.0;	
		y+=(m1+2*m2+2*m3+m4)/6.0;
		fprintf(fp,"%f	%f\n",x,y);
	}while(t<=20);
	printf("DONE\n");
}
