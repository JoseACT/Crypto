#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE (1024*1024)
int main(int argc, char *args[])
{
  FILE *MENSAJE, *new;
  char *key;
  new = fopen(args[2],"w");
  MENSAJE = fopen(args[1],"rb");
  /* int a = atoi(args[3]); */
  /* key = malloc ( sizeof(char) * a); */
  key = args[3];
  char buffer[SIZE];
  size_t bytes;
  int lens = strlen(key);
  while (0 < (bytes = fread(buffer, 1, sizeof(buffer), MENSAJE)))
    {
      for ( int i = 0 ; i < SIZE ; i++)
	{
	  for ( int j = 0 ; j < lens ; j ++)
	    {
	      buffer[i] = buffer[i] ^= key[j%lens] ;
	    }
	}
      fwrite(buffer, 1, bytes, new);
    }
  return 0;
}

