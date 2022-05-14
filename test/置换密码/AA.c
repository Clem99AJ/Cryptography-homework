# include"AA.h"
void Run() {

	int chioce = 0;
	RE:
	printf("-------------\n");
	printf("|1、置换加密|\n");
	printf("|2、置换解密|\n");
	printf("|0、退出程序|\n");
	printf("-------------\n");
	printf("请选择功能：");
	scanf("%d",&chioce);
	getchar();
	switch (chioce) {
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
			printf("**请输入有效选项**\n");
			goto RE;

	}
}
void GetC() {
	int n = 0;//设n为密钥长度
	char m[MAX];//设m[]为明文
	char c[MAX];//设c[]为密文
	int key[MAX];//设key[]为密钥
	printf("**你选择了置换加密**\n");
	printf("请输入明文：");
	scanf("%[^\n]s",m);
	getchar();

	Re:
	printf("请输入密钥长度：");
	scanf("%d",&n);
	getchar();
	
	if (n > strlen(m)) {
		printf("**密钥长度不能大于明文长度**\n");
		goto Re;
	}
	for (int i = 0; i < n; i++) {
		printf("请输入第%d个序号：",i+1);
		scanf("%d",&key[i]);
		getchar();
	}
	
	for (int i = 0; i < n; i++) {
		int t = 0;
		for (int j = 0; j < n; j++) {
			if (key[i] == key[j])
				t++;
			if (t > 1) {
				printf("**置换加密密钥不能重复**\n");
				goto Re;
			}
		}
	}//置换加密必须满足满射，判断是否符合条件

	/*
	if (strlen(m) % n != 0) {
		printf("**置换加密的密钥长度必须是明文长度的因子**\n");
		goto Re;
	}//限制条件与现实很难符合（舍弃）
	*/
	for (int i = 0; i < n;i++) {
		key[i]--;
	}//把输入与数组下标的误差去除

	for (int i = 0; i < strlen(m);i++) {

		/*
			设j为模n的余数
			设x为n的倍数
			设a为置换时明文对应的下标
		*/
		int j = i % n;
		int x = i / n;
		int a = key[j] + n * x;
		if (x < (strlen(m) / n)) {
			c[i] = m[a];
		}
		else {
			c[i] = m[i];
		}//在现实中，明文总不可能满足是密钥的倍数，所以把分组结尾无法满足满射的那部分不予加密
		/*
		if (m[a] >= 'A' && m[a] <= 'Z' || m[a] >= 'a' && m[a] <= 'z')
				c[i] = m[a];
			else {
				c[i] = m[a];
				j--;
			}
		*/
		
	}
	c[strlen(m)] = '\0';
	printf("加密后：%s",c);
	printf("\n");
	printf("**按回车后继续**\n");
	getchar();
	system("cls");
}
void GetM() {
	int n = 0;//设n为密钥长度
	char m[MAX];//设m[]为明文
	char c[MAX];//设c[]为密文
	int key[MAX];//设key[]为密钥
	int unkey[MAX];//设unkey[]为反置换
	printf("**你选择了置换解密**\n");
	printf("请输入密文：");
	scanf("%[^\n]s", c);
	getchar();
	Re:
	printf("请输入密钥长度：");
	scanf("%d",&n);
	getchar();
	
	if (n > strlen(c)) {
		printf("**密钥长度不能大于明文长度**\n");
		goto Re;
	}
	for (int i = 0; i < n; i++) {
		printf("请输入第%d个序号：",i+1);
		scanf("%d",&key[i]);
		getchar();
	}
	
	for (int i = 0; i < n; i++) {
		int t = 0;
		for (int j = 0; j < n; j++) {
			if (key[i] == key[j])
				t++;
			if (t > 1) {
				printf("**置换加密密钥不能重复**\n");
				goto Re;
			}
		}
	}//置换加密必须满足满射，判断是否符合条件

	/*
	if (strlen(m) % n != 0) {
		printf("**置换加密的密钥长度必须是明文长度的因子**\n");
		goto Re;
	}//限制条件与现实很难符合（舍弃）
	*/
	for (int i = 0; i < n;i++) {
		key[i]--;
	}//把输入与数组下标的误差去除

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n;j++) {
			if (key[j] == i) {
				unkey[i] = j;
			}
		}
	}
	//for (int i = 0; i < n;i++) {
	//	printf("%d-->%d\n",i,unkey[i]);
	//}
	//getchar();
	for (int i = 0; i < strlen(c); i++) {

		/*
			设j为模n的余数
			设x为n的倍数
			设a为置换时明文对应的下标
		*/
		int j = i % n;
		int x = i / n;
		int a = unkey[j] + n * x;
		if (x < (strlen(c) / n)) {
			m[i] = c[a];
		}
		else {
			m[i] = c[i];
		}
	}
	m[strlen(c)] = '\0';
	printf("加密后：%s", m);
	printf("\n");
	printf("**按回车后继续**\n");
	getchar();
	system("cls");
}