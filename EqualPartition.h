#include <stdlib.h>
#include<stdio.h>
#include<vector>
#include<algorithm> 

#include"Subset.h"

using namespace std;

bool EqualSumPartition(vector<int> arr){
  int sum = 0;
  for(auto i:arr)sum += i;
  if(sum % 2!=0)
    return false;
  return SubsetSumRecursion(arr,sum/2,arr.size()-1);
}