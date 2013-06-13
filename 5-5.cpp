#include <iostream>
#include <bitset>

using namespace std;


int ct(int A, int B){
  bitset<8> C(A^B);
  return C.count();
}

int main(){
  int A = 7;
  int B = 14;
  bitset<8> AA(A);
  bitset<8> BB(B);
  cout << "To convert " << AA.to_string() <<" to " << BB.to_string() << ", " << ct(A,B) << " bits are needed." << endl;  
  return 0;
}
