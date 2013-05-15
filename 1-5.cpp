#include <iostream>
#include <string>


using namespace std;

class Solution{
public:
	string compress(string str){
		string res="";
		if (str.size()==0) {return str;}
		char last = str[0];
		int count  = 0;
		for (int i=0;i<str.size();i++){
			if (str[i]==last){
				count ++;
			}else{
				res  = res + last;
				if (count >1){
					string cst = "";
					while(count!=0){
						cst = char(count%10+'0')+cst;
						count  = count/10;
					}
					res = res+cst;
				}
				count = 1;
				last = str[i];
			}
		}
		string cst = "";
		if (count >1){		
			while(count!=0){
				cst = char(count%10+'0')+cst;
				count  = count/10;
			}
		}
		res = res + last + cst;
		return res;
	}

  
};

int main(){
  Solution sol;
  //string  str1 = "aaaabbcccddeeaaaaaaaavbaaaa";
  string str1 = "abcdefg";
  string str2 = sol.compress(str1);
	cout << str1 << endl;
	cout << str2 << endl;
  return 0;
}
