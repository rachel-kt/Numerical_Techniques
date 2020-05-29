#include<stdio.h>
#include<math.h>
/*
Function with name f of type float and has one argument which is of type float
*/

float f(float x)
{
  float z;
  z = x*x*x + sin(x)*log(x);
  return (z);
}

/*
  Main function which will call above function*/

main()
{
  float y;
  float f(float x); /*function declaration*/
  printf("supply the value for which you want to evaluate the function\n");
  scanf("%f",&y);
  printf("%6.2f %6.2f\n", y, f(y));
}
