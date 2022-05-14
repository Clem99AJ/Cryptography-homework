# include"AA.h"
void Run() 
{
	int choice;
RE:
	printf("-------------\n");
	printf("|1、代换加密|\n");
	printf("|2、代换解密|\n");
	printf("|0、退出程序|\n");
	printf("-------------\n");
	printf("请输入你的选择：");
	scanf("%d",&choice);
	getchar();
	switch(choice){
			case 0:
				printf("**退出成功**\n");
				return 0;
			case 1: {
				GetC();
			}goto RE;
			case 2: {
				GetM();
			}goto RE;
			default:
				system("cls");
				printf("**请输入有效选项**\n");
				goto RE;
	}
	
}
void GetC() {
	char key[27];
	char m[MAX];
	char c[MAX];
	printf("请输入明文：");
	scanf("%[^\n]s",m);
	getchar();
Re:
	printf("请输入密钥：");
	scanf("%s", key);
	getchar();
	for (int i = 0; i < 26; i++) {
		int n = 0;
		for (int j = 0; j < 26; j++) {
			if (key[i] == key[j])
				n++;
			if (n > 1) {
				printf("**请输入不重复的密钥**\n");
				goto Re;
			}
		}
	}
	for (int i = 0; i < 26;i++) {
		printf("%c----→%c\n",'A' + i,key[i]);
	}

	for (int i = 0; i < MAX;i++) {
		int j;
		if (m[i] >= 'A' && m[i] <= 'Z') {
			j = m[i] - 'A';//得出明文到'A'的偏移量，既是第几个字母
			c[i] = key[j];//然后就可以通过密钥查找到对应的密文
		}
		else if (m[i] >= 'a' && m[i] <= 'z') {
			j = m[i] - 'a';
			c[i] = key[j] + ('a' - 'A');
		}
		else
			c[i] = m[i];
	}
	printf("加密后：%s\n",c);
	printf("**输入回车返回菜单**\n");
	getchar();
	system("cls");
}
void GetM() {
	char key[27];
	char m[MAX];
	char c[MAX];
	printf("请输入密文：");
	scanf("%[^\n]s", c);
	getchar();
	Re:
	printf("请输入密钥：");
	scanf("%s", key);
	getchar();
	for (int i = 0; i < 26;i++) {
		int n = 0;
		for (int j = 0; j < 26;j++) {
			if (key[i] == key[j])
				n++;
			if (n > 1) {
				printf("**请输入不重复的密钥**\n");
				goto Re;
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		printf("%c----→%c\n", 'A' + i, key[i]);
	}

	for (int i = 0; i < MAX; i++) {
		int j;
		if (c[i] >= 'A' && c[i] <= 'Z') {
			for (int n = 0; n < 26;n++) {
				if (c[i] == key[n])
					j = n;
			}
			m[i] = 'A' + j;
		}
		else if (c[i] >= 'a' && c[i] <= 'z') {
			char t = c[i] - ('a' - 'A');
			for (int n = 0; n < 26; n++) {
				if (t == key[n])
					j = n;
			}
			m[i] = 'a' + j;
		}
		else
			m[i] = c[i];
	}
	printf("解密后：%s\n", m);
	printf("**输入回车返回菜单**\n");
	getchar();
	system("cls");
}