#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


void subSet(string str, vector<string> &res){
  int sz = str.length();
  int rsz=0;
  sort(str.begin(),str.end());
  for (int i=0;i<sz;i++){
    if (i==0){
      res.push_back("");
      res.push_back(string(1,str[i]));
    }else{
	    
	    if (str[i]==str[i-1]){
		int r = res.size();
		for (int j=r-rsz;j<r;j++){
			res.push_back(res[j]+str[i]);
		}
	    }
    
	if (str[i]!=str[i-1]){
		rsz=res.size();
		for (int j=0;j<rsz;j++){
			res.push_back(res[j]+str[i]);
		}
	}
  }
}

}


int main(){
  string str = "1222"; //input set
  vector<string> res;
  subSet(str,res);
  for (int i=0;i<res.size();i++){
    cout << res[i] << endl;
  }
}

