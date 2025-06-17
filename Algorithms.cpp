/*
#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<char>> mat;
typedef vector<char> vec;

void generateNoAdjacentDupes(vector<char>& colors, int rows, string current, vector<string>& result) {
    if (current.size() == rows) {
        result.push_back(current);
        return;
    }
    for (char c : colors) {
        if (!current.empty() && current.back() == c) continue;
        current.push_back(c);
        generateNoAdjacentDupes(colors, rows, current, result);
        current.pop_back();
    }
}

int solve(int prevIndex, int columnLeft, vector<string>& columnState) {
    if (columnLeft == 0) {
        return 1;
    }
    int ans = 0;
    string prevState = (prevIndex == -1) ? string(columnState[0].size(), ' ') : columnState[prevIndex];
    for (int i = 0; i < columnState.size(); i++) {
        bool isValid = true;
        for (int j = 0; j < prevState.size(); j++) {
            if (prevState[j] == columnState[i][j]) {
                isValid = false;
                break;
            }
        }
        if (isValid) {
            ans += solve(i, columnLeft - 1, columnState);
        }
    }
    return ans;
}

int paintGrid(mat &grid, vec &colors) {
    int row = grid.size();
    int col = grid[0].size();
    if (row == 0 || col == 0) {
        return 0;
    }
    vector<string> result;
    generateNoAdjacentDupes(colors, row, "", result);
    int ans = 0;
    for (int i = 0; i < result.size(); i++) {
        ans += solve(i, col - 1, result);
    }
    return ans;
}

int main() {
    int row, col;
    cin >> row >> col;
    mat grid(row, vec(col, ' '));
    vec colors = {'R', 'G', 'B'};
    cout << paintGrid(grid, colors) << endl;
    return 0;
}

*/


/* Longest Prefix-Suffix 

#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPSArray(string pat){
    int n=pat.size();
    vector<int> lps(pat.size(), 0);
    int i = 1;
    int j = 0;
    while(i<n){
        if(pat[i]==pat[j]){
            lps[i]=j+1;
            i++;
            j++;
        }else{
            if(j!=0){
                j=lps[j-1];
            }else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}

int searchPattern(string pat, string txt) {
    vector<int> lps = computeLPSArray(pat);
    int i = 0, j = 0;

    while (i < txt.size()) {
        if (pat[j] == txt[i]) {
            i++;
            j++;

            if (j == pat.size()) {
                return i - j;
            }
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return -1;
}



int main(){
    string str1="ABCDABKDABCD";
    string str2="BKD";
    int idx=searchPattern(str2, str1);
    cout<<str1.substr(idx, str2.size());
    return 0;
}






#include <bits/stdc++.h>
using namespace std;

void print(vector<int>&num){
    for(int &v:num){
        cout<<v<<" ";
    }
    cout<<endl;
}
//mid-point



int main(){
    // int a=0;
    // int b=6;
    // cout<<midpoint(a,b);
    vector<int>a={0,4,3,1,0};
    vector<int>b={1,4,3,1,5};
    int val=inner_product(a.begin(),a.end(),b.begin(),0);
    int val2=inner_product(a.begin(),a.end(),b.begin(),0,plus<>(),equal_to<>());
    cout<<val<<endl;
    cout<<val2<<endl;
    vector<int>ans(5);//first create an empty vector of same size
    partial_sum(b.begin(),b.end(),ans.begin());  // used to get prefix sum
    for(int &i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    vector<int>num1={5,2,3,78,9,6};
    sort(num1.begin(),num1.end(),greater<int>());
    
    cout<<"Sorted in decending order"<<endl;
    print(num1);
    // squaree(num1);
    string str1="ABCDABKDABCD";
    string str2="A.*";
    regex_match(str1,regex(str2));
    return 0;
}

*/

#include <bits/stdc++.h>
using namespace std;
