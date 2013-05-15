#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
  void rotate(int a[][5], int n){
      for (int layer = 0; layer<n/2;layer++){
      int first = layer;
      int last = n-layer-1;
      for (int i = first; i<last;i++){
        int top = a[first][i];
        int offset = i-first;
        
        a[first][i] = a[last-offset][first];
        a[last-offset][first] = a[last][last-offset];
        a[last][last-offset] = a[i][last];
        a[i][last] = top;
      }
    
    }
  }
};

int main(){

  Solution sol;
  int a[5][5] = {{1,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5}};
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
