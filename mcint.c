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
	float fx=5*x + 7;
	return fx;
}
main()
{
	FILE *fp1=NULL;
	fp1=fopen("mcint.txt","w");
	int m,c=0,a=9999,N;
	int i=0,rn1=9865,rn2=3345,M=0;
	float z1,z2,s,x1,y1,y2,l,area,erp,f;
	m=pow(2,17);
	for(N=1000;N<=10000;N+=10)
	{
		for(i=0;i<=N;i++)
		{
			rn1=randx(rn1,c,m,a);
			rn2=randx(rn2,c,m,a);
			z1=(float)rn1/(float)m;
			z2=(float)rn2/(float)m;
			x1= 10*z1;
			y1= 57*z2;
			f = f1(x1);
			if((f>=y1))
			{
				M++;
			}
		}
		area = 570*(float)M/(float)N;
		fprintf(fp1,"%d	%f\n",N,area);
		M=0;
	}
}
