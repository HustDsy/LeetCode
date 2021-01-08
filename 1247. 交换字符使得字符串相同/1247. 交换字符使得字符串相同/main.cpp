//
//  main.cpp
//  1247. 交换字符使得字符串相同
//
//  Created by dsy on 2021/1/7.
//

#include <iostream>
#include<string>
using namespace std;

class Solution {
public:
    int minimumSwap(string s1, string s2) {
          int x_num=0;
          int y_num=0;
          for(int i=0;i<s1.length();i++){
              if(s1[i]!=s2[i]){
                  if(s1[i]=='x'){
                      x_num++;
                  }else{
                      y_num++;
                  }
              }
          }
          int ans=(x_num+y_num)%2==0?(x_num+1)/2+(y_num+1)/2:-1;
          return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
