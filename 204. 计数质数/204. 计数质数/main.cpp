//
//  main.cpp
//  204. 计数质数
//
//  Created by dsy on 2020/12/4.
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPrime(int num){
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
        
    }
    int countPrimes(int n) {
            int ans = 0;
            for (int i = 2; i < n; ++i) {
                ans += isPrime(i);
            }
            return ans;
        }
   
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
