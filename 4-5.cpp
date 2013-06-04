#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class TreeNode{
public:
  TreeNode* left;
  TreeNode* right;
  int val;
  TreeNode(int x):val(x),left(NULL),right(NULL){}
};

static int last = INT_MIN;

class Solution{
public:
  void inOrder(TreeNode* root, vector<int> &l){
    if (root==NULL){
      return;
    }else{
      inOrder(root->left,l);
      cout << root->val << " ";
      l.push_back(root->val);
      inOrder(root->right,l);
    }
  }
  bool checkbst(TreeNode* root){
    vector<int> l;
    inOrder(root,l);
    for (int i=1;i<l.size();i++){
      if (l[i]<l[i-1]){
        return false;
      }
    }
    return true;
  }
  
  
  bool checkbst2(TreeNode* root){
    if (root==NULL){
      return true;
    }else{
      if (!checkbst2(root->left)){return false;}
      if (root->val<last){return false;}
      last=root->val;
      if (!checkbst2(root->right)){return false;}
      return true;
    }
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
  Solution sol;
  if (sol.checkbst(root)){
    cout << "This is a BST" << endl;
  }else{
    cout << "This is NOT a BST" << endl;
  }
  
   if (sol.checkbst2(root)){
    cout << "This is a BST" << endl;
  }else{
    cout << "This is NOT a BST" << endl;
  }
  return 0;
}
