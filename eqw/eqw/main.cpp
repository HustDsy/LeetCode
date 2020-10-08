//
//  main.cpp
//  eqw
//
//  Created by 董深育 on 2020/10/8.
//

#include <iostream>
#include<vector>
#include<memory>
using namespace std;

//vector<int>*get(){
//    return new vector<int>();
//}
//
//vector<int>*getNum(){
//    int num;
//    vector<int>*temp=get();
//    while(cin>>num){
//        temp->push_back(num);
//    }
//    return temp;
//}
//
//void print(){
//    vector<int>*temp=getNum();
//    for(int i:*temp){
//        cout<<i<<endl;
//    }
//    delete temp;
//    temp=nullptr;
//}
shared_ptr<vector<int>>get(){
    return make_shared<vector<int>>();
}

shared_ptr<vector<int>>getNum(){
    int num;
    shared_ptr<vector<int>>temp=get();
    while(cin>>num){
        temp->push_back(num);
    }
    return temp;
}

void print(){
    shared_ptr<vector<int>>temp=getNum();
    for(int i:*temp){
        cout<<i<<endl;
    }
    
}


shared_ptr<int>get_(){
    return make_shared<int>(1);
}

int main(int argc, const char * argv[]) {
    int*i=new int(5);
    int*j=i;
    *i=2;
    delete i;
    *i=3;
    int b=*i;
    cout<<*i;
    return 0;
}
