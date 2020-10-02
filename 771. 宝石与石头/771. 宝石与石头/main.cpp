//
//  main.cpp
//  771. 宝石与石头
//
//  Created by 董深育 on 2020/10/2.
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        //ASCILL表中大写A开头为65-90
        //ASCILL表中小写a开头为97-122
        vector<int>dp(57,0);
        for(int i=0;i<J.length();i++){
            dp[J[i]-'A']++;
        }
        int num=0;
        for(int i=0;i<S.length();i++){
            if(dp[S[i]-'A']) num++;
        }
        return num;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
