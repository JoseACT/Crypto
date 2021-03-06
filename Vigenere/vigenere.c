#include "vigenere.h"

int main(int argc, char *args[])
{
  File *MENSAJE ;

  char buffer[SIZE];
  size_t bytes;

  unsigned int encry_freq[ ALP_SIZE ] = {0};
  unsigned int text_size = 0;
  MENSAJE = fopen(args[1],"rb");
  while (0 < (bytes = fread(buffer, 1, sizeof(buffer), MENSAJE)))
    text_size += frequency( &buffer , &encry_freq);
  
  fclose(MENSAJE);
  char blocks [ALPH_SIZE] [SIZE/2] = {{'0'},{'0'}};
  for ( int i = 1 ; i < ALP_SIZE ; i ++ )
    {
      MENSAJE = fopen(args[1],"rb");
      while (0 < (bytes = fread(buffer, 1, sizeof(buffer), MENSAJE)))
	{
	  for ( int j = 0 ; j < SIZE ; j++)
	    {
	      blocks [ j ] [ j % i ] ++ ;
	    }
	} 
      fclose(MENSAJE);
    }

  return 0;
}
unsigned int frequency(char* texto, unsigned int*freq )
{
  unsigned int index = 0;
  unsigned int text_lenth = 0;
  for ( size_t i = 0 ; i < (sizeof(texto)/texto[0]) ; i ++ )
    {
      if ( texto[i] < 'A' || texto[i] > 'Z' || NH != texto[i])
	continue;
      if ( texto[i] == NH )
	index = ALP_SIZE - 1;
      else 
	index = texto[i] - 'A';
      text_lenth++;
      freq[index]++;
    }
  return text_lenth;
}
