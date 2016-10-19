#include <iostream>
#include <string.h>
using namespace std;

void reverse(char Str[]){
  for(int i=strlen(Str);i>=0;i--)
  {
	  cout<<Str[i];
  }
}

int main(){
  char str[30];
  cout<<"input character\t:";
  cin.getline(str,sizeof(str));
  cout << str << " -> ";
  reverse(str);
  return 0;
}


