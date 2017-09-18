#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 2048
#define CORRIMIENTO 3
#define SPACE 32
#define COMMA 44
#define DOT 46
#define INIT_ABC 90
#define INIT_ABC_CAPS 65
#define SIZE_ABC 26
#define GATO 35

char buff[MAX_SIZE];
char * line = NULL;
size_t len = 0;
int read ;
FILE * fr;
FILE * fw;
int corrimiento();
int descorrimiento();
int main(int argc, char *args[]){
  int mode = args[1][0];
  char * file_name ;
  if ( mode != 48)
    {
      file_name = "Descifrado.txt";
      printf("!0\n");
    }
  else
    {
      file_name = "Cifrado.txt";
      printf("0\n");
    }
  
  printf("ABRIENDO FILE\n");
  fw = fopen(file_name, "w");
  if( fw == NULL ) exit(-1);

  fr = fopen(args[2],"r");
  if( fr == NULL ) exit(-1);
  while( (read = getline(&line, &len , fr)) != -1 )
    {
      //printf("size = %d\n", read);
      //printf("LINE %s", line);
      if( mode != 48 ) {
	printf("Descifrando\n");
	descorrimiento( line , read , args[3][0] - '0');
      }else {
	printf("Cifrando\n");
	corrimiento( line , read , args[3][0] - '0');
      }
    }
  fclose(fr);
  if(fw)
    fclose(fw);
}
int descorrimiento ( char * line , int len , int type){
  char temp [ len ] ;
  switch (type)
    {
    case 0:
      for ( int i = 0 ; i < len ; i ++)
	{
	  temp [i] = ( line[i] - CORRIMIENTO) % 256;
	}
      break;
    case 1:
      for ( int i = 0 ; i < len ; i ++)
	{
	  if( line [i] >= INIT_ABC_CAPS && line [i] < INIT_ABC_CAPS + SIZE_ABC)
	    temp [i] = ( line[i] - CORRIMIENTO) % 256;
	  else
	    temp [i] = GATO;
	} 
      break;
    case 2:
      for ( int i = 0 ; i < len ; i ++)
	{
	  if( line [i] >= INIT_ABC_CAPS && line [i] < INIT_ABC_CAPS + SIZE_ABC ||
	      line [i] == SPACE || line [i] == COMMA || line [i] == DOT
	      )
	    temp [i] = ( line[i] - CORRIMIENTO) % 256;
	  else
	    temp [i] = GATO;
	}  
      break;
    case CORRIMIENTO:
      for ( int i = 0 ; i < len ; i ++)
	{
	  if( line [i] >= INIT_ABC_CAPS && line [i] < INIT_ABC_CAPS + SIZE_ABC ||
	      line [i] == SPACE || line [i] == COMMA || line [i] == DOT ||
	      line [i] >= INIT_ABC && line [i] < INIT_ABC + SIZE_ABC
	      )
	    temp [i] = ( line[i] - CORRIMIENTO) % 256;
	  else
	    temp [i] = GATO;
	}  
      break;
    default :
      exit(-2);
      break;
    }
  printf("Writing %s\n", temp);
  fprintf(fw, "%s\n" , temp);
}
int corrimiento( char * line , int len , int type){
  char temp [ len ] ;
  printf("type%d\n", type);
  switch (type)
    {
    case 0:
      for ( int i = 0 ; i < len ; i ++)
	{
	  temp [i] = ( line[i] + 3) % 256;
	}
      break;
    case 1:
      for ( int i = 0 ; i < len ; i ++)
	{
	  if( line [i] >= INIT_ABC_CAPS && line [i] < INIT_ABC_CAPS + SIZE_ABC)
	    temp [i] = ( line[i] + 3) % 256;
	  else
	    temp [i] = GATO;
	} 
      break;
    case 2:
      for ( int i = 0 ; i < len ; i ++)
	{
	  if( line [i] >= INIT_ABC_CAPS && line [i] < INIT_ABC_CAPS + SIZE_ABC ||
	      line [i] == SPACE || line [i] == COMMA || line [i] == DOT
	      )
	    temp [i] = ( line[i] + 3) % 256;
	  else
	    temp [i] = GATO;
	}  
      break;
    case 3:
      for ( int i = 0 ; i < len ; i ++)
	{
	  if( line [i] >= INIT_ABC_CAPS && line [i] < INIT_ABC_CAPS + SIZE_ABC ||
	      line [i] == SPACE || line [i] == COMMA || line [i] == DOT ||
	      line [i] >= INIT_ABC && line [i] < INIT_ABC + SIZE_ABC
	      )
	    temp [i] = ( line[i] + 3) % 256;
	  else
	    temp [i] = GATO;
	}  
      break;
    default :
      printf("DEFAULT");
      exit(-2);
      break;
    }
  fprintf(fw,"%s\n",temp);
  /* printf("Normal String = %s\n" , line ); */
  /* printf("Encrypted String = %s\n" , temp); */
}
