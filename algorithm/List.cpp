#include "MyHeader.h"
struct Node
{
	int Data;
	Node *next;
};
class List
{
	Node *head;
public:
	List(){head=NULL;};
	void insertList(int aData,int bData);
	void deleteList(int aData);
	void printList();
	Node *getHead(){return head;}
};
void List::printList()
{
	Node *current=head;
	while(current!=NULL)
	{
		cout<<current->Data<<" ";
		current=current->next;
	}
}
void List::insertList(int aData,int bData)
{
	Node *p,*q,*s;
	s=new Node;
	s->Data=bData;
	p=head;
	if(head==NULL){
		head=s;
		s->next=NULL;
	}else if(p->Data==aData) {
		s->next=p;
		head=s;
	}else{
		while(p->Data!=aData&&p->next!=NULL){
			q=p;
			p=p->next;
		}
		if (p->Data==aData)
		{
			q->next=s;
			s->next=p;
		}else{
			p->next=s;
			s->next=NULL;
		}
	}
}
void List::deleteList(int aData){
	Node *p,*q;
	p=head;
	if(head==NULL){return;}
	if(p->Data==aData){
		head=p->next;
		delete p;
	}else{
		while(p->Data!=aData&&p->next!=NULL){
			q=p;
			p=p->next;
		}
		if(p->Data==aData){
			q->next=p->next;
			delete p;
		}
	}
}
int main()
{
	List A,B;
	int Data[10]={25,41,16,98,5,67,9,55,1,121};
	//建立链表A首结点
 	A.insertList(0,Data[0]); 
 	//顺序向后插入
 	for(int i=1;i<10;i++)
  		A.insertList(0,Data[i]); 
	cout<<"\n链表A:";
	A.printList();
	A.deleteList(Data[7]);
	cout<<endl;
	cout<<"删除A:";
	A.printList();
	//建立链表B首结点
	B.insertList(0,Data[0]); 
 	for(int i=0;i<10;i++)
 		//在首结点处顺序向后插入
  		B.insertList(B.getHead()->Data,Data[i]); 
	cout<<"\n链表B:";
	B.printList();
	B.deleteList(67);
	cout<<endl;
	cout<<"删除B:";
	B.printList(); 
	return 0;
}