//
//  main.cpp
//  135. 分发糖果
//
//  Created by dsy on 2020/12/24.
//

#include <iostream>
#include<vector>
#include<numeric>
using namespace std;


class Solution {
public:
    int candy(vector<int>& ratings) {
      int len=(int)ratings.size();
      vector<int>dp(len,1);
      for(int i=1;i<len;i++){
          if(ratings[i]>ratings[i-1]){
              dp[i]=dp[i-1]+1;
          }
      }
      for(int i=len-1;i>=1;i--){
          if((ratings[i]<ratings[i-1])&&dp[i-1]<=dp[i]){
              dp[i-1]=dp[i]+1;
          }
      }
      return accumulate(dp.begin(), dp.end(), 0);
  }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
