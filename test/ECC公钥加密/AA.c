# include "AA.h"
void Run() {
	//变量区
	LIST* list = (LIST*)malloc(sizeof(LIST));
	SPOT* A = (SPOT*)malloc(sizeof(SPOT));
	SPOT* B = (SPOT*)malloc(sizeof(SPOT));
	SPOT* sum = (SPOT*)malloc(sizeof(SPOT));
	int a = 0, b = 0, p = 0;
	//输入区
Re:
	puts("请分别输入椭圆曲线的");
	printf("请输入a:");
	scanf("%d", &a);
	getchar();
	printf("请输入b:");
	scanf("%d", &b);
	getchar();
	int c = 4 * (int)pow(a, 3) + 27 * (int)pow(b, 2);
	if (c == 0) {
		puts("**你输入的a、b不符合条件**");
		goto Re;
	}
Re_1:
	printf("请输入p:");
	scanf("%d", &p);
	getchar();
	if (p == 0 || p == 1) {
		puts("**你输入的p不符合条件**");
		goto Re_1;
	}
	for (int i = 2; i <= sqrt(p); i++) 
		if (p % i == 0) {
			puts("**你输入的p不符合条件**");
			goto Re_1;
		}
	//输出区
	DisPlay_1(a,b);
	//得到所有点
	list = GetSpot(a, b, p);
	//输出所有点,以及点数
	DisPlay_AllSpot(list);
	//输入点
	A = GetAorB(list,'A');
	B = GetAorB(list,'B');
	//得到A + B
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
	printf("请输入%c点：\n", choice);
	printf("%c点X = ", choice);
	scanf("%d", &spot->x);
	getchar();
	printf("%c点Y = ", choice);
	scanf("%d", &spot->y);
	getchar();

	Q = list->first;
	for (int i = 0; i < list->len; i++) {
		if (spot->x == Q->x && spot->y == Q->y) {
			return spot;
		}
		Q = Q->next;
	}
	printf("**%c点不存在椭圆曲线集合上的，请重新输入**\n", choice);
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
	printf("椭圆曲线的式子为：");
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
	printf("\n一共%d个点", list->len);
}