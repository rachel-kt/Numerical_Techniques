#include<stdio.h>
#include<math.h>
#define pi 3.14159
main()
{
	float x,y,z,x1,x2,x3,y1,y2,y3,m1,m2,m3;
	printf("Enter the points of the first vertex\n");
	scanf("%f,%f",x1,y1);
	printf("Enter the points of the second vertex\n");
	scanf("%f,%f",x2,y2);
	printf("Enter the points of the third vertex\n");
	scanf("%f,%f",x3,y3);
	m1=(y2-y1)/(x2-x1);
	m2=(y3-y2)/(x3-x2);
	m3=(y3-y1)/(x3-x1);
	FILE *fp=NULL;
	fp= fopen("circle.txt","w");
	for(x=-(pi);x<=(pi);x=x+0.001*pi)
	{
		a=5+(3*sin(x));
		b=5+(3*cos(x));
		printf("%f \t %f\n",x,y);
		fprintf(fp,"%f \t %f\n",x,y);
	}
	fclose(fp);
}
