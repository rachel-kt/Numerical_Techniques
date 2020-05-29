/************************* LINEAR REGRESSION **************************/

#include<stdio.h>
#include<math.h>
int randx(int rn,int c,int m,int a)
{
	rn = (a*rn + c)%m;
	return rn;
}
main()
{
	FILE *fp1=NULL;
	fp1=fopen("linfit.txt","w");
	int m,c=0,a=9999,N = 10000;
	int i=0,rn1=9865,rn2=3345;
	float z1,z2,x1,y1,y[50],y_fit[50],x[50],M=1.8,C=13,d[50],mean = 0,s=0,sx=0,sy=0,sxx=0,sxy=0,delta,A,b;
	x[0]=15;
	float pi=4.0*atan(1.0);
	m=pow(2,17);

/****************************** initialisation ************************/

	for(i=0;i<50;i++)
	{
		y[i]= 0;
		y_fit[i]= 0;
		x[i]= 0;
		d[i]= 0;
	}

/****************************** generating data **********************/
	for(i=0;i<20;i++)
	{
		rn1=randx(rn1,c,m,a);
		z1=(float)rn1/(float)m;
		y1 = 20*z1 - 10;
		y[i] = M * x[i] + C + y1;
		x[i+1] = x[i] + 10;
		d[i] = y1;
		//fprintf(fp1,"%f	%f\n",x[i],y[i]);
		mean+=y[i];
	}
	mean = mean/20;
	printf("\nMEAN = %f",mean);
/******************** calculating coefficients ********************/
	/*for(i=0;i<20;i++)
	{
		d[i] = y[i] - mean;
		//printf("%f\n",d[i]);
	}*/
	for(i=0;i<20;i++)
	{
		s+=1/(d[i]*d[i]);
		sx+=x[i]/(d[i]*d[i]);
		sy+=y[i]/(d[i]*d[i]);
		sxx+=(x[i]*x[i])/(d[i]*d[i]);
		sxy+=(x[i]*y[i])/(d[i]*d[i]);
	}
	delta = (s*sxx - sx*sx);
	A = (sxx*sy - sx*sxy)/delta;
	b = (s*sxy - sx*sy)/delta;

	printf("\nThe value of slope is %f\nThe value of constant is %f",b,A);

/**************** generating new data for fit ********************/

	for(i=0;i<20;i++)
	{
		y_fit[i] = b*x[i] + A;
		fprintf(fp1,"%f	%f	%f	%f\n",x[i],y[i],d[i],y_fit[i]);
	}
}

