# define _CRT_SECURE_NO_DEPRECATE
# define MAX 20
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <stdlib.h>
# include <windows.h>
void Run();
char * geteightKey(char *key);//��ȡ����Ҫ�����Կ
int* Get64Bit(char* ch);//���ַ���ת���ɶ����Ƶ�64λ
int* GetPC_1Key(int *key);//�õ�PC_1�û���Ľ��
int* GetRemoveKey(int *key);//�õ�ѭ�����ƵĽ��
int* GetPC_2Key(int* key);//�õ�PC_2�û���Ľ��
int* Get12Key(int* key);//�õ����12��λ�õ�ʮ������
void readKey(int* key,int n);//��ȡkey.���(int [],int size)
void read16Key(int* key,int n);//��ȡ16�������
