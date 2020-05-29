#include<stdio.h>
#include<math.h>
main()
{
  int a,b,c,f,i,j;
   for(a=1;a<100;a++)
     {
       for(b=a;b<100;b++)
	 {
	   f=a*a+b*b;
	   c=sqrt(f);
	   if((c<100)&&(((a*a)+(b*b))==(c*c)))
	     {
	       printf("%d^2 + %d^2 = %d^2\n",a,b,c);
	     }
	 }
     }
}
	       
