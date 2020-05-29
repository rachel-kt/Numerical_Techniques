#include<stdio.h>
#include<math.h>
float rn[101],i,count[1000];
randx(int xp,int c,int m,int a)
{
	xp = (a*xp + c) % m;
	return (xp/m);
}

/*int highest()
{
	int h;
	h = rn[0];
	for(i=0;i<101;i++)
	{	if(rn[i+1]>rn[i])
			h=rn[i+1];
	}
	return h;
}
int lowest()
{
	int l;
	l = rn[0];
	for(i=0;i<101;i++)
	{	if(rn[i+1]<rn[i])
			l=rn[i+1];
	}
	return l;
}
freq(int step, int b)
{
	int j;
	for(j=0;j<b;j++)
	{
		for(i=0;i<101;i++)
		{
			if((rn[0]>(j*step))&&(rn[0]<=((j+1)*step)))
			count[j]++;
			
		}
	}
}
*/
main()
{
	FILE *fp=NULL;
	fp=fopen("randnm.txt","w");
	fp=fopen("freq.txt","w");
	int c=0,m,s,a=1277,i=0,g,bn,step,k=0,w,l;
	printf("\nEnter your seed:");
	scanf("%d",&s);
	m=pow(2,17);
	rn[0]=s;
	for(i=0;i<101;i++)
	{
		rn[i+1]=randx(rn[i],c,m,a);
		//printf("%d	%d\n",i,rn[i]);	
		fprintf(fp,"%d	%d\n",i+1,rn[i]);
	}
	g=highest();
	w=lowest();	
	printf("highest number is %d:\n",g);
	printf("lowest number is %d:\n",w);	
	printf("Enter the number of bins:\n");
	scanf("%d",&bn);
	step = (g-w)/bn;
	printf("step size = %d\n",step);
	freq(step,bn);
	for(k=0;k<bn;k++)
	{
		fprintf(fp,"%d	%d\n",k+1,count[k]);
	}
}


