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
	fp1=fopen("corr.txt","w");
	FILE *fp2=NULL;
	fp2=fopen("acc2.txt","w");
	int m,c=0,a=9999,N=100000;
	int i=0,rn1=9865,rn2=3345,M[13],C[1000];
	float z,z1[1000],z2,s,x,chx,x1,y,y1,k,y2,l,area,erp,f,area_sum=0, avg_area;
	m=pow(2,17);
	k=0;
	for(i=0;i<1000;i++)
	{
			rn1=randx(rn1,c,m,a);
			z1[i]=(float)rn1/(float)m;
	}
	for(i=0;i<500;i++)
	{
		fprintf(fp1,"%f	%f\n",z1[i],z1[500+i]);
	}
}

