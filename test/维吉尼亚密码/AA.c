# include "AA.h"
void Run() {
	int choice = 0;
	RE:
	printf("-----------------\n");
	printf("|1��ά�����Ǽ���|\n");
	printf("|2��ά�����ǽ���|\n");
	printf("|  0���˳�����  |\n");
	printf("-----------------\n");
	printf("��ѡ��:");
	scanf("%d",&choice);
	getchar();
	switch (choice){
	case 0:
		printf("**�˳��ɹ�**");
		return 0;
	case 1:
		GetC();
		goto RE;
	case 2:
		GetM();
		goto RE;
	default:
		system("cls");
		printf("**��������Чѡ��**");
		goto RE;
	}
}
void GetC() {
	/*
		��m[]Ϊ����
		��c[]Ϊ����
		��keyΪ��Կ
	*/
	char m[MAX];
	char c[MAX];
	char key[MAX];
	printf("**��ѡ����ά�����Ǽ���**\n");
	printf("������������ģ�");
	scanf("%[^\n]s",m);
	getchar();
	printf("�����������Կ��");
	scanf("%s",key);
	getchar();
	for (int i = 0,j = 0; i < strlen(m); i++,j++) {
		/*
			��xΪ�����롮A����a����λ����
			�ã�x = m[i] - 'A'  �� x = m[i] - 'a';
			��yΪ��Կ�롮A����a����λ����
			�ã�y = key[j] - 'A'  �� y = key[j] - 'a';
			��j������(mod strlen(key))�������õ�����Կ���±꣩
			��ô���Եõ�c[i] = 'A' + (��������Կ��λ����֮��) (mod 26)
			�� c[i] = 'A' + (x + y) % 26;
			�� c[i] = 'a' = (x + y) % 26;
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
	printf("���ܺ�%s\n",c);
	printf("**�س������**");
	getchar();
	system("cls");
}
void GetM() {
	char m[MAX];
	char c[MAX];
	char key[MAX];
	printf("**��ѡ����ά�����ǽ���**\n");
	printf("������������ģ�");
	scanf("%[^\n]s", c);
	getchar();
	printf("�����������Կ��");
	scanf("%s", key);
	getchar();
	for (int i = 0, j = 0; i < strlen(c); i++, j++) {
		/*
			����ʱ���ɰѼ���ʱ��ʽ��c[i] = 'A' + ((x + y) % 26);
			�������ͬ��ʽ�е�m[i];
			m[i]��x�У�
			x = m[i] - 'A';
			��ã�m[i] = ((x - y + 26) % 26) + 'A';
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
	printf("���ܺ�%s\n", m);
	printf("**�س������**");
	getchar();
	system("cls");
}