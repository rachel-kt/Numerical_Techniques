/* sinx.c - Program to calculate sin(x) */
#include<stdio.h>
#include<math.h>

main()
{
  float x,y;
  printf("Supply the value of x in radians\n");
  scanf("%f",&x);
  y = sin(x);
  printf("%f, %f\n", x,y);
}
