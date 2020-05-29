/***************** INTEGRATION ******************/
#include<stdio.h>
#include<math.h>
int randx(int rn,int c,int m,int a)
{
	rn = (a*rn + c)%m;
	return rn;
}
float f1(float x)
{
	float fx= exp(x);
	return fx;
}
main()
{
	FILE *fp1=NULL;
	fp1=fopen("accrej2.txt","w");
	FILE *fp2=NULL;
	fp2=fopen("acc2.txt","w");
	int m,c=0,a=9999,N=100000;
	int i=0,rn1=9865,rn2=3345,M[13],C[1000];
	for(i=0;i<10;i++)
	{
		C[i]=0;
	}
	float z,z1,z2,s,x,chx,x1,y,y1,k,y2,l,area,erp,f,area_sum=0, avg_area;
	m=pow(2,17);
	k=0;
	for(i=0;i<=N;i++)
	{
			rn1=randx(rn1,c,m,a);
			z1=(float)rn1/(float)m;
			y= 10*z1;			
			f = f1(y);
			chx = exp(10) + 0.2;
			rn2=randx(rn2,c,m,a);
			z2 = (float)rn2/(float)m;
			y1= z2*chx;
			if(z2*chx <= f)
			{
				C[(int)y]++;
				fprintf(fp2,"%f\n",y);
			}
	}
	for(i=0;i<10;i++)
	{
		fprintf(fp1,"%d	%d\n",i,C[i]);
	}
}

