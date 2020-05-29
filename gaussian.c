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
	float fx= 1/(1+x*x);
	return fx;
}
main()
{
	FILE *fp1=NULL;
	fp1=fopen("gaussian.txt","w");
	FILE *fp2=NULL;
	fp2=fopen("gaussdata.txt","w");
	int m,c=0,a=9999,N=10000,k,n;
	int i=0,e,rn1=9865,rn2=3345,M[13],C[1000],j;
	int bin1[1000],bin2[1000];

	n = (30+30)/0.1;	// FOR X-RANGE -30 TO 30 AND BIN SIZE 0.1
	for(i=0;i<=n;i++)
	{
		bin1[i]=0;        // INITIALISATION OF BINS
		bin2[i]=0;
	}
	float z,z1,z2,s,x,chx,l[1000],x1,y,y1,y2,area,erp,f,rsqr,v1,v2,r,d;
	for(d=30,e=0;(d+0.1)>=-30;d=d-0.1,e++)
	{
		l[e]=d;  // ASSINING BIN CAPS TO VARIABLE l
	}
	m=pow(2,17);

/********************************* MAIN PROGRAM FOR GAUSSIAN DISTRIBUTION *****************************/
	for(j=0;j<=N;j++)
	{
		rn1=randx(rn1,c,m,a);
		z1=(float)rn1/(float)m;
		rn2=randx(rn2,c,m,a);
		z2 = (float)rn2/(float)m;
		v1 = 2*z1 - 1;
		v2 = 2*z2 - 1;
		r = v1*v1 + v2*v2;
		rsqr = r*r;
		if(rsqr>1)
		{;}
		else if(rsqr<1)
		{
			z1 = v1*sqrt(-2*(log(rsqr))/rsqr);
			z2 = v2*sqrt(-2*(log(rsqr))/rsqr);
			fprintf(fp2,"%f	%f\n",z1,z2);
			i=0;k=0;
/*------------------------------ SORTING THE POINT INTO BINS ---------------------------------*/
			for(i=0;i<=n;i++)
			{
				if((z1<=l[i]) && (z1>l[i+1]))
				{
					bin1[i]+=1;
				}
				if((z2<=l[i]) && (z2>l[i+1]))
				{
					bin2[i]+=1;
				}
			}
		}
	}
	for(i=0;i<=n;i++)
	{
		fprintf(fp1,"%f	%d	%d\n",l[i],bin1[i],bin2[i]);
		printf("%f	%d	%d\n",l[i],bin1[i],bin2[i]);
	}
}

