#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int isRepeat(int arr[],int len,int a) {
    for (int i=0;i<len;i++) {
        if (a==arr[i]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int arr[10]={0};
    int len=sizeof(arr)/sizeof(arr[0]);
    srand(time(NULL));
    int flag=1;
    for (int i=0;i<len;i++) {
        while (flag==1) {
            int a=rand()%100+1;
        flag=isRepeat(arr,len,a);
        arr[i]=a;
        }
        flag=1;
    }
    for (int i=0;i<len;i++) {
        printf("%d ",arr[i]);
    }

    double sum=0.0;
    double avg;
    for (int i=0;i<len;i++) {
        sum+=arr[i];
    }
    avg=sum/len;
    printf("\navg=%lf",avg);

    int n=0;
    for (int i=0;i<len;i++) {
        if (arr[i]>avg) {
            n++;
        }
    }
    printf("\n%d",n);
    return 0;
}
