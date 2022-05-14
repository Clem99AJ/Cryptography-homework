#include "AA.h"
const int MAX[3] = { 19,22,23 };
const char Lname[3][7] = { "XLFSR\0","YLFSR\0","ZLFSR\0" };
void Run() {
	//变量区
	int n = 0;
	char** LFSR_c = (char**)malloc(sizeof(char*) * 3);
	for (int i = 0; i < 3; i++) {
		LFSR_c[i] = (char*)malloc(sizeof(char) * MAX[i]);
	}
	int** LFSR_i = (int**)malloc(sizeof(int*) * 3);
	for (int i = 0; i < 3;i++) {
		LFSR_i[i] = (int*)malloc(sizeof(int) * MAX[i]);
	}
	int* key = (int*)malloc(sizeof(int) * n);
	//输入n
	Re:
	printf("请输入需要生成的位数:");
	scanf("%d", &n);
	getchar();
	if (n < 1) {
		puts("**请输入大于0的数**");
		goto Re;
	}
	//输入LFSR
	for (int i = 0;i < 3;i++)
		LFSR_c[i] = GetLFSR(i);
	//转化LFSR
	for (int i = 0; i < 3;i++)
		LFSR_i[i] = CharToInt(LFSR_c[i], i);
	//遍历检查
	/*for(int i =0;i < 3;i++)
		DisPlay_INT(LFSR_i[i], MAX[i]);*/
	//获取密钥流
	printf("密钥流是：");
	key = GetKey(LFSR_i, n);
	for (int i = 0; i < n; i++)
		printf("%d", key[i]);
	puts("");
	getchar();
}
char* GetLFSR(int i) {
	char* XX = (char*)malloc(sizeof(char) * MAX[i]);
Re_0:
	printf("请输入%s的初始状态（%d位）:", Lname[i], MAX[i]);
	scanf("%s", XX);
	getchar();
	if (strlen(XX) != MAX[i]) {
		printf("**输入的%s不是%d位**\n", Lname[i], MAX[i]);
		goto Re_0;
	}
	for (int j = 0; j < MAX[i];j++) {
		if (XX[j]!='0'&&XX[j]!='1') {
			puts("**请输入0、1串**");
			goto Re_0;
		}
	}
	return XX;
}
int* CharToInt(char* XX_c, int i) {
	int* XX_i = (int*)malloc(sizeof(int) * MAX[i]);
	for (int j = 0; j < MAX[i]; j++)
		XX_i[j] = XX_c[j] - '0';
	return XX_i;
}
int* GetKey(int** LFSR, int n) {
	int* key = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n;i++) {
		int a = LFSR[0][8] * 4 + LFSR[1][10] * 2 + LFSR[2][10];
		if (a == 0||a == 7) {
			for(int j = 0;j < 3;j++)
				LFSR[j] = RM(LFSR[j],j);
		}
		if (a == 1||a == 6) {
			for (int j = 0; j < 2; j++)
				LFSR[j] = RM(LFSR[j], j);
		}
		if (a == 2||a == 5) {
			LFSR[0] = RM(LFSR[0],0);
			LFSR[2] = RM(LFSR[2],2);
		}
		if (a == 3||a == 4) {
			for (int j = 1; j < 3; j++)
				LFSR[j] = RM(LFSR[j], j);
		}
		key[i] = LFSR[0][MAX[0] - 1] ^ LFSR[1][MAX[1] - 1] ^ LFSR[2][MAX[2] - 1];
	}
	return key;
}
int* RM(int* X,int n) {
	int t = 0;
	if(n == 0)
		t = X[13] ^ X[16] ^ X[17] ^ X[18];
	if (n == 1)
		t = X[20] ^ X[21];
	if (n == 2)
		t = X[7] ^ X[20] ^ X[21] ^ X[22];
	for (int i = MAX[n] - 1; i > 0;i--)
		X[i] = X[i - 1];
	X[0] = t;
	return X;
}
void DisPlay_INT(int* XX, int n) {
	for (int i = 0; i < n; i++) {
		printf("%2d ", XX[i]);
	}
	puts("");
}