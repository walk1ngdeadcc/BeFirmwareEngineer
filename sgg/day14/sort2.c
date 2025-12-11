#include <stdio.h>
int partition(int arr[],int start,int end) {
    int pivot=arr[start];
    int left=start;
    int right=end;
    while (left<right) {
        while (arr[right]>pivot&&left<right) {
            right--;
        }
        arr[left]=arr[right];
        while (arr[left]<pivot&&left<right) {
            left++;
        }
        arr[right]=arr[left];
    }
    arr[left]=pivot;
    return left;
}
void sort(int arr[],int start,int end) {
    if (start>=end) {
        return;
    }
    int pivotIndex=partition(arr,start,end);
    sort(arr,start,pivotIndex-1);
    sort(arr,pivotIndex+1,end);
}
int main() {
    int arr[]={2,41,34,6,7,3,5,8,9,66};
    int len=10;
    sort(arr,0,9);
    for (int i = 0; i < 10; ++i) {
        printf("%d ",arr[i]);
    }
    return 0;
}