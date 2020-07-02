//
//  main.cpp
//  9-回文数
//
//  Created by 董深育 on 2020/7/2.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        bool flag=false;
        if(x<0){
           flag=false;
        }else if(x>=0&&x<10){
           flag=true;
        }else if(x>=10&&(x%10!=0)){//这里注意，这种翻转只适合于不能被10整除的数）
            int y=0;
            while(x>y)
            {
                int z=x%10;
                y=y*10+z;
                x=x/10;
            }
            if((x==y)||(x==(y/10))){
                flag=true;
            }
        }
        return flag;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
