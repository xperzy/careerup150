#include <iostream>
#include <string>
#include <vector>
using namespace std;



bool myfunc(string a, string b){
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  return (a<b);
}

void sortArr(vector<string> &str_arr){
  sort(str_arr.begin(),str_arr.end(),myfunc);
}




int main(){
  vector<string> str_arr;
  str_arr.push_back("bcdde");
  str_arr.push_back("abcde");
  str_arr.push_back("aaaaa");
  str_arr.push_back("bcdec");
  str_arr.push_back("adbce");
  str_arr.push_back("bdcce");
  str_arr.push_back("ccccc");
  str_arr.push_back("aaacc");
  str_arr.push_back("ddecb");
  str_arr.push_back("ccaaa");
  
    
  sortArr(str_arr);
  
  for (int i=0;i<str_arr.size();i++){
    cout << str_arr[i] <<" ";
  }
  cout <<endl;
  
  
  return 0;
}
