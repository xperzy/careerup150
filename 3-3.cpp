#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class SetOfStack{
vector<stack<int> > stacks;
int capacity;
public:
  SetOfStack(int cap):capacity(cap){} 
  
  void push(int i){
    if (getLastStack()>=0 && stacks[getLastStack()].size()<capacity){
	    stacks[getLastStack()].push(i);
	    cout << i << "pushed into " << getLastStack() << endl;
    }else {
      stack<int> nst;
      nst.push(i);  
      stacks.push_back(nst);
      cout << i << "pushed into new stack " << getLastStack() << endl;
      }
  }
    
  void pop(){
    if (stacks[getLastStack()].size()==0){cerr<< "Empty stack!" << endl; }
    else{
        if (stacks[getLastStack()].size()==1){
          stacks.pop_back();
        }else{
          stacks[getLastStack()].pop();
        }
    }
  }
  
  void popAt(int index){
	if (index>getLastStack() || index<0){cerr<<"Index out of range!" << endl;}
	else{
		if (stacks[index].size()==1){
			stacks.erase(stacks.begin()+index);
		}else{
			stacks[index].pop();
		}
		
	}
  }
  
	  
  int top()	{
	if ( !isempty() && (!stacks[getLastStack()].empty())){
		return stacks[getLastStack()].top();	
	}else{cerr<< "Empty Stack"<<endl;}	
  }

  int topAt(int index){
	if (index>getLastStack() || index<0){cerr<<"Index out of range!" << endl;}
	else{
		return stacks[index].top();
	}
  }
  
  bool isempty(){
    if (stacks.size()==0){return true;}
    else{
      return false;
    }
  }
  
  int size(){
    return stacks.size();
  }
  
  int getLastStack(){
    return stacks.size()-1;
  }
  
};



int main(){
 SetOfStack sst(4);
 for (int i=1;i<16;i++){
   sst.push(i);
 }
 
 for (int i=0;i<sst.size();i++){
	 sst.popAt(i);
	 cout << "poping " << i << "th stack...";
	 cout << "Top element now is: " << sst.topAt(i)<<endl;
 }
 
 
 
 return 0;
}


