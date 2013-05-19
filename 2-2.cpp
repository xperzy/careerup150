#include <iostream>

using namespace std;

class ListNode{
public:
	int val;
	ListNode* next;
	ListNode(int i): val(i), next(NULL){}
};


int findlastn(ListNode* head, int n){
	ListNode* p=head;
	while(n>0 && p){
		p=p->next;
		n--;
	}
	if (n>0) {return 0;}
	
	ListNode* q = head;
	
	while (p->next){
		q=q->next;
		p=p->next;		
	}
	return q->val;
	
}

int main(){
	ListNode* head = new ListNode(1);
	ListNode* q=head;
	int a[15] = {1,2,3,4,5,6,7,4,5,2,10,8,9,0,5};
	//int a[15] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	for (int i=0;i<15;i++){
		ListNode* p=new ListNode(a[i]);
		q->next = p;
		q=p;
	}
	int n = 5;
	cout << "The " << n << "th to last element is " << findlastn(head,n-1) << endl;
}
