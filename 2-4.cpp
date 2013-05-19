// 2.5 in 5th edtion, 2.4 in 4th edtion
#include <iostream>

using namespace std;



class ListNode{
public:
  int val;
  ListNode* next;
  ListNode(int i): val(i),next(NULL){}
};

//add two list
ListNode* add2l(ListNode* l1, ListNode* l2){
  int carry=0;
  ListNode* p=l1;
  ListNode* q=l2;
  while(p && q){
	int s = p->val+q->val + carry;
	p->val = s%10;
	q->val = s%10;	
	carry = s/10;
	p=p->next;
	q=q->next;
  }
  
  if (p==NULL){
	while (q->next && carry>0)  {
	q->val = q->val+carry;
	carry = q->val/10;
	q->val=q->val%10;		
	q=q->next;
	}
	if (carry>0){
		q->val =q->val+carry;
		if (q->val>=10) {
			q->next = new ListNode(q->val/10);
			q->val = q->val%10;
		}
	}
        return l2;	  
  }
  
  if (q==NULL){
	while (p->next && carry>0)  {
	p->val = p->val+carry;
	carry = p->val/10;
	p->val=p->val%10;		
	p=p->next;
	}
	if (carry>0){
		p->val =p->val+carry;
		if (p->val>=10) {
			p->next = new ListNode(p->val/10);
			p->val = p->val%10;
		}
	}
        return l1;	  
  }
  

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
  int A[4] = {4,3,6,9}; //9634
  int B[4] = {5,2,6};    //625
  ListNode* l1 = creatl(A,4);
  ListNode* l2 = creatl(B,3);
  ListNode* ls = add2l(l1,l2);
  printList(ls);
  return 0;
}

