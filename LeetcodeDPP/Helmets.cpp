#include <bits/stdc++.h>
using namespace std;
typedef vector<long> vi;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long size; long long key;
        cin >> size >> key;
        vi a(size,0);
        for (size_t i = 0; i < size; i++) {
            cin>>a[i];
        }
        vi b(size,0);
        for (size_t i = 0; i < size; i++) {
            cin>>b[i];
        }
        vector<pair<long long, long long>> vc;
        for (int i = 0; i < a.size(); i++) {
            vc.push_back({a[i], b[i]});
        }
        sort(vc.begin(), vc.end(), [](pair<long long, long long> &a, pair<long long, long long> &b) {
            return a.second < b.second;
        });

        long long ans=0;
        long long i=0;
        long long j=size;
        ans+=key;
        j--;
        while(i<vc.size()&& j>0){
            long long currRate=vc[i].second;
            long long nextRange=vc[i].first;
            if(currRate<=key){
                if(j>=nextRange){
                    j-=nextRange;
                    ans+=(nextRange*currRate);
                    i++;
                }else{
                    ans+=(j*currRate);
                    j=0;
                }
            }else{
                i++;
                ans+=(j*key);
                j=0;
            }
        }
        cout <<ans<<endl;
    }
    return 0;
}