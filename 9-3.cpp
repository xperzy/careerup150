#include <iostream>
#include <vector>

using namespace std;


int findMagic(int A[],int st, int ed){
   if (st>ed){
     return -1;
   }
   int mid = st+ (ed-st)/2;
   if(A[mid]<mid){
     return findMagic(A,mid+1,ed);
   }
   if(A[mid]==mid){return mid;}
   if(A[mid]>mid){
     return findMagic(A,st,mid-1);
   }
}

int main(){
  int A[10]={-10,-5,-1,1,2,3,5,7,9,12};
//  int A[10]={0,1,2,3,4,5,6,7,8,9,10};
  int n = 10;
  int idx = findMagic(A,0,n-1); 
  if (idx==-1){
    cout << "NOT found!" << endl;
  }else{
    cout << idx << endl;
  }
  return 0;
}
