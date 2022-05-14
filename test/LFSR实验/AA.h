# define _CRT_SECURE_NO_DEPRECATE
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <windows.h>
# include <math.h>
# define PATHMAX 100
void Run();
int Judge(char *XX);//判断是否为0、1序列
int* CharToInt(char *XX);//char转int
int Get_oneT(int* xishu,int* chushi,int n);//返回最小正周期，且处理每个状态
int* GetKey(int* xishu, int* chushi,int n,int T);//得到密钥
void JiaMi(int * key,int T);//读取文件并且加密、解密到文件中
void DisPlay_Int_N(int* XX, int n);//打印int XX[n]数组