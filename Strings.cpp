#include <iostream>
#include <string>
using namespace std;





int main(){
    /*
    string str1;
    getline(cin,str1);//getting the first string from the user
    cout<<str1<<endl;


    double num=stod(str1);// converting string to double
    cout<<num<<endl;


    int num2=stoi(str1);// converting string to integer
    cout<<num2<<endl;
    
    const double pi=3.14;
    string str2="Value of pi is "+ to_string(pi);// converting double to string
    cout<<str2<<endl;


    


    //APPEND 

    string str1="Hello ";
    string str2="World";
    string str3="This is a string";
    cout<<str1.append(str2)<<endl;  //append second word after first word
    cout<<str1.append(5u,'.')<<endl;    // add 5 dots to the end of the string
    cout<<str1.append(str3.begin()+6,str3.end())<<endl; //add the last 5 characters of str3 to str1


    

   //OPERATOR +=

    string str1="Hello ";
    string str2="World";
    str1+=str2;
    cout<<str1<<endl;  //add str2 to 

    */ 

    //SUBSTRING

    // string str1="My name is Mahesh Singh ";
    // string str2=str1.substr(8,7); //get the substring from index 7
    // size_t pos=str1.find("Singh"); //find the position of Singh
    // cout<<str2<<endl;  //get the substring from index 7
    // cout<<pos<<endl;
    // cout<<str1.substr(pos)<<endl;  //get the substring from index 7

    string str="daabcbaabcbc";
    while (str.find("abc") != string::npos){
        str.erase(str.find("abc"),3);
    }
    cout<<str<<endl;
    return 0;
}