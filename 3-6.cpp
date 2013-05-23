#include <iostream>
#include <stack>

using namespace std;

void sort(stack<int> &st1, stack<int> &st2){
  while (!st1.empty()){
    int tmp = st1.top();
    st1.pop();
    while (!st2.empty() && st2.top()>tmp){
      st1.push(st2.top());
      st2.pop();
    }
    st2.push(tmp);    
  }
}


int main(){
  stack<int> st1;
  stack<int> st2;
  int A[9] = {2,4,5,3,1,7,9,8,6};
  for (int i=0;i<9;i++){
    st1.push(A[i]);
  }
  sort(st1,st2);
  while (!st2.empty()){
    cout << st2.top() << " ";
    st2.pop();
  }
  cout << endl;
    
  return 0;
}

