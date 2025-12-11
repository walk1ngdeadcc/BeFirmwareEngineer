//
// Created by 14574 on 2025/11/25.
//
#include <stdio.h>

int main() {
    char str1[12] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0'}; // 显式地设值 \0
    char str2[4] = {'t', 'o', 'm'}; // 后面自动添加 \0
    char str3[] = {'j', 'a', 'c', 'k'}; // 不会自动添加 \0

    printf("str1=%s \n", str1);
    printf("str2=%s \n", str2);
    printf("str3=%s \n", str3); // 由于没有结束标识，会包括相邻内存的数据，直到遇到结束标记
    printf("--------------------------------------------\n");

    char str4[] = {"haha666"};
    char str5[] = "lala777";
    printf("str4=%s\n", str4);
    printf("str5=%s\n", str5);
    printf("--------------------------------------------\n");

    int len = sizeof str5 / sizeof str5[0];
    printf("str5的第2个字符是%c\n", str5[1]);
    for (int i = 0; i < len; i++) {
        printf("%c\n", str5[i]);
    }
    return 0;
}
