
/*
// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>  // for reverse
// using namespace std;

// int bintodecimal(const string& bin) {
//     int dec = 0;
//     for (char bit : bin) {
//         dec = (dec << 1) | (bit - '0');  // Shift left and add current bit
//     }
//     return dec;
// }

// string decitobin(int decimal) {
//     if (decimal == 0) return "0";
    
//     bool isNegative = decimal < 0;
//     if (isNegative) {
//         decimal = ~decimal + 1;  // Get two's complement of negative number
//     }
    
//     string binary;
//     while (decimal > 0) {
//         binary += (decimal & 1) ? '1' : '0';  // Append the least significant bit
//         decimal >>= 1;  // Shift the decimal number to the right
//     }
    
//     reverse(binary.begin(), binary.end());  // Reverse the string for the correct order

//     if (isNegative) {
//         binary = "Two's complement: -" + binary;  // Indicate two's complement form
//     }

//     return binary;
// }


// bool ithbitissetornot(int num1, int num2) {
//     return (num1 & (1 << num2)) != 0;
// }

// int settheIthbit(int num1, int num2){
//     num2=(1<<num2);
//     return num1|num2;
// }

// int cleartheithbit(int num1, int num2){
//     return num1^(1<<num2);
// }

// int clearfirstset(int num){
//     int num2=num-1;
//     return num & num2;
// }

// bool checkpowerof2(int num){
//     if(num==0) return false;
//     return (num & (num-1))==0;  
// }


// vector<vector<int>> generateSubset(vector<int>nums){
//     int n=nums.size();
//     vector<vector<int>> subsets;
//     for(int i=0;i<(1<<n);i++){
//         vector<int> subset;
//         for(int j=0;j<n;j++){
//             if(i&(1<<j)){
//                 subset.push_back(nums[j]);
//             }
//         }
//         subsets.push_back(subset);
//     }
//     return subsets;
// }


// int main() {
//     /*
//     int a = 5;
//     int b = 3;
//     cout << "And: " << (a & b) << endl;
//     cout << "Or: " << (a | b) << endl;
//     cout << "Xor: " << (6^ 5) << endl;
//     cout << "Left shift: << " << (a << 1) << endl;   // x << k = x * 2^k
//     cout << "a: " << a << endl;
//     cout << "Right shift: >> " << (a >> 1) << endl;  // x >> k = x / 2^k
//     cout << "NOT: " << (~(-5)) << endl;
//     //for not of a positive number=> Step: 1 first flip if you get -ve sign get 2's complement and it return that number with that negative sign mean's the number what we get afer 
//     // 2's complement is the answer of not of that number with negative sign.
//     // for not of a negative number=> Step 1: get 1's of it's positive number then 2's
//     //Step: 2 now flip if you get -ve sign get 2's complement and it return that number with that positive sign mean's the number what we get afer
//     cout << "Binary to Decimal of \"110\": " << bintodecimal("110") << endl;
//     cout << "Decimal to Binary of 6: " << decitobin(6) << endl;

//     cout<<"a before swap: "<<a<<endl;
//     cout<<"b before swap: "<<b<<endl;
//     cout<<"a after swap: "<<((a^b)^a)<<endl;   
//     cout<<"b after swap: "<<((a^b)^b)<<endl;

//     if(ithbitissetornot(5,1)){
//         cout<<"set"<<endl;
//     }else{
//         cout<<"Not a set"<<endl;
//     }

    
// //    int a=7;
// //    cout<<(a>>3);


//     //cout<<settheIthbit(9,2);
//    // cout<<cleartheithbit(7,1);
//    if(checkpowerof2(16)){
//     cout<<"Truee: "<<endl;
//    }
//    else{
//     cout<<"False: "<<endl;
//    }
//     */
//    vector<int> v={1,2,3};
//    vector<vector<int>> ans;
//    ans=generateSubset(v);
//    for(auto i:ans){
//     for(auto j:i){
//         cout<<j<<" ";
//     }
//     cout<<endl;
//    }
//  }

/*

#include <iostream>
using namespace std;

void printBinary(int n){
    for(int i=10;i>=0;i--){
        cout<<((n>>i)&1);
    }
    cout<<endl;
}

int main(){
    int n=7;
    // printBinary(n);
    // int cnt=0;
    // for(int i=31;i>=0;i--){
    //     if(((1<<i)&n)!=0){
    //         cnt++;
    //     }
    // }
    // cout<<"Set bits are: "<<cnt<<endl;

    // unset all bits before ith bit
    // int a=57;
    // int b=5;
    // int j=(1 << b);
    // printBinary(j);
    // printBinary(~j);
    // j=(j-1);
    // printBinary(a);
    // printBinary((a&(~j)));

    //convert uppercase to lowercase and vice versa

    // char ch1='G';
    // char ch2='m';

    // ch ^= (1 << 5); // XOR with 1 at 5th position


    // cout<<(char)(ch1 |' ')<<endl;//Uppercase to lowercase
    // cout<<(char)(ch2 & '_')<<endl;//Lowercase to uppercase


    //division using bit
    n=10;
    cout<<(1<<n);  //power of two
    cout<<()

    return 0;
}

*/



#include <iostream>
#include <vector>

using namespace std;

void printBinary(int num){
    for(int i=10; i>=0; i--) {
        cout << ((num >> i) & 1);
    }
    cout << endl;
}

int main(){
    // vector<int> arr={1,2,7,6,7,6,2};
    // int ans=0;
    // for(int i:arr){
    //     cout<<"Before: ";printBinary(i);
    //     ans^=i;
    //     cout<<"After: ";printBinary(ans);
    // }
    // cout << "The unique element is: " << ans << endl;
    printBinary(10);
    printBinary(~10);

}


