//
//  main.cpp
//  383. 赎金信
//
//  Created by 董深育 on 2020/9/29.
//

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int arry[26]={0};
        for(int i=0;i<magazine.length();i++){
            arry[magazine[i]-'a']+=1;
        }
        for(int i=0;i<ransomNote.length();i++){
            arry[ransomNote[i]-'a']--;
            if(arry[ransomNote[i]-'a']<0) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
