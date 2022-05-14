# define _CRT_SECURE_NO_DEPRECATE
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# define RL(x,y) (((x)<<(y))|((x)>>(32-(y))))
# define f1(b,c,d) ((b&c)|((~b)&d))
# define f2(b,c,d) (b^c^d)
# define f3(b,c,d) ((b&c)|(b&d)|(c&d))
# define f4(b,c,d) (b^c^d)
# define MAX 512
void Run();
void SGetC();
void FGetC();
void GetC(unsigned char* M);
int Getn(int len);
int* GetM_16N(unsigned char* M);
int* GetM_80(unsigned int* M_16);
int* Fun(unsigned int* M_80);
void DisPlay(int* XX, int n);
void ReSet_ABCDE();
void Clean();