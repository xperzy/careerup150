#include <iostream>

using namespace std;

void reverse(char* str){
    char* ed = str;
    char* st = str;
    while (*ed)  { ed++; }
    ed--;
    while (st<ed) {
    char tmp = *st;
    *st = *ed;
    *ed = tmp;
    st++;
    ed--;
    }
    cout << str<< endl;
}

int main(){
  char str[]="abcdefghjka"; //If use char* = "adadaf", the memory is read-only, which will cause error
  cout << str << " -> ";
  reverse(str);
  return 0;
}


