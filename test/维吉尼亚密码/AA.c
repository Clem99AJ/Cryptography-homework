# include "AA.h"
void Run() {
	int choice = 0;
	RE:
	printf("-----------------\n");
	printf("|1、维吉尼亚加密|\n");
	printf("|2、维吉尼亚解密|\n");
	printf("|  0、退出程序  |\n");
	printf("-----------------\n");
	printf("请选择:");
	scanf("%d",&choice);
	getchar();
	switch (choice){
	case 0:
		printf("**退出成功**");
		return 0;
	case 1:
		GetC();
		goto RE;
	case 2:
		GetM();
		goto RE;
	default:
		system("cls");
		printf("**请输入有效选项**");
		goto RE;
	}
}
void GetC() {
	/*
		设m[]为明文
		设c[]为密文
		设key为密钥
	*/
	char m[MAX];
	char c[MAX];
	char key[MAX];
	printf("**你选择了维吉尼亚加密**\n");
	printf("请输入你的明文：");
	scanf("%[^\n]s",m);
	getchar();
	printf("请输入你的密钥：");
	scanf("%s",key);
	getchar();
	for (int i = 0,j = 0; i < strlen(m); i++,j++) {
		/*
			设x为明文与‘A’或‘a’的位移量
			得：x = m[i] - 'A'  或 x = m[i] - 'a';
			设y为密钥与‘A’或‘a’的位移量
			得：y = key[j] - 'A'  或 y = key[j] - 'a';
			（j代表在(mod strlen(key))的域内用到的密钥的下标）
			那么可以得到c[i] = 'A' + (明文与密钥的位移量之和) (mod 26)
			既 c[i] = 'A' + (x + y) % 26;
			或 c[i] = 'a' = (x + y) % 26;
		*/
		
		int x=0;
		int y=0;
		j = j % strlen(key);
		if (m[i] >= 'A' && m[i] <= 'Z') {
			x = m[i] - 'A';
			if (key[j] >= 'a' && key[j] <= 'z')
				y = key[j] - 'a';
			else if(key[j] >= 'A' && key[j] <= 'Z')
				y = key[j] - 'A';
			c[i] = 'A' + ((x + y) % 26);
		}
		else if (m[i] >= 'a' && m[i] <= 'z') {
			x = m[i] - 'a';
			if (key[j] >= 'a' && key[j] <= 'z')
				y = key[j] - 'a';
			else if (key[j] >= 'A' && key[j] <= 'Z')
				y = key[j] - 'A';
			c[i] = 'a' + ((x + y) % 26);
		}
		else{
			c[i] = m[i];
			j--;
		}
	}
	c[strlen(m)] = '\0';
	printf("加密后：%s\n",c);
	printf("**回车后继续**");
	getchar();
	system("cls");
}
void GetM() {
	char m[MAX];
	char c[MAX];
	char key[MAX];
	printf("**你选择了维吉尼亚解密**\n");
	printf("请输入你的密文：");
	scanf("%[^\n]s", c);
	getchar();
	printf("请输入你的密钥：");
	scanf("%s", key);
	getchar();
	for (int i = 0, j = 0; i < strlen(c); i++, j++) {
		/*
			解密时，可把加密时的式子c[i] = 'A' + ((x + y) % 26);
			用来求解同余式中的m[i];
			m[i]在x中；
			x = m[i] - 'A';
			解得：m[i] = ((x - y + 26) % 26) + 'A';
		*/
		int x = 0;
		int y = 0;
		j = j % strlen(key);
		if (c[i] >= 'A' && c[i] <= 'Z') {
			x = c[i] - 'A';
			if (key[j] >= 'a' && key[j] <= 'z')
				y = key[j] - 'a';
			else if (key[j] >= 'A' && key[j] <= 'Z')
				y = key[j] - 'A';
			m[i] = ((x - y + 26) % 26) + 'A';
		}
			
		else if (c[i] >= 'a' && c[i] <= 'z') {
			x = c[i] - 'a';
			if (key[j] >= 'a' && key[j] <= 'z')
				y = key[j] - 'a';
			else if (key[j] >= 'A' && key[j] <= 'Z')
				y = key[j] - 'A';
			m[i] = ((x - y + 26) % 26) + 'a';
		}
		else {
			m[i] = c[i];
			j--;
		}
	}
	m[strlen(c)] = '\0';
	printf("解密后：%s\n", m);
	printf("**回车后继续**");
	getchar();
	system("cls");
}