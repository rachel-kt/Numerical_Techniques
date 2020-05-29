#include<stdio.h>
#include<math.h>
int prime_check(int n)
{
  int flag=0,j;
  for(j=2;j<=n/2;j++)
    {
      if(n%j==0)
	{
	  flag=1;
	  break;
	}
    }
  /*if(flag==0)
      {
	printf("\n%d is a prime",n);
	  
      }
    else
      {
	printf("\n%d is not a prime",n);
      }*/
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
  printf("\n Total number of primes up to %d(last number included) is %d\n",x,np);
}
