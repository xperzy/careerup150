#include <iostream>
using namespace std;


void merge2(int A[], int na, int B[], int nb){
  int ia = na-1;
  int ib = nb-1;
  int idx = na+nb-1;
  
  while (ia>=0 && ib>=0){
    A[idx--]=A[ia]>B[ib]?A[ia--]:B[ib--];
  }
  
  while (ib>=0){
    A[idx--]=B[ib--];
  }

}


int main(){
  int A[12] = {1,3,5,6,9,10,0,0,0,0,0,0};
  int B[6] = {2,4,7,8,11,12};
  
  merge2(A,6,B,6);
  
  cout << "Merged: ";
  for (int i=0;i<12;i++){
    cout << A[i] << " ";
  }
  cout <<endl;

  return 0;
}
