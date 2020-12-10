//
//  main.cpp
//  860. 柠檬水找零
//
//  Created by dsy on 2020/12/10.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        //dp[0] 5块多少张
        //dp[1] 10块多少张
        //dp[2] 20多少张
        int dp[3]={0};
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                dp[0]+=1;
            }else if(bills[i]==10){
                dp[1]+=1;
                if(dp[0]==0) return false;
                dp[0]--;
            }else{
                dp[2]++;
                if(dp[0]==0) return false;
                if(dp[1]!=0){
                    dp[1]--;
                    dp[0]--;
                    continue;
                }
                if(dp[1]==0){
                    if(dp[0]<3) return false;
                    dp[0]-=3;
                }
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
