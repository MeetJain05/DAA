#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high){
    int pivot = low;
    int left = low + 1;
    int right = high;
    
    while(left < right){
        while(left < high && arr[left] <= arr[pivot]) left++;
        while(right > low && arr[right] > arr[pivot]) right--;
        if(left < right) swap(arr[left],arr[right]);
    }
    swap(arr[pivot],arr[right]);
    return right;
}

void quicksort(int arr[], int low, int high){
    if(low < high){
        int pivot = partition(arr,low,high);
        quicksort(arr,low,pivot-1);
        quicksort(arr,pivot+1,high);
    }
}

int main(){
    int arr[] = {15,15,41,13,12,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}