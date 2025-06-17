#include <bits/stdc++.h>
using namespace std;


//bool check prime

bool isPrime(int num){
    if(num<2) return false;
    for(int i=2;i*i<=num;i++){
        if(num%i==0) return false;
    }
    return true;
}

//sieve of erasthones

void sieve(int n){
    vector<bool> isPrime(n+1,true);
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i*i<=n;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=n;j+=i){
                isPrime[j]=false;
            }
        }
    }
    for(int i=0;i<=n;i++){
        cout<<i<<" "<<isPrime[i]<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    if(isPrime(n)) cout<<"Prime";
    else cout<<"Not Prime";
    sieve(n);
    return 0;
}