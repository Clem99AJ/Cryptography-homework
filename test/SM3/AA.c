# include "AA.h"
int length = 0;
unsigned int T1 = 0x79CC4519;
unsigned int T2 = 0x7A879D8A;
unsigned int H[8] = { 0x7380166F,0x4914B2B9,0x172442D7,0xDA8A0600,0xA96F30BC,0x163138AA,0xE38DEE4D,0xB0FB0E4E };
void Run() {
	int choice = -1;
RE:
	puts("-------------");
	puts("|====SM4====|");
	puts("|1、键盘输入|");
	puts("|0、退出程序|");
	puts("-------------");
	printf("请选择：");
	scanf("%d", &choice);
	getchar();

	switch (choice) {
	case 0:
		puts("**退出成功**");
		return;
	case 1:
		SGetC();
		break;
	default:
		puts("**请输入有效选项**");
	}
	Clean();
	goto RE;
}
void SGetC() {
	unsigned char* M = (unsigned char*)malloc(sizeof(char) * MAX);
	printf("请输入明文：");
	scanf("%[^\n]s", M);
	getchar();
	GetC(M);
}
void GetC(unsigned char* M) {
	unsigned int* M_16N;
	unsigned int* M_16 = (unsigned int*)malloc(sizeof(int) * 16);
	M_16N = GetM_16N(M);
	//输出检查M_16N
	//DisPlay(M_16N,length);
	for (int i = 0; i < length; i++) {
		M_16[i % 16] = M_16N[i % 16];
		if (i != 0 && i % 16 == 15)
			Fun(M_16);
	}
}
int Getn(int len) {
	int n = 1;
	length = len * 8;
	for (int i = length / 256; i > 256; i /= 256)
		n++;
	return n;
}
int* GetM_16N(unsigned char* M) {
	unsigned int* M_16;
	int len = strlen(M);
	int q = len / 64;
	int r = len % 64;
	int n = Getn(len);
	if (r <= 56) {
		M_16 = (unsigned int*)malloc(sizeof(int) * (q + 1) * 16);
		for (int i = 0; i < q * 64 + r; i++)
			if (i % 4 == 0)
				M_16[i / 4] = M[i] * (unsigned int)pow(256, 3 - (i % 4));
			else
				M_16[i / 4] += M[i] * (unsigned int)pow(256, 3 - (i % 4));
		for (int i = q * 64 + r; i < (q + 1) * 64; i++) {
			unsigned int m = 0;
			if (i == q * 64 + r)
				m = 0x80;
			else
				m = 0;
			if (i % 4 == 0)
				M_16[i / 4] = m * (unsigned int)pow(256, 3 - (i % 4));
			else
				M_16[i / 4] += m * (unsigned int)pow(256, 3 - (i % 4));
		}
		for (int i = (q + 1) * 64 - n, j = n; i < (q + 1) * 64; i++, j--) {
			unsigned int m = 0;
			if (j < 2)
				m = length;
			else
				m = length / (int)pow(256, j - 1) % (int)pow(256, j - 2);
			if (i % 4 == 0)
				M_16[i / 4] = m * (unsigned int)pow(256, 3 - (i % 4));
			else
				M_16[i / 4] += m * (unsigned int)pow(256, 3 - (i % 4));
		}
		length = (q + 1) * 16;
	}
	else {
		len = 64 + q * 64 + (64 - r);
		q++;
		r -= 56;
		M_16 = (unsigned int*)malloc(sizeof(int) * (q + 1) * 16);
		for (int i = 0; i < q * 64 + r; i++)
			if (i % 4 == 0)
				M_16[i / 4] = M[i] * (unsigned int)pow(256, 3 - (i % 4));
			else
				M_16[i / 4] += M[i] * (unsigned int)pow(256, 3 - (i % 4));
		for (int i = q * 64 + r; i < (q + 1) * 64; i++) {
			unsigned int m = 0;
			if (i == q * 64 + r)
				m = 0x80;
			else
				m = 0;
			if (i % 4 == 0)
				M_16[i / 4] = m * (unsigned int)pow(256, 3 - (i % 4));
			else
				M_16[i / 4] += m * (unsigned int)pow(256, 3 - (i % 4));
		}
		for (int i = (q + 1) * 64 - n, j = n; i < (q + 1) * 64; i++, j--) {
			unsigned int m = 0;
			if (j < 2)
				m = length;
			else
				m = length / (int)pow(256, j - 1) % (int)pow(256, j - 2);
			if (i % 4 == 0)
				M_16[i / 4] = m * (unsigned int)pow(256, 3 - (i % 4));
			else
				M_16[i / 4] += m * (unsigned int)pow(256, 3 - (i % 4));
		}
		length = (q + 1) * 16;
	}
	puts("");
	return M_16;
}
void Fun(unsigned int* M_16) {
	unsigned int* W = (unsigned int)malloc(sizeof(int) * 68);
	unsigned int* W_1 = (unsigned int)malloc(sizeof(int) * 64);
	//消息扩展
	for (int i = 0; i < 68;i++)
		if (i < 16) 
			W[i] = M_16[i];
		else
			W[i] = P_1(W[i - 16]^W[i - 9]^ RL(W[i-3], 15)) ^ (RL(W[i-13], 7)) ^ W[i - 6];
	for (int i = 0; i < 64;i++)
		W_1[i] = W[i] ^ W[i + 4];
	//压缩函数
	unsigned int* IV = (unsigned int*)malloc(sizeof(int) * 8);
	unsigned int SS1, SS2, TT1, TT2;
	for (int i = 0; i < 8;i++)
		IV[i] = H[i];
	for (int i = 0; i < 64;i++) {
		if (i < 16) {
			SS1 = RL((RL(IV[0], 12) + IV[4] + RL(T1,i)), 7);
			SS2 = SS1 ^ RL(IV[0],12);
			TT1 = FF1(IV[0], IV[1], IV[2]) + IV[3] + SS2 + W_1[i];
			TT2 = GG1(IV[4], IV[5], IV[6]) + IV[7] + SS1 + W[i];
		}
		else {
			SS1 = RL((RL(IV[0], 12) + IV[4] + RL(T2, i)), 7);
			SS2 = SS1 ^ RL(IV[0], 12);
			TT1 = FF2(IV[0], IV[1], IV[2]) + IV[3] + SS2 + W_1[i];
			TT2 = GG2(IV[4], IV[5], IV[6]) + IV[7] + SS1 + W[i];
		}
		IV[3] = IV[2];
		IV[2] = RL(IV[1], 9);
		IV[1] = IV[0];
		IV[0] = TT1;
		IV[7] = IV[6];
		IV[6] = RL(IV[5], 19);
		IV[5] = IV[4];
		IV[4] = P_0(TT2);
	}

	for (int i = 0; i < 8;i++)
		IV[i] ^= H[i];
	printf("SM3 Code:");
	for (int i = 0; i < 8; i++)
		printf("%08X",IV[i]);
	puts("");
}
void DisPlay(int* XX, int n) {
	for (int i = 0; i < n; i++) {
		if (i != 0 && i % 4 == 0)
			puts("");
		printf("%08X ", XX[i]);
	}
	puts("");
}
void Clean() {
	puts("**输入回车后继续**");
	getchar();
	system("cls");
}