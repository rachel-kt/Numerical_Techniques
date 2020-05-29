#include<stdio.h>
#include<math.h>
main()
{
  int n,o,t;
  for(n=50;n<=70;n++)
    {
  o=n%10;
  t=n/10;
  if(n%(o+t)==0)
    {
      printf("the number %d is harshad\n",n);
    }
    }
}
