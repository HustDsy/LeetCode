//
//  main.cpp
//  925. 长按键入
//
//  Created by 董深育 on 2020/10/21.
//

#include <iostream>
#include<string>
using namespace std;


class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0;
        int j=0;
        int len_name=(int)name.length();
        int len_typed=(int)typed.length();
        char pre=' ';
        while(i<len_name||j<len_typed){
            if(name[i]==typed[j]){
                pre=typed[j];
                i++;
                j++;
            }else{
                if(pre==typed[j]){
                    j++;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.isLongPressedName("alex", "alexxr");
    return 0;
}
