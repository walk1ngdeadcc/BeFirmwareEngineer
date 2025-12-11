#include <stdio.h>

int main() {
    int sum = 0;
    for (int i = 1; i < 6; i++) {
        int n = 0;
        printf("输入第%d个数：\n",i);
        fflush(stdout);
        scanf("%d", &n);
        sum += n;
    }
    printf("平均数是%d", sum / 5);
    return 0;
}
