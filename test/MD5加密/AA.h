# define _CRT_SECURE_NO_DEPRECATE
# include <stdio.h>
# include<string.h>
# include<stdlib.h>
# include<math.h>
# include<Windows.h>
# define MAX 512 * 10
# define F(x,y,z) (((x) & (y))|((~x) & (z)))
# define G(x,y,z) (((x) & (z))|((y) & (~z)))
# define H(x,y,z) ((x) ^ (y) ^ (z))
# define I(x,y,z) ((y) ^ ((x) | (~z)))
# define RL(x,y) (((x) << (y)) | ((x) >> (32 - (y))))//循环左移y位
# define PP(x) (x<<24) | ((x<<8)&0xff0000) | ((x>>8)&0xff00) | (x>>24)//将x高低位互换，aabbccdd变ddccbbaa
# define FF(a,b,c,d,x,s,ac) (b + (RL((a + F(b,c,d) + x + ac),s)))
# define GG(a,b,c,d,x,s,ac) (b + (RL((a + G(b,c,d) + x + ac),s)))
# define HH(a,b,c,d,x,s,ac) (b + (RL((a + H(b,c,d) + x + ac),s)))
# define II(a,b,c,d,x,s,ac) (b + (RL((a + I(b,c,d) + x + ac),s)))
void Run();
void SgetC();
void FgetC();
void GetC(char* M);
int Getn(int len);
unsigned int* GetM_16(char* M);
unsigned int* Fun_MD5(int* x);
void ReSet_ABCD();
void Clean();