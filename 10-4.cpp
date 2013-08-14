#include <iostream>
#include <bitset>
#include <cstdlib> 
using namespace std;

void genArr(int arr[], int N){
  int n = 20; //nubmer of duplicates
  int *dup = new int[n];
  cout << "GroundTruth: ";
  for (int i=0;i<n;i++){
      dup[i]=rand()%100;
      cout << dup[i] << " ";
  }
  cout <<endl;
  
  for (int i=0;i<N;i++){
    arr[i]=i;
  }
  
  int j = rand() % 50+120;
  for (int i=j;i<j+n;i++){
    arr[i]= dup[i-j];
  }

}



int main(){
  int N=30000; //totall number of the array
  
  bitset<32000> bs; // 4 kilo-bytes
  bs.reset();	
	
  int* arr = new int[N];
  genArr(arr,N);
	
  cout << "PredicteRes: "  ;
	
  for (int i=0;i<N;i++){
    //if (bs.test(arr[i])){
   if (bs[arr[i]]==1){
      cout << arr[i] << " ";
    }else{
      bs[arr[i]]=1;
    }
  }
  cout << endl;
  
  cout << "Predicte2 : ";
  //use char array to represent byte array;
  char* bs2 = new char[4000];
  for (int i=0;i<N;i++)  {
    int pos= arr[i]/8; //get the byte position
    if ((bs2[pos] & (1 << arr[i]%8)) == 0) {  // 1<< arr[i]8 sets the specific bit to 1,  the & check if there exists the number
	bs2[pos] = bs2[pos] | (1 << arr[i]%8) ;    // if not exist, set the bit to 1.
    }else{
      cout << arr[i]<<" ";	    // else print the duplicate
    }
    
  }
  cout << endl; 
 }

