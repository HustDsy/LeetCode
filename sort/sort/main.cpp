//
//  main.cpp
//  sort
//
//  Created by 董深育 on 2020/7/3.
//  Copyright © 2020 董深育. All rights reserved.
//

#include <iostream>
using namespace std;

template<typename T>
void merge_sort(T arr[], int len) {
    //用a记录原有的数组
    T *a = arr;
    //b用来存储归并后的数组
    T *b = new T[len];
    for (int seg = 1; seg < len; seg += seg) {
        for (int start = 0; start < len; start += seg + seg) {
            int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            //理解成b[k]=a[start],k++,start++,左闭右开
            while (start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        //将第一遍归并完的数组记录下来，之后就是对a进行处理了
        T *temp = a;
        a = b;
        b = temp;
    }
    //处理完的数据都在a里面，因为
    if (a != arr) {
        for (int i = 0; i < len; i++)
            b[i] = a[i];
        b = a;
    }
    delete[] b;
}

void merge(int arry[],int len){
    int*a=arry;
    int*b=new int[len];
    for(int seg=1;seg<len;seg+=seg){
        for(int start=0;start<len;start+=seg+seg){
            int low=start;
            int mid=min(len,start+seg);
            int high=min(start+seg+seg,len);
            int k=low;
            int start1=low,end1=mid;
            int start2=mid,end2=high;
            while(low<mid&&mid<high){
                b[k++]=a[start1]<a[start2]?a[start1++]:a[start2++];
            }
            while(low<mid){
                b[k++]=a[start1++];
            }
            while(low<mid&&mid<high){
                b[k++]=a[start2++];
            }
        }
        a=b;
    }
    for(int i=0;i<len;i++){
        arry[i]=a[i];
    }
}

void mergesort(int*arry,int*temp,int left,int right){
    if(left>=right){
        return;
    }
    int mid=(left+right)/2;
    int start1 = left, end1 = mid;
    int start2 = mid + 1, end2 = right;
    mergesort(arry, temp,start1, end1);
    mergesort(arry,temp, start2, end2);
    int k=left;
    while (start1 <= end1 && start2 <= end2)
        temp[k++] = arry[start1] < arry[start2] ? arry[start1++] : arry[start2++];
    while (start1 <= end1)
        temp[k++] = arry[start1++];
    while (start2 <= end2)
        temp[k++] = arry[start2++];
    for (k = left; k <= right; k++)
        arry[k] = temp[k];
        
}
template<typename T>
void quick_sort_recursive(T arr[], int start, int end) {
    if (start >= end) return;
    T mid = arr[end];
    int left = start, right = end - 1;
    while (left < right) {
        while (arr[left] < mid && left < right) left++;
        while (arr[right] >= mid && left < right) right--;
        std::swap(arr[left], arr[right]);
    }
    if (arr[left] >= arr[end])
        std::swap(arr[left], arr[end]);
    else
        left++;
    quick_sort_recursive(arr, start, left - 1);
    quick_sort_recursive(arr, left + 1, end);
}

template<typename T>
void quick_sort(T arr[], int len) {
    quick_sort_recursive(arr, 0, len - 1);
}


void quick_sort(int arry[],int start,int end){
    if(start>=end){
        return;
    }
    int pivot=arry[end];
    int left=start;
    int right=end-1;
    while(left<right){
        while(arry[left]<pivot&&left<right) left++;
        while(arry[right]<pivot&&left<right) right--;
        swap(arry[left],arry[right]);
    }
    if (arry[left] >= arry[end])
         swap(arry[left], arry[end]);
     else
         left++;
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
