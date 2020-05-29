#include<stdio.h>
#include<math.h>
main()
{
	float x,t,sum;
	int n,i;
	printf("supply x and the number of terms n\n");
	scanf("%f,%d",&x,&n);
	sum=1.0; 
	t=1.0;
	for(i=1;i<n;i++)
	{
		t*=(x/i);
		sum+=t;
	}
	printf("\n");
	printf("x=%6.2f, n=%d, sum=%12.5e",x,n,sum);
}


