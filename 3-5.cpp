#include <iostream>
#include <stack>
using namespace std;

template <class T>
class MyQueue{
  stack<T> s_new;
  stack<T> s_old;
public:
  void push(T i){
    s_new.push(i);
  }
  void pop(){
    if (!s_old.empty()){
      s_old.pop();
    }else{
      if (s_new.empty()){
       cerr<<"Empty Queue!" << endl;
      }else{
        while (!s_new.empty()){
          s_old.push(s_new.top());
          s_new.pop();
        }
        s_old.pop();
      }
    }
  }
  
  T front(){
    if (!s_old.empty()){
      return s_old.top();
    }else{
      if (s_new.empty()){
       cerr<<"Empty Queue!" << endl;
      }else{
        while (!s_new.empty()){
          s_old.push(s_new.top());
          s_new.pop();
        }
        return s_old.top();
      }
    }
  }
  
  bool empty(){
    return s_new.empty()&&s_old.empty();
  }
};


int main(){
  MyQueue<int> mq;
  
  for (int i=0;i<10;i++){
    mq.push(i);
  }
    
  while (!mq.empty())  {
     cout<< mq.front()<<endl;
     mq.pop();
  }
  return 0;
}



