#include <stdlib.h>
#include<stdio.h>
#include<vector>
#include<algorithm> 


using namespace std;


int INT_MAX = 2147483647;

vector<vector<int>> t;

int coinChange_Two(vector<int> coins,int sum,int n){
  for(int i = 0;i <= n+1;i++){
    t.push_back({});
    for(int j = 0;j <= sum;j++){
      if(i == 0)
        t[i].push_back(INT_MAX -1);
      else if(j == 0)
        t[i].push_back(0);
      else if(i == 1 && j > 0){
        if(j%coins[0] == 0)
          t[i].push_back(j/coins[0]);
        else
          t[i].push_back(INT_MAX - 1);
      }else
        t[i].push_back(0);
    }
  }

  for(int i = 2;i <= n+1;i++){
    for(int j = 1;j <= sum;j++){
      if(coins[i-1] <= sum){
        t[i][j] = min(1 + t[i][j-coins[i-1]], t[i-1][j] );
      }else 
        t[i][j] = t[i-1][j];
    }
  }

  return t[n+1][sum];
}