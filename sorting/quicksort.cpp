#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>&nums, int start, int end){
    int pivot=nums[start];
    
}


void quickSort(vector<int>&nums,int start, int end){
    if(nums.size()<=1){
        return;
    }
    int pvt=partition(nums,start,end);
}


int main() {
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int *arr=new int[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}