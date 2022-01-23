#ifndef FOMRAS_H
#define FOMRAS_H

#include "main.h"
void* cria_retangulo(char i[], char w[], char h[],char x[],char y[],char corb[],char corp []);
void* cria_circulo(char i[], char r[],char x[],char y[],char corb[],char corp []);
void* cria_linha (char i[],char x1[],char y1[],char x2[],char y2[],char cor[] );
void* cria_texto (char i[],char x[],char y[],char corb[], char corp[],char txto[]);
#endif