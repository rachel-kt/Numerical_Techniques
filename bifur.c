#include<stdio.h>
#include<math.h>
main()
{
	float x,a,in;
	int i;
	FILE *fp=NULL;
	fp=fopen("bifur.txt","w");
	printf("Enter the intial value for x [0,1] excluding 0,0.5,1:\n");
	scanf("%f",&in);
	for(a=1;a<=4;a+=0.05)
	{
		x=in;
		for(i=0;i<=10100;i++)
		{
			x=a*x*(1-x);
			if(i>10000)
			{
				fprintf(fp,"%f	%f\n",a,x);
			}
		}
	}
	fclose(fp);
	printf("DONE!\n");
}
