# include "AA.h"
/*
 * 扩展 SM4 S盒
 /* Sbox table: 8bit输入转化成8bit输出*/
static const unsigned char SboxTable[16][16] =
{
        {0xd6, 0x90, 0xe9, 0xfe, 0xcc, 0xe1, 0x3d, 0xb7, 0x16, 0xb6, 0x14, 0xc2, 0x28, 0xfb, 0x2c, 0x05},
        {0x2b, 0x67, 0x9a, 0x76, 0x2a, 0xbe, 0x04, 0xc3, 0xaa, 0x44, 0x13, 0x26, 0x49, 0x86, 0x06, 0x99},
        {0x9c, 0x42, 0x50, 0xf4, 0x91, 0xef, 0x98, 0x7a, 0x33, 0x54, 0x0b, 0x43, 0xed, 0xcf, 0xac, 0x62},
        {0xe4, 0xb3, 0x1c, 0xa9, 0xc9, 0x08, 0xe8, 0x95, 0x80, 0xdf, 0x94, 0xfa, 0x75, 0x8f, 0x3f, 0xa6},
        {0x47, 0x07, 0xa7, 0xfc, 0xf3, 0x73, 0x17, 0xba, 0x83, 0x59, 0x3c, 0x19, 0xe6, 0x85, 0x4f, 0xa8},
        {0x68, 0x6b, 0x81, 0xb2, 0x71, 0x64, 0xda, 0x8b, 0xf8, 0xeb, 0x0f, 0x4b, 0x70, 0x56, 0x9d, 0x35},
        {0x1e, 0x24, 0x0e, 0x5e, 0x63, 0x58, 0xd1, 0xa2, 0x25, 0x22, 0x7c, 0x3b, 0x01, 0x21, 0x78, 0x87},
        {0xd4, 0x00, 0x46, 0x57, 0x9f, 0xd3, 0x27, 0x52, 0x4c, 0x36, 0x02, 0xe7, 0xa0, 0xc4, 0xc8, 0x9e},
        {0xea, 0xbf, 0x8a, 0xd2, 0x40, 0xc7, 0x38, 0xb5, 0xa3, 0xf7, 0xf2, 0xce, 0xf9, 0x61, 0x15, 0xa1},
        {0xe0, 0xae, 0x5d, 0xa4, 0x9b, 0x34, 0x1a, 0x55, 0xad, 0x93, 0x32, 0x30, 0xf5, 0x8c, 0xb1, 0xe3},
        {0x1d, 0xf6, 0xe2, 0x2e, 0x82, 0x66, 0xca, 0x60, 0xc0, 0x29, 0x23, 0xab, 0x0d, 0x53, 0x4e, 0x6f},
        {0xd5, 0xdb, 0x37, 0x45, 0xde, 0xfd, 0x8e, 0x2f, 0x03, 0xff, 0x6a, 0x72, 0x6d, 0x6c, 0x5b, 0x51},
        {0x8d, 0x1b, 0xaf, 0x92, 0xbb, 0xdd, 0xbc, 0x7f, 0x11, 0xd9, 0x5c, 0x41, 0x1f, 0x10, 0x5a, 0xd8},
        {0x0a, 0xc1, 0x31, 0x88, 0xa5, 0xcd, 0x7b, 0xbd, 0x2d, 0x74, 0xd0, 0x12, 0xb8, 0xe5, 0xb4, 0xb0},
        {0x89, 0x69, 0x97, 0x4a, 0x0c, 0x96, 0x77, 0x7e, 0x65, 0xb9, 0xf1, 0x09, 0xc5, 0x6e, 0xc6, 0x84},
        {0x18, 0xf0, 0x7d, 0xec, 0x3a, 0xdc, 0x4d, 0x20, 0x79, 0xee, 0x5f, 0x3e, 0xd7, 0xcb, 0x39, 0x48}
};
/* 系统参数 */
static const unsigned long FK[4] = { 0xa3b1bac6, 0x56aa3350, 0x677d9197, 0xb27022dc };
/* 固定参数 */
static const unsigned long CK[32] =
{
        0x00070e15, 0x1c232a31, 0x383f464d, 0x545b6269,
        0x70777e85, 0x8c939aa1, 0xa8afb6bd, 0xc4cbd2d9,
        0xe0e7eef5, 0xfc030a11, 0x181f262d, 0x343b4249,
        0x50575e65, 0x6c737a81, 0x888f969d, 0xa4abb2b9,
        0xc0c7ced5, 0xdce3eaf1, 0xf8ff060d, 0x141b2229,
        0x30373e45, 0x4c535a61, 0x686f767d, 0x848b9299,
        0xa0a7aeb5, 0xbcc3cad1, 0xd8dfe6ed, 0xf4fb0209,
        0x10171e25, 0x2c333a41, 0x484f565d, 0x646b7279
};
void Run() {
    int choice = -1;
RE:
    puts("-------------");
    puts("|  1、加密  |");
    puts("|  2、解密  |");
    puts("|  0、退出  |");
    puts("-------------");
    printf("请选择：");
    scanf("%d", &choice);
    getchar();
    switch (choice) {
    case 0:
        puts("**退出成功**");
        return 0;
    case 1:
        GetCorM(choice);
        ClearScreen();
        break;
    case 2:
        GetCorM(choice);
        ClearScreen();
        break;
    default:
        puts("请输入有效选项");
        ClearScreen();
    }
    goto RE;
}
void GetCorM(int choice) {
        FILE* Mfp = NULL;
        FILE* Cfp = NULL;
        unsigned char* key = (unsigned char*)malloc(sizeof(char)*17);
        unsigned long* sonkey = (unsigned long*)malloc(sizeof(long) * 36);
        unsigned char *input = (unsigned char*)malloc(sizeof(char) * KEYMAX);
        unsigned long* output = (unsigned long*)malloc(sizeof(long) * 36);
        unsigned char* output_1 = (unsigned char*)malloc(sizeof(char) * KEYMAX);
        char MPath[PATHMAX];
        char CPath[PATHMAX];
        memset(key, '0', sizeof(key));
        memset(input, '0', sizeof(input));
        memset(output, '0', sizeof(output)); 
        //对加密和解密进行不同的操作选择
        switch (choice)
        {
            case 1: {
            Re:
                printf("请输入%d字节的密钥:", KEYMAX);
                scanf("%[^\n]s", key);
                getchar();

                if (strlen(key) != 16) {
                    puts("**请输入%d位的密钥**");
                    goto Re;
                }
            Re_1:
                printf("请输入需要加密的文件路径:");
                scanf("%s", MPath);
                getchar();
                Mfp = fopen(MPath, "r");
                if (Mfp == NULL) {
                    puts("**该文件不存在**");
                    goto Re_1;
                }
                printf("请输入写入密文的文件路径:");
                scanf("%s", CPath);
                getchar();
                //得到32轮的密钥
                sonkey = GetSonKey(key);
                //输出子密钥
                DisPlaySonKey(sonkey);
                //打开写数据流
                Cfp = fopen(CPath, "w+");
                //进行预读取，让循环能正常运行
                int len = fread(input, sizeof(char), 16, Mfp);
                while (len > 0) {
                    if (len != 16) {
                        //需要做填充
                        for (int i = 0; i < 16 - len; i++) {
                            input[len + i] = 16 - len;
                        }
                    }
                    output = GetC_1(input, sonkey,choice);
                    //输出
                    for (int j = 4; j < 36; j++) {
                        if (j % 4 == 0 && j != 4)
                            puts("");
                        printf("第%d轮加密为%X ", j - 3, output[j]);
                    }
                    //处理得到的32轮密钥，得到最后四轮对应的格式和类型
                    output_1 = GetOutPut(output);
                    //进行本组的写入，及下一组的读取
                    fwrite(output_1, sizeof(char) * KEYMAX, 1, Cfp);
                    len = fread(input, sizeof(char), KEYMAX, Mfp);
                }
                //关闭文件流
                fclose(Mfp);
                fclose(Cfp);
            }break;
            case 2: {
            Re_3:
                printf("请输入%d字节的密钥:", KEYMAX);
                scanf("%[^\n]s", key);
                getchar();

                if (strlen(key) != 16) {
                    printf("请输入%d字节的密钥:", KEYMAX);
                    goto Re_3;
                }
            Re_4:
                printf("请输入需要解密的文件路径:");
                scanf("%s", CPath);
                getchar();
                Cfp = fopen(CPath, "r");
                if (Cfp == NULL) {
                    puts("**该文件不存在**");
                    goto Re_4;
                }
                //得到32轮的密钥
                sonkey = GetSonKey(key);
                //输出子密钥
                DisPlaySonKey(sonkey);
                //进行预读取，让循环能正常运行
                int len = fread(input, sizeof(char), 16, Cfp);
                while (len > 0) {
                    output = GetC_1(input, sonkey, choice);//这里需要修改
                    //输出
                    for (int j = 4; j < 36; j++) {
                        if (j % 4 == 0 && j != 4)
                            puts("");
                        printf("第%d轮解密密为%X ", j - 3, output[j]);
                    }
                    puts("");
                    //处理得到的32轮密钥，得到最后四轮对应的格式和类型
                    output_1 = GetOutPut(output);
                    //进行本组的输出，及下一组的读取
                    printf("解密的结果是：");
                    for (int i = 0; i < KEYMAX;i++) {
                        printf("%c",output_1[i]);
                    }
                    puts("");
                    len = fread(input, sizeof(char), KEYMAX, Cfp);
                }
                //关闭文件流
                fclose(Cfp);
            } break;              
            default:
                puts("**不可能出现的结果**");
                return;
        }    
}
unsigned long* GetSonKey(unsigned char* key) {
    unsigned long* sonkey = (unsigned long*)malloc(sizeof(long) * 36);
    for (int i = 0; i < 36;i++) {
        if (i < 4)
            sonkey[i] = GetK_i(key,i);
        else
            sonkey[i] = GetRk_i(sonkey, i);        
    }
    return sonkey;
}
unsigned long GetK_i(unsigned char* key, int i) {
    //这里实现前四位的转化，方便子密钥的生成
    unsigned long K_i = FourToOne(key, i) ^ FK[i];
    return K_i;
}
unsigned long FourToOne(unsigned char* key, int i) {
    unsigned long result = 0;
    for (int j = 0,k = 7; j < 4; j++,k -= 2) {
        //这里实现把那16个读取的字符转为4组
        result += (unsigned long)(key[i * 4 + j] / 16 )* (unsigned long)pow(16, k) + (unsigned long)(key[i * 4 + j] % 16)* (unsigned long)pow(16, k- 1);
    }
    return result;
}
unsigned long GetRk_i(unsigned long* sonkey, int i) {
    //这里实现得到子密钥的功能,这里的i从4开始
    unsigned long rk;
    unsigned long sk;
    sk = sonkey[i - 3] ^ sonkey[i - 2] ^ sonkey[i - 1] ^ CK[i - 4];
    rk = sonkey[i - 4] ^ T(sk,0);
    return rk;
}
unsigned long T(unsigned long sk,int k) {
    unsigned long t;
    unsigned long B[5];
    if (k == 0) {
        B[0] = Sub(sk);
        //移位
        B[1] = (B[0]>>(32 - 13))|(B[0] << 13);//循环左移13位
        B[2] = (B[0] >> (32 - 23)) | (B[0] << 23);//循环左移23位
        t = B[0] ^ B[1] ^ B[2];
    }
    else if(k == 1){
        B[0] = Sub(sk);
        B[1] = (B[0] >> (32 - 2)) | (B[0] << 2);//循环左移13位
        B[2] = (B[0] >> (32 - 10)) | (B[0] << 10);//循环左移23位
        B[3] = (B[0] >> (32 - 18)) | (B[0] << 18);//循环左移23位
        B[4] = (B[0] >> (32 - 24)) | (B[0] << 24);//循环左移23位
        t = B[0] ^ B[1] ^ B[2] ^ B[3] ^ B[4];
    }
    return t;
}
unsigned long Sub(unsigned long sk) {
    unsigned long s = 0;
    int r = 0;
    int c = 0;
    int t = 0;
    for (int i = 7; i > 0;i-=2) {
        r = sk / (unsigned long)pow(16,i) % 16;
        c = sk / (unsigned long)pow(16,i - 1) % 16;
        t = SboxTable[r][c];
        s += t / 16 * (unsigned long)pow(16, i) + t % 16 * (unsigned long)pow(16, i-1);
    }
    return s;
}
unsigned long* GetC_1(unsigned char* input, unsigned long* sonkey, int choice) {
    unsigned long* c = (unsigned long*)malloc(sizeof(long) * 36);
    for (int i = 0; i < 36; i++) {
        if (i < 4)
            c[i] = FourToOne(input,i);
        else {
            if (choice == 1)
                c[i] = GetRX(c, i, sonkey);
            else if (choice == 2)
                c[i] = GetRX_CtoM(c, i, sonkey);
            else
                puts("**不可能，绝对不可能**");
        } 
    }
    //输出检查
    /*for (int j = 0; j < 36; j++) {
        printf("%X\n", c[j]);
    }
    getchar();*/
    return c;
}
unsigned long GetRX(unsigned long* c, int i, unsigned long* sonkey) {
    //这里实现得到子密钥的功能,这里的i从4开始
    unsigned long rk;
    unsigned long sk;
    sk = c[i - 3] ^ c[i - 2] ^ c[i - 1] ^ sonkey[i];
    rk = c[i - 4] ^ T(sk, 1);
    return rk;
}
unsigned char* GetOutPut(unsigned long* output){
    unsigned char* output_1 = (unsigned char*)malloc(sizeof(char) * KEYMAX);
    for (int i = 0; i < 4;i++) {
        int a = 0, b = 0;
        for (int j = 7,k = 0; k < 4; j -= 2,k++) {
            a = output[35 - i] / (unsigned long)pow(16, j) % 16;
            b = output[35 - i] / (unsigned long)pow(16, j - 1) % 16;
            output_1[i * 4 + k] = a * 16 + b;
        }
    }
    return output_1;
}
unsigned long GetRX_CtoM(unsigned long* c, int i, unsigned long* sonkey) {
    //这里实现得到子密钥的功能,这里的i从4开始
    unsigned long rk;
    unsigned long sk;
    sk = c[i - 3] ^ c[i - 2] ^ c[i - 1] ^ sonkey[35 - i + 4];
    rk = c[i - 4] ^ T(sk, 1);
    return rk;
}
void DisPlaySonKey(unsigned long* sonkey) {
    for (int j = 4; j < 36; j++) {
        if (j % 4 == 0 && j != 4)
            puts("");
        printf("第%d轮密钥为%X ", j - 3, sonkey[j]);
    }
    puts("");
}
void ClearScreen() {
    puts("");
    puts("**输入回车后继续**");
    getchar();
    system("cls");
}