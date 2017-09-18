#include <stdio.h>

int gcd( int A, int B );
int main (int argc, char* args )
{
  printf ("%d\n", gcd( 48 , 12*47 ) );
}
int gcd(int A , int B )
{
  return ( B == 0 ? A : gcd (B,A%B) );
}

