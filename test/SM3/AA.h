# define _CRT_SECURE_NO_DEPRECATE
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# define RL(x,y) (((x)<<(y))|((x)>>(32-(y))))
# define P_0(x) (x^RL(x,9)^RL(x,17))
# define P_1(x) (x^RL(x,15)^RL(x,23))
# define FF1(x,y,z) (x^y^z)
# define FF2(x,y,z) ((x&y)|(x&z)|(y&z))
# define GG1(x,y,z) (x^y^z)
# define GG2(x,y,z) ((x&y)|((~x)&z))
# define MAX 512
void Run();
void SGetC();
void GetC(unsigned char* M);
int Getn(int len);
int* GetM_16N(unsigned char* M);
void Fun(unsigned int* M_16);
void DisPlay(int* XX, int n);
void Clean();