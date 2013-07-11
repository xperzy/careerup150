#include <iostream>
#include <vector>

using namespace std;

int mc2(int n, int d){
  int next_d = 0;
  switch (d){
	case 25:
		next_d=10;
	        break;
	case 10:
		next_d=5;
	        break;
	case 5:
		next_d=1;
	        break;
	case 1:
		return 1;
  }
 
  int ways=0;
  for (int i=0;i*d<=n;i++)  {
    ways+=mc2(n-i*d,next_d);
  }
  return ways;
}

int main(){
  int n=100;
  cout << mc2(n,25) << endl;
  return 0;
}
