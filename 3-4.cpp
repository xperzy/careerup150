//unfinished

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void moveTopTo(vector<stack<int> >&towers, int origin, int dest){
  int tmp = towers[origin].top();
  towers[origin].pop();
  towers[dest].push(tmp);
  cout << "move disk" << tmp << " from " << origin << " to " << dest << endl;
}

void  moveplate(int n,vector<stack<int> >&towers, int origin, int buffer, int destination){
 if (n<=0){return;}
 moveplate(n-1,towers,origin,buffer,destination);
 moveTopTo(towers, origin,destination);
 moveplate(n-1,towers,buffer,destination,origin);
}

int main(){
 int np = 5; 
 vector<stack<int> >towers;
 stack<int> st;
towers.push_back(st);
towers.push_back(st);
towers.push_back(st);
 for (int i=np;i>=1;i--){
    towers[0].push(i);
 }
 moveplate(np,towers,0,1,2);
 return 0;
}
