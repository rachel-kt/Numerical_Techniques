#include<stdio.h>
#include<math.h>
int m, a=9999;

int randx(int rn)
{
	m=pow(2,17);
//	rn = (a*rn + c)%m;
        rn = (a*rn)%m;
	return rn;
}
main()
{
	FILE *fp1=NULL;
	FILE *fp2=NULL;
	fp1=fopen("randnm.txt","w");
	fp2=fopen("chitest.txt","w");
	int c=0,N;
	int i=0,rn,p,q,x[8];
	x[1]=0;x[2]=0;x[3]=0;x[4]=0;x[5]=0;x[6]=0;
	float z,s,y, chi[8], chi_sqr;
	printf("\nEnter your seed:");
	scanf("%d",&rn);
	p=0;q=6;
	m=pow(2,17);	
	for(N=100;N<10000;N+=10)
	{
		for(i=0;i<N;i++)
		{
			rn=randx(rn);
			z=(float)rn/(float)m;
			//printf("%d\n",rn);	
		
/************************************* mapping (DIE) **************************************/
	
			int k=p;
			s=(q-p);
			y= s*z + k;
			fprintf(fp1,"%f\n",y);
					if((y<6)&&(y>=5))
					{
						x[6]=x[6]+1;
					}
					else if((y<5)&&(y>=4))
					{
						x[5]=x[5]+1;
					}
					else if((y<4)&&(y>=3))
					{
						x[4]=x[4]+1;
					}
					else if((y<3)&&(y>=2))
					{
						x[3]=x[3]+1;
					}
					else if((y<2)&&(y>=1))
					{
						x[2]=x[2]+1;
					}
					else if((y<1)&&(y>=0))
					{
						x[1]=x[1]+1;
					}		
	
		}	
		for(i=1;i<=6;i++)
		{
			chi[i]= pow((N/6.0-x[i]),2)/(float)x[i];
			chi_sqr+=chi[i];
		}
		fprintf(fp2,"%d	%f	%d	%d	%d	%d	%d	%d\n",N,chi_sqr,x[1],x[2],x[3],x[4],x[5],x[6]);
		for(i=1;i<=6;i++)
		{	
			x[i]=0;
			chi[i]=0;
			
		}
		chi_sqr=0;
	}
}	
