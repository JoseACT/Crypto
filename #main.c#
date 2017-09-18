#include <stdlib.h>
#include <stdio.h>
#define SIZE (1024*1024)
int main ( ){
  unsigned char cracked[4];
  unsigned char try[4];
  FILE *ptr;
  FILE *trying;
  char corrimiento;
  int flag = 1;
  ptr = fopen("im.png","rb");  // r for read, b for binary
  trying = fopen("imagen.png.enc","rb");
  fread(try,sizeof(try),1,trying); // read 5 bytes to our buffer
  fread(cracked,sizeof(cracked),1,ptr); // read 5 bytes to our buffer
  for(int i = 0 ; i < 256 ; i ++)
    {
      printf("Iteracion %d\n", i);
      printf("OPERACION %d\n",( (try [0] + i) % 256  == cracked[0]));
      if( ( ( try [0] + i) % 256 ) == cracked[0] )
	{
	  printf(" IN IF %d , %d \n", (try[0] + i) % 256 ,cracked[0]);
	  flag = 0;
	  corrimiento = i;
	}
    }
  printf("Corrimiento de %d\n", (int)corrimiento); 
  fclose(ptr);
  fclose(trying);
  FILE *new;
  new = fopen("imagen.png","w");
  trying = fopen("imagen.png.enc","rb");
  char buffer[SIZE];
  size_t bytes;
  while (0 < (bytes = fread(buffer, 1, sizeof(buffer), trying)))
    {
      for ( int i = 0 ; i < SIZE ; i++)
	buffer[i] = (buffer[i] + corrimiento) % 256 ; 
      fwrite(buffer, 1, bytes, new);
    }
}
