# define _CRT_SECURE_NO_DEPRECATE
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <windows.h>
# include <math.h>
# define PATHMAX 100
void Run();
int Judge(char *XX);//�ж��Ƿ�Ϊ0��1����
int* CharToInt(char *XX);//charתint
int Get_oneT(int* xishu,int* chushi,int n);//������С�����ڣ��Ҵ���ÿ��״̬
int* GetKey(int* xishu, int* chushi,int n,int T);//�õ���Կ
void JiaMi(int * key,int T);//��ȡ�ļ����Ҽ��ܡ����ܵ��ļ���
void DisPlay_Int_N(int* XX, int n);//��ӡint XX[n]����