#include <iostream>
#include <math.h>


using namespace std;


class TreeNode{
public:
  TreeNode* left;
  TreeNode* right;
  int val;
  TreeNode(int i):val(i),left(NULL),right(NULL){}
};

int getH(TreeNode* root){
   if (root==NULL){
     return 0;
   }else{
     int l = getH(root->left);
     if (l==-1){return -1;}
     int r = getH(root->right);
     if (r==-1){return -1;}
     
     if (abs(r-l)>1){
       return -1;
     }else{
       return max(l,r)+1;
     }
   
   }
}

bool isBalanced(TreeNode* root){
  if (getH(root)==-1){
    return false;
  }else{
    return true;
  }
}


int main(){
  TreeNode* root = new TreeNode(0);
  root->left = new TreeNode(1);
  root->right = new TreeNode(2);
  
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(6);

  root->right->right->right = new TreeNode(7);
  root->right->right->right->right = new TreeNode(8);
  
    
  if (isBalanced(root)){
   cout << "Balanced!"<< endl;
  }else{
   cout << "unBalanced!" << endl;
  }
  return 0;
}
