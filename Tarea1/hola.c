#include <stdio.h> 
#include <math.h>
int gcd(int a, int h) 
{
  int temp; 
  while(1)
    {
      temp = a%h;
      if(temp==0)
	return h;
      a = h;
      h = temp;
    }
} 
int main() 
{
  int c,d; 
  printf("enter two values to find for relative prime or co prime\n");
  scanf("%d",&d);
  for ( int i = 2 ; i < d ; i ++ )
    {
      if (gcd(d,i) ==1)
	printf("Numero %d es coprimo de 36\n",i);
      else
	printf("Numero %d no es coprimo de 36\n",i);
    }
}
