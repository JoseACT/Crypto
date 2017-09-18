# include <stdio.h>
# include <math.h>

int gcd(int i, int x){
  if(x % i == 0)
    return( i );
  return( gcd( x % i, x ) );
}
void primeFactors(int n)
{
  // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        printf("%d ", 2);
        n = n/2;
    }
    // n must be odd at this point.  So we can skip 
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            printf("%d ", i);
            n = n/i;
        }
    }
    // This condition is to handle the case when n 
    // is a prime number greater than 2
    if (n > 2)
        printf ("%d ", n);
}
 
/* Driver program to test above function */
int main()
{
  
    /* int z = 36; */
    /* int aux = 0; */
    /* int e , flag; */

    /* for(e = 2; e < z; e++){ */
    /*   aux = gcd( e , z ); */
    /*   printf("E = %d , gdc (%d,%d) = %d\n", e, e, z, aux); */
    /*   if( aux == 1) */
    /* 	{ */
    /* 	  printf("Primo relativo de %d , es: %d\n", z , e); */
    /* 	  flag = 1; */
    /* 	  continue; */
    /* 	} */
    /* } */
    int nums[5] = {385,420,56,343,175};
    for ( int i = 0 , n = nums[i] ; i < 5 ; i ++, n = nums[i])
      {
	primeFactors(n);
	printf("\n");
      }
    return 0;
}
