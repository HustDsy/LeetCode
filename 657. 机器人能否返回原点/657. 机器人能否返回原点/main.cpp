//
//  main.cpp
//  657. 机器人能否返回原点
//
//  Created by 董深育 on 2020/8/28.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int x=0;
        int y=0;
        for(int i=0;i<moves.length();i++){
            char num=moves[i];
            switch (num) {
                case 'L':
                    y=y-1;
                    break;
                case 'R':
                    y=y+1;
                    break;
                case 'U':
                    x=x-1;
                    break;
                case 'D':
                    x=x+1;
                    break;
                default:
                    break;
            }
                
        }
        return x==0&&y==0;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
