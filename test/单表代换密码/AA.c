# include"AA.h"
void Run() 
{
	int choice;
RE:
	printf("-------------\n");
	printf("|1����������|\n");
	printf("|2����������|\n");
	printf("|0���˳�����|\n");
	printf("-------------\n");
	printf("���������ѡ��");
	scanf("%d",&choice);
	getchar();
	switch(choice){
			case 0:
				printf("**�˳��ɹ�**\n");
				return 0;
			case 1: {
				GetC();
			}goto RE;
			case 2: {
				GetM();
			}goto RE;
			default:
				system("cls");
				printf("**��������Чѡ��**\n");
				goto RE;
	}
	
}
void GetC() {
	char key[27];
	char m[MAX];
	char c[MAX];
	printf("���������ģ�");
	scanf("%[^\n]s",m);
	getchar();
Re:
	printf("��������Կ��");
	scanf("%s", key);
	getchar();
	for (int i = 0; i < 26; i++) {
		int n = 0;
		for (int j = 0; j < 26; j++) {
			if (key[i] == key[j])
				n++;
			if (n > 1) {
				printf("**�����벻�ظ�����Կ**\n");
				goto Re;
			}
		}
	}
	for (int i = 0; i < 26;i++) {
		printf("%c----��%c\n",'A' + i,key[i]);
	}

	for (int i = 0; i < MAX;i++) {
		int j;
		if (m[i] >= 'A' && m[i] <= 'Z') {
			j = m[i] - 'A';//�ó����ĵ�'A'��ƫ���������ǵڼ�����ĸ
			c[i] = key[j];//Ȼ��Ϳ���ͨ����Կ���ҵ���Ӧ������
		}
		else if (m[i] >= 'a' && m[i] <= 'z') {
			j = m[i] - 'a';
			c[i] = key[j] + ('a' - 'A');
		}
		else
			c[i] = m[i];
	}
	printf("���ܺ�%s\n",c);
	printf("**����س����ز˵�**\n");
	getchar();
	system("cls");
}
void GetM() {
	char key[27];
	char m[MAX];
	char c[MAX];
	printf("���������ģ�");
	scanf("%[^\n]s", c);
	getchar();
	Re:
	printf("��������Կ��");
	scanf("%s", key);
	getchar();
	for (int i = 0; i < 26;i++) {
		int n = 0;
		for (int j = 0; j < 26;j++) {
			if (key[i] == key[j])
				n++;
			if (n > 1) {
				printf("**�����벻�ظ�����Կ**\n");
				goto Re;
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		printf("%c----��%c\n", 'A' + i, key[i]);
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
	printf("���ܺ�%s\n", m);
	printf("**����س����ز˵�**\n");
	getchar();
	system("cls");
}