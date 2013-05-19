//2.4 in 5th edtion

#include<iostream>

using namespace std;

class ListNode{
public:
  int val;
  ListNode* next;
  ListNode(int i): val(i),next(NULL){}
};


ListNode* parti(ListNode *head, int x){
  ListNode* p=new ListNode(0);
  p->next=head;
  head= p;
  while (p->next){
    if (p->next->val<x){
      ListNode* q= p->next;
      p->next = p->next->next;
      q->next = head->next;
      head->next = q;
    }else{
        p=p->next;
    }
  }
  return head->next;
}



ListNode* creatl(int* A,int n){
  ListNode* head = new ListNode(A[0]);
  ListNode* q=head; 
  for (int i=1;i<n;i++){
    ListNode* p=new ListNode(A[i]);
    q->next = p;
    q=p;
  }
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
  int A[12] = {9,8,7,4,5,3,2,8,4,3,6,0};
  ListNode* head = creatl(A,12);
  int x = 5;
  ListNode* res = parti(head,x);
  printList(res);
  return 0;
}

