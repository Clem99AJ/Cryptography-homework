# define _CRT_SECURE_NO_DEPRECATE
# include <stdio.h>
# include <math.h>
# include <string.h>
# include <stdlib.h>
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
# define f1(b,c,d) ((b&c)|((~b)&d))
# define f2(b,c,d) (b^c^d)
# define f3(b,c,d) ((b&c)|(b&d)|(c&d))
# define f4(b,c,d) (b^c^d)
# define MAX 512
void Run();
//HMAC_MD5 means
void HMAC_MD5();
//HMAC_SHA1 means
void HMAC_SHA1(); 
unsigned int* GetC_MD5(unsigned char* M);
unsigned int* GetC_SHA1(unsigned char* M);
unsigned int* GetM_16N_MD5(unsigned char* M);
unsigned int* GetM_16N_SHA1(unsigned char* M);
unsigned int* GetM_80(unsigned int* M_16);
unsigned int* Fun_MD5(unsigned int* M_16);
unsigned int* Fun_SHA1(unsigned int* M_80);
void ReSet_ABCDE();
void ReSet_ABCD();
int Getn(int len);
void DisPlay(int* XX, int n);
//Other
void Clean();