# define _CRT_SECURE_NO_DEPRECATE
# define MAX 100
# define KMAX 27
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <windows.h>
void Run();//�˵�������                               *
void readKey(char* key);//��ȡ������Կ                *
char* GetKey(char* key);//�õ�����Ҫ���һά��Կ      *
char* GetM1(char *m);//�õ�����Ҫ�������(����ǰ��)   *
char* GetC1(char *c);//�õ�����Ҫ�������(����ǰ��)   *
char* GetM2(char* c, char* key);//�õ����ܺ������    *
char* GetC2(char* m, char* key);//�õ����ܺ������    *
void GetC();//����                                    *
void GetM();//����									  *