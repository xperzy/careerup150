#include <vector>
#include <iostream>


using namespace std;

class Box{
public:
  int h;
  int w;
  int d;
  Box(int h1,int w1,int d1):h(h1),w(w1),d(d1){};
  bool canBeAbove(Box b){
    if (b.empty()) {return true;}
    if ((h<b.h)&&(w<b.w)&&(d<b.d)){
      return true;
    }
    return false;
  }
  
  bool empty(){
    if ((h==0)&&(w==0)&&(d==0)){return true;}
    return false;
  }
  
};

int getHeight(vector<Box> st){
  int maxh=0;
  if (st.empty()){return 0;}
  for (vector<Box>::iterator it=st.begin();it!=st.end();it++){
    maxh+=it->h;
  }
  return maxh;
}

vector<Box> creatStack(vector<Box> boxes, Box bottom){
  int max_height = 0;
  vector<Box> max_stack;
  
  for (int i=0;i<boxes.size();i++){
    if (boxes[i].canBeAbove(bottom)){
      vector<Box> new_stack = creatStack(boxes,boxes[i]);
      int new_height = getHeight(new_stack);
      if (new_height>max_height){
        max_stack = new_stack;
        max_height = new_height;
      }
    }
  }

  if (!bottom.empty()){
    max_stack.push_back(bottom);
  }
  
  
  return max_stack;
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

vector<Box> stack;
Box bottom(0,0,0);
stack = creatStack(boxes, bottom);
cout << "Max height is:" << getHeight(stack) << endl;
return 0;
}
