#include <stdio.h>
int BinarySearch(int arr[],int length,int target) {
    int left=0;
    int right=length-1;
    while (left<=right) {
        int mid=(left+right)/2;
        if (arr[mid]==target) {
            return mid;
        }
        if (arr[mid]>target) {
            right=mid-1;
        }else {
            left=mid+1;
        }
    }
    return -1;
}
int main() {
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    printf("%d",BinarySearch(arr,10,2));
    return 0;
}