#include <iostream>
#include <bitset>

using namespace std;

void drawLine(char[] screen, int width, int x1, int x2, int y){

}

int main(){
  int width=8;
  int x1 = 3;
  int x2 = 5;
  int y = 2;
  char* screen = new char[width*y];
  drawLine(screen, width, x1, x2, y);
  
  for (int i=0;i<y;i++){
    for(int j=0;j<width;j++){
      cout << screen[i*width+j] << " ";
    }
    cout << endl;
  }
  
  return 0;
}
