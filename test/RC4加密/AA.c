# include "AA.h"
int SBox[256] = {0};
int SBox_key[256] = {0};
void Run() {
	int choice = -1;
Re:
	Menu();
	scanf("%d",&choice);
	getchar();
	switch (choice)
	{
		case 0:
			puts("**退出成功**");
			return;
		case 1:
			Fun();
			break;
		case 2:
			Fun();
			break;
	default:
		puts("**请输入有效选项**");
		break;
	}
	Clean();
	goto Re;
}
void Menu() {
	puts("---------------");
	puts("| 1、RC4加密  |");
	puts("| 2、RC4解密  |");
	puts("|  0、退出    |");
	puts("---------------");
	printf("请选择:");
}
void Fun() {
	FILE* Mfp = NULL;
	FILE* Cfp = NULL;
	char MPath[MAX];
	char CPath[MAX];
	unsigned char* key = (char*)malloc(sizeof(char) * MAX);
	int len = 0;
	Re:
	printf("请输入明文（密文）的路径：");
	scanf("%s",MPath);
	getchar();
	Mfp = fopen(MPath,"r");
	if (Mfp == NULL) {
		puts("**请输入有效路径**");
		goto Re;
	}
	printf("请输入加密（解密）后保存的路径：");
	scanf("%s",CPath);
	getchar();
	//读取文件的字节
	fseek(Mfp,0,SEEK_END);
	len = ftell(Mfp);
	printf("文件大小为：%d字节\n",len);
	unsigned char * M = (unsigned char*)malloc(sizeof(char) * len);
	unsigned char * C = (unsigned char*)malloc(sizeof(char) * len);
	fseek(Mfp, 0, SEEK_SET);
	fread(M,sizeof(char) * len,1,Mfp);
	M[len] = '\0';
	printf("读取的文件内容是：%s\n",M);
	//输入密钥
	printf("请输入密钥：");
	scanf("%[^\n]s",key);
	getchar();
	//加密（或解密）
	C = GetC(M,key);
	C[len] = '\0';
	printf("加密（解密）后的结果为：%s\n",C);
	Cfp = fopen(CPath, "w+");
	fwrite(C,sizeof(char) * len,1,Cfp);
	//关闭流
	fclose(Mfp);
	fclose(Cfp);
}
unsigned char* GetC(unsigned char *M, unsigned char* key) {
	unsigned char* C = (unsigned char*)malloc(sizeof(char) * strlen(M));
	//初始化S盒
	InitializationSBox();
	InitializationSBox_key(key);
	//检查初始化结果
	//DisPlay_SBox(SBox);
	//DisPlay_SBox(SBox_key);
	//扰乱S盒
	Mix_XBox();
	puts("扰乱后的S盒为：");
	DisPlay_SBox(SBox);
	//加密
	for (int t = 0, i = 0, j = 0; t < strlen(C); t++) {
		i = (i + 1) % 256;
		j = (j + SBox[i]) % 256;
		int temp = SBox[i];
		SBox[i] = SBox[j];
		SBox[j] = temp;
		C[t] = (int)M[t] ^ SBox[(SBox[i] + SBox[j]) % 256];
	}
	return C;
}
void InitializationSBox() {
	for (int i = 0; i < 256; i++)
		SBox[i] = i;
}
void InitializationSBox_key(unsigned char* key) {
	for (int i = 0; i < 256;i++)
		SBox_key[i] = key[i % strlen(key)];
}
void Mix_XBox() {
	for (int i = 0,j = 0; i < 256;i++) {
		j = (j + SBox[i] + SBox_key[i]) % 256;
		int t = SBox[i];
		SBox[i] = SBox[j];
		SBox[j] = t;
	}
}
void DisPlay_SBox(int* SBOX) {
	for (int i = 0; i < 256; i++) {
		if (i != 0 && i % 16 == 0)
			puts("");
		printf("%2X ",SBOX[i]);
	}
	puts("");
}
void Clean() {
	puts("**输入回车后继续**");
	getchar();
	system("cls");
}