# include "AA.h"
void Run() {
	int choice = -1;
Re:
	puts("_____________________");
	puts("|  1�������������  |");
	puts("|  2�������������  |");
	puts("|  0���˳�����      |");
	puts("---------------------");
	printf("��ѡ��");
	scanf("%d",&choice);
	getchar();

	switch (choice)
	{
		case 0:
			puts("**�˳��ɹ�**");
			return;
		case 1:
			GetC();
			break;
		case 2:
			GetM();
			break;
		default:
			puts("**��������Чѡ��**");
			break;
	}
	Clear_screen();
	goto Re;
}
void GetC() {
	//������
	int m = 0, n = 0;//������m,n
	int a = 0, b = 0;//�жϻ�����
	int len = 0;//�������еĳ���
	int* element;//����Ԫ������
	int* key;//��Կ����
	char* M = (char*)malloc(sizeof(char) * 512);
	int* M_2;//���Ķ�����
	int M_2_len = 0;//�����Ķ����Ƶĳ���
	int* C;//����
	int q = 0, r = 0;
	//����Ԫ����
	printf("�����볬�������е�Ԫ�ظ�����");
	scanf("%d", &len);
	getchar();
	element = (int*)malloc(sizeof(int) * len);
	key = (int*)malloc(sizeof(int) * len);
	element = Get_Element(len);
	
	Re:
	printf("������m = ");
	scanf("%d",&m);
	getchar();
	printf("������n = ");
	scanf("%d",&n);
	getchar();
	//�ж�m��n����
	a = m > n ? m : n;
	b = m > n ? n : m;
	
	if (a % b == 0) {
		puts("�����뻥�ʵ�m��n");
		goto Re;
	}
	for (int i = 2; i <= sqrt(b);i++) {
		if (a % i == 0 && b % i == 0 ) {
			puts("�����뻥�ʵ�m��n");
			goto Re;
		}
	}
	//�õ���Կ
	for (int i = 0; i < len;i++)
		*(key + i) = *(element + i) * n % m;
	//��������
	printf("��������Ҫ���ܵ����ģ�");
	scanf("%s",M);
	getchar();
	//�����Ĵ���Ϊ������
	if (strlen(M) * 8 % 6 != 0)
		M_2_len = ((strlen(M) * 8 / 6) + 1) * 6;
	else
		M_2_len = strlen(M) * 8;
	M_2 = (int*)malloc(sizeof(int) * M_2_len);
	memset(M_2,0, M_2_len * sizeof(int));
	
	for (int i = 0; i < strlen(M);i++) {
		q = *(M + i);
		r = *(M + i) % 2;
		for (int j = 7; q != 0; j--) {
			*(M_2 + i * 8 + j)= r;
			q = q / 2;
			r = q % 2;
		}
	}
	puts("���ɵ����Ķ����ƴ�Ϊ��");
	for (int i = 0; i < strlen(M) * 8;i++) {
		printf("%d",*(M_2 + i));
		if (i != 0 && i % 8 == 7)
			printf("  ");
	}
	puts("");
	//�õ���Կ
	C = (int*)malloc(sizeof(int) * M_2_len / 6);
	memset(C,0,sizeof(int) * M_2_len / 6);
	
	for (int i = 0; i < M_2_len; i++) 
		if (M_2[i] == 1 && C[i / 6] == 0)
			C[i / 6] = M_2[i] * key[i % 6];
		else if (M_2[i] == 1)
			C[i / 6] += M_2[i] * key[i % 6];

	printf("���ɵ����Ĵ�Ϊ��");
	for (int i = 0; i < M_2_len / 6;i++)
		printf("%d ",C[i]);
	puts("");
}
void GetM() {
	//������
	int m = 0, n = 0,n_ni = 0;//������m,n
	int a = 0, b = 0;//�жϻ�����
	int len = 0;//�������еĳ���
	int* element;//����Ԫ������
	int* key;//��Կ����
	int* key_2;
	int C_len = 0;
	int* C;
	
	int q = 0, r = 0;
	//����Ԫ����
	printf("�����볬�������е�Ԫ�ظ�����");
	scanf("%d", &len);
	getchar();
	element = (int*)malloc(sizeof(int) * len);
	element = Get_Element(len);

Re:
	printf("������m = ");
	scanf("%d", &m);
	getchar();
	printf("������n = ");
	scanf("%d", &n);
	getchar();
	//�ж�m��n����
	a = m > n ? m : n;
	b = m > n ? n : m;

	if (a % b == 0) {
		puts("�����뻥�ʵ�m��n");
		goto Re;
	}
	for (int i = 2; i <= sqrt(b); i++) {
		if (a % i == 0 && b % i == 0) {
			puts("�����뻥�ʵ�m��n");
			goto Re;
		}
	}
	//�õ�n����Ԫ
	for (int i = 0; i < m - 1;i++)
		if (n * i % m == 1) {
			n_ni = i;
			break;
		}
	//��������
	printf("��������Ҫ���ܵ����ĸ�����");
	scanf("%d",&C_len);
	getchar();
	C = (int*)malloc(sizeof(int) * C_len);
	key = (int*)malloc(sizeof(int) * C_len);
	for (int i = 0; i < C_len;i++) {
		printf("�������%d�����ģ�",i + 1);
		scanf("%d",C + i);
		getchar();
	}
	for (int i = 0; i < C_len; i++)
		*(key + i) = n_ni * *(C + i) % m;
	//�ֽ�Ϊ������
	key_2 = (int*)malloc(sizeof(int) * len * C_len);
	memset(key_2,0,sizeof(int) * len * C_len);
	
	for (int i = 0,difference = 0;i < len * C_len;i++) {
		if (i % len == 0) 
			if (key[i / len] >= element[len - 1 - (i % len)]) {
				difference = key[i / len] - element[len - 1 - (i % len)];
				key_2[(i / len) * len + (len - 1 - (i % len))] = 1;
			}
			else
				difference = key[i / len];
		else 
			if (difference >= element[len - 1 - (i % len)]) {
				difference -= element[len - 1 - (i % len)];
				key_2[(i / len) * len + (len - 1 - (i % len))] = 1;
			}
	}
	for (int i = 0; i < len * C_len;i++) {
		printf("%d", key_2[i]);
		if (i % len == len - 1)
			printf("  ");
	}
	puts("");
	//�õ�����
	unsigned char* M = (unsigned char*)malloc(sizeof(char) * len * C_len / 8);
	for (int i = 0; i < (len * C_len / 8) * 8;i++) {
		if (i % 8 == 0)
			M[i / 8] = key_2[i] * (int)pow(2,7 - (i % 8));
		else
			M[i / 8] += key_2[i] * (int)pow(2,7 - (i % 8));
	}
	M[len * C_len / 8] = '\0';
	printf("���ܺ�Ľ���ǣ�%s\n",M);
}
int* Get_Element(int len) {
	int* element = (int*)malloc(sizeof(int) * len);
	int sum = 0;
	for (int i = 0; i < len;i++) {
		Re:
		printf("�������%d��Ԫ�أ�",i + 1);
		scanf("%d",(element + i));
		getchar();
		if (*(element + i) > sum)
			sum += *(element + i);
		else {
			puts("**�������ǳ��������е���**");
			goto Re;
		}	
	}
	return element;
}
int GetN(int b) {
	int n = 1;
	for (int q = b / 2; q != 0; q /= 2)
		n++;
	return n;
}
void Clear_screen() {
	puts("**����س������**");
	getchar();
	system("cls");
}