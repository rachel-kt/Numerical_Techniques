#include<stdio.h>
#include<math.h>
/* 
Function with same name f of type float and has two arguments, one of type float and other of type int.
*/

float f(float x, int n)
{
  float y,z=1.0;
  int i;

  for(i=1;i<=n;i++)
    {
      z*=x;
    }
  if (x<0.0)
    {
      y = z-1 + exp(x);
    }
  else 
    {
      y = z - log(1+x);
    }
  return (y);
}

/*global function declaration */
float f(float x, int n);

/* main function will call f */
main()
{ 
  float q;
  int j;
  printf("Supply the value of x(float), n(int)\n");
  scanf("%f, %d", &q, &j);
  printf("x=%6.2f n=%d f=%6.2f\n", q, j, f(q,j));
}
