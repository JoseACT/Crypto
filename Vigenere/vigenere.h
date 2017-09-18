#ifndef VIGENERE_HEADER_FILE
#define VIGENERE_HEADERS_FILE

/* Buenas Practicas */

#include <stdio.h>
#include <stdlib.h>
#include <string.h

#define SIZE (1024*1024)
#define NH 209
#define ALP_SIZE 27
#define UPPER 0.0741lf
#define LOWER 0.037lf
#define MAX_T 10
const unsigned char alphabet[]  = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',NH};

unsigned int * frequency(char* texto);

#endif  
