# include "AA.h"
void Run() {
	//������
	LIST* list = (LIST*)malloc(sizeof(LIST));
	SPOT* A = (SPOT*)malloc(sizeof(SPOT));
	SPOT* B = (SPOT*)malloc(sizeof(SPOT));
	SPOT* sum = (SPOT*)malloc(sizeof(SPOT));
	int a = 0, b = 0, p = 0;
	//������
Re:
	puts("��ֱ�������Բ���ߵ�");
	printf("������a:");
	scanf("%d", &a);
	getchar();
	printf("������b:");
	scanf("%d", &b);
	getchar();
	int c = 4 * (int)pow(a, 3) + 27 * (int)pow(b, 2);
	if (c == 0) {
		puts("**�������a��b����������**");
		goto Re;
	}
Re_1:
	printf("������p:");
	scanf("%d", &p);
	getchar();
	if (p == 0 || p == 1) {
		puts("**�������p����������**");
		goto Re_1;
	}
	for (int i = 2; i <= sqrt(p); i++) 
		if (p % i == 0) {
			puts("**�������p����������**");
			goto Re_1;
		}
	//�����
	DisPlay_1(a,b);
	//�õ����е�
	list = GetSpot(a, b, p);
	//������е�,�Լ�����
	DisPlay_AllSpot(list);
	//�����
	A = GetAorB(list,'A');
	B = GetAorB(list,'B');
	//�õ�A + B
	sum = GetSum(A,B,a,p);
	printf("A + B = (%d,%d)",sum->x,sum->y);
}
LIST* GetSpot(int a, int b, int p) {
	LIST* list = (LIST*)malloc(sizeof(LIST));
	list->len = 0;
	for (int i = 0; i <= p - 1; i++) 
		for (int j = 0; j <= p - 1; j++) 
			if ((((int)pow(i, 3) + a * i + b) % p) == ((int)pow(j, 2) % p))
				if (list->len == 0) {
					SPOT* newspot = (SPOT*)malloc(sizeof(SPOT));
					newspot->x = i;
					newspot->y = j;
					newspot->next = NULL;
					list->first = list->last = newspot;
					list->len++;
				}
				else {
					SPOT* newspot = (SPOT*)malloc(sizeof(SPOT));
					newspot->x = i;
					newspot->y = j;
					newspot->next = NULL;
					list->last->next = newspot;
					list->last = newspot;
					list->len++;
				}
	return list;
}
SPOT* GetAorB(LIST* list, char choice) {
	SPOT* Q = (SPOT*)malloc(sizeof(SPOT));
	SPOT* spot = (SPOT*)malloc(sizeof(SPOT));
Re:
	printf("������%c�㣺\n", choice);
	printf("%c��X = ", choice);
	scanf("%d", &spot->x);
	getchar();
	printf("%c��Y = ", choice);
	scanf("%d", &spot->y);
	getchar();

	Q = list->first;
	for (int i = 0; i < list->len; i++) {
		if (spot->x == Q->x && spot->y == Q->y) {
			return spot;
		}
		Q = Q->next;
	}
	printf("**%c�㲻������Բ���߼����ϵģ�����������**\n", choice);
	goto Re;
}
SPOT* GetSum(SPOT* A, SPOT* B, int a, int p) {
	SPOT* sum = (SPOT*)malloc(sizeof(SPOT));
	int m = 0, n = 0,k = 0;

	if (A->x == B->x && A->y == B->y) {
		m = (3 * (int)pow(A->x,2) + a) % p;
		n = (2 * A->y) % p;
		if (m < 0)
			m += p;
		if (n < 0)
			n += p;
		for (int i = 0; i < p; i++)
			if ((i * n) % p == m) {
				k = i;
				break;
			}
		sum->x = ((int)pow(k, 2) - 2 * A->x) % p;
		if (sum->x < 0)
			sum->x += p;
		sum->y = (-1 * A->y + k * (A->x - sum->x)) % p;
		if (sum->y < 0)
			sum->y += p;
	}else if (A->x == B->x && A->y == -1 * B->y) {
		sum->x = sum->y = 0;
	}else {
		m = (A->y - B->y) % p;
		n = (A->x - B->x) % p;
		if (m < 0)
			m += p;
		if (n < 0)
			n += p;
		for (int i = 0; i < p; i++)
			if ((i * n) % p == m) {
				k = i;
				break;
			}
		sum->x = ((int)pow(k, 2) - A->x - B->x) % p;
		if (sum->x < 0)
			sum->x += p;
		sum->y = (-1 * A->y + k * (A->x - sum->x)) % p;
		if (sum->y < 0)
			sum->y += p;
	}
	return sum;
}
void DisPlay_1(int a, int b) {
	printf("��Բ���ߵ�ʽ��Ϊ��");
	printf("y^2 = x^3");
	if (a > 0 && a != 1)
		printf("+%dx", a);
	else if (a == 1)
		printf("+x");
	else if (a < 0)
		printf("%dx", a);
	else if (a == -1)
		printf("-x");
	if (b > 0)
		printf("+%d", b);
	else if (b < 0)
		printf("%d", b);
	puts("");
}
void DisPlay_AllSpot(LIST *list) {
	SPOT* Q = (SPOT*)malloc(sizeof(SPOT));
	Q = list->first;
	for (int i = 0; i < list->len; i++) {
		printf("(%02d,%02d)  ", Q->x, Q->y);
		Q = Q->next;
		if (i != 0 && i % 5 == 4)
			puts("");
	}
	printf("\nһ��%d����", list->len);
}