/************ estimation of pi ******************/

#include<stdio.h>
#include<math.h>
//#include<time.h>
int randx(int rn,int c,int m,int a)
{
	rn = (a*rn + c)%m;
	return rn;
}

main()
{
	FILE *fp1=NULL;
	fp1=fopen("pi.txt","w");
	int m,c=0,a=13,N;
	int i=0,rn1=9865,rn2=3345,p=-1,q=1,M=0;
	float z1,z2,s,y1,y2,l,pi,erp,r,pi_sum=0,avpi;
	//srand(time(NULL));
	//r=rand*1.0/RAND_MAX;
	//m=pow(2,17);
        m=31927173;
	for(N=100;N<=60000;N+=10)
	{
		for(i=0;i<=N;i++)
		{
			rn1=randx(rn1,c,m,a);
			rn2=randx(rn2,c,m,a);
			z1=(float)rn1/(float)m;
			z2=(float)rn2/(float)m;
			y1= 2*z1 - 1;
			y2= 2*z2 - 1;
			l= y1*y1 + y2*y2;
			if(sqrt(l)<1)
			{
				M++;
			}
		}
		pi = 4*(float)M/(float)N;
		erp = (pi-3.141592)/3.141592;
		fprintf(fp1,"%d	%f	%f\n",N,pi,erp);
		M=0;
		pi_sum+=pi;
	}
	avpi= pi_sum/((60000-100)/10);
	printf("\nVALUE OF PI IS %f",avpi);
}
