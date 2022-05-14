# include "AA.h" 
const int MulFactor[4][4] = { 
                       {0x02, 0x03, 0x01, 0x01},
                       {0x01, 0x02, 0x03, 0x01},
                       {0x01, 0x01, 0x02, 0x03},
                       {0x03, 0x01, 0x01, 0x02} };
const int MulFactor_1[4][4] = { {0x0E, 0x0B, 0x0D, 0x09},
                         {0x09, 0x0E, 0x0B, 0x0D},
                         {0x0D, 0x09, 0x0E, 0x0B},
                         {0x0B, 0x0D, 0x09, 0x0E} };//����ʹ��
const int S[16][16] = { {0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76},
                 {0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0},
                 {0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15},
                 {0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75},
                 {0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84},
                 {0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf},
                 {0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8},
                 {0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2},
                 {0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73},
                 {0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb},
                 {0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79},
                 {0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08},
                 {0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a},
                 {0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e},
                 {0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf},
                 {0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16} };
const int S_1[16][16] = { {0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb},
                   {0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb},
                   {0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e},
                   {0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25},
                   {0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92},
                   {0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84},
                   {0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06},
                   {0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b},
                   {0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73},
                   {0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e},
                   {0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b},
                   {0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4},
                   {0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f},
                   {0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef},
                   {0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61},
                   {0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d}
};//����ʹ��
const int RCon[11][4] = {
        {0x00, 0x00, 0x00, 0x00},
        {0x01, 0x00, 0x00, 0x00},
        {0x02, 0x00, 0x00, 0x00},
        {0x04, 0x00, 0x00, 0x00},
        {0x08, 0x00, 0x00, 0x00},
        {0x10, 0x00, 0x00, 0x00},
        {0x20, 0x00, 0x00, 0x00},
        {0x40, 0x00, 0x00, 0x00},
        {0x80, 0x00, 0x00, 0x00},
        {0x1B, 0x00, 0x00, 0x00},
        {0x36, 0x00, 0x00, 0x00} };
