#include<stdio.h>
#include<math.h>
int fact(int l)
{
	if(l>0)
	return l*fact(l-1);
	else
	return 1;
}
main()
{
	float x,t,sum,j[4];
	int i,n;
	FILE *fp=NULL;
	fp=fopen("series3.txt","w");
	//printf("Enter the value of n\n");
	//scanf("%d",&n);printf("ok");
	for(x=0;x<=10;x+=0.1)
	{
		for(n=0;n<=2;n++)
		{
			i=1; 
			t=1./fact(n);
			sum=t;
			do
			{
				t*=-(x*x/4.)/(i*(n+i));
				sum+=t;
				i+=1;
			}while(fabs(t/sum)>1.0e-4);
			j[n]=pow((x/2),n)*sum;
		}
	fprintf(fp,"%f \t %f \t %f \t %f\n",x,j[0],j[1],j[2]);			
	}
printf("DONE!");
}
