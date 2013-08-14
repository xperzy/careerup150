#include <vector>
#include <iostream>

using namespace std;

class Box{
public:
  int h;
  int w;
  int d;
  Box(int h1,int w1,int d1):h(h1),w(w1),d(d1){};
  bool empty(){
    if (h==0 && w==0 && d==0){return true;}
    return false;
  }
  
  bool CanBeAbove(Box b){
    if (b.empty()) {return true;}
    if (h<b.h && w<b.w && d<b.d){return true;}
    return false;
  }
};


void build(vector<Box> &st, vector<Box> &boxes, int hh, int &maxh){
  Box top(0,0,0);
  if (!st.empty()){
    top=st.back();
  }
  
  for (int i=0;i<boxes.size();i++){
    if (boxes[i].CanBeAbove(top)){
      st.push_back(boxes[i]);
      //cout << "push " << boxes[i].h << endl;
      build(st,boxes,hh+boxes[i].h,maxh);
      st.pop_back();
    }
  }
  
  if (hh>maxh){maxh=hh;}
  
}


int main(){
//input data
Box b1(1,2,3);
Box b2(2,3,4);
Box b3(5,2,6);
Box b4(7,8,9);
Box b5(12,11,10);
vector<Box> boxes;
boxes.push_back(b1);
boxes.push_back(b2);
boxes.push_back(b3);
boxes.push_back(b4);
boxes.push_back(b5);

vector<Box> st;
int maxh=0;
	
build(st, boxes, 0, maxh)	;
	
cout << "Max height is:" << maxh << endl;
return 0;
}

