# define _CRT_SECURE_NO_DEPRECATE
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <windows.h>
# include <math.h>
# define KEYMAX 16
# define MAX 100
void Run();//�˵�������
void AES(int ch);
unsigned char* Zero(unsigned char* m);//��䷽ʽZero
unsigned char* X923(unsigned char* m);//��䷽ʽX923
unsigned char* PKCS7(unsigned char* m);//��䷽ʽPKCS7
unsigned char* ISO10126(unsigned char* m);//��䷽ʽISO10126
unsigned char* GetMatrixKey(unsigned char* key);//��Կ����
int** GetSonKey(unsigned char* key);//�õ�4x44����Կ����
int** GetSonKey2(int** key);//��4x44����Կ��װ��11x16���������,���һ��װ��ʼ��Կ
int** GetC(unsigned char* m, int** key,int *IV,int ch);
int* GetC1(int* m, int** key,int *XX,int ch);//�õ�ÿһ����ܺ�Ľ��
int** GetC2(int** m, int* key, int n);//���ܵĹ��̰���10��
int** SubByte(int** m, int** temp);//S���滻
int** ShiftRows(int** m, int** temp);//����λ����
int** MixColumns(int** m, int** temp);//�л���
void DisPlayMatrix(unsigned char* XX);//����4x4�ַ�
void DisPlayMatrix1(int** XX);//����4x4����
void DisPlayKEY4x44(int** key);//�������4x44key
void DisPlayKEY10x16(int** key);//�������10x16key
void DisPlayKEY_Nx16(int** key, int n);//�������Nx16key
void ClearScreen();