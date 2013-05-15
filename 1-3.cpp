#include <iostream>
#include <string>

using namespace std;

bool isAnag(string &str1, string &str2){
	if (str1.size()!=str2.size()){return false;}
	int *A = new int[256];
	for (int i=0;i<str1.size();i++){
		A[str1[i]]++;
	}
	for (int i=0;i<str2.size();i++){
		if (A[str2[i]]<=0) {return false;}
		A[str2[i]]--;
	}
	return true;
}

int main(){
	string str1 = "aaabb";
	string str2 = "aabbb";
	cout << isAnag(str1,str2);
	return 0;
	
}
