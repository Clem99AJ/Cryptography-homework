# define _CRT_SECURE_NO_DEPRECATE
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <windows.h>
# include <math.h>
# define KEYMAX 16
# define MAX 100
void Run();//�˵�������
char * Zero(char *m);//��䷽ʽZero
char* X923(char* m);//��䷽ʽX923
char* PKCS7(char* m);//��䷽ʽPKCS7
char* ISO10126(char* m);//��䷽ʽISO10126
char* GetMatrixKey(char* key);//��Կ����
int** GetSonKey(char* key);//�õ�4x44����Կ����
int** GetSonKey2(int **key);//��4x44����Կ��װ��11x16���������,���һ��װ��ʼ��Կ
int** GetC(char *m,int **key);
int* GetC1(int *m, int** key);//�õ�ÿһ����ܺ�Ľ��
int** GetC2(int **m, int* key,int n);//���ܵĹ���9��֮ǰ
int** SubByte(int **m,int **temp);//S���滻
int** ShiftRows(int** m, int** temp);//����λ����
int** MixColumns(int** m, int** temp);//�л���
void DisPlayMatrix(char* XX);//����4x4�ַ�
void DisPlayMatrix1(int** XX);//����4x4����
void DisPlayKEY4x44(int** key);//�������4x44key
void DisPlayKEY10x16(int** key);//�������10x16key
void DisPlayKEY_Nx16(int** key,int n);//�������Nx16key