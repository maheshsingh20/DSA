#include <iostream>
#include <vector>
using namespace std;

bool bSearch(vector<int> arr, int target){
    int start=0;
    int end=arr.size()-1;
    int mid=start+(end-start)/2;
    while(start<=end){
        if(arr[mid]==target){
            return true;
        }
        else if(arr[mid]<target){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return false;
}


/*Using recursion*/

bool bSearchh(vector<int> arr, int start, int end, int target){
    if(start>end){
        return false;
    }
    int mid=start+(end-start)/2;
    if(arr[mid]==target){
        return true;
    }
    else if(arr[mid]<target){
        return bSearchh(arr,mid+1,end,target);
    }
    else{
        return bSearchh(arr,start,mid-1,target);
    }
}


int main(){
    vector<int> arr={10,34,45,67,78,97,112,334,556,678};
    int n=45;
    if(bSearch(arr,n)){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;

    }
}