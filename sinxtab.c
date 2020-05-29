/* sinxtab.c - To tabulate values of sin x */
#include<stdio.h>
#include<math.h>
main()
{ 
  float x, x1, x2, y, dx, pi;
  int i, n=20;
  pi = 4.0*atan(1.0);
  printf("Supply x1 and x2 in units of pi\n");
  scanf("%f, %f", &x1, &x2);
  x1 = x1*pi;
  x2 = x2*pi;
  dx = (x2-x1)/(float)(n);
  for(i=0; i<=n; i++)
    {
      x = x1 + i*dx;
      y = sin(x);
      printf("%6.2f %6.2f\n", x, y);
    }
}
