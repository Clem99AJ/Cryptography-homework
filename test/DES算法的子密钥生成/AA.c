# include"AA.h"
const int ROL_TIMES[16] = { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };
const int PC_1[56] = { 56, 48, 40, 32, 24, 16, 8, 0,
					   57, 49, 41, 33, 25, 17, 9, 1,
					   58, 50, 42, 34, 26, 18, 10, 2,
					   59, 51, 43, 35, 62, 54, 46, 38,
					   30, 22, 14, 6, 61, 53, 45, 37,
					   29, 21, 13, 5, 60, 52, 44, 36,
					   28, 20, 12, 4, 27, 19, 11, 3 };
const int PC_2[48] = { 13, 16, 10, 23, 0, 4, 2, 27,
					   14, 5, 20, 9, 22, 18, 11, 3,
					   25, 7, 15, 6, 26, 19, 12, 1,
					   40, 51, 30, 36,46, 54, 29, 39,
					   50, 44, 32, 46, 43, 48, 38, 55,
					   33, 52, 45, 41, 49, 35, 28, 31 };
void Run() {
	char* key = (char*)malloc(MAX * sizeof(char));
	int* key2 = (int*)malloc(64 * sizeof(int));//���64λ]
	int* key3 = (int*)malloc(56 * sizeof(int));//���56λ]--->������
	int* key4 = (int*)malloc(48 * sizeof(int));//���48λ]
	int* key5 = (int*)malloc(12 * sizeof(int));//���ʮ�����Ƶ�12��λ��
	RE:
	printf("������8�ֽڵ���Կ��");
	scanf("%s",key);
	getchar();
	if (strlen(key) > 8) {
		printf("**���벻�ܴ���8λ**");
		goto RE;
	}
	else if (strlen(key) < 8) {
		key = geteightKey(key);
	}
	key2 = Get64Bit(key);
	//readKey(key2,64);
	key3 = GetPC_1Key(key2);
	//readKey(key3,56);

	//���ﻹ��ѭ������
	for (int i = 0; i < 16; i++) {
		key3 = GetRemoveKey(key3, ROL_TIMES[i]);
		key4 = GetPC_2Key(key3);
		key5 = Get12Key(key4);
		printf("��%d�����ɵ�����Կ�ǣ�",i + 1);
		read16Key(key5, 12);
	}
}
char *geteightKey(char* key) {
	for (int i = strlen(key); i < 8; i++)
		key[i] =0x0;
	key[8] = '\0';
	return key;
}
int* Get64Bit(char *ch) {
	int * bit = (int*)malloc(sizeof(int)*64);
	memset(bit,0, sizeof(int) * 64);
	for (int i = 0;i < 8;i++) {
		int q = *(ch + i);
		int r = *(ch + i) % 2;
		for (int j = 7;j >= 0 ;j--) {
			if (q != 0 && r != 0) {
				bit[i * 8 + j] = r;
			}
			q = q / 2;
			r = q % 2;
		}
	}
	bit[64] = '\0';
	return bit;
}
int* GetPC_1Key(int *key) {
	int* key2 = (int*)malloc(sizeof(int)*56);
	memset(key2, 0, sizeof(int) * 56);
	for (int i = 0; i < 56; i++) {
		*(key2 + i) = key[PC_1[i]];
	}
	return key2;
}
int* GetRemoveKey(int* key,int t) {
	int* temp = (int*)malloc(sizeof(int) * t);
	//ԭ������memset(temp,key,t);  ������Ϊ���ǿ������ת����int*תΪchar*���·���Ŀռ��������
	//������forʵ��
	//��ǰ28�����в���
	for (int i = 0; i < t;i++) {
		*(temp + i) = *(key + i);
	}
	for (int i = t; i < 28; i++) {
		*(key + i - t) = *(key + i);
	}
	for (int i = 28 - t,j = 0; i < 28; i++,j++) {
		*(key + i) = *(temp + j);
	}
	//�Ժ�28�����в���
	for (int i = 28; i < 28 + t;i++) {
		*(temp + i - 28) = *(key + i);
	}
	for (int i = t + 28; i < 56; i++) {
		*(key + i - t) = *(key + i);
	}
	for (int i = 56 - t, j = 0; i < 56; i++, j++) {
		*(key + i) = *(temp + j);
	}
	//readKey(key,56);
	return key;
}
int* GetPC_2Key(int* key) {
	int* key2 = (int*)malloc(sizeof(int) * 48);
	memset(key2, 0, sizeof(int) * 48);
	for (int i = 0; i < 48; i++) {
		*(key2 + i) = key[PC_2[i]];
	}
	return key2;
}
int* Get12Key(int* key) {
	int* key2 = (int*)malloc(sizeof(int) * 12);
	for (int i = 0; i < 12;i++) {
		int num = 0;
		for (int j = 3; j >= 0; j--) {
			num += (int)pow(2,3 - j) * (*((key + i * 4) + j));
			//printf("(%d,%d) = %d\n", (int)pow(2, 3 - j), (*((key + i * 4) + j)),num);
		}
		*(key2 + i) = num;
	}
	return key2;
}
void readKey(int* key,int n) {
	for (int i = 0; i < n; i++) {
		if (i % 8 == 0)
			puts("");
		printf("%d ", *(key + i));
	}
	puts("");
}
void read16Key(int* key,int n) {
	for (int i = 0; i < n; i++) {
		printf("%X", *(key + i));
	}
	puts("");
}