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
			puts("**�˳��ɹ�**");
			return;
		case 1:
			Fun();
			break;
		case 2:
			Fun();
			break;
	default:
		puts("**��������Чѡ��**");
		break;
	}
	Clean();
	goto Re;
}
void Menu() {
	puts("---------------");
	puts("| 1��RC4����  |");
	puts("| 2��RC4����  |");
	puts("|  0���˳�    |");
	puts("---------------");
	printf("��ѡ��:");
}
void Fun() {
	FILE* Mfp = NULL;
	FILE* Cfp = NULL;
	char MPath[MAX];
	char CPath[MAX];
	unsigned char* key = (char*)malloc(sizeof(char) * MAX);
	int len = 0;
	Re:
	printf("���������ģ����ģ���·����");
	scanf("%s",MPath);
	getchar();
	Mfp = fopen(MPath,"r");
	if (Mfp == NULL) {
		puts("**��������Ч·��**");
		goto Re;
	}
	printf("��������ܣ����ܣ��󱣴��·����");
	scanf("%s",CPath);
	getchar();
	//��ȡ�ļ����ֽ�
	fseek(Mfp,0,SEEK_END);
	len = ftell(Mfp);
	printf("�ļ���СΪ��%d�ֽ�\n",len);
	unsigned char * M = (unsigned char*)malloc(sizeof(char) * len);
	unsigned char * C = (unsigned char*)malloc(sizeof(char) * len);
	fseek(Mfp, 0, SEEK_SET);
	fread(M,sizeof(char) * len,1,Mfp);
	M[len] = '\0';
	printf("��ȡ���ļ������ǣ�%s\n",M);
	//������Կ
	printf("��������Կ��");
	scanf("%[^\n]s",key);
	getchar();
	//���ܣ�����ܣ�
	C = GetC(M,key);
	C[len] = '\0';
	printf("���ܣ����ܣ���Ľ��Ϊ��%s\n",C);
	Cfp = fopen(CPath, "w+");
	fwrite(C,sizeof(char) * len,1,Cfp);
	//�ر���
	fclose(Mfp);
	fclose(Cfp);
}
unsigned char* GetC(unsigned char *M, unsigned char* key) {
	unsigned char* C = (unsigned char*)malloc(sizeof(char) * strlen(M));
	//��ʼ��S��
	InitializationSBox();
	InitializationSBox_key(key);
	//����ʼ�����
	//DisPlay_SBox(SBox);
	//DisPlay_SBox(SBox_key);
	//����S��
	Mix_XBox();
	puts("���Һ��S��Ϊ��");
	DisPlay_SBox(SBox);
	//����
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
	puts("**����س������**");
	getchar();
	system("cls");
}