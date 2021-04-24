#include <stdlib.h>
#include<stdio.h>
#include<vector>
#include<algorithm> 
#include<string>

using namespace std;
 
vector<vector<int>> t;

string reverse_s(string s){
  string new_s ="";
  for(int i =s.size()-1;i>=0;i-=1)new_s+=s[i];
  return new_s;
}

string print_LCS(string s1, string s2) {
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
  int i = n;
  int j = m;
  string s = "";
  while(i > 0&& j >0){
    if(s1[i-1] == s2[j-1]){
      s += s1[i-1];
      i-= 1;
      j -= 1;
    }else{
      if(t[i-1][j] > t[i][j-1])
        i -= 1;
      else 
        j -= 1;
    }
  }
  
  return reverse_s(s);
}
