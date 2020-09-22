//
//  main.cpp
//  6. Z 字形变换
//
//  Created by 董深育 on 2020/9/21.
//

#include <iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        string::size_type len=s.length();
        string ret="";
        int cnt=2*numRows-2;
        for(int i=0;i<numRows;i++){
            int begin=i;
            int odd=0;
            int next=0;
            while(begin<len){
                ret+=s[begin];
                //第一个和最后一个按照cnt就行
                if(i==0||i==(numRows-1)){
                    next=cnt;
                }else{
                    if(odd%2==0){
                        next=2*numRows-2*(i+1);
                    }else{
                        next=2*i;
                    }
                    odd+=1;
                }
                begin+=next;
            }
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.convert("PAYPALISHIRING", 3);
    return 0;
}
