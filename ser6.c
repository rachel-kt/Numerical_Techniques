#include<stdio.h>
#include<math.h>
#define pi 3.14159
int fact(int l)
{
	if(l>0)
	return l*fact(l-1);
	else
	return 1;
}
main()
{
	float x,t,sum,f;
	int i,n;
	FILE *fp=NULL;
	fp=fopen("ser6.txt","w");
	printf("Enter the value of n\n");
	scanf("%d",&n);
	for(x=-10;x<=0;x+=0.05)
	{
		i=1; 
		t=1;
		sum=t;
		do
		{
			t*=(x*x*x)/((3*i)*(3*i-1));
			sum+=t;
			i+=1;
		}while(fabs(t/sum)>1.0e-4);
		f=0.35503*sum;
		printf("x= %f, f = %f\n",x,f);
		fprintf(fp,"%f \t %f\n",x,f);
	}

}
