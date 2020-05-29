#include<stdio.h>
#include<math.h>
int prime_check(int n)
{
  int flag=0,j;
  for(j=2;j<=sqrt(n);j++)
    {
      if(n%j==0)
	{
	  flag=1;
	  break;
	}
    }
   return (flag);
}
main()
{
  int x,i,check,np=1;
  printf("Enter a number greater than 3 \n");
  scanf("%d", &x);
  for(i=3;i<=x;i++)
    {
      check=prime_check(i);
      if(check==0)
	{
	  np++;
	}  
    }
  printf("\nTotal number of primes up to %d(last number included) is %d\n",x,np);
}
