# define _CRT_SECURE_NO_DEPRECATE
# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<math.h>
# include<windows.h>
# define MAX 100
void Run();
void Menu();//�˵�
void Fun();//���ܣ����ܣ�����
unsigned char * GetC(unsigned char* M, unsigned char* key);//����
void InitializationSBox();//��ʼ��S��
void InitializationSBox_key(unsigned char* key);//��ʼ��S_key��
void Mix_XBox();//S�л���
void DisPlay_SBox(int * SBOX);//�������S��
void Clean();//����