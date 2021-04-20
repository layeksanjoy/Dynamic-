#include <stdlib.h>
#include<stdio.h>
#include<vector>
#include<algorithm> 

using namespace std;

vector<vector<int>> t;

int noOfSub(vector<int> &arr,int sum,int n){
  if(sum == 0)
    return 1;
  if(n < 0)
    return 0;
  if(arr[n] <= sum){
    return noOfSub(arr, sum-arr[n], n-1) + noOfSub(arr, sum, n-1);
  }else{
    return noOfSub(arr, sum, n-1);
  }
}

int noOfSub_Memo(vector<int> &arr, int sum, int n) {
    if (sum == 0)
        return 1;
    if (n < 0)
        return 0;
    if (t[n][sum] != 0)
        return t[n][sum];
    if (arr[n] <= sum) {
        return t[n][sum] += (noOfSub_Memo(arr, sum - arr[n], n - 1) + noOfSub_Memo(arr, sum, n - 1));
    }
    else {
        return t[n][sum] += noOfSub_Memo(arr, sum, n - 1);
    }
}

int noOfSub_Memo_Helper(vector<int> &arr,int sum){
      for (int i = 0; i <= arr.size(); i++) {
        t.push_back({});
        for (int j = 0; j <= sum; j++) {
            
            t[i].push_back(0);
        }
    }  
    return noOfSub_Memo(arr, sum, arr.size()-1);
}