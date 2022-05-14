# include "AA.h"

void Run() {
	int choice = 0;
	RE:
	printf("----------\n");
	printf("|1、加密 |\n");
	printf("|2、解密 |\n");
	printf("|0、退出 |\n");
	printf("----------\n");
	printf("请输入你的选择：");
	scanf("%d",&choice);
	getchar();
	switch (choice) {
		case 0:
			printf("**退出程序成功**");
			return 0;
		case 1:
			GetC();
			goto RE;
		case 2:
			GetM();
			goto RE;
		default:
			system("cls");
			printf("**请输入有效选项**\n");
			goto RE;
	}
}
void GetC() {
	char m[MAX];
	char *m2;
	char c[MAX];
	char key[KMAX];
	char *key2;
	char key3[5][5];
	printf("请输入明文:");
	scanf("%[^\n]s", m);
	getchar();
	printf("请输入密钥:");
	scanf("%[^\n]s", key);
	getchar();
	//读取处理后的密钥
	key2 = GetKey(key);
	//制表、读表
	for (int i = 0; i < 5;i++)
		for (int j = 0; j < 5;j++)
			key3[i][j] = *((key2 + i * 5) + j);
	readKey(key2);
	//获取符合条件的密文
	m2 = GetM1(m);
	//符合条件的加密
	printf("加密后：%s\n",GetC2(m2,key3));
	printf("**输入回车继续**\n");
	getchar();
	system("cls");
}
void GetM() {
	char m[MAX];
	char c[MAX];
	char* c2;
	char key[KMAX];
	char* key2;
	char key3[5][5];
	printf("请输入密文:");
	scanf("%[^\n]s", c);
	getchar();
	printf("请输入密钥:");
	scanf("%[^\n]s", key);
	getchar();
	//读取处理后的密钥
	key2 = GetKey(key);
	//制表、读表
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			key3[i][j] = *((key2 + i * 5) + j);
	readKey(key2);
	//获取符合条件的密文
	c2 = GetC1(c);
	//符合条件的解密
	printf("解密后：%s\n", GetM2(c2, key3));
	printf("**输入回车继续**\n");
	getchar();
	system("cls");
}
char * GetKey(char* key) {
	char *key2 = (char*)malloc(KMAX*sizeof(char));
	//变大写 
	for (int i = 0; i < strlen(key); i++)
		if (key[i] >= 'a' && key[i] <= 'z')
			key[i] = 'A' + key[i] - 'a';
	printf("密钥变大写后：%s\n", key);
	//J变I 
	for (int i = 0; i < strlen(key); i++)
		if (key[i] == 'J')
			key[i] = 'I';
	printf("密钥J变I后：%s\n", key);
	//剔除符号空格 
	int n = 0;
	for (int i = 0, j = 0; i < strlen(key); i++, j++) {
		if (key[i] >= 'A' && key[i] <= 'Z')
			key2[j] = key[i];
		else {
			j--;
		}
		n = j;
	}
	key2[n + 1] = '\0';
	printf("密钥去除符号后：%s\n", key2);
	strcpy(key, key2);
	memset(key2, '0', KMAX * sizeof(char));
	//去除重复
	for (int i = 0, j = 0; i < strlen(key); i++, j++) {
		int x = 0;
		for (int y = 0; y < strlen(key); y++) {
			if (key[i] != key2[y])
				x++;
		}
		if (x == strlen(key))
			key2[j] = key[i];
		else {
			j--;
		}
		n = j;
	}
	key2[n + 1] = '\0';
	printf("去重后的密钥是：%s\n", key2);
	strcpy(key, key2);
	key2[n + 1] = '0';
	//填充密钥
	for (int i = 0, j = strlen(key); i < 26; i++) {
		int y = 0;
		if (('A' + i) == 'J')
			continue;
		for (int x = 0; x < strlen(key); x++)
			if ('A' + i != key[x]) {
				y++;
			}
		if (y == strlen(key)) {
			key2[j] = 'A' + i;
			j++;
		}
	}
	key2[KMAX - 2] = '\0';

	printf("密钥填充后：%s\n", key2);
	
	return key2;
}
char * GetM1(char* m) {
	char *m2 = (char*)malloc(MAX * sizeof(char));
	//变大写 
	for (int i = 0; i < strlen(m); i++)
		if (m[i] >= 'a' && m[i] <= 'z')
			m[i] = 'A' + m[i] - 'a';
	printf("明文变大写后：%s\n", m);
	//J变I 
	for (int i = 0; i < strlen(m); i++)
		if (m[i] == 'J')
			m[i] = 'I';
	printf("明文J变I后：%s\n", m);
	//剔除符号空格 
	int n = 0;
	for (int i = 0, j = 0; i < strlen(m); i++, j++) {
		if (m[i] >= 'A' && m[i] <= 'Z')
			m2[j] = m[i];
		else {
			j--;
		}
		n = j;
	}
	m2[n + 1] = '\0';
	printf("明文去除符号后：%s\n", m2);
	strcpy(m, m2);
	memset(m2, '0', MAX * sizeof(char));
	//对明文分组进行处理
	n = strlen(m);
	for (int i = 0,j = 0; i < strlen(m);j = j + 2) {		
		if (m[i] == m[i + 1]) {
			m2[j] = m[i];
			if (m[i] == 'Z') {
				m2[j + 1] = 'A';
			}
			else {
				m2[j + 1] = 'Z';
			}
			i++;
			n++;
		}
		else {
			m2[j] = m[i];
			m2[j + 1] = m[i + 1];
			i = i + 2;
		}
	}
	m2[n] = '\0';
	//因为多一个'\0'，所以其实判断奇数填字母
	if ((strlen(m2) % 2) == 1) {
		if (m2[n] == 'Z') 
			m2[n] = 'A';
		else
			m2[n] = 'Z';
		m2[n + 1] = '\0';
	}
	printf("分组处理后的明文是：%s\n", m2);
	return m2;
}
char * GetC1(char* c) {
	char* c2 = (char*)malloc(MAX * sizeof(char));
	//变大写 
	for (int i = 0; i < strlen(c); i++)
		if (c[i] >= 'a' && c[i] <= 'z')
			c[i] = 'A' + c[i] - 'a';
	printf("密文变大写后：%s\n", c);
	//J变I 
	for (int i = 0; i < strlen(c); i++)
		if (c[i] == 'J')
			c[i] = 'I';
	printf("密文J变I后：%s\n", c);
	//剔除符号空格 
	int n = 0;
	for (int i = 0, j = 0; i < strlen(c); i++, j++) {
		if (c[i] >= 'A' && c[i] <= 'Z')
			c2[j] = c[i];
		else {
			j--;
		}
		n = j;
	}
	c2[n + 1] = '\0';
	printf("密文去除符号后：%s\n", c2);
	strcpy(c, c2);
	memset(c2, '0', MAX * sizeof(char));
	//对密文分组进行处理
	n = strlen(c);
	for (int i = 0, j = 0; i < strlen(c); j = j + 2) {
		if (c[i] == c[i + 1]) {
			c2[j] = c[i];
			if (c[i] == 'Z') {
				c2[j + 1] = 'A';
			}
			else {
				c2[j + 1] = 'Z';
			}
			i++;
			n++;
		}
		else {
			c2[j] = c[i];
			c2[j + 1] = c[i + 1];
			i = i + 2;
		}
	}
	c2[n] = '\0';
	//因为多一个'\0'，所以其实判断奇数填字母
	if ((strlen(c2) % 2) == 1) {
		if (c2[n] == 'Z')
			c2[n] = 'A';
		else
			c2[n] = 'Z';
		c2[n + 1] = '\0';
	}
	printf("分组处理后的密文是：%s\n", c2);
	return c2;
}
char * GetM2(char* c, char* key) {
	char* m = (char*)malloc(sizeof(char) * MAX);
	for (int i = 0; i < strlen(c); i = i + 2) {
		int x = 0;//x为列，横坐标  内层循环
		int y = 0;//y为行，纵坐标  外层循环
		int x1 = 0;
		int y1 = 0;
		//找每组第一个的坐标
		for (y = 0; y < 5; y++) {
			for (x = 0; x < 5; x++)
				if (*(c + i) == *((key + y * 5) + x))
					break;
			if (x < 5)
				break;
		}
		//printf("(%d,%d)\n", x, y);//输出坐标检验是否正确
		//找每组第二个的坐标
		for (y1 = 0; y1 < 5; y1++) {
			for (x1 = 0; x1 < 5; x1++)
				if (*(c + i + 1) == *((key + y1 * 5) + x1))
					break;
			if (x1 < 5)
				break;
		}
		//printf("(%d,%d)\n", x1, y1);//输出坐标检验是否正确

		if (x == x1) {
			m[i] = *((key + ((y + 4) % 5) * 5) + x);
			m[i + 1] = *((key + ((y1 + 4) % 5) * 5) + x1);
		}
		else if (y == y1) {
			m[i] = *((key + y * 5) + (x + 4) % 5);
			m[i + 1] = *((key + y1 * 5) + (x1 + 4) % 5);
		}
		else {
			m[i] = *((key + y * 5) + x1);
			m[i + 1] = *((key + y1 * 5) + x);
		}
	}
	m[strlen(c)] = '\0';
	//printf("解密后：%s\n", m);
	return m;
}
char* GetC2(char* m, char* key) {
	char *c = (char*)malloc(sizeof(char) * MAX);
	for (int i = 0; i < strlen(m); i = i + 2) {
		int x = 0;//x为列，横坐标  内层循环
		int y = 0;//y为行，纵坐标  外层循环
		int x1 = 0;
		int y1 = 0;
		//找每组第一个的坐标
		for (y = 0; y < 5; y++) {
			for (x = 0; x < 5; x++) 
				if (*(m + i) == *((key + y * 5) + x))
					break;
			if (x < 5)
				break;
		}
		//printf("(%d,%d)\n",x,y);
		//找每组第二个的坐标
		for (y1 = 0; y1 < 5; y1++) {
			for (x1 = 0; x1 < 5; x1++)
				if (*(m + i + 1) == *((key + y1 * 5) + x1))
					break;
			if (x1 < 5)
				break;
		}
		//printf("(%d,%d)\n", x1, y1);

		if (x == x1) {
			c[i] = *((key + ((y + 1) % 5) * 5) + x);
			c[i + 1] = *((key + ((y1 + 1) % 5) * 5) + x1);
		}
		else if (y == y1) {
			c[i] = *((key + y * 5) + (x + 1) % 5);
			c[i + 1] = *((key + y1 * 5) + (x1 + 1) % 5);
		}
		else {
			c[i] = *((key + y * 5) + x1);
			c[i + 1] = *((key + y1 * 5) + x);
		}
	}
	c[strlen(m)] = '\0';
	//printf("加密后：%s\n",c);
	return c;
}
void readKey(char *key){
	for (int i = 0; i < 5; i++) {
		printf("---------------------\n");
		printf("| ");
		for (int j = 0; j < 5; j++)
			printf("%c | ", *((key + i * 5) + j));
		printf("\n");
	}
	printf("---------------------\n");
}