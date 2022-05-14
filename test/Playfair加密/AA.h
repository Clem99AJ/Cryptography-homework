# define _CRT_SECURE_NO_DEPRECATE
# define MAX 100
# define KMAX 27
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <windows.h>
void Run();//菜单及调用                               *
void readKey(char* key);//读取矩阵密钥                *
char* GetKey(char* key);//得到满足要求的一维密钥      *
char* GetM1(char *m);//得到满足要求的明文(加密前用)   *
char* GetC1(char *c);//得到满足要求的密文(解密前用)   *
char* GetM2(char* c, char* key);//得到解密后的明文    *
char* GetC2(char* m, char* key);//得到加密后的密文    *
void GetC();//加密                                    *
void GetM();//解密									  *