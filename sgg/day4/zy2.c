//
// Created by 14574 on 2025/11/25.
//
#include <stdio.h>
int main() {
    for (int i=100;i<1000;i++) {
        int g=i%10;
        int s=i/10%10;
        int b=i/100;
        if (g*g*g+s*s*s+b*b*b==i) {
            printf("%d ",i);
        }
    }
}