#include <iostream>
#include <bitset>
using namespace std;


void showbin(int v){
    string str(32,'0');
    int i=31;
    while (v>0){
      if (v%2==1){str[i]='1';}
      v=v/2;
      i--;
    }
    cout << str << endl;
}


int main(){

  int m=255;
  int n=14;
  int i=3;
  int j=6;   


  int aa=~0;
  aa = aa << j;
  int bb=(1<<i) -1;
  	
  bitset<32>a(aa);	
  //cout << a.to_string() << endl;
  bitset<32>b(bb);	
  //cout << b.to_string() << endl;

  int cc = aa|bb;
  bitset<32>c(cc);	
  cout << c.to_string() << endl;
	
  m = m&cc;
  n=n<<i;  
  
  m = m|n;

  bitset<32>mm(m);
  bitset<32>nn(n);
  cout << mm.to_string() << endl;
  //cout << nn.to_string() << endl;
   int t=0;	
   for (int k = i;k<=j;k++){
	   mm[k]=nn[t];
	   t++;
   }	
  
   //cout << mm.to_string() << endl;
  	

  return 0;
}
