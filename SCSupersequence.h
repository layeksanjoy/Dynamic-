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

string shortestCommonSupersequence(string s1,string s2){
  string s = print_LCS(s1, s2);
  cout<<s<<endl;
  int i = 0;
  int j = 0;
  int c = 0;

  string re = "";
  while(i < s1.size() || j <s2.size()){
    if(s1[i] == s[0]){

        while(s2[j] != s1[i]){
          re += s2[j];
          j++;
        cout<<s1[i]<<" "<<i<<" "<<s2[j]<<" "<<j<<endl;

        }
        j++;
        re+= s1[i];
        i+= 1;
        for(int k = 0;k<s.size();k++){
          if(s[k] == s1[i-1]){
            s.erase(k,1);
            break;
          }
        }
        cout<<s1[i]<<" "<<i<<" "<<s2[j]<<" "<<j<<endl;
    }
        else if(s[0] != s1[i]){
        re+= s1[i];
        i+= 1;
        cout<<s1[i]<<" "<<i<<" "<<s2[j]<<" "<<j<<endl;

    }
    else if(s[0] == s2[j]){

        while(s1[i] != s2[j]){
          re += s1[i];
          i++;
        cout<<s1[i]<<" "<<i<<" "<<s2[j]<<" "<<j<<endl;

        }
        i++;
                re+= s2[j];
        j+= 1;
        for(int k = 0;k<s.size();k++){
          if(s[k] == s2[j-1]){
            s.erase(k,1);
            break;
          }
        }
        cout<<s1[i]<<" "<<i<<" "<<s2[j]<<" "<<j<<endl;

    }

    else if(s[0] != s2[j]){
      re+= s2[j];
      j+= 1;
        cout<<s1[i]<<" "<<i<<" "<<s2[j]<<" "<<j<<endl;

    }
    cout<<re<<" "<<i<<" "<<j<<endl;
  }
  return re;
}
