//2.6 in 5th edtion

#include<iostream>

using namespace std;

class ListNode{
public:
  int val;
  ListNode* next;
  ListNode(int i): val(i),next(NULL){}
};


ListNode* ff(ListNode *node){
  ListNode* p=node;//slow 
  ListNode* q=node; //faster
  while (true){
    p=p->next;
    q=q->next->next;
    if (p==q) break;
  }
  p=node;  
  while (p!=q){
	p=p->next;
	q=q->next;
  }
 
  return q;
  
}



ListNode* creatl(int* A,int n){
  ListNode* head = new ListNode(A[0]);
  ListNode* q=head; 
  for (int i=1;i<n;i++){
    ListNode* p=new ListNode(A[i]);
    q->next = p;
    q=p;
  }
  cout << "GT: last = " << q->val << endl;
  q->next = head->next->next->next;
  cout << "GT: loop = " << q->next->val << endl;
  return head;
}

void printList(ListNode* head){
  if (head==NULL){cout << "Empty List" << endl; }
    while (head!=NULL){
      cout << head->val << " ";
      head = head->next;
    }
  cout << endl;
}

int main(){
  int A[11] = {9,8,7,4,5,3,2,8,4,3,6};
  ListNode* head = creatl(A,11);  // head = 9, last = 0, loop  = 4;
  cout << "List head: " << head->val << endl;
  ListNode* res = ff(head);
  cout << "Loop start: " << res->val << endl;
  return 0;
}

