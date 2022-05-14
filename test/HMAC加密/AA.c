# include "AA.h"
//MD5 use
const unsigned int T[64] = {
		0xD76AA478,0xE8C7B756,0x242070DB,0xC1BDCEEE,0xF57C0FAF,0x4787C62A,0xA8304613,0xFD469501,
		0x698098D8,0x8B44F7AF,0xFFFF5BB1,0x895CD7BE,0x6B901122,0xFD987193,0xA679438E,0x49B40821,
		0xF61E2562,0xC040B340,0x265E5A51,0xE9B6C7AA,0xD62F105D,0x02441453,0xD8A1E681,0xE7D3FBC8,
		0x21E1CDE6,0xC33707D6,0xF4D50D87,0x455A14ED,0xA9E3E905,0xFCEFA3F8,0x676F02D9,0x8D2A4C8A,
		0xFFFA3942,0x8771F681,0x6D9D6122,0xFDE5380C,0xA4BEEA44,0x4BDECFA9,0xF6BB4B60,0xBEBFBC70,
		0x289B7EC6,0xEAA127FA,0xD4EF3085,0x04881D05,0xD9D4D039,0xE6DB99E5,0x1FA27CF8,0xC4AC5665,
		0xF4292244,0x432AFF97,0xAB9423A7,0xFC93A039,0x655B59C3,0x8F0CCC92,0xFFEFF47D,0x85845DD1,
		0x6FA87E4F,0xFE2CE6E0,0xA3014314,0x4E0811A1,0xF7537E82,0xBD3AF235,0x2AD7D2BB,0xEB86D391
};
unsigned int ABCD[4] = { 0x67452301,0xefcdab89,0x98badcfe,0x10325476 };
const unsigned int S[64] = {
		7,12,17,22,7,12,17,22,
		7,12,17,22,7,12,17,22,
		5,9,14,20,5,9,14,20,
		5,9,14,20,5,9,14,20,
		4,11,16,23,4,11,16,23,
		4,11,16,23,4,11,16,23,
		6,10,15,21,6,10,15,21,
		6,10,15,21,6,10,15,21
};
//SHA1 use
unsigned int ABCDE[5] = { 0x67452301,0xEFCDAB89,0x98BADCFE,0x10325476,0xC3D2E1F0 };
const unsigned int Kt[4] = { 0x5A827999,0x6ED9EBA1,0x8F1BBCDC,0xCA62C1D6 };
int length = 0;
void Run() {
	int choice = -1;
	RE:
	puts("------------------");
	puts("|  1、HMAC-MD5   |");
	puts("|  2、HMAC-SHA1  |");
	puts("| 0、Exit Program|");
	puts("------------------");
	printf("Please enter a choice:");
	scanf("%d",&choice);
	getchar();
	switch (choice)
	{
		case 0:
			puts("**EXIT SECCESS**");
			return;
		case 1:
			HMAC_MD5();
			break;
		case 2:
			HMAC_SHA1();
			break;
		default:
			puts("**Please enter a useful choice**");
			break;
	}
	Clean();
	goto RE;
}
void HMAC_MD5() {
	unsigned char* M = (unsigned char*)malloc(sizeof(char) * MAX);
	unsigned char* key = (unsigned char*)malloc(sizeof(char) * MAX);
	unsigned int* key_1 = (unsigned int*)malloc(sizeof(int) * 4);
	unsigned int* key_2 = (unsigned int*)malloc(sizeof(int) * 64);
	unsigned int* ipad = (unsigned int*)malloc(sizeof(int) * 64);
	unsigned int* opad = (unsigned int*)malloc(sizeof(int) * 64);
	unsigned char* temp = (unsigned char*)malloc(sizeof(char) * MAX);
	printf("Please enter M：");
	scanf("%[^\n]s", M);
	getchar();
	printf("Please enter key:");
	scanf("%s", key);
	getchar();
	//1、判断
	int a = 0;
	if (strlen(key) > 64) {
		key_1 = GetC_MD5(key);
		//转化为16个
		for (int i = 0; i < 16; i++)
			key_2[i] = key_1[i / 4] / (unsigned int)pow(256, 3 - (i % 4)) % 256;
		a = 16;
	}
	else {
		for (int i = 0; i < strlen(key); i++)
			key_2[i] = key[i];
		a = strlen(key);
	}

	//2、填充
	for (int i = a; i < 64; i++) {
		key_2[i] = 0;
	}
	//输出检查
	/*puts("填充后：");
	DisPlay(key_2,64);*/

	//3、得到ipad和opad
	for (int i = 0; i < 64; i++) {
		ipad[i] = key_2[i] ^ 0x36;
		opad[i] = key_2[i] ^ 0x5c;
	}
	//输出检查
	/*puts("ipad：");
	DisPlay(ipad, 64);
	puts("opad：");
	DisPlay(opad, 64);*/
	//4、ipad拼接，并加密
	for (int i = 0; i < 64 + strlen(M); i++) {
		if (i < 64)
			temp[i] = ipad[i];
		else
			temp[i] = M[i % 64];
	}
	temp[64 + strlen(M)] = '\0';
	//输出检查
	/*puts("明文：");
	for (int i = 0; i < strlen(M);i++) {
		printf("%02X  ", M[i]);
	}
	puts("");*/

	/*puts("ipad拼接后：");
	for (int i = 0; i < strlen(temp); i++) {
		if (i != 0 && i % 4 == 0)
			puts("");
		printf("%02X", temp[i]);
	}*/
	key_1 = GetC_MD5(temp);
	/*puts("ipad加密后：");
	for (int i = 0; i < 4; i++) {
		printf("%08X", key_1[i]);
	}
	puts("");
	*/
	//5、opad拼接,并加密
	for (int i = 0; i < 80; i++) {
		if (i < 64)
			temp[i] = opad[i];
		else
			temp[i] = key_1[(i % 64) / 4] / (unsigned int)pow(256, 3 - ((i % 64) % 4)) % 256;;
	}
	temp[80] = '\0';

	/*puts("opad拼接后：");
	for (int i = 0; i < 80; i++) {
		if (i != 0 && i % 4 == 0)
			puts("");
		printf("%02X  ", temp[i]);
	}*/
	key_1 = GetC_MD5(temp);
	puts("");
	printf("HMAC-MD5 Code:");
	for (int i = 0; i < 4; i++) {
		printf("%08X", key_1[i]);
	}
	puts("");
}
void HMAC_SHA1() {
	unsigned char* M = (unsigned char*)malloc(sizeof(char) * MAX);
	unsigned char* key = (unsigned char*)malloc(sizeof(char) * MAX);
	unsigned int* key_1 = (unsigned int*)malloc(sizeof(int) * 5);
	unsigned int* key_2 = (unsigned int*)malloc(sizeof(int) * 64);
	unsigned int* ipad = (unsigned int*)malloc(sizeof(int) * 64);
	unsigned int* opad = (unsigned int*)malloc(sizeof(int) * 64);
	unsigned char* temp = (unsigned char*)malloc(sizeof(char) * MAX);
	printf("Please enter M：");
	scanf("%[^\n]s", M);
	getchar();
	printf("Please enter key:");
	scanf("%s", key);
	getchar();
	//1、判断
	int a = 0;
	if (strlen(key) > 64) {
		key_1 = GetC_SHA1(key);
		//转化为20个
		for (int i = 0; i < 20;i++)
			key_2[i] = key_1[i / 4] / (unsigned int)pow(256, 3 - (i % 4)) % 256;
		a = 20;
	}else {
		for (int i = 0; i < strlen(key);i++)
			key_2[i] = key[i];
		a = strlen(key);
	}

	//2、填充
	for (int i = a; i < 64;i++) {
		key_2[i] = 0;
	}
	//输出检查
	/*puts("填充后：");
	DisPlay(key_2,64);*/
	
	//3、得到ipad和opad
	for (int i = 0; i < 64; i++) {
		ipad[i] = key_2[i] ^ 0x36;
		opad[i] = key_2[i] ^ 0x5c;
	}
	//输出检查
	/*puts("ipad：");
	DisPlay(ipad, 64);
	puts("opad：");
	DisPlay(opad, 64);*/
	//4、ipad拼接，并加密
	for (int i = 0; i < 64 + strlen(M);i++) {
		if (i < 64)
			temp[i] = ipad[i];
		else
			temp[i] = M[i % 64];
	}
	temp[64 + strlen(M)] = '\0';
	//输出检查
	/*puts("明文：");
	for (int i = 0; i < strlen(M);i++) {
		printf("%02X  ", M[i]);
	}
	puts("");*/

	/*puts("ipad拼接后：");
	for (int i = 0; i < strlen(temp); i++) {
		if (i != 0 && i % 4 == 0)
			puts("");
		printf("%02X", temp[i]);
	}*/
	key_1 = GetC_SHA1(temp);
	/*puts("ipad加密后：");
	for (int i = 0; i < 5; i++) {
		printf("%08X", key_1[i]);
	}
	puts("");*/
	//5、opad拼接,并加密
	for (int i = 0; i < 84; i++) {
		if (i < 64)
			temp[i] = opad[i];
		else
			temp[i] = key_1[(i % 64) / 4] / (unsigned int)pow(256, 3 - ((i % 64) % 4)) % 256;;
	}
	temp[84] = '\0';

	/*puts("opad拼接后：");
	for (int i = 0; i < 84; i++) {
		if (i != 0 && i % 4 == 0)
			puts("");
		printf("%02X  ", temp[i]);
	}*/
	key_1 = GetC_SHA1(temp);
	puts("");
	printf("HMAC-SHA1 Code:");
	for (int i = 0; i < 5; i++) {
		printf("%08X", key_1[i]);
	}
	puts("");
}
//getC
unsigned int* GetC_MD5(unsigned char* M) {
	ReSet_ABCD();
	unsigned int* M_16N;
	unsigned int* c = (unsigned int*)malloc(sizeof(int) * 4);
	unsigned int* M_16 = (unsigned int*)malloc(sizeof(int) * 16);
	M_16N = GetM_16N_MD5(M);
	
	for (int i = 0; i < length; i++) {
		M_16[i % 16] = M_16N[i];
		if (i != 0 && i % 16 == 15)
			c = Fun_MD5(M_16);
	}
	for (int i = 0; i < 4; i++)
		c[i] = PP(c[i]);
	return c;
}
unsigned int* GetC_SHA1(unsigned char* M) {
	unsigned int* M_16N;
	unsigned int* M_16 = (unsigned int*)malloc(sizeof(int) * 16);
	unsigned int* M_80 = (unsigned int*)malloc(sizeof(int) * 80);
	unsigned int* c = (unsigned int*)malloc(sizeof(int) * 5);
	M_16N = GetM_16N_SHA1(M);
	//输出检查M_16N
	//DisPlay(M_16N, length);
	//puts("");
	ReSet_ABCDE();
	for (int i = 0; i < length; i++) {
		M_16[i % 16] = M_16N[i];
		if (i != 0 && i % 16 == 15) {
			M_80 = GetM_80(M_16);
			//输出检查
			//DisPlay(M_80, 80);
			c = Fun_SHA1(M_80);
			//对下一组初始变量赋值
			for (int i = 0; i < 5; i++)
				ABCDE[i] = c[i];
			/*puts("");
			printf("SHA-1 Code:");
			for (int i = 0; i < 5; i++) {
				printf("%08X", c[i]);
			}
			puts("");*/
		}
	}
	return c;
}
//GetM_80
unsigned int* GetM_80(unsigned int* M_16) {
	unsigned int* M_80 = (unsigned int*)malloc(sizeof(int) * 80);
	for (int i = 0; i < 80; i++) {
		if (i < 16)
			M_80[i] = M_16[i];
		else
			M_80[i] = RL(M_80[i - 3] ^ M_80[i - 8] ^ M_80[i - 14] ^ M_80[i - 16], 1);
	}
	return M_80;
}
//GetM_16N
unsigned int* GetM_16N_MD5(unsigned char* M) {
	unsigned int* M_16;
	int len = strlen(M);
	int q = len / 64;
	int r = len % 64;
	int n = Getn(len);
	if (r <= 56) {
		M_16 = (unsigned int*)malloc(sizeof(int) * (q + 1) * 16);
		for (int i = 0; i < q * 64 + r; i++)
			if (i % 4 == 0)
				M_16[i / 4] = M[i] * (unsigned int)pow(256, 3);
			else
				M_16[i / 4] += M[i] * (unsigned int)pow(256, 3 - (i % 4));
		for (int i = q * 64 + r; i < (q + 1) * 64; i++) {
			unsigned int m = 0;
			if (i == q * 64 + r)
				m = 0x80;
			else
				m = 0;
			if (i % 4 == 0)
				M_16[i / 4] = m * (unsigned int)pow(256, 3);
			else
				M_16[i / 4] += m * (unsigned int)pow(256, 3 - (i % 4));
		}

		M_16[((q + 1) * 64 - 8) / 4] = length;
		M_16[((q + 1) * 64 - 8) / 4] = PP(M_16[((q + 1) * 64 - 8) / 4]);
		length = (q + 1) * 16;
	}
	else {
		M_16 = (unsigned int*)malloc(sizeof(int) * (q + 2) * 16);
		for (int i = 0; i < q * 64 + r; i++)
			if (i % 4 == 0)
				M_16[i / 4] = M[i] * (unsigned int)pow(256, 3 - (i % 4));
			else
				M_16[i / 4] += M[i] * (unsigned int)pow(256, 3 - (i % 4));
		for (int i = q * 64 + r; i < (q + 2) * 64; i++) {
			unsigned int m = 0;
			if (i == q * 64 + r)
				m = 0x80;
			else
				m = 0;
			if (i % 4 == 0)
				M_16[i / 4] = m * (unsigned int)pow(256, 3 - (i % 4));
			else
				M_16[i / 4] += m * (unsigned int)pow(256, 3 - (i % 4));
		}
		M_16[((q + 2) * 64 - 8) / 4] = length;
		M_16[((q + 2) * 64 - 8) / 4] = PP(M_16[((q + 2) * 64 - 8) / 4]);
		length = (q + 2) * 16;
	}
	//转为大端存储
	for (int i = 0; i < length; i++)
		M_16[i] = PP(M_16[i]);
	return M_16;
}
unsigned int* GetM_16N_SHA1(unsigned char* M) {
	unsigned int* M_16;
	int len = strlen(M);
	int q = len / 64;
	int r = len % 64;
	int n = Getn(len);
	if (r <= 56) {
		M_16 = (unsigned int*)malloc(sizeof(int) * (q + 1) * 16);
		for (int i = 0; i < q * 64 + r; i++)
			if (i % 4 == 0)
				M_16[i / 4] = M[i] * (unsigned int)pow(256, 3 - (i % 4));
			else
				M_16[i / 4] += M[i] * (unsigned int)pow(256, 3 - (i % 4));
		for (int i = q * 64 + r; i < (q + 1) * 64; i++) {
			unsigned int m = 0;
			if (i == q * 64 + r)
				m = 0x80;
			else
				m = 0;
			if (i % 4 == 0)
				M_16[i / 4] = m * (unsigned int)pow(256, 3 - (i % 4));
			else
				M_16[i / 4] += m * (unsigned int)pow(256, 3 - (i % 4));
		}
		for (int i = (q + 1) * 64 - n, j = n; i < (q + 1) * 64; i++, j--) {
			unsigned int m = 0;
			if (j < 2)
				m = length;
			else
				m = length / (int)pow(256, j - 1) % (int)pow(256, j - 2);
			if (i % 4 == 0)
				M_16[i / 4] = m * (unsigned int)pow(256, 3 - (i % 4));
			else
				M_16[i / 4] += m * (unsigned int)pow(256, 3 - (i % 4));
		}
		length = (q + 1) * 16;
	}
	else {
		M_16 = (unsigned int*)malloc(sizeof(int) * (q + 2) * 16);
		for (int i = 0; i < q * 64 + r; i++)
			if (i % 4 == 0)
				M_16[i / 4] = M[i] * (unsigned int)pow(256, 3 - (i % 4));
			else
				M_16[i / 4] += M[i] * (unsigned int)pow(256, 3 - (i % 4));
		for (int i = q * 64 + r; i < (q + 2) * 64; i++) {
			unsigned int m = 0;
			if (i == q * 64 + r)
				m = 0x80;
			else
				m = 0;
			if (i % 4 == 0)
				M_16[i / 4] = m * (unsigned int)pow(256, 3 - (i % 4));
			else
				M_16[i / 4] += m * (unsigned int)pow(256, 3 - (i % 4));
		}
		for (int i = (q + 2) * 64 - n, j = n; i < (q + 2) * 64; i++, j--) {
			unsigned int m = 0;
			if (j < 2)
				m = length;
			else
				m = length / (int)pow(256, j - 1) % (int)pow(256, j - 2);
			if (i % 4 == 0)
				M_16[i / 4] = m * (unsigned int)pow(256, 3 - (i % 4));
			else
				M_16[i / 4] += m * (unsigned int)pow(256, 3 - (i % 4));
		}

		length = (q + 2) * 16;
	}
	return M_16;
}
//Fun
unsigned int* Fun_MD5(unsigned int* x) {
	
	unsigned int* abcd = (unsigned int*)malloc(sizeof(int) * 4);
	unsigned int temp = 0;
	for (int i = 0; i < 4; i++)
		abcd[i] = ABCD[i];
	for (int i = 0; i < 64; i++) {
		int k = 0;
		if (i < 16) {
			temp = FF(abcd[0], abcd[1], abcd[2], abcd[3], x[i], S[i], T[i]);
		}
		else if (i < 32) {
			k = (1 + 5 * (i % 16)) % 16;
			temp = GG(abcd[0], abcd[1], abcd[2], abcd[3], x[k], S[i], T[i]);
		}
		else if (i < 48) {
			k = (5 + 3 * (i % 16)) % 16;
			temp = HH(abcd[0], abcd[1], abcd[2], abcd[3], x[k], S[i], T[i]);
		}
		else {
			k = (7 * (i % 16)) % 16;
			temp = II(abcd[0], abcd[1], abcd[2], abcd[3], x[k], S[i], T[i]);
		}
		abcd[0] = abcd[3];
		abcd[3] = abcd[2];
		abcd[2] = abcd[1];
		abcd[1] = temp;
	}
	for (int i = 0; i < 4; i++) {
		abcd[i] += ABCD[i];
		//对下一组初始变量赋值
		ABCD[i] = abcd[i];
	}
	return abcd;
}
unsigned int* Fun_SHA1(unsigned int* M_80) {
	unsigned int* abcde = (unsigned int*)malloc(sizeof(int) * 5);
	for (int i = 0; i < 5; i++)
		abcde[i] = ABCDE[i];
	for (int i = 0; i < 80; i++) {
		unsigned int temp = 0;
		if (i < 20)
			temp = RL(abcde[0], 5) + f1(abcde[1], abcde[2], abcde[3]) + abcde[4] + M_80[i] + Kt[0];
		else if (i < 40)
			temp = RL(abcde[0], 5) + f2(abcde[1], abcde[2], abcde[3]) + abcde[4] + M_80[i] + Kt[1];
		else if (i < 60)
			temp = RL(abcde[0], 5) + f3(abcde[1], abcde[2], abcde[3]) + abcde[4] + M_80[i] + Kt[2];
		else if (i < 80)
			temp = RL(abcde[0], 5) + f4(abcde[1], abcde[2], abcde[3]) + abcde[4] + M_80[i] + Kt[3];
		//printf("第%d步：a=[%08X],M[%d]=[%08X]\n", i + 1, abcde[0], i, M_80[i]);
		//printf("%08X  %08X  %08X %08X  %08X\n", RL(abcde[0], 5), f1(abcde[1], abcde[2], abcde[3]), abcde[4], M_80[i], Kt[0]);
		abcde[4] = abcde[3];
		abcde[3] = abcde[2];
		abcde[2] = RL(abcde[1], 30);
		abcde[1] = abcde[0];
		abcde[0] = temp;
	}
	for (int i = 0; i < 5; i++) {
		abcde[i] += ABCDE[i];
	}
	return abcde;
}
//Reset
void ReSet_ABCDE() {
	ABCDE[0] = 0x67452301;
	ABCDE[1] = 0xEFCDAB89;
	ABCDE[2] = 0x98BADCFE;
	ABCDE[3] = 0x10325476;
	ABCDE[4] = 0xC3D2E1F0;
}
void ReSet_ABCD() {
	ABCD[0] = 0x67452301;
	ABCD[1] = 0xefcdab89;
	ABCD[2] = 0x98badcfe;
	ABCD[3] = 0x10325476;
}
//
int Getn(int len) {
	int n = 1;
	length = len * 8;
	for (int i = length / 256; i != 0; i /= 256)
		n++;
	return n;
}
//Display
void DisPlay(int* XX, int n) {
	for (int i = 0; i < n; i++) {
		if (i != 0 && i % 4 == 0)
			puts("");
		printf("%02X ", XX[i]);
	}
	puts("");
}
//Other
void Clean() {
	puts("**输入回车后继续**");
	getchar();
	system("cls");
}