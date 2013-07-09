#include <iostream>
#include <string>
#include <vector>

using namespace std;

void swap(string &str, int a, int b){
  char ch = str[a];
  str[a]=str[b];
  str[b]=ch;
}

void perm(string str,int k,int n, vector<string> &res){
  if (k==n){
    res.push_back(str);
  }else{
    for (int i=k;i<n;i++){
      swap(str,k,i);
      perm(str,k+1,n,res);
      swap(str,k,i);
    }
    
  }
  
}

int main(){
  string str = "abc";
  vector<string> res;
  perm(str,0,str.size(),res);
  for (int i=0;i<res.size();i++){
    cout << res[i] << endl;
  }
  return 0;
}
