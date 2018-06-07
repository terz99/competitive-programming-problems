#include <bits/stdc++.h>
using namespace std;

int peak(int arr[], const int& leftIdx, const int& rightIdx, const int& n){

    if(leftIdx == rightIdx){
        return leftIdx;
    }

    int midIdx = (leftIdx+rightIdx)/2;
    int leftElem = midIdx == 0 ? INT_MIN : arr[midIdx-1];
    int rightElem = midIdx == n-1 ? INT_MIN : arr[midIdx+1];
    if(arr[midIdx] > leftElem && arr[midIdx] > rightElem){
        return midIdx;
    } else if(arr[midIdx] < leftElem){
        return peak(arr, leftIdx, midIdx-1, n);
    } else {
        return peak(arr, midIdx+1, rightIdx, n);
    }
}

int peak(int arr[], int n){
    return peak(arr, 0, n-1, n);
}

int main(){

    return 0;
}