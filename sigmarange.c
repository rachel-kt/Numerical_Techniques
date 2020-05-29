/***************** GAUSSIAN DISTRIBUTION SIGMA RANGE ******************/
#include<stdio.h>
#include<math.h>
int randx(int rn,int c,int m,int a)
{
	rn = (a*rn + c)%m;
	return rn;
}
float f1(float x)
{
    float pi=4.0*atan(1.0);
	float fx=exp(-x*x/2.0)*(1/sqrt(2*pi));
	return fx;
}
main()
{
	FILE *fp1=NULL;
	fp1=fopen("sigmar.txt","w");
	FILE *fp2=NULL;
	fp2=fopen("fn.txt","w");
	int m,c=0,a=8444,N=50000;
	int i=0,rn1=4815,rn2=2315,M=0;
	float z,z1,z2,s,x,x1,y1,y2,l,area=0,erp,f,area_sum=0, avg_area;
	float pi=4.0*atan(1.0);
	m=pow(2,17);
	/*for(x=2;x<=10;x+=0.05)
	{
		z=f1(x);
		fprintf(fp2,"%f	%f\n",x,z);
	}
	*/
	//for(N=100;N<=10000;N+=10)
	//{
		for(i=1;i<=N;i++)
		{
			rn1=randx(rn1,c,m,a);
			rn2=randx(rn2,c,m,a);
			z1=(float)rn1/(float)m;
			z2=(float)rn2/(float)m;
			x1= 2*z1 - 1;
			y1= (1/sqrt(2*pi))*z2;
			f = f1(x1);
			if(f>y1)
			{
				M++;
			}
		}
		area = (2/sqrt(2*pi))*100*(float)M/(float)N;
        //printf("%d	%f\n",N,area);
		//area_sum+=area;
		//M=0;
	//}
	//avg_area = area_sum/((10000-100)/10);
	printf("\nThe area under the curve is %f\n",area);
}
