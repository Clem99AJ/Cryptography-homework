#include "AA.h"
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
unsigned int length = 0;
void Run() {
    int choice = -1;
Re:
    puts("---------------");
    puts("|   MD5加密   |");
    puts("| 1、键盘输入 |");
    puts("| 2、文件输入 |");
    puts("|-------------|");
    printf("请选择：");
    scanf("%d", &choice);
    getchar();
    switch (choice) {
    case 0:
        puts("程序退出成功");
        return;
    case 1:
        SgetC();
        break;
    case 2:
        FgetC();
        break;
    default:
        puts("**请输入有效选项**");
    }
    Clean();
    goto Re;
}
void SgetC() {
    char* M = (char*)malloc(sizeof(char) * MAX);
    printf("请输入需要Hash的字符串：");
    scanf("%[^\n]s", M);
    getchar();
    ReSet_ABCD();
    GetC(M);
}
void FgetC() {
    char* M = (char*)malloc(sizeof(char) * MAX);
    char* filepath = (char*)malloc(sizeof(char) * MAX);
    FILE* f = NULL;
    int len  = 0;
    Re:
    printf("请输入文件所在路径：");
    scanf("%s",filepath);
    getchar();
    f = fopen(filepath,"r");
    if (f == NULL) {
        puts("**该文件不存在**");
        goto Re;
    }
    fseek(f,0,SEEK_END);
    len = ftell(f);
    fseek(f, 0, SEEK_SET);
    fread(M,sizeof(char)*len,1,f);
    M[len] = '\0';
    fclose(f);
    GetC(M);
}
void GetC(char* M) {
    unsigned int* M_16N;
    unsigned int* c = (unsigned int*)malloc(sizeof(int)  * 4);
    unsigned int* M_16 = (unsigned int*)malloc(sizeof(int) * 16);
    
    M_16N = GetM_16(M);
    puts("M_16N");
    for (int i = 0; i < length; i++) {
        printf("%08X  ",M_16N[i]);
        if (i % 4 == 3)
            puts("");
    }
    for (int i = 0; i < length; i++) {
        M_16[i % 16] = M_16N[i];
        if (i != 0 && i % 16 == 15) {
            
            c = Fun_MD5(M_16);
            
            printf("ABCD:");
            for (int i = 0; i < 4; i++) {
                printf("%08X", ABCD[i]);
            }
            puts("");
        }
    }
    printf("MD5 Code:");
    for (int i = 0; i < 4; i++) 
        printf("%08X", PP(c[i]));
    puts("");
}
unsigned int* GetM_16(char* M) {
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
int Getn(int len) {
    int n = 1;
    length = len * 8;
    for (int i = length / 256; i != 0; i /= 256)
        n++; 
    return n;
}
unsigned int* Fun_MD5(int * x) {
    puts("M_16");
    for (int i = 0; i < 16; i++) {
        printf("%08X  ", x[i]);
        if (i % 4 == 3)
            puts("");
    }
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
        else{
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
void ReSet_ABCD() {
    ABCD[0] = 0x67452301;
    ABCD[1] = 0xefcdab89;
    ABCD[2] = 0x98badcfe;
    ABCD[3] = 0x10325476;
}
void Clean() {
    puts("**输入回车后继续**");
    getchar();
    system("cls");
}