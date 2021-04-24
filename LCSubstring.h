#include <stdlib.h>
#include<stdio.h>
#include<vector>
#include<algorithm> 
#include<string>
#include <bits/stdc++.h>

using namespace std;

int LCSubstring_Bottom_UP(string s1,string s2){
  int n = s1.size();
  int m = s2.size();

  int mx = INT_MIN;
  int t[n+1][m+1];

  for(int i = 0;i<=n;i++){
    for(int j = 0;j< m;j++){
      if(i == 0||j == 0){
        t[i][j] = 0;
      }else{
        if(s1[i-1]  == s2[j-1]){
          t[i][j] = t[i-1][j-1] + 1;
          mx = max(mx,t[i][j]);

        }else{
          t[i][j] = 0;
        }
      }
    }
  }
  return mx;
}

int LCSubstring_recurr_Memo(string s1,string s2,int n,int m,vector<vector<int>> &t){
  if(t[n][m] != -1){
    return t[n][m];
  }
  if(s1[n-1] == s2[m-1]){
    return t[n][m] = 1+LCSubstring_recurr_Memo(s1,s2,n-1,m-1,t);
  }else{
    t[n][m] = 0;
    return LCSubstring_recurr_Memo(s1,s2,n-1,m-1,t);
  }
}

int LCSubstring_recurr_Memo_Helper(string s1,string s2){
  int n = s1.size();
  int m = s2.size();
  vector<vector<int>> t;

  for(int i = 0;i<=n;i++){
    t.push_back({});
    for(int j = 0;j<=m;j++){
      if(i == 0|| j == 0)
        t[i].push_back(0);
      else
        t[i].push_back(-1);        
    }
  }

  int x = LCSubstring_recurr_Memo(s1,s2,n-1,m-1,t);

  int mx =INT_MIN;
  for(int i = 0;i<=n;i++){
    for(int j = 0;j<=m;j++){
      mx = max(mx,t[i][j]);
    }
  }
  return mx;
}