#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


bool OK(int x, int y, const vector<int> mp){
  for (int i=0;i<x;i++){
    if (mp[i]==y || abs(x-i)==abs(y-mp[i])){
      return false;
    }
  }
  return true;
}


void dp(int n, vector<int> &mp, vector<vector<int> > &res, int nqueen){
  if (n==nqueen){
    res.push_back(mp);
  }else{
    for (int i=0;i<8;i++){
      if (OK(n,i,mp) ){
        mp[n]=i;
        dp(n+1,mp,res,nqueen);
        mp[n]=0;
      }
    }
  }
}


int main(){
  int nqueen = 8;
  vector<vector<int> > res;
  vector<int> mp(8,0);
  dp(0,mp,res,nqueen);
  
  for (int i=0;i<res.size();i++){ 
     for (int j=0;j<nqueen;j++){
       cout << res[i][j] << " ";
     }
     cout <<  endl;
  }
  cout << res.size()<< endl;
  return 0;
}
