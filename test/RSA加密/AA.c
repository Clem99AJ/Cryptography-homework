#include"AA.h"
int isSushu(int n) {
	if (n == 1)
		return 0;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0 && n != 2)
			return 0;
	return 1;
}
int GetSushu() {
	int p = 0;
Re:
	scanf("%d", &p);
	getchar();
	if (!isSushu(p)) {
		puts("**Please enter a prime number**");
		goto Re;
	}
	return p;
}
int GetN(int b) {
	int n = 1;
	for (int q = b / 2; q != 0; q /= 2)
		n++;
	return n;
}

void  GetC(int M, int e, int n) {
	int c = 0;
	int n_2 = GetN(e);
	int* b = (int*)malloc(sizeof(int) * n_2);
	//10 to  2
	int q = e / 2, r = e % 2;
	for (int i = 0; i < n_2; i++) {
		b[i] = r;
		r = q % 2;
		q = q / 2;

	}
	/*for (int i = n_2 - 1; i >= 0; i--) {
		printf("%d ", b[i]);
	}
	puts("");*/
	//GetC
	if (b[0] == 1)
		c = M % n;
	int Ai = M % n;
	for (int i = 0; i < n_2; i++) {
		if (b[i] == 1 && i != 0) {
			c = (c * Ai) % n ;
		}
		Ai = (int)pow(Ai, 2) % n;
	}
	printf("%04d  ",c);
}
void Run() {
	char* M = (char*)malloc(sizeof(char) * MAX);
	int* M_i = (int*)malloc(sizeof(int) * MAX);
	int p = 0, q = 0, e = 0, n = 0,yn = 0;
	int a = 0, b = 0;

	printf("Please enter p:");
	p = GetSushu();
	printf("Please enter q:");
	q = GetSushu();

	n = p * q;
	yn = (p - 1) * (q - 1);
Re:
	printf("Please enter e:");
	scanf("%d", &e);
	getchar();
	a = e > yn ? e : yn;
	b = e > yn ? yn : e;
	for (int i = 2; i <= b; i++) {
		if (a % i == 0 && b % i == 0) {
			puts("**You must enter e that is coprime with y(n)**");
			goto Re;
		}
	}
Re_1:
	printf("Please enter a M:");
	scanf("%[^\n]s", M);
	getchar();
	for (int i = 0; i < strlen(M); i++) {
		if (M[i] > n) {
			puts("**Please enter M that is less than n**");
			goto Re_1;
		}
	}
	//转换存储
	int c = 0;
	for (int i = 0; i < strlen(M);i++) {
		if (M[i] >= 'a' && M[i] <= 'z') {
			M_i[c] = M[i] - 'a';
			c++;
		}else if(M[i] >= 'A' && M[i] <= 'Z') {
			M_i[c] = M[i] - 'A';
			c++;
		}
	}
	if (c % 2 == 1) {
		M_i[c] = 0;
		c++;
	}
	int* M_i2 = (int*)malloc(sizeof(int) * c / 2);
	for (int i = 0; i < c ;i+=2)
		M_i2[i / 2] = M_i[i] * 100 + M_i[i + 1];
	//开始加密
	puts("RSA Code:");
	for (int i = 0; i < c / 2;i++)
		GetC(M_i2[i], e, n);
	puts("");
}