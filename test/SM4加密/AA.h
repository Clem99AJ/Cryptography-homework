# define _CRT_SECURE_NO_DEPRECATE
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <windows.h>
# include <math.h>
# define KEYMAX 16
# define PATHMAX 100

void Run();
void GetCorM(int choice);//1Ϊ���ܡ�2Ϊ����
unsigned long* GetSonKey(unsigned char* key);//�õ���Կ
unsigned long GetK_i(unsigned char* key, int i);//�õ���Կ��չǰ��4��K
unsigned long FourToOne(unsigned char* key, int i);//��16���ַ�����Ϊ4��һ��
unsigned long GetRk_i(unsigned long* sonkey,int i);//32��Կ��չ
unsigned long T(unsigned long* sonkey,int k);//k=0��T'����Կ�ã�,k=1��T�������ã�
unsigned long Sub(unsigned long sk);//S���û�
unsigned long* GetC_1(unsigned char* key, unsigned long*sonkey,int choice);//����32��
unsigned long GetRX(unsigned long* c, int i, unsigned long* sonkey);//ʵ�ֵõ�����Կ�Ĺ���
unsigned char* GetOutPut(unsigned long* output);//��32�ּ��ܽ�������õ���Ҫд��ĸ�ʽ������
unsigned long GetRX_CtoM(unsigned long* c, int i, unsigned long* sonkey);//ʵ�ֵõ�
void DisPlaySonKey(unsigned long* sonkey);//�����������Կ
void ClearScreen();//����