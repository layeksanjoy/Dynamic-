#include <stdlib.h>
#include<stdio.h>
#include<vector>
#include<algorithm> 

using namespace std;

vector<vector<int>> t;

bool SubsetSumRecursion(vector<int> arr, int sum,int n) {
    if (sum == 0 )
        return true;
    if (n < 0)
        return false;
    if (arr[n] <= sum) {
        return SubsetSumRecursion(arr, sum - arr[n], n - 1) || SubsetSumRecursion(arr, sum, n - 1);
    }
    else
        return SubsetSumRecursion(arr, sum, n - 1);
}
 
bool SubsetSum_Recurr_Memo( vector<int> arr, int sum, int n) {
  if (sum == 0)
      return true;
  if (n < 0)
      return false;
  if (arr[n] <= sum) {
      return t[n][sum] = (SubsetSum_Recurr_Memo(arr, sum - arr[n], n - 1)|| SubsetSum_Recurr_Memo(arr, sum, n - 1));
  }
  else
      return t[n][sum] = SubsetSum_Recurr_Memo(arr, sum, n - 1);
   
}

bool SubsetSum_Recurr_Memo_helper( vector<int> arr, int sum, int n){
  for (int i = 0; i <= arr.size(); i++) {
      t.push_back({});
      for (int j = 0; j <= sum; j++) {
        if (j == 0)
            t[i].push_back(true);
        else if (i == 0 && j != 0)
            t[i].push_back(false);
        else
            t[i].push_back(false);
      }
  }  
  return SubsetSum_Recurr_Memo(arr,sum,n);
}

bool SubsetSum_Top_Bottom(vector<int> arr, int sum, int n) {
    for (int i = 0; i <= arr.size(); i++) {
        t.push_back({});
        for (int j = 0; j <= sum; j++) {
            if (j == 0)
                t[i].push_back(true);
            else if (i == 0 && j != 0)
                t[i].push_back(false);
            else
                t[i].push_back(false);
        }
    }

    for (int i = 1; i <= arr.size(); i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] <= j) {
                bool t1 = t[i - 1][j - arr[i - 1]];
                bool t2 = t[i - 1][j];
                t[i][j] = (t1 || t2);
            }
            else {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n + 1][sum];
}