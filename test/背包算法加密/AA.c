# include "AA.h"
void Run() {
	int choice = -1;
Re:
	puts("_____________________");
	puts("|  1、背包问题加密  |");
	puts("|  2、背包问题解密  |");
	puts("|  0、退出程序      |");
	puts("---------------------");
	printf("请选择：");
	scanf("%d",&choice);
	getchar();

	switch (choice)
	{
		case 0:
			puts("**退出成功**");
			return;
		case 1:
			GetC();
			break;
		case 2:
			GetM();
			break;
		default:
			puts("**请输入有效选项**");
			break;
	}
	Clear_screen();
	goto Re;
}
void GetC() {
	//变量区
	int m = 0, n = 0;//单纯的m,n
	int a = 0, b = 0;//判断互质用
	int len = 0;//输入序列的长度
	int* element;//序列元素数组
	int* key;//公钥数组
	char* M = (char*)malloc(sizeof(char) * 512);
	int* M_2;//明文二进制
	int M_2_len = 0;//总明文二进制的长度
	int* C;//密文
	int q = 0, r = 0;
	//输入元素区
	printf("请输入超递增序列的元素个数：");
	scanf("%d", &len);
	getchar();
	element = (int*)malloc(sizeof(int) * len);
	key = (int*)malloc(sizeof(int) * len);
	element = Get_Element(len);
	
	Re:
	printf("请输入m = ");
	scanf("%d",&m);
	getchar();
	printf("请输入n = ");
	scanf("%d",&n);
	getchar();
	//判断m和n互质
	a = m > n ? m : n;
	b = m > n ? n : m;
	
	if (a % b == 0) {
		puts("请输入互质的m和n");
		goto Re;
	}
	for (int i = 2; i <= sqrt(b);i++) {
		if (a % i == 0 && b % i == 0 ) {
			puts("请输入互质的m和n");
			goto Re;
		}
	}
	//得到公钥
	for (int i = 0; i < len;i++)
		*(key + i) = *(element + i) * n % m;
	//输入明文
	printf("请输入需要加密的明文：");
	scanf("%s",M);
	getchar();
	//把明文处理为二进制
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
	puts("生成的明文二进制串为：");
	for (int i = 0; i < strlen(M) * 8;i++) {
		printf("%d",*(M_2 + i));
		if (i != 0 && i % 8 == 7)
			printf("  ");
	}
	puts("");
	//得到密钥
	C = (int*)malloc(sizeof(int) * M_2_len / 6);
	memset(C,0,sizeof(int) * M_2_len / 6);
	
	for (int i = 0; i < M_2_len; i++) 
		if (M_2[i] == 1 && C[i / 6] == 0)
			C[i / 6] = M_2[i] * key[i % 6];
		else if (M_2[i] == 1)
			C[i / 6] += M_2[i] * key[i % 6];

	printf("生成的密文串为：");
	for (int i = 0; i < M_2_len / 6;i++)
		printf("%d ",C[i]);
	puts("");
}
void GetM() {
	//变量区
	int m = 0, n = 0,n_ni = 0;//单纯的m,n
	int a = 0, b = 0;//判断互质用
	int len = 0;//输入序列的长度
	int* element;//序列元素数组
	int* key;//公钥数组
	int* key_2;
	int C_len = 0;
	int* C;
	
	int q = 0, r = 0;
	//输入元素区
	printf("请输入超递增序列的元素个数：");
	scanf("%d", &len);
	getchar();
	element = (int*)malloc(sizeof(int) * len);
	element = Get_Element(len);

Re:
	printf("请输入m = ");
	scanf("%d", &m);
	getchar();
	printf("请输入n = ");
	scanf("%d", &n);
	getchar();
	//判断m和n互质
	a = m > n ? m : n;
	b = m > n ? n : m;

	if (a % b == 0) {
		puts("请输入互质的m和n");
		goto Re;
	}
	for (int i = 2; i <= sqrt(b); i++) {
		if (a % i == 0 && b % i == 0) {
			puts("请输入互质的m和n");
			goto Re;
		}
	}
	//得到n的逆元
	for (int i = 0; i < m - 1;i++)
		if (n * i % m == 1) {
			n_ni = i;
			break;
		}
	//接收密文
	printf("请输入需要解密的密文个数：");
	scanf("%d",&C_len);
	getchar();
	C = (int*)malloc(sizeof(int) * C_len);
	key = (int*)malloc(sizeof(int) * C_len);
	for (int i = 0; i < C_len;i++) {
		printf("请输入第%d个密文：",i + 1);
		scanf("%d",C + i);
		getchar();
	}
	for (int i = 0; i < C_len; i++)
		*(key + i) = n_ni * *(C + i) % m;
	//分解为二进制
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
	//得到明文
	unsigned char* M = (unsigned char*)malloc(sizeof(char) * len * C_len / 8);
	for (int i = 0; i < (len * C_len / 8) * 8;i++) {
		if (i % 8 == 0)
			M[i / 8] = key_2[i] * (int)pow(2,7 - (i % 8));
		else
			M[i / 8] += key_2[i] * (int)pow(2,7 - (i % 8));
	}
	M[len * C_len / 8] = '\0';
	printf("解密后的结果是：%s\n",M);
}
int* Get_Element(int len) {
	int* element = (int*)malloc(sizeof(int) * len);
	int sum = 0;
	for (int i = 0; i < len;i++) {
		Re:
		printf("请输入第%d个元素：",i + 1);
		scanf("%d",(element + i));
		getchar();
		if (*(element + i) > sum)
			sum += *(element + i);
		else {
			puts("**请输入是超递增序列的数**");
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
	puts("**输入回车后继续**");
	getchar();
	system("cls");
}