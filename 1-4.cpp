#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
  void replace(string &str){
    int sz = str.size();
    int c = 0;
    if (sz == 0 ) {return;}
    for (int i = sz-1;i>=0;i--){
        if (str[i]==' ') {c++;}
    }
    int j = sz + c*2;
    str = str+string(c*2,' ') ;
    for (int i = sz-1;i>=0;i--){
        if (str[i]!=' ') {
           str[--j]=str[i];
        }else{
           str[--j] ='%';
           str[--j]='0';
           str[--j]='2';     
        }
    }
  }
};

int main(){

  Solution sol;
  string str = "I am programming c++ language.    That's good!" ;
  cout << str << endl;
  sol.replace(str);
  cout << str << endl;
  return 0;
}
