# define _CRT_SECURE_NO_DEPRECATE
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
void Run();//���ܵ��ü��˵�
char* GetLFSR(int i);//����LFSR
int* CharToInt(char* XX_c, int i);//�ַ�ת����
int* GetKey(int** LFSR, int n);//�õ���Կ
int* RM(int *X,int n);//�ƶ�
void DisPlay_INT(int* XX, int n);//������