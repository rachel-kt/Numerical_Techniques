/***************** INTEGRATION ******************/
#include<stdio.h>
#include<math.h>
#define pi 3.14159
int randx(int rn,int c,int m,int a)
{
	rn = (a*rn + c)%m;
	return rn;
}
float f1(float x)
{
	float fx=(exp(-pow((x-0),2)/(2)))/(2*pi);
	return fx;
}
main()
{
	FILE *fp1=NULL;
	fp1=fopen("mcint2.txt","w");
	FILE *fp2=NULL;
	fp2=fopen("fn.txt","w");
	int m,c=0,a=9999,N;
	int i=0,rn1=9865,rn2=3345,M=0;
	float z,z1,z2,s,x,x1,y1,y2,l,area,erp,f,area_sum=0, avg_area;
	m=31927173;
	/*for(x=2;x<=10;x+=0.05)
	{
		z=f1(x);
		fprintf(fp2,"%f	%f\n",x,z);
	}
	*/
	for(N=1000;N<=10000;N+=10)
	{	
		for(i=0;i<=N;i++)
		{
			rn1=randx(rn1,c,m,a);
			rn2=randx(rn2,c,m,a);
			z1=(float)rn1/(float)m;
			z2=(float)rn2/(float)m;
			x1= 2*z1 - 1 ;	
			y1= (1/(2*pi))*z2;
			f = f1(x1);
			if(f>=y1)
			{
				M++;
			}
		}
		area = (2*(1/(2*pi)))*(float)M/(float)N;
		fprintf(fp1,"%d	%f\n",N,area);
		area_sum+=area;
		M=0;
	}
	avg_area = area_sum/((10000-1000)/10);
	printf("\nThe area under the curve is %f\n",avg_area);
}
