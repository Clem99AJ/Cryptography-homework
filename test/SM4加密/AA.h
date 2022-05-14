# define _CRT_SECURE_NO_DEPRECATE
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <windows.h>
# include <math.h>
# define KEYMAX 16
# define PATHMAX 100

void Run();
void GetCorM(int choice);//1为加密。2为解密
unsigned long* GetSonKey(unsigned char* key);//得到密钥
unsigned long GetK_i(unsigned char* key, int i);//得到密钥扩展前的4个K
unsigned long FourToOne(unsigned char* key, int i);//把16个字符处理为4个一组
unsigned long GetRk_i(unsigned long* sonkey,int i);//32密钥扩展
unsigned long T(unsigned long* sonkey,int k);//k=0是T'（密钥用）,k=1是T（加密用）
unsigned long Sub(unsigned long sk);//S盒置换
unsigned long* GetC_1(unsigned char* key, unsigned long*sonkey,int choice);//加密32轮
unsigned long GetRX(unsigned long* c, int i, unsigned long* sonkey);//实现得到子密钥的功能
unsigned char* GetOutPut(unsigned long* output);//把32轮加密结果处理，得到需要写入的格式及内容
unsigned long GetRX_CtoM(unsigned long* c, int i, unsigned long* sonkey);//实现得到
void DisPlaySonKey(unsigned long* sonkey);//遍历输出子密钥
void ClearScreen();//清屏