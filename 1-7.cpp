#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
  void rotate(int a[][5], int n){
	bool col=true;
	bool row=true;
	for (int i=0;i<n;i++)  {
		if (a[i][0]==0) {col=false;}
		if (a[0][i]==0) {row=false;}
	}
	  
      for(int i=1;i<n;i++){
	for (int j=1;j<n;j++) {
		if (a[i][j]==0){
		     a[0][j]	=0;
		     a[i][0] = 0;
		}
	}
      }
      
      for (int i=0;i<n;i++){
	      if (a[0][i]==0) {
		 for (int j = 0;j<n;j++)     {
			 a[j][i]=0;
			 }
		}
	       if (a[i][0]==0) {
		 for (int j=0;j<n;j++)     {
			 a[i][j]=0;
			 }
		}
	
	 }
      
	 if (!row){
		for (int i=0;i<n;i++){
	         a[0][i]=0;
	       }	
        }
	
	if (!col){
		for (int i=0;i<n;i++){
	         a[i][0]=0;
	       }	
        }
  }
};

int main(){

  Solution sol;
  int a[5][5] = {{1,0,3,4,5}, {1,2,3,0,5}, {0,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5}};
    for (int i=0;i<5;i++){
    for (int j=0;j<5;j++){
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  sol.rotate(a,5);
  for (int i=0;i<5;i++){
    for (int j=0;j<5;j++){
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  
    
  return 0;
}

