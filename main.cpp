#include <iostream>
#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm> 
#include <bitset> 
#include<map>
#include<string>
#include<limits.h>
#include <chrono>

#include "minimumSubsetDiffrence.h"

using namespace std;

int main() {
  vector<int> arr = {1, 6, 11, 5};
  cout<<minSubsetDiff_nonDP(arr);
}