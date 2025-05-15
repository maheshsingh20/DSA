// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     string_view sv = "Hello, world!";
//     string_view sv2(sv.data(),5);
//     size_t len= sv2.length();
//     cout<<"Sv: "<<sv<<endl;
//     cout<<"Sv2 "<<sv2<<endl;
//     cout<<"Length of Sv2: " <<len<<endl;
//     cout<<"Front of sv: "<<sv.front()<<endl;
//     cout<<"Back of sv: "<<sv.back()<<endl;
//     cout<<"Check if sv is empty: "<<sv.empty()<<endl;
//     cout<<"Check if sv2 is empty: "<<sv2.empty()<<endl;
//     cout<<"Check if sv2 is equal to sv: "<<(sv2==sv)<<endl;
//     sv.remove_prefix(3);
//     cout<<"Sv after removing prefix: "<<sv<<endl;
//     sv.remove_suffix(3);
//     cout<<"Sv after removing suffix: "<<sv<<endl;

//     return 0;
// }




#include <iostream>
#include <span>
using namespace std;

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    std::span<int> sp(arr);
    cout<<sp[0]<<endl;
    cout<<sp[1]<<endl;
    cout<<sp[2]<<endl;
    cout<<sp[3]<<endl;
}