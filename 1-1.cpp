#include <iostream>
#include <string>

using namespace std;

class Solution{
  public:
    bool isunique1(string str){
      for (int i=0;i<str.size();i++){
        for (int j=0;j<str.size();j++){
          if (i!=j && str[i]==str[j]){
            return false;
          }
        }
      }
      return true;
    }
    
    bool isunique2(string str){
      bool* A = new bool[256];
      for (int i=0;i<str.size();i++){
        if (A[str[i]]==true){
          return false;
        }else{
          A[str[i]]=true;
        }
      }
      return true;
    }
};

int main(){
  Solution sol;
  string str = "asdafajkbczmvbus";
  //cin >> str;
  cout << str  << ": ";
  sol.isunique1(str) ? (cout << "true" << endl) : (cout << "false" << endl);
  cout << str<< ": ";
  sol.isunique2(str) ? (cout << "true" << endl) : (cout << "false" << endl);
  return 0;
}
