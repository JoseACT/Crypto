#include "cifrado.h"
#include <stdio.h>
#include <stdlib.h>
#define SIZE (1024*1024)
int gcd( int A, int B );
int inverso(int A, int B);

int main ( int argc, char* args[])
{
  FILE *file, *new, *keys;
  keys = fopen(args[2], "r");
  file = fopen(args[1],"rb");
  new = fopen(strcat(args[1],".enc"),"w");
  char buffer[SIZE];
  size_t bytes;
  while (0 < (bytes = fread(buffer, 1, sizeof(buffer), file )))
    {
      fwrite(buffer, 1, bytes, new);
    }
}
void afin_encryption ( char * buffer , char m , int x )
{
  if (  gcd( m , (char)sizeof(char) ))
    return ;
  for ( int i = 0 ; sizeof(buffer) ; i ++ )
    buffer [ i ] = ( ( m * buffer [ i ]) + x ) % MAX_SIZE  ;
}
void afin_decryption ( char * buffer , char m , int x )
{
  for ( int i = 0 ; sizeof(buffer) ; i ++ )
    buffer [ i ] = ( ( inverso( m ,MAX_SIZE) * buffer [ i ]) - x ) % MAX_SIZE ;
}
void vigeniere_encryption ( char * buffer, char * key )
{
  for ( int i = 0 ; sizeof(buffer) ; i ++ )
    buffer [i] = ( (  buffer[i] ^= key[i] ) % MAX_SIZE ); 
}
void vigeniere_decyption ( char * buffer, char * key )
{
  for ( int i = 0 ; sizeof(buffer) ; i ++ )
    buffer [i] = ( (  buffer[i] ) ^= key[i] ) % MAX_SIZE ; 
}
void mezclado_encryption ( char * buffer , char key[MAX_SIZE])
{
  for ( int i = 0 ; sizeof(buffer) ; i ++ )
    buffer [i] = key[buffer[i]] % MAX_SIZE ; 
}
void mezclado_decryption ( char * buffer , char key[MAX_SIZE])
{
  for ( int i = 0 ; sizeof(buffer) ; i ++ )
    buffer [i] =  buffer[key[i]]   % MAX_SIZE ; 
}
int gcd(int A , int B )
{
  return ( B == 0 ? A : gcd (B,A%B) );
}
int inverso(int A, int B)
{
  int  x;
  for(int i = 0; i < B; i++)
    {
      x = (A * i) % MAX_SIZE;
      if (x == 1 )
	return i;
    }
  return 0;
}
