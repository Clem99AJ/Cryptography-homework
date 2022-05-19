# define _CRT_SECURE_NO_DEPRECATE
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
# define MAX 512
typedef struct Spot {
	int x;
	int y;
	struct Spot* next;
}SPOT;
typedef struct {
	int len;
	SPOT* first;
	SPOT* last;
}LIST;
void Run();
LIST* GetSpot(int a,int b,int p);//得到曲线上所有点
SPOT* GetAorB(LIST* list,char choice);//得到A或B
SPOT* GetSum(SPOT *A,SPOT *B,int a,int p);//得到A + B
void DisPlay_1(int a, int b);
void DisPlay_AllSpot(LIST* list);