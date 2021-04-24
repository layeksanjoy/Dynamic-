#include <stdlib.h>
#include<stdio.h>
#include<vector>
#include<algorithm> 

using namespace std;

int CoinChange(vector<int> coins,int sum,int n){
  if(sum == 0)
    return 1;
  if(n< 0)
    return 0;
  if(coins[n] <= sum){
    return (CoinChange(coins, sum - coins[n],n) + CoinChange(coins, sum ,n-1));
  }
  return CoinChange(coins, sum ,n-1);
}