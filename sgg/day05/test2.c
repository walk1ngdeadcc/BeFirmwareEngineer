#include <stdio.h>

int main() {
    setbuf(stdout, NULL);
    double score[5];
    printf("请输入5个成绩：");
    for (int i=0;i<5;i++) {
        scanf("%lf",&score[i]);
    }

    for (int i=0;i<5;i++) {
        printf("%lf ",score[i]);
    }
    return 0;
}