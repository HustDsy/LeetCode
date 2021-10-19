//
//  main.cpp
//  354. 俄罗斯套娃信封问题
//
//  Created by dsy on 2021/3/16.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[](auto&a,auto&b)->bool{
            if(a[0]==b[0]){
                return a[1]<=b[1];
            }
            return a[0]<b[0];
        });
        //dp[i]表示以这个为结尾会有多少个数据
        int n=envelopes.size();
        int max=0;
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(envelopes[i][0]>envelopes[j][0]&&envelopes[i][1]>envelopes[j][1]){
                    dp[i]=std::max(dp[i],dp[j]+1);
                }
            }
            max=max>dp[i]?max:dp[i];
        }
        return max;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
