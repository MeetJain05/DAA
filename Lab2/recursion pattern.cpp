#include <bits/stdc++.h>
using namespace std;
int pr(int n){
    if(n==0) return 0;
    return n + pr(n-1);
}
void rev(int arr[],int i, int n){
    if(i>=n/2) return;
    swap(arr[i],arr[n-i-1]);
    rev(arr,i+1,n);
}
int palindrome(string s,int i,int n){
    if(i>=n/2) return true;
    if(s[i]!=s[n-i-1]){
        return false;
    }
    return palindrome(s,i+1,n);
}
int fibonacci(int n){
    if(n<=1) return n;
    return fibonacci(n-1)+fibonacci(n-2);
}

void powerset(int i,int n,int arr[],vector<int> ans,int sum,int k){
    if(i==n){
        if(sum == k){
            if(ans.size()==0) cout << "null";
        for(auto it: ans){
        cout << it << ",";
        }
        cout << endl;
        
        }
        return;
    }
    ans.push_back(arr[i]);
    sum+=arr[i];
    powerset(i+1,n,arr,ans,sum,k);
    ans.pop_back();
    sum -= arr[i];
    powerset(i+1,n,arr,ans,sum,k);
    
}
bool powerset2(int i,int n,int arr[],vector<int> ans,int sum,int k){
    if(i==n){
        if(sum == k){
            if(ans.size()==0) cout << "null";
            for(auto it: ans){
                cout << it << ",";
            }
            cout << endl;
            return true;
        }
        else return false;
    }
    ans.push_back(arr[i]);
    sum+=arr[i];
    if(powerset2(i+1,n,arr,ans,sum,k)==true) return true;
    ans.pop_back();
    sum -= arr[i];
    if(powerset2(i+1,n,arr,ans,sum,k)==true) return true;
    return false;
}
int powerset3(int i,int n,int arr[],int sum,int k){
    if(i==n){
        if(sum == k) return 1;
        else return 0;
    }
    int l,r;
    
    sum+=arr[i];
    l = powerset3(i+1,n,arr,sum,k);
    sum -= arr[i];
    r = powerset3(i+1,n,arr,sum,k);
    return l+r;
}
int main(){
    int arr[] = {3,3,3,2};
    vector<int> ans;
    cout << powerset3(0,4,arr,0,5);
    return 0;
}