#include <iostream>

using namespace std;


string printBin(double x){
  if (x>1 || x<0){cerr<< "Wrong input!"<<endl; return "";}
  else{
    int i=0;
    string str = "";
    while (str.length()<32){
      if (x==0){return str;}
      else{
        if (int(x*2)==1) {str=str+'1'; x = x*2-1;}
        else {str=str+'0'; x=x*2;}
      }
    }
    return str;
  }

}

int main(){
  double x1 = 0.8125;
  double x2 = 0.72;
  double x3 = 1.2;	
  cout << "The binary of " << x1 << " is 0." << printBin(x1) << endl;
  cout << "The binary of " << x2 << " is 0." << printBin(x2) << endl;
  cout << "The binary of " << x3 << " is 0." << printBin(x3) << endl;
  return 0;
}
