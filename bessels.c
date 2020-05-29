#include<stdio.h>
#include<math.h>
#define pi 3.14159
main()
{
	int n,l,k,i;
	float x,y,j[20],z,p;
	FILE *fp=NULL;
	fp=fopen("bes05.txt","w");
	for(z=0.01;z<=10;z=z+0.01)
	{
		j[0]=sin(z)/z;
		j[1]=(sin(z)/(z*z))-(cos(z)/z);
		for(i=2;i<=5;i++)
		{
			for(n=1;n<i;n++)
			{
				j[n+1]=(((2*n)+1)*(j[n]/z))-j[n-1];
			}
		}
	fprintf(fp,"%f \t %f \t %f \t %f \t %f \t %f \t %f\n",z,j[0],j[1],j[2],j[3],j[4],j[5]);
	}		
	printf("\nDONE!\n");
	fclose(fp);	
}
