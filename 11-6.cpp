#include <iostream>
#include <vector>

using namespace std;



void findEle(const vector<vector<int> > &matrix,int x,int &row,int &col){
  int nrow = matrix.size();
  if (nrow==0){return;}
  int ncol = matrix[0].size();
  
  int i=0; 
  int j=ncol-1;
  
    
  while (i<nrow && j>=0){
    if (matrix[i][j]==x){
      row=i;
      col=j;
      return;
    }else{
      if (matrix[i][j]<x){
        i++;
      }else{
        j--;
      }
    }
  }

}




int main(){
  int A[4][4] = {{15,20,40,85},
                 {20,35,80,95},
                 {30,55,95,105},
                 {40,80,100,120}};
                 
  vector<vector<int> > matrix(4,vector<int>(4,0));
  cout << "Matrix: " << endl;
  for (int i=0;i<4;i++){
    for (int j=0;j<4;j++){
      matrix[i][j]=A[i][j];
      cout << matrix[i][j] << " " ;
    }
    cout << endl;
  }
  
  int row=-1;
  int col=-1;
  int x = 55;
  cout << "Finding element: "<<x << endl;
  findEle(matrix,x,row,col);
  cout << "matrix[" << row+1 << "][" << col+1 <<"]=" << x<<endl; 

  return 0; 
}
