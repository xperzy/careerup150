#include <iostream>
#include <queue>
#include <list>
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

//store a tree according to the level
void storeTree(TreeNode* root, vector<vector<int> > &res){
	queue<pair<TreeNode*, int> > q;
	if (root==NULL){cout << "Empty Tree! "<< endl; return;}
	int dep=0;
	q.push(make_pair(root,dep));
	vector<int> lev;
	while (!q.empty()){
		if (q.front().second!=dep){
		  res.push_back(lev);
		  lev.clear();
		}
		dep = q.front().second;
		lev.push_back(q.front().first->val);
		
		if (q.front().first->left!=NULL){q.push( make_pair(q.front().first->left,dep+1));}
		if (q.front().first->right!=NULL){q.push( make_pair(q.front().first->right,dep+1));}
		
		q.pop();
	}
	res.push_back(lev);
}

int main(){
  int n=13;
  int* A = new int[n];
  for (int i=0;i<n;i++){
    A[i]=i;
  }
   
  TreeNode* root;
  root  = BST(A,0,n-1);
  
  vector<vector<int> > res;
  storeTree(root,res);
    
  for (int i=0;i<res.size();i++){
    for (int j=0;j<res[i].size();j++){
       cout << res[i][j]<<" ";	     
    }	  
    cout << endl;
  }
  
  return 0;
}

