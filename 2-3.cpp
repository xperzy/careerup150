#include <iostream>
using namespace std;

class ListNode{
public:
  int val;
  ListNode* next;
  ListNode(int i): val(i),next(NULL){}
};


void delmid(ListNode* head){
  ListNode* p = new ListNode(0);
  p->next = head;
  ListNode* q = head;
  
  if (!q->next){head=NULL; return;}
  
  while (q->next && q->next->next){
   q = q->next->next;
   p = p->next;
  } 
  
  p->next = p->next->next;

}

int main(){
  ListNode* head = new ListNode(0);
  ListNode* q=head;
  int a[16] = {1,2,3,4,5,6,7,8,7,6,5,4,3,2,1,0};
  
  for (int i=0;i<16;i++){
    ListNode* p=new ListNode(a[i]);
    q->next = p;
    q=p;
  }
    
  delmid(head);
  
  
  if (head==NULL){cout << "Empty List" << endl; return 0;}
  while (head!=NULL){
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
  
  return 0;
    
 

}
