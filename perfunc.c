#include<stdio.h>
#include<math.h>
main()
{
	float x,y,z;
	FILE *fp=NULL;
fp = fopen("data2.txt", "w"); 
	for(x=0; x<=6; x+=0.1)
	{
		z=x-2.0*(int)(x/2.0);
		if(z<1.0)
			y=z;
		else
			y=2.0-z;
fprintf(fp, "%f \t %f \n", x,y);
}
fclose(fp);
}
