/***************** gausint ******************/



/* -----------------------  for sigma = 2 and mean = 1  --------------------------------*/


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
	float fx = (1/(2*sqrt(2.0*pi))) * exp(-(x-1)*(x-1)/8.0);
	return fx;
}
main()
{
	FILE *fp1=NULL;
	fp1=fopen("gint.txt","w");
	int m,c=0,a=9999,N = 10000;
	int i=0,rn1=9865,rn2=3345,M=0;
	float z1,z2,s,x1,y1,y2,l,area,erp,f;
	float pi=4.0*atan(1.0);	
	m=pow(2,17);
	//for(N=1000;N<=10000;N+=10)
	//{	
		for(i=0;i<N;i++)
		{
			rn1=randx(rn1,c,m,a);
			rn2=randx(rn2,c,m,a);
			z1=(float)rn1/(float)m;
			z2=(float)rn2/(float)m;
			x1 = 4*z1 - 1;	
			y1 = (1/(2*sqrt(2.0*pi)))*z2;
			f = f1(x1);
			if(f>=y1)
			{
				M++;
			}
		}
		area = 400*(1/(2*sqrt(2.0*pi)))*((float)M/(float)N);
		printf("The area under the curve within two sigma range is %f\n",area);
		//M=0;
	//}
}
