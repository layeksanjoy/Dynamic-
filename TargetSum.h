#include <stdlib.h>
#include<stdio.h>
#include<vector>
#include<algorithm> 

#include"NoOfSubsetWithGivenDiff.h"

using namespace std;

int targetSum(vector<int> arr,int target){
  return noOfSubWithGivenDiff(arr, target);
}