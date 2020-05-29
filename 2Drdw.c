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
	FILE *fp2=NULL;
	int x,y;
	x=0;y=0;
	fp1=fopen("2drw.txt","w");
	fp2=fopen("var.txt","w");
	int m,c=0,a=9999;
	int i=0,rn1=6865,p=-2,q=2,M=0,k;
	float z1,z2,s,y1,y2,l,pi,d[10000],meand=0,var;
	m=pow(2,17);
	
		for(k=0;k<10000;k++)
		{
			for(i=0;i<1000;i++)
			{
				rn1=randx(rn1,c,m,a);
				z1=(float)rn1/(float)m;
				y1= 4*z1 - 2;
				if((y1<2)&&(y1>=1))
				{
					x=x+1;
				}
				else if((y1<1)&&(y1>=0))
				{
					x=x-1;
				}
				else if((y1<0)&&(y1>=-1))
				{
					y=y+1;
				}
				else if((y1<-1)&&(y1>=-2))
				{
					y=y-1;
				}
			}
			d[k]=sqrt(x*x + y*y);
			meand=meand + d[k];
			fprintf(fp1,"%d	%f\n",k,d);
			x=0;y=0;
		}
	meand = meand/10000;
	for(k=0;k<=10000;k++)
	{
		var = sqrt(fabs((d[k]*d[k])-(meand*meand)));
		fprintf(fp2,"%d	%f\n",k+1,var);
	}
	
}

	
	
	
