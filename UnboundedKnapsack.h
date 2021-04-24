#include <stdlib.h>
#include<stdio.h>
#include<vector>
#include<algorithm> 

using namespace std;

int UnboundedKnapsack(vector<int> weight,vector<int> values,int w,int n){
  if(n<0 || w == 0)
    return 0;
  if(weight[n] <= w){
    return max(values[n] + UnboundedKnapsack(weight,values,w-weight[n],n),UnboundedKnapsack(weight,values,w,n-1));
  }else
    return UnboundedKnapsack(weight, values, w, n-1);
}