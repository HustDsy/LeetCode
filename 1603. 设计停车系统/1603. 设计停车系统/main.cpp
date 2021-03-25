//
//  main.cpp
//  1603. 设计停车系统
//
//  Created by dsy on 2021/3/19.
//

#include <iostream>
using namespace std;

class ParkingSystem {
public:
    int big;
    int medium;
    int small;
    ParkingSystem(int big, int medium, int small) {
        this->big=big;
        this->medium=medium;
        this->small=small;
    }
    
    bool addCar(int carType) {
        if(carType==1){
            if(big==0) return false;
            big--;
        }else if(carType==2){
            if(medium==0) return false;
            medium--;
        }else if(carType==3){
            if(small==0) return false;
            small--;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
