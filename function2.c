#include<stdio.h>
#include<math.h>
#define f(x) ((x)*(x)*(x) + sin(x)*log(x)) /* inline function */

/*Main function which will call above function*/
main()
{
  float y;
  printf("Supply the value for which you wnat to evaluate the function\n");
  scanf("%f", &y);
  printf("%6.2f %6.2f\n", y, f(y));
}
