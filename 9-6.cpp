#include <iostream>
#include <string>
#include <vector>

using namespace std;


void dps(string str, int l, int r, vector<string> &res){
 if (l==0 && r==0){
   res.push_back(str);
 }else{
   if (l>0){
     dps(str+"(",l-1,r,res);
   }
   
   if (r>0 && r>l){
     dps(str+")",l,r-1,res);
   }
 }

}

int main(){
  int n=3;
  vector<string> res;
  dps("",n,n,res);
  for (int i=0;i<res.size();i++){
    cout << res[i] << endl;
  }
  return 0;
}
