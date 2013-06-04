#include <iostream>
#include <queue>
using namespace std;

class TreeNode{
public:
  TreeNode* left;
  TreeNode* right;
  int val;
  TreeNode(int x):val(x),left(NULL),right(NULL){}
};


TreeNode* BST(int* A,int st, int ed){
 if (st>ed){return NULL;}
 else{
  int mid = st+(ed-st)/2;
  TreeNode* node = new TreeNode(A[mid]);
  //cout << A[mid] << " ";
  node->left = BST(A,st,mid-1);
  node->right = BST(A,mid+1,ed);
  return node;
 }
}

//print a tree according to the level
void printTree(TreeNode* root){
	queue<TreeNode*> q;
	if (root==NULL){cout << "Empty Tree! "<< endl; return;}
	q.push(root);
	while (!q.empty()){
		cout << q.front()->val << " ";
		if (q.front()->left!=NULL){q.push(q.front()->left);}
		if (q.front()->right!=NULL){q.push(q.front()->right);}
		q.pop();
	}
	cout << endl;
}

int main(){
  int n=13;
  int* A = new int[n];
  for (int i=0;i<n;i++){
    A[i]=i;
  }
   
  TreeNode* root;
  root  = BST(A,0,n-1);
  
  printTree(root);
    
  return 0;
}

