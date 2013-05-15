#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
  bool check(string str1, string str2){
    str1 = str1 + str1;
    if (str1.find(str2)==-1)
      return false;
      else
      return true;
  }
};

int main(){

  Solution sol;
  string str1 = "erbottlewat";
  string str2 = "waterbottle";

  if (sol.check(str1,str2))
    cout << str1 << " is a rotation of " << str2 <<endl;
  else
    cout << str1 << " is NOT a rotation of " << str2 <<endl;
    
  return 0;
}

