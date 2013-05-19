//2.4 in 5th edtion

#include<iostream>
#include <stack>
using namespace std;

class ListNode{
public:
  int val;
  ListNode* next;
  ListNode(int i): val(i),next(NULL){}
};


bool isp(ListNode* head,int len){
  ListNode* p=head;
  stack<int> st;
  int i = len/2;
  while (i>0){
   st.push(p->val);
   p=p->next;
   i--;
  }
  
  if (len%2!=0){p=p->next;}
  
  while (p){
  if (p->val!=st.top()){return false;}
  else{
    st.pop();
    p=p->next;
  }
  }
    
  return true;

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
  int A[13] = {9,8,7,4,5,3,1,3,5,4,7,8,9};
  ListNode* head = creatl(A,13);
  printList(head);
  int len = 13;
  if (isp(head,13)){cout << "This is a palindrome"<<endl;}
  else{cout << "This is NOT a palindrome"<<endl;}

  return 0;
}

