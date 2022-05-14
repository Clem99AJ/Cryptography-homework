# define _CRT_SECURE_NO_DEPRECATE
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <windows.h>
# include <math.h>
# define KEYMAX 16
# define MAX 100
void Run();//菜单及调用
void AES(int ch);
unsigned char* Zero(unsigned char* m);//填充方式Zero
unsigned char* X923(unsigned char* m);//填充方式X923
unsigned char* PKCS7(unsigned char* m);//填充方式PKCS7
unsigned char* ISO10126(unsigned char* m);//填充方式ISO10126
unsigned char* GetMatrixKey(unsigned char* key);//密钥矩阵化
int** GetSonKey(unsigned char* key);//得到4x44的密钥矩阵
int** GetSonKey2(int** key);//把4x44的密钥，装入11x16，方便输出,最后一个装初始密钥
int** GetC(unsigned char* m, int** key,int *IV,int ch);
int* GetC1(int* m, int** key,int *XX,int ch);//得到每一组加密后的结果
int** GetC2(int** m, int* key, int n);//加密的过程包含10轮
int** SubByte(int** m, int** temp);//S盒替换
int** ShiftRows(int** m, int** temp);//行移位处理
int** MixColumns(int** m, int** temp);//列混淆
void DisPlayMatrix(unsigned char* XX);//遍历4x4字符
void DisPlayMatrix1(int** XX);//遍历4x4整型
void DisPlayKEY4x44(int** key);//遍历检查4x44key
void DisPlayKEY10x16(int** key);//遍历输出10x16key
void DisPlayKEY_Nx16(int** key, int n);//遍历输出Nx16key
void ClearScreen();