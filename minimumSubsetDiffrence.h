#include <stdlib.h>
#include<stdio.h>
#include<vector>
#include<algorithm> 

#include "Subset.h"

using namespace std;

int minSubsetDiff_nonDP(vector<int> arr){
  int range = 0;
  for(int i:arr)range+=i;
  for(int i = int(range/2);i >= 0;i++){
    if(SubsetSumRecursion(arr,i,arr.size()-1)){
      return (range - 2*i);
    }
  }
  return range;
}


vector<int> SubsetSum_Top_Bottom_modified(vector<int> arr, int sum, int n) {
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
  vector<int> re;
  for(int i = 0;i <= sum ;i++){
    if(t[n][i])
      re.push_back(i);
  }
  return re;
}

int minSubsetDiff_DP(vector<int> arr){
  int range= 0;
  for(int i :arr) range+=i;
  vector<int> re = SubsetSum_Top_Bottom_modified(arr,range,arr.size()-1);
  int mi = range;
  for(int i:re){
    int temp = (range - 2*i);
    mi = min(mi,temp);
  }
  return mi;
}