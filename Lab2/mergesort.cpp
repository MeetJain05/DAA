#include <bits/stdc++.h>
using namespace std;

void merge(int a[],int l,int mid,int h){
    int temp[h-l+1];
    int left = l;
    int right = mid+1;
    int i = 0;
    while(left<=mid && right <=h){
        if(a[left] < a[right]){
            temp[i] = a[left];
            i++;
            left++;
        }
        else {
            temp[i] = a[right];
            i++;
            right++;
        }
    }
    while(left <= mid){
        temp[i] = a[left];
        i++;
        left++;
    } 
    while(right<=h){
        temp[i] = a[right];
        i++;
        right++;
    }
    for(int j=l;j<=h;j++){
        a[j] = temp[j-l];
    }
}

void mergesort(int a[], int l,int h){
    if(l == h) return;
    int mid = (l+h)/2;
    mergesort(a,l,mid);
    mergesort(a,mid+1,h);
    merge(a,l,mid,h);
}

int main(){
    int array[] = {5,4,3,2,1};
    int n = sizeof(array)/sizeof(array[0]);
    mergesort(array,0,n-1);
    for(int i=0;i<n;i++){
        cout << array[i] << " ";
    }
    return 0;
}