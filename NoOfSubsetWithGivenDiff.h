#include <stdlib.h>
#include<stdio.h>
#include<vector>
#include<algorithm> 

#include"NoofSubsetWithSum.h"

using namespace std;

int noOfSubWithGivenDiff(vector<int> arr,int diff){
  int range = 0;
  for(int i:arr)range += i;
  int s1 = (range+diff)/2;
  return noOfSub_Memo_Helper(arr,s1,arr.size()-1);
}