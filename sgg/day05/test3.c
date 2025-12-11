#include <stdio.h>

int main() {
    setbuf(stdout, NULL);
    double weight[6]={3,5,1,3.4,2,50};
    double weights=0;
    for (int i=0;i<6;i++) {
        weights+=weight[i];
    }
    printf("总体重：%lfkg",weights);
    printf("平均体重：%lfkg",weights/6);
    return 0;
}