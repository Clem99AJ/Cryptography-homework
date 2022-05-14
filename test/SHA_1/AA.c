# include "AA.h"
unsigned int ABCDE[5] = { 0x67452301,0xEFCDAB89,0x98BADCFE,0x10325476,0xC3D2E1F0};
const unsigned int Kt[4] = {0x5A827999,0x6ED9EBA1,0x8F1BBCDC,0xCA62C1D6};
int length = 0;
void Run() {
	int choice = -1;
RE:
	puts("-------------");
	puts("|===SHA-1===|");
	puts("|1、键盘输入|");
	puts("|2、文件输入|");
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
	case 2:
		FGetC();
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
void FGetC() {
	unsigned char* M = (unsigned char*)malloc(sizeof(char) * MAX);
	char filepath[100];
	FILE* f = NULL;
	int len = 0;
	Re:
	printf("请输入需要加密的路径：");
	scanf("%s",filepath);
	getchar();
	f = fopen(filepath,"r");
	if (f == NULL) {
		puts("**文件不存在**");
		goto Re;
	}
	fseek(f,0,SEEK_END);
	len = ftell(f);
	fseek(f,0,SEEK_SET);
	fread(M,sizeof(unsigned char)*len,1,f);
	fclose(f);
	M[len] = '\0';
	printf("%s",M);
	GetC(M);
}
void GetC(unsigned char* M) {
	unsigned int* M_16N;
	unsigned int* M_16 = (unsigned int*)malloc(sizeof(int) * 16);
	unsigned int* M_80 = (unsigned int*)malloc(sizeof(int) * 80);
	unsigned int* c = (unsigned int*)malloc(sizeof(int) * 5);
	M_16N = GetM_16N(M);
	//输出检查M_16N
	DisPlay(M_16N, length);
	puts("");
	ReSet_ABCDE();
	for (int i = 0; i < length;i++) {
		M_16[i % 16] = M_16N[i];
		if (i != 0 && i % 16 == 15) {
			M_80 = GetM_80(M_16);
			//输出检查
			//DisPlay(M_80, 80);
			c = Fun(M_80);	
			//对下一组初始变量赋值
			for (int i = 0; i < 5; i++)
				ABCDE[i] = c[i];
			printf("SHA-1 Code:");
			for (int i = 0; i < 5; i++) {
				printf("%08X", c[i]);
			}
			puts("");
		}
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
				M_16[i / 4] += M[i] * (unsigned int)pow(256,3 - (i % 4));
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
		for (int i = (q + 1) * 64 - n, j = n; i < (q + 1) * 64; i++, j--){
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
		M_16 = (unsigned int*)malloc(sizeof(int) * (q + 2) * 16);
		for (int i = 0; i < q * 64 + r; i++)
			if (i % 4 == 0)
				M_16[i / 4] = M[i] * (unsigned int)pow(256, 3 - (i % 4));
			else
				M_16[i / 4] += M[i] * (unsigned int)pow(256, 3 - (i % 4));
		for (int i = q * 64 + r; i < (q + 2) * 64; i++) {
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
		for (int i = (q + 2) * 64 - n, j = n; i < (q + 2) * 64; i++, j--) {
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
		length = (q + 2) * 16;
	}
	return M_16;
}
int* GetM_80(unsigned int* M_16) {
	unsigned int* M_80 = (unsigned int*)malloc(sizeof(int) * 80);
	for (int i = 0; i < 80;i++) {
		if (i < 16)
			M_80[i] = M_16[i];
		else
			M_80[i] = RL(M_80[i - 3] ^ M_80[i - 8] ^ M_80[i - 14] ^ M_80[i - 16], 1);
	}
	return M_80;
}
unsigned int* Fun(unsigned int* M_80) {
	unsigned int* abcde = (unsigned int*)malloc(sizeof(int) * 5);
	for (int i = 0; i < 5; i++)
		abcde[i] = ABCDE[i];
	for (int i = 0; i < 80;i++) {
		unsigned int temp = 0;
		if (i < 20)
			temp = RL(abcde[0], 5) + f1(abcde[1], abcde[2], abcde[3]) + abcde[4] + M_80[i] + Kt[0];
		else if (i < 40) 
			temp = RL(abcde[0], 5) + f2(abcde[1], abcde[2], abcde[3]) + abcde[4] + M_80[i] + Kt[1];
		else if (i < 60)
			temp = RL(abcde[0], 5) + f3(abcde[1], abcde[2], abcde[3]) + abcde[4] + M_80[i] + Kt[2];
		else if (i < 80)
			temp = RL(abcde[0], 5) + f4(abcde[1], abcde[2], abcde[3]) + abcde[4] + M_80[i] + Kt[3];
		//printf("第%d步：a=[%08X],M[%d]=[%08X]\n",i+1,abcde[0],i,M_80[i]);
		//printf("%08X  %08X  %08X %08X  %08X\n", RL(abcde[0], 5), f1(abcde[1], abcde[2], abcde[3]), abcde[4], M_80[i], Kt[0]);
		abcde[4] = abcde[3];
		abcde[3] = abcde[2];
		abcde[2] = RL(abcde[1],30);
		abcde[1] = abcde[0];
		abcde[0] = temp;
	}
	for (int i = 0; i < 5; i++) {
		abcde[i]+=ABCDE[i];
	}
	return abcde;
}
void DisPlay(int* XX,int n) {
	for (int i = 0; i < n; i++) {
		if (i != 0 && i % 4 == 0)
			puts("");
		printf("%08X ", XX[i]);
	}
	puts("");
}
void ReSet_ABCDE() {
	ABCDE[0] = 0x67452301;
	ABCDE[1] = 0xEFCDAB89;
	ABCDE[2] = 0x98BADCFE;
	ABCDE[3] = 0x10325476;
	ABCDE[4] = 0xC3D2E1F0;
}
void Clean() {
	puts("**输入回车后继续**");
	getchar();
	system("cls");
}