#include <stdlib.h>
#include<stdio.h>
#include<vector>
#include<algorithm> 
#include<string>

using namespace std;
 
vector<vector<int>> t;
int lcs_Recurr_Memo(string s1,string s2,int n,int m){
    if(t[n][m] != -1)
        return t[n][m];
    if(s1[n-1] == s2[m-1]){
        return t[n][m] = lcs_Recurr_Memo(s1,s2,n-1,m-1)+1;
    }else{
        return t[n][m] = max(lcs_Recurr_Memo(s1,s2,n-1,m),lcs_Recurr_Memo(s1,s2,n,m-1));
    }
}
  
int lcs_Recurr_Memo_Helper(string text1, string text2) {
    for(int i = 0;i <= text1.size();i++){
        t.push_back({});
        for(int j = 0;j <= text2.size();j++){
            if(i == 0|| j == 0){
                t[i].push_back(0);
            }else
                t[i].push_back(-1);
        }
    }
    return lcs_Recurr_Memo(text1,text2,text1.size(),text2.size());
}


int lcs_Bottom_up(string s1, string s2) {
  int n = s1.size();
  int m = s2.size();
  vector<vector<int>> t;

  for(int i = 0;i <= n;i++){
      t.push_back({});
      for(int j = 0;j <= m;j++){
          if(i == 0|| j == 0){
              t[i].push_back(0);
          }else{
              t[i].push_back(0);
          }
      }
  }
  
  for(int i = 1;i <= n;i++){
      for(int j = 1;j <= m;j++){
          if(s1[i-1] == s2[j-1]){
              t[i][j] = t[i-1][j-1]+1;
          }else{
                t[i][j] = max(t[i-1][j],t[i][j-1]);
          }
      }
  }

  return t[n][m];
}