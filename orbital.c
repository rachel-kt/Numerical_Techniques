#include<stdio.h>
#include<math.h>
#define pi 3.14159
main()
{
	float x[10],y[10],o,t,p;
	int m=0,l=3;
	//printf("Enter the value of m:\n");
	//scanf("%d",&m);
	FILE *fp=NULL;
	fp= fopen("orball.txt","w");
	for(t=0;t<=(2*pi);t=t+0.001*pi)
	{
		for(m=0;m<=3;m++)
		{
			if(m==0)
			{
			o=(3*sqrt(14)/4)*(((5*pow(cos(t),3)/3)-cos(t)));
			}
			else if(m==1||m==-1)
			{
			o=(sqrt(42)/8)*(sin(t)*(5*(pow(cos(t),2))-1));
			}
			else if(m==2||m==-2)
			{
			o=(sqrt(105)/4)*(sin(t)*sin(t)*cos(t));
			}
			else if(m==3||m==-3)
			{
			o=(sqrt(70)/8)*(pow(sin(t),3));
			}
		p=fabs(o);
		x[m]=p*p*cos(t);
		y[m]=p*p*sin(t);
		}
		fprintf(fp,"%f \t %f \t %f \t %f \t %f \t %f \t %f \t %f\n",x[0],y[0],x[1],y[1],x[2],y[2],x[3],y[3]);
	}
	printf("DONE!");
	fclose(fp);
}
