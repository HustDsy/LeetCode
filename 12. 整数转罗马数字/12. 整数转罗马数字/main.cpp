//
//  main.cpp
//  12. 整数转罗马数字
//
//  Created by dsy on 2021/5/14.
//

#include <iostream>]
#include<vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<int>n={1,4,5,9,10,40,50,90,100,400,500,900,1000};
        vector<string>s={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        int cur;
        string ans;
        for(int i=12;i>=0&&num;i--){
            cur=num/n[i];
            for(int j=0;j<cur;j++){
                ans+=s[i];
            }
            num%=n[i];
            
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
