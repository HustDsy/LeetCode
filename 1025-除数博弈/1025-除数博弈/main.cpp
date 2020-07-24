//
//  main.cpp
//  1025-除数博弈
//
//  Created by 董深育 on 2020/7/24.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
   bool divisorGame(int N) {
          if(N%2==0){
              return true;
          }
          return false;
      }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
