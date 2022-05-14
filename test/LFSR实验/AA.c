# include "AA.h"
void Run() {
	//�������
	int n = 0;
Re_01:
	printf("������������λ�Ĵ����Ľ���(n > 2):");
	scanf("%d", &n);
	getchar();
	if (n <= 2) {
		puts("���������2�Ľ���");
		goto Re_01;
	}
	//����ϵ��
	char* xishu_c = (char *)malloc(sizeof(char) * (n + 1));
	int* xishu_i = (int*)malloc(sizeof(int) * n);
Re_02:
	printf("�����뷴�������е�ϵ��(��a%d��a1��˳��):", n);
	scanf("%s",xishu_c);
	getchar();
	if (strlen(xishu_c) != n) {
		printf("**���벻��%dλ**\n",n);
		goto Re_02;
	}
	if (Judge(xishu_c)==0) {
		puts("**ֻ������0��1����**");
		goto Re_02;
	}
	xishu_i = CharToInt(xishu_c);
	//�����ʼ״̬
	char* chushi_c = (char*)malloc(sizeof(char) * (n + 1));
	int* chushi_i = (int*)malloc(sizeof(int) * n);
Re_03:
	printf("�������ʼ״̬(��a%d��a1��˳��):", n);	
	scanf("%s", chushi_c);
	getchar();
	if (strlen(chushi_c) != n) {
		printf("**���벻��%dλ**\n",n);
		goto Re_03;
	}
	if (Judge(chushi_c) == 0) {
		puts("**ֻ������0��1����**");
		goto Re_03;
	}
	chushi_i = CharToInt(chushi_c);
	//��ʼ�õ���Կ��չ
	int T = Get_oneT(xishu_i, chushi_i, n);
	int* key = (int*)malloc(sizeof(int) * (T + 1));
	key = GetKey(xishu_i, chushi_i, n, T);
	DisPlay_Int_N(key, T + 1);
	printf("����Ϊ%d\n", T);
	//�ӽ���
	JiaMi(key, T);
}
int Judge(char* XX){
	int j = 1;
	for (int i = 0; i < strlen(XX);i++)
		if (XX[i] != '0' && XX[i] != '1')
			j = 0;
	return j;
}
int* CharToInt(char* XX_c) {
	int* XX_i = (int*)malloc(sizeof(int) * strlen(XX_c));
	for (int i = 0; i < strlen(XX_c);i++)
		XX_i[i] = XX_c[i] - '0';
	return XX_i;
}
int Get_oneT(int* xishu, int* chushi,int n) {
	int* temp = (int*)malloc(sizeof(int) * n);
	int t;
	for (int i = 0; 1; i++) {
		if (i == 0)
			for (int j = 0; j < n; j++)
				temp[j] = chushi[j];
		else {
			//������������һ����Ȼ����������
			for (int j = n - 1; j >= 0;j--)
				temp[j] = temp[j - 1];
			temp[0] = t;
		}
		//�õ���Ӧ�������
		t = -1;
		for (int j = 0; j < n;j++) {
			if (xishu[j]){
				if (t == -1) {
					t = temp[j];
				}
				else {
					t = t ^ temp[j];
				}
			}
		}
		printf("t%dʱ�̵�״̬��:",i);
		DisPlay_Int_N(temp, n);
		//�ж��Ƿ���˳�
		if (i != 0)
			for (int j = 0; j <= n; j++)
				if (j == n)
					return i;
				else if (chushi[j] != temp[j])
					break;
	}
}
int* GetKey(int* xishu, int* chushi, int n,int T) {
	int* key = (int*)malloc(sizeof(int) * (T + 1));
	for (int i = 0; i < n;i++) {
		key[i] = chushi[n - i - 1];
	}
	for (int i = n; i < T + 1;i++) {
		int t;
		t = -1;
		for (int j = 0; j < n;j++) {
			if (xishu[j]) {
				if (t == -1) {
					t = key[i - n + j];
				}else {
					t = t ^ key[i - n + j];
				}
			}
		}
		key[i] = t;
	}
	return key;
}
void JiaMi(int* key, int T) {
	FILE* Mfp = NULL;
	FILE* Cfp = NULL;
	unsigned char *ch_M = (unsigned char*)malloc(sizeof(char));
	unsigned char *ch_C = (unsigned char*)malloc(sizeof(char));
	*ch_C = '0';
	char MPath[PATHMAX];
	char CPath[PATHMAX];
Re_1:
	printf("��������Ҫ����(����)���ļ�·��:");
	scanf("%s", MPath);
	getchar();
	Mfp = fopen(MPath, "r");
	if (Mfp == NULL) {
		puts("**���ļ�������**");
		goto Re_1;
	}
	printf("������д������(����)���ļ�·��:");
	scanf("%s", CPath);
	getchar();
	//��д������
	Cfp = fopen(CPath, "w+");
	//����Ԥ��ȡ����ѭ������������
	int len = fread(ch_M, sizeof(char), 1, Mfp);
	int t_i = 0;
	int j = 0;
	for (int i = 0; len > 0;i++) {
		t_i = 0;
		for (int k = 0; k < 8; j++, k++)
			t_i += key[(i * 8 + j) % T] * (int)pow(2, 7 - k);
		j--;
		//printf("�գ�%d\n",t_i);
		*ch_C = (unsigned char)t_i ^ (unsigned char)*ch_M;
		//���б����д�룬����һ��Ķ�ȡ
		fwrite(ch_C, sizeof(char), 1, Cfp);
		len = fread(ch_M, sizeof(char), 1, Mfp);
	}
	//�ر��ļ���
	fclose(Mfp);
	fclose(Cfp);
	puts("**����(����)�������ɹ�**");
}
void DisPlay_Int_N(int* XX, int n) {
	for (int i = 0; i < n;i++)
		printf("%d ",XX[i]);
	puts("");
}