const char Printfchoice[5][30] = { "**�˳�����ɹ�**\0","Zero\0","X923\0","PKCS7\0","ISO10126\0"};
void Run() {
    int choice = -1;
    char* prch = NULL;//���ڲ�ͬѡ��ʱ��ָ��ͬ���͵���ʾ��
    char* m = (char*)malloc(sizeof(char) * MAX);
    char* key = (char*)malloc(sizeof(char) * KEYMAX);
    int** key1 = (int**)malloc(sizeof(int*) * 4);
    for (int i = 0; i < 4; i++) {
        key1[i] = (int*)malloc(sizeof(int) * 44);
        memset(key1[i], 0, sizeof(int) * 44);
    }//����װ4x44����
    int** key2 = (int**)malloc(sizeof(int*) * 11);
    for (int i = 0; i < 10; i++) {
        key2[i] = (int*)malloc(sizeof(int) * KEYMAX);
        memset(key2[i], 0, sizeof(int) * KEYMAX);
    }//����װ10x16����
    int** c = NULL;
    
    RE_0:
    printf("---------------------\n");
    printf("|  ==AES�����㷨==  |\n");
    printf("|   1��Zero���     |\n");
    printf("|   2��X923���     |\n");
    printf("|   3��FKCS7���    |\n");
    printf("|  4��ISO10126���  |\n");
    printf("|   0���˳�����     |\n");
    printf("---------------------\n");
    printf("��ѡ��������䷽ʽ��");
    scanf("%d",&choice);
    getchar();
    prch = Printfchoice[choice];
    switch (choice)
    {
        case 0:
            printf("%s\n",prch);
            return;
        case 1:
            printf("����������(������%d�ֽ�)��", MAX);
            scanf("%[^\n]s", m);
            getchar();
            if(strlen(m) % KEYMAX != 0)
                m = Zero(m);
            break;
        case 2:
            printf("����������(������%d�ֽ�)��", MAX);
            scanf("%[^\n]s", m);
            getchar();
            if (strlen(m) % KEYMAX != 0)
                m = X923(m);
            break;
        case 3:
            printf("����������(������%d�ֽ�)��", MAX);
            scanf("%[^\n]s", m);
            getchar();
            if (strlen(m) % KEYMAX != 0)
                m = PKCS7(m);
            break;
        case 4:
            printf("����������(������%d�ֽ�)��", MAX);
            scanf("%[^\n]s", m);
            getchar();
            if (strlen(m) % KEYMAX != 0)
                m = ISO10126(m);
            break;
        default:
            system("cls");
            printf("**��������Чѡ��**\n");
            goto RE_0;
    }
    RE_1:
    printf("������%dλ����Կ��",KEYMAX);
    scanf("%s",key);
    getchar();
    if (strlen(key) != KEYMAX) {
        printf("**���������Կ������%d�ֽڣ�����������**\n",KEYMAX);
        goto RE_1;
    }
    printf("    ---���ڲ�������Կ---\n");
    printf("----��ɾ��󻯵�����ԿΪ----\n");
    key = GetMatrixKey(key);
    DisPlayMatrix(key);

    key1 = GetSonKey(key);

    key2 = GetSonKey2(key1);
    DisPlayKEY10x16(key2);

    printf("%s���ģʽ�µ�����Ϊ��%s\n",prch,m);
    c = GetC(m,key2);
    printf("�����ǣ�");
    printf("%s\n",m);
    printf("��Կ�ǣ�");
    for (int i = 0; i < KEYMAX;i++) {
        printf("%c",key2[10][i]);
    }
    puts("");
    printf("AES���ܵĽ���ǣ�");
    for (int i = 0;i < strlen(m) / KEYMAX;i++) {
        for (int j = 0; j < KEYMAX;j++) {
            printf("%02X ",c[i][j]);
        }
    }
    puts("");
    printf("**����س�����**");
    getchar();
    system("cls");
    goto RE_0;
}
char* Zero(char* m) {
    int len = strlen(m);
    int q = len / KEYMAX;
    int r = len % KEYMAX;
    for (int i = 0; i < KEYMAX - r;i++) {
        m[q * KEYMAX + r + i] = '0';
    }
    m[(q + 1) * KEYMAX] = '\0';
    printf("%s\n", m);
    return m;
}
char* X923(char *m) {
    int len = strlen(m);
    int q = len / KEYMAX;
    int r = len % KEYMAX;
    for (int i = 0; i < KEYMAX - r; i++) {
            m[q * KEYMAX + r + i] = '0';
    }
    m[(q + 1) * KEYMAX - 1] = KEYMAX - r;
    m[(q + 1) * KEYMAX] = '\0';
    printf("%s\n", m);
    return m;
}
char* PKCS7(char* m) {
    int len = strlen(m);
    int q = len / KEYMAX;
    int r = len % KEYMAX;
    for (int i = 0; i < KEYMAX - r; i++) {
        m[q * KEYMAX + r + i] = KEYMAX - r;
    }
    m[(q + 1) * KEYMAX] = '\0';
    printf("%s\n", m);
    return m;
}
char* ISO10126(char* m) {
    int len = strlen(m);
    int q = len / KEYMAX;
    int r = len % KEYMAX;
    srand(time(NULL));
    for (int i = 0; i < KEYMAX - r; i++) {
        m[q * KEYMAX + r + i] = rand() % 127;
    }
    m[(q + 1) * KEYMAX - 1] = KEYMAX - r;
    m[(q + 1) * KEYMAX] = '\0';
    printf("%s\n", m);
    return m;
}
char* GetMatrixKey(char* key) {
    char* key1 = (char*)malloc(sizeof(char) * KEYMAX);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            *((key1 + i * 4) + j) = *((key + j * 4) + i);
        }
    }
    return key1;
}
int** GetSonKey(char* key) {
    int** key1 = (int**)malloc(sizeof(int*) * 4);
    for (int i = 0; i < 4; i++) {
        key1[i] = (int*)malloc(sizeof(int) * 44);
        memset(key1[i],0, sizeof(int) * 44);
    }
    //��ԭ�еĲ��ַ���
    for (int i = 0; i < 4;i++) {
        for (int j = 0; j < 4;j++) {
            key1[i][j] = key[i * 4 + j];
        }
    }

    for (int i = 4; i < 44;i++) {
        for (int j = 0; j < 4;j++) {
            //�ҵ���λ����S���е�����
            int q = key1[(j + 1) % 4][i - 1] / 16;
            int r = key1[(j + 1) % 4][i - 1] % 16;
            if (i % 4 == 0) {
                key1[j][i] =S[q][r] ^ key1[j][i - 4] ^ RCon[i / 4][j];
            }
            else {
                key1[j][i] = key1[j][i - 1] ^ key1[j][i - 4];
            }
        }  
    }
    return key1;
}
int** GetSonKey2(int** key) {
    int** key1 = (int**)malloc(sizeof(int*) * 11);
    for (int i = 0; i < 11;i++) {
        key1[i] = (int*)malloc(sizeof(int) * KEYMAX);
        memset(key1[i],0,sizeof(int)*KEYMAX);
    }
    for (int i = 0; i < 10;i++) {
        for (int j = 0; j < KEYMAX;j++) {
            key1[i][j] = key[j % 4][(i + 1) * 4 + j / 4];
        }
    }
    for (int i = 0; i < KEYMAX; i++) {
        key1[10][i] = key[i % 4][i / 4];
    }
    
    return key1;
}
int** GetC(char *m, int** key) {
    int q = strlen(m) / KEYMAX;//������ĵ�����
    //�������
    int** c = (int**)malloc(sizeof(int*) * q);
    for (int i = 0; i < strlen(m) / KEYMAX; i++) {
        c[i] = (int*)malloc(sizeof(int) * KEYMAX);
        memset(c[i], 0, sizeof(int) * KEYMAX);
    }
    //����һ��������װ�����ĵķ�����
    int** m1 = (int**)malloc(sizeof(int*) * q);
    for (int i = 0; i < strlen(m) / KEYMAX;i++) {
        m1[i] = (int*)malloc(sizeof(int) * KEYMAX);
        memset(m1[i],0,sizeof(int)*KEYMAX);
    }
    //�����ķ���,����ѭ������
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < KEYMAX;j++) {
            m1[i][j] = m[i * 16 + j];
        }
    }
    //DisPlayKEY_Nx16(m1,q);//����������
    
    //�������
    for (int i = 0; i < q; i++) {
        printf("��%d����ܣ�\n",i + 1);
        c[i] = GetC1(m1[i],key);
    }
    
    return c;
}
int* GetC1(int* m, int** key) {
    int* c = (int*)malloc(sizeof(int) * KEYMAX);
    int** MC = (int**)malloc(sizeof(int*) * 4);
    for (int i = 0; i < 4;i++) {
        MC[i] = (int*)malloc(sizeof(int) * 4);
        memset(MC[i],0,sizeof(int) * 4);
    }
    //�����ľ���
    printf("==��ɾ��󻯵ľ���Ϊ==\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            MC[j][i] = m[i * 4 + j];
        }
    }
    DisPlayMatrix1(MC);

    //��ʼ���
   /* for (int i = 0; i < KEYMAX;i++) {
        MC[i % 4][i / 4] = MC[i % 4][i / 4] ^ key[10][i];
    }*/
    printf("���ڿ�ʼ����==>\n");
    for (int i = 0; i < 10;i++) {
        puts("--------------------");
        printf("��%d�ּ���:\n",i + 1);
            MC = GetC2(MC,key[i],i);
    }
    //������cת����һά����ȥ
    for (int i = 0; i < 16;i++) {
        c[i] = MC[i % 4][i / 4];
    }
    return c;
}
int** GetC2(int** m,int* key, int n) {
    int** temp = (int**)malloc(sizeof(int*) * 4);
    for (int i = 0; i < 4; i++) {
        temp[i] = (int*)malloc(sizeof(int) * 4);
        memset(temp[i], 0, sizeof(int) * 4);
    }
    printf("===���SubByte�任�ľ���Ϊ===\n");
    temp = SubByte(m,temp);
    DisPlayMatrix1(temp);
    printf("===���ShiftRows�任�ľ���Ϊ===\n");
    m = ShiftRows(temp,m);
    DisPlayMatrix1(m);

    if (n != 9) {
        printf("===���MixColumns�任�ľ���Ϊ===\n");
        temp = MixColumns(m, temp);
        DisPlayMatrix1(temp);
    }
    else
        temp = m;
    //���
    printf("���ܵĽ���ǣ�\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4;j++) {
            m[j][i] = temp[j][i] ^ key[i * 4 + j];
        }
    }
    DisPlayMatrix1(m);
    return m;
}
int** SubByte(int** m, int** temp) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int q = m[i][j] / 16;
            int r = m[i][j] % 16;
            temp[i][j] = S[q][r];
        }
    }
    return temp;
}
int** ShiftRows(int** m, int** temp) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            temp[i][j] = m[i][(j + i) % 4];
        }
    }
    return temp;
}
int** MixColumns(int** m, int** temp) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int num = 0, x = 0;
            for (int k = 0; k < 4; k++) {
                if (num == 0) {
                    if (MulFactor[j][k] == 1) {
                        num = m[k][i];
                    }
                    else if (MulFactor[j][k] == 2) {
                        if (m[k][i] >= 128) {
                            num = m[k][i] << 1;
                            num = num ^ 27;
                        }
                        else {
                            num = m[k][i] << 1;
                        }
                    }
                    else if (MulFactor[j][k] == 3) {
                        if (m[k][i] >= 128) {
                            num = m[k][i] << 1;
                            num = num ^ 27;
                        }
                        else {
                            num = m[k][i] << 1;
                        }
                        num = num ^ m[k][i];

                    }
                }
                else {

                    if (MulFactor[j][k] == 1) {
                        num = m[k][i] ^ num;
                    }
                    else if (MulFactor[j][k] == 2) {
                        if (m[k][i] >= 128) {
                            x = m[k][i] << 1;
                            x = x ^ 27;
                        }
                        else {
                            x = m[k][i] << 1;
                        }
                        num = x ^ num;
                    }
                    else if (MulFactor[j][k] == 3) {
                        if (m[k][i] >= 128) {
                            x = m[k][i] << 1;
                            x = x ^ 27;
                        }
                        else {
                            x = m[k][i] << 1;
                        }
                        x = x ^ m[k][i];
                        num = num ^ x;
                    }
                }
            }
            num = num % 256;
            temp[j][i] = num;
        }
    }
    return temp;
}
void DisPlayMatrix(char* XX) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%c ", *((XX + i * 4) + j));
        }
        puts("");
    }
}
void DisPlayMatrix1(int **XX) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%02X ", XX[i][j]);
        }
        puts("");
    }
}
void DisPlayKEY4x44(int** key) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 44; j++) {
            printf("%02X ", key[i][j]);
        }
        puts("");
    }
}
void DisPlayKEY10x16(int** key) {
    for (int i = 0; i < 10; i++) {
        printf("��%2d������Կ�ǣ�",i + 1);
        for (int j = 0; j < KEYMAX; j++) {
            printf("%02X ", key[i][j]);
        }
        puts("");
    }
}
void DisPlayKEY_Nx16(int** XX, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < KEYMAX; j++) {
            printf("%02X ", XX[i][j]);
        }
        puts("");
    }
}