# include"AA.h"
void Run() {

	int chioce = 0;
	RE:
	printf("-------------\n");
	printf("|1���û�����|\n");
	printf("|2���û�����|\n");
	printf("|0���˳�����|\n");
	printf("-------------\n");
	printf("��ѡ���ܣ�");
	scanf("%d",&chioce);
	getchar();
	switch (chioce) {
		case 0:
			printf("**�˳�����ɹ�**");
			return 0;
		case 1:
			GetC();
			goto RE;
		case 2:
			GetM();
			goto RE;
		default:
			printf("**��������Чѡ��**\n");
			goto RE;

	}
}
void GetC() {
	int n = 0;//��nΪ��Կ����
	char m[MAX];//��m[]Ϊ����
	char c[MAX];//��c[]Ϊ����
	int key[MAX];//��key[]Ϊ��Կ
	printf("**��ѡ�����û�����**\n");
	printf("���������ģ�");
	scanf("%[^\n]s",m);
	getchar();

	Re:
	printf("��������Կ���ȣ�");
	scanf("%d",&n);
	getchar();
	
	if (n > strlen(m)) {
		printf("**��Կ���Ȳ��ܴ������ĳ���**\n");
		goto Re;
	}
	for (int i = 0; i < n; i++) {
		printf("�������%d����ţ�",i+1);
		scanf("%d",&key[i]);
		getchar();
	}
	
	for (int i = 0; i < n; i++) {
		int t = 0;
		for (int j = 0; j < n; j++) {
			if (key[i] == key[j])
				t++;
			if (t > 1) {
				printf("**�û�������Կ�����ظ�**\n");
				goto Re;
			}
		}
	}//�û����ܱ����������䣬�ж��Ƿ��������

	/*
	if (strlen(m) % n != 0) {
		printf("**�û����ܵ���Կ���ȱ��������ĳ��ȵ�����**\n");
		goto Re;
	}//������������ʵ���ѷ��ϣ�������
	*/
	for (int i = 0; i < n;i++) {
		key[i]--;
	}//�������������±�����ȥ��

	for (int i = 0; i < strlen(m);i++) {

		/*
			��jΪģn������
			��xΪn�ı���
			��aΪ�û�ʱ���Ķ�Ӧ���±�
		*/
		int j = i % n;
		int x = i / n;
		int a = key[j] + n * x;
		if (x < (strlen(m) / n)) {
			c[i] = m[a];
		}
		else {
			c[i] = m[i];
		}//����ʵ�У������ܲ�������������Կ�ı��������԰ѷ����β�޷�����������ǲ��ֲ������
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
	printf("���ܺ�%s",c);
	printf("\n");
	printf("**���س������**\n");
	getchar();
	system("cls");
}
void GetM() {
	int n = 0;//��nΪ��Կ����
	char m[MAX];//��m[]Ϊ����
	char c[MAX];//��c[]Ϊ����
	int key[MAX];//��key[]Ϊ��Կ
	int unkey[MAX];//��unkey[]Ϊ���û�
	printf("**��ѡ�����û�����**\n");
	printf("���������ģ�");
	scanf("%[^\n]s", c);
	getchar();
	Re:
	printf("��������Կ���ȣ�");
	scanf("%d",&n);
	getchar();
	
	if (n > strlen(c)) {
		printf("**��Կ���Ȳ��ܴ������ĳ���**\n");
		goto Re;
	}
	for (int i = 0; i < n; i++) {
		printf("�������%d����ţ�",i+1);
		scanf("%d",&key[i]);
		getchar();
	}
	
	for (int i = 0; i < n; i++) {
		int t = 0;
		for (int j = 0; j < n; j++) {
			if (key[i] == key[j])
				t++;
			if (t > 1) {
				printf("**�û�������Կ�����ظ�**\n");
				goto Re;
			}
		}
	}//�û����ܱ����������䣬�ж��Ƿ��������

	/*
	if (strlen(m) % n != 0) {
		printf("**�û����ܵ���Կ���ȱ��������ĳ��ȵ�����**\n");
		goto Re;
	}//������������ʵ���ѷ��ϣ�������
	*/
	for (int i = 0; i < n;i++) {
		key[i]--;
	}//�������������±�����ȥ��

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
			��jΪģn������
			��xΪn�ı���
			��aΪ�û�ʱ���Ķ�Ӧ���±�
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
	printf("���ܺ�%s", m);
	printf("\n");
	printf("**���س������**\n");
	getchar();
	system("cls");
}