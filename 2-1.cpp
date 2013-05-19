#include <iostream>
#include <string>

using namespace std;

class ListNode{
public:
  int val;
  ListNode* next;
  ListNode(int v): val(v),next(NULL){}
};

void deletedup(ListNode* head){
  ListNode* p=head;
  ListNode* q=head; 
  while (p->next){
    bool f = true;
    while(q!=p->next){
      if (p->next->val==q->val){
        p->next=p->next->next;
	      f = false;
        break;
      }
      q=q->next;
    }
    if (f) {p=p->next;}
    q=head;    
  }

}


int main(){
  ListNode* head = new ListNode(1);
  ListNode* q=head;
  int a[15] = {1,2,3,4,5,6,7,4,5,2,10,8,9,0,0};
  //int a[15] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
  for (int i=0;i<15;i++){
    ListNode* p=new ListNode(a[i]);
    q->next = p;
    q=p;
  }
    
  deletedup(head);
  if (head==NULL){cout << "Empty List" << endl; return 0;}
  while (head!=NULL){
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
  
  return 0;
}

