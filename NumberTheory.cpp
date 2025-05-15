/*

#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return a%b==0?b:gcd(b,a%b);
}

int lcm(int a, int b){
    if(a==0 || b==0) return 0;
    return abs(a*b)/gcd(a,b);
}


int main(){
    int a=10;
    int b=20;
    cout<<gcd(a,b)<<endl;
    cout<<lcm(a,b)<<endl;
    return 0;
}

*/


// #include <iostream>
// #include <vector>
// #include <cmath>
// using namespace std;


// //binary exponentiation



// //FEDYA AND MATHS --->>> (1^n + 2^n + 3^n + 4^n) mod 5


// int expoPower(int a, int b){
//     if(b==0) return 1;
//     a%=5;
//     for(int i=0;i<b;i++){
//         a=(a*b)%5;
//     }
//     return a;
// }


// //Sieve Of Erastosthenes

// vector <bool> SieveOfEratosthenes(int n){
//     vector<bool> primes(n+1,true);
//     primes[0]=primes[1]=false;
//     for(int i=2;i*i<=n;i++){
//         if(primes[i]){
//             for(int j=i*i;j<=n;j+=i){
//                 primes[j]=false;
//             }
//         }
//     }
//     return primes;
// }

// int main(){
//     // int a=100;
//     // vector<bool> primes=SieveOfEratosthenes(a);
//     // for(int i=0;i<=a;i++){
//     //     if(primes[i]) cout<<i<<" ";
//     // }cout << endl;


//     int a=4;
//     int result = expoPower(a, 2);
//     //cout << "Result of " << a << "^2 mod 5 is: " << result << endl;
//     int ans=(expoPower(1,4)%5+expoPower(2,4)%5 + expoPower(3,4)%5 +expoPower(4,4)%5 )%5;
//     cout<<ans<<endl;
//     return 0;
// }





#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return a%b==0?b:gcd(b-a,a);
}

int lcm(int a, int b){
    return abs(a*b)/gcd(a,b);
}

int main(){
    int n;
    cin>>n;
    int m=lcm(n,n-1);
    cout<<lcm(m,n-2);
    return 0;
}



