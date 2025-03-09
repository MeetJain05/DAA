#include <bits/stdc++.h>
using namespace std;
void printarr(int arr[],int n){
    for(int i =0;i<n;i++){
        cout << arr[i] <<" ";
    }
    cout << endl;
}
int selection_sort(int arr[],int n){
    for(int i = 0;i<n;i++){
        int min = arr[i];
        //finding the minimum in further part of the array and swapping it
        for(int j = i+1;j < n;j++){
            if(arr[j] < min){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
                min = arr[i];
            }
        }
    }
    printarr(arr,n);
}
int insertion_sort(int arr[], int n){
    for(int i = 1;i<n;i++){
        int j = i;
        //swap until the element reaches its correct index in sorted part of 
        while(j>0){
            if(arr[j-1] > arr[j]){
                int temp = arr[j];
                arr[j] = arr [j-1];
                arr[j-1] = temp;
            }
            j--;
        }
    }
    printarr(arr,n);
}
int main(){
    int arr1[5] = {5,42,200,29,1};
    int arr2[5] = {51,42,20,29,1};
    int n=5;
    insertion_sort(arr1,n); 
    selection_sort(arr2,n);
}