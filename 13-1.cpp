#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


void printKlines(const char* fname,int k){
  vector<string> Lines(k,"");
  string line;
  ifstream fid;
  fid.open(fname);
  int size=0;
  while (getline(fid,line)){
    Lines[size%k]=line;
    size++;
  }
  
  for (int i=0;i<Lines.size();i++){
    cout << Lines[i] << endl;
  }
  
}


int main(){
  char* fname = "13-1f.txt";
  int k=5;
  printKlines(fname,k);
  return 0;
}
