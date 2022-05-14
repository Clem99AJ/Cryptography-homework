# define _CRT_SECURE_NO_DEPRECATE
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
void Run();//功能调用及菜单
char* GetLFSR(int i);//输入LFSR
int* CharToInt(char* XX_c, int i);//字符转整型
int* GetKey(int** LFSR, int n);//得到密钥
int* RM(int *X,int n);//移动
void DisPlay_INT(int* XX, int n);//输出检查