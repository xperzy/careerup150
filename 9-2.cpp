#include <iostream>
#include <string>
#include <vector>
using namespace std;

int getNum(int x, int y){
  int m=x+y;
  int n=x;
  double res = 1;
  while (m!=x){
    res =res*m;
    m--;
  }
  while (n!=0){
   res = res/n;
   n--;
  }
  return int(res);
}


void getPath(int x1,int y1,int x, int y,vector<char> &path,int &num){
  if (x1==x && y1==y){
     num++;
     cout << num << ":";
     for (int i=0;i<path.size();i++){
       cout << path[i];
     }
     cout << endl;
  }else{
     
     if (x1+1<=x){
       path.push_back('R');
       getPath(x1+1,y1,x,y,path,num);
       path.pop_back();
     }
     
     if (y1+1<=y){
       path.push_back('L');
       getPath(x1,y1+1,x,y,path,num);
       path.pop_back();
     }
  }
}

int main(){
  int x = 3;
  int y = 3;
  
  int res = getNum(x,y);
  cout << "Number of ways from (0,0) to (";
  cout << x << "," << y << ") is: " << res <<endl;
  
  cout << "The paths are: " << endl;
  
  vector<char> path;
  int num=0;
  getPath(0,0,x,y,path,num);
  
  return 0;
}
