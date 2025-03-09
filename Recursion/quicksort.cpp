#include <bits/stdc++.h>
using namespace std;

int partition(int arr[],int low,int high){
    int pivot = low;
    int i = low;
    int j = high;
    
    while(i<j){
        while(i < high && arr[i] <= arr[pivot]) i++;
        while(j>low && arr[j] > arr[pivot]) j--;
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[pivot],arr[j]);
    return j;
}
void quicksort(int a[],int low, int high){
    if(low<high){
        int p = partition(a,low,high);
        quicksort(a,low,p-1);
        quicksort(a,p+1,high);
    }

}


int main(){
    int array[] = {15,15,41,13,12,1};
    int n = sizeof(array)/sizeof(array[0]);
    quicksort(array,0,n-1);
    for(int i=0;i<n;i++){
        cout << array[i] << " ";
    }
    return 0;
}