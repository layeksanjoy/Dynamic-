#include <stdlib.h>
#include<stdio.h>
#include<vector>
#include<algorithm> 

using namespace std;

int rodCutting(vector<int> length,vector<int> values,int l,int n){
  if(l == 0 || n < 0)
    return 0;
  
  if(length[n] <= l){
    return max(values[n] + rodCutting(length, values, l-length[n],n),rodCutting(length, values, l,n-1));
  }else
    return rodCutting(length, values, l ,n-1);
}