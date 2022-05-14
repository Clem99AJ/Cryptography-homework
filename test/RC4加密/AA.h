# define _CRT_SECURE_NO_DEPRECATE
# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<math.h>
# include<windows.h>
# define MAX 100
void Run();
void Menu();//菜单
void Fun();//加密（解密）功能
unsigned char * GetC(unsigned char* M, unsigned char* key);//加密
void InitializationSBox();//初始化S盒
void InitializationSBox_key(unsigned char* key);//初始化S_key盒
void Mix_XBox();//S盒混淆
void DisPlay_SBox(int * SBOX);//遍历检查S盒
void Clean();//清屏