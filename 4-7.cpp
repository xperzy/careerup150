//Common Ancestor
#include <iostream>
using namespace std;

class TreeNode{
public:
  TreeNode* left;
  TreeNode* right;
  int val;
  TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution{
public:
  bool inLeft(TreeNode* root, TreeNode* node){
    if (root==NULL) {return false;}
    if (root==node) {return true;}
    return inLeft(root->left,node) || inLeft(root->right,node);  
  }

  TreeNode* commonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if (root==NULL){return NULL;}
    if (root==p || root==q){return root;}
    
    bool is_left_p=false;
    bool is_left_q=false;
    if (root->left){
     is_left_p= inLeft(root->left,p);
     is_left_q= inLeft(root->left,q);
    }
    
    if (is_left_p!=is_left_q){return root;}
    if (is_left_p){return commonAncestor(root->left,p,q);}
    else{return commonAncestor(root->right,p,q);}
  }
};


int main(){
  //construct tree
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(1);
  root->right = new TreeNode(5);
  
  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(2);
  
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(6);

  root->right->right->right = new TreeNode(7);
  root->right->right->right->right = new TreeNode(8);
  
  TreeNode* p = root->right->right->right;
  //TreeNode* q = root->right->right->right->right;
  TreeNode* q = root->left->left;
  
                
  Solution sol;
  TreeNode* ans = sol.commonAncestor(root,p,q);
  cout << ans->val << endl;
  return 0;
}
