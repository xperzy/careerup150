#include <iostream>
#include <bitset>
using namespace std;


int swap(int x){
  int maskE = 170; //8 bits, 10101010
  int maskO = 85; //8 bit, 01010101
  return ((x&maskE) >> 1)|((x&maskO) << 1);      
}

int main(){
 int x = 145;
 bitset<8> xx(x);
 cout << "Swap " << xx.to_string() << endl;
 bitset<8> res(swap(x));
 cout <<  "E to O " << res.to_string() << endl;
 return 0; 
}
