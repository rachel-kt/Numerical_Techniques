#include<stdio.h>
#include<math.h>
main()
{
  int a,b,c;
  printf("Enter the numbers a, b, c:\n");
  scanf("%d,%d,%d",&a,&b,&c);
  if(((a*a)+(b*b))==c*c)
    {
      printf("%d^2 + %d^2 = %d^2\n",a,b,c);
    }
  else if(((a*a)+(c*c))==b*b)
    {
      printf("%d^2 + %d^2 = %d^2\n",a,c,b);
    }
    else if(((b*b)+(c*c))==a*a)
    {
      printf("%d^2 + %d^2 = %d^2\n",b,c,a);
    }
  else
    printf("The numbers are not pythagorean!");
}


