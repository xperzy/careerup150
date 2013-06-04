//subtree
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
  bool isSameTree(TreeNode *root1, TreeNode* root2){
    if (root1==NULL && root2==NULL){return true;}
    if (root1==NULL || root2==NULL){return false;}
    if (root1->val!=root2->val){return false;}
    return isSameTree(root1->left,root2->left)&&isSameTree(root1->right,root2->right);
  }

  bool isSub(TreeNode* bigTree, TreeNode* smTree){
        if (bigTree==NULL){return false;}
        if (bigTree->val==smTree->val && isSameTree(bigTree,smTree)) {return true;}
        return isSub(bigTree->left,smTree) || isSub(bigTree->right,smTree);
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
  
  TreeNode* root2 = root->right;       // yes
  TreeNode* root3 = new TreeNode(4);   // yes
  TreeNode* root4 = new TreeNode(5);   // no
  root4->left = new TreeNode(4);
  root4->right = new TreeNode(6);
  
  TreeNode* root5 = new TreeNode(1);  // yes
  root5->left=new TreeNode(0);
  root5->right=new TreeNode(2);


  Solution sol;
  if (sol.isSub(root,root2)){
    cout << "Tree2 is a subtree of Tree1" << endl;
  }else{
    cout << "Tree2 is NOT a subtree of Tree1" << endl;
  }
  
  if (sol.isSub(root,root3)){
    cout << "Tree3 is a subtree of Tree1" << endl;
  }else{
    cout << "Tree3 is NOT a subtree of Tree1" << endl;
  }
    if (sol.isSub(root,root4)){
    cout << "Tree4 is a subtree of Tree1" << endl;
  }else{
    cout << "Tree4 is NOT a subtree of Tree1" << endl;
  }
    if (sol.isSub(root,root5)){
    cout << "Tree5 is a subtree of Tree1" << endl;
  }else{
    cout << "Tree5 is NOT a subtree of Tree1" << endl;
  }
  return 0;
  
}
