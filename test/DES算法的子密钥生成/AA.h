# define _CRT_SECURE_NO_DEPRECATE
# define MAX 20
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <stdlib.h>
# include <windows.h>
void Run();
char * geteightKey(char *key);//获取符合要求的密钥
int* Get64Bit(char* ch);//把字符串转换成二进制的64位
int* GetPC_1Key(int *key);//得到PC_1置换后的结果
int* GetRemoveKey(int *key);//得到循环左移的结果
int* GetPC_2Key(int* key);//得到PC_2置换后的结果
int* Get12Key(int* key);//得到存放12个位置的十六进制
void readKey(int* key,int n);//读取key.输出(int [],int size)
void read16Key(int* key,int n);//读取16进制输出
