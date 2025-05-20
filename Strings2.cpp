/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//if array is sorted than only we can use this

int countGoodPairs(vector<int>& nums, int lower, int upper){
    sort(nums.begin(), nums.end());
    int count = 0;
    int start=0;
    int n=nums.size();
    int end=n-1;
    while(start<end){
        int sum=nums[start]+nums[end];
        if(sum>lower && sum<=upper){
            count+=(end-start);
            start++;
        }
        else if(sum>upper){
            end--;
        }
        else{
            start++;
        }
    }
    return count;
}


//      String match-->>
#define no_of_chars 256
int size;

void badCharHeuristic(string str, int sizeOfMainString, int badchar[no_of_chars]){
    for(int i=0;i<no_of_chars;i++){
        badchar[i]=-1;
    }
    for(int i=0;i<sizeOfMainString;i++){
        badchar[(int)str[i]];
    }
}

string searchIdThisFound(string s, string t){
    int n=s.size();
    int m=t.size();
    int arr[no_of_chars];
    
}




int main(){
    vector<int>ans={0,1,7,4,4,5};
    cout<<"Answer is: "<<countGoodPairs(ans, 3, 6)<<endl;
}

*/


/*

#include <bits/stdc++.h>
using namespace std;

//Longest Substring without repeating characters
string longestSubString(string s){
    string result="";
    int start=0;
    int Maxlen=0;
    string curr="";
    vector<int>fre(26,0);
    for(int i=0;i<s.size();i++){
        if(fre[s[i]-'A']==0){
            fre[s[i]-'A']++;
        }
        else{
            while(fre[s[i]-'A']>0){
                fre[s[start]-'A']--;
                start++;
            }
        }
        if(i-start+1>Maxlen){
            Maxlen=i-start+1;
            result=s.substr(start,Maxlen);
        }
    }
    return result;
}



int main(){
    string str1="MAABC";
    cout<<longestSubString(str1)<<endl;
}
*/

#include <bits/stdc++.h>
using namespace std;

vector<int>lps

int main(){
    string s="abc";
    string t="def";
    cout<<searchIdThisFound(s,t)<<endl;
}