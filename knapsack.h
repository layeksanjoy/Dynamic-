#include <stdlib.h>
#include<stdio.h>
#include<vector>
#include<algorithm> 

using namespace std;

vector<vector<int>> t;

int knapsack_TopDown(vector<int> weight, vector<int> values, int W, int n) {
    for (int i = 0; i <= weight.size(); i++) {
        t.push_back({});
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0)
                t[i].push_back(0);
            else
                t[i].push_back(-1);
        }
    }

    for (int i = 0; i <= weight.size(); i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0)
                t[i][j] = 0;
            else if (weight[i - 1] <= j) {
                int t1 = values[i - 1] + t[i - 1][j - weight[i - 1]];
                int t2 = t[i - 1][j];
                t[i][j] = max(t1, t2);
            }
            else {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n+1][W];
}

int knapsack_Recursion_Memo_Helper(vector<int> weight, vector<int> values, int W, int n) {
  if (t[n][W] != -1)
      return t[n][W];
  if (weight[n] <= W)
      return t[n][W] = max((values[n] + knapsack_Recursion_Memo_Helper(weight, values, W - weight[n], n - 1)), knapsack_Recursion_Memo_Helper(weight, values, W, n - 1));
  else
      return t[n][W] = knapsack_Recursion_Memo_Helper(weight, values,W, n - 1);
}

int knapsack_Recursion_Memo_Init(vector<int> weight, vector<int> values, int W,int n) {

  for (int i = 0; i <= weight.size(); i++) {
      t.push_back({});
      for (int j = 0; j <= W; j++) {
          if (i == 0 || j == 0)
              t[i].push_back(0);
          else
              t[i].push_back(-1);
      }
  }

  return knapsack_Recursion_Memo_Helper(vector<int> weight, vector<int> values, int W,int n);
}

int knapsackRecusion(vector<int> weight, vector<int> values, int W,int n) {
    if (W == 0 || n == 0)
        return 0;
    if (weight[n] <= W) {
        return max( (values[n] + knapsack(weight, values, W - weight[n], n - 1)), knapsack(weight, values, W, n - 1));
    }
    else
        return knapsack(weight, values, W, n - 1);
    
}