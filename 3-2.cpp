//3.2 Stack with minimum

#include<iostream>
#include<stack>

using namespace std;


// Composition of stack class
template <class T>
class StackWithMin{
stack<pair<T,T> > st;
public:
  void push(T t){
    if (!st.empty()){
      T m;
      if (t>min()) {m = min();}else{m=t;}
      st.push(make_pair(t,m));
    }else{
	st.push(make_pair(t,t));    
    }
  }
  bool empty() { return st.empty(); }
  void pop(){st.pop();}
  T top(){return st.top().first;}
  T min(){return st.top().second;}
};





int main(){
  //StackWithMin<int> st;
  StackWithMin2<int> st;

        st.push(20);
	st.push(10);
	st.push(25);
	st.push(8);
	st.push(9);
	st.push(7);
	st.push(20);

  cout << "20" << endl;
  cout <<	"7 "  << endl;
  cout <<	"9 "  << endl;
  cout <<	"8 " << endl;
  cout <<	"25" << endl; 
  cout <<	"10" << endl;
  cout <<	"20" << endl; 
	
	
  while (!st.empty()){ 
    cout << "Current min = " << st.min() << "   ";
    cout << st.top() << " Poped.  "  << endl;
    st.pop();
  }
    
  return 0;
}

