#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node{
	int data;
	Node* next;
};


class QueueLinkedlist
{
	Node* head;
	Node* tail;
	public:
		QueueLinkedlist()
		{
			head=NULL;
			tail=NULL;
		}
	bool isempty()
		{
			if(head==NULL)
				return true;
		
			return !true;
		}
	void push(int data)
	{
		if(head==NULL)
		{
			Node* node=(Node*)malloc(sizeof(Node));
			node->data=data;
			head=node;
			node->next=head;
			tail=head;
			return;
		}
		Node* node=(Node*)malloc(sizeof(Node));
		node->data=data;
		node->next=head;
		tail->next=node;
		tail=node;
	}	
	void pop()
		{
			if(head==NULL)
			return;
			if(head==tail)
			{
				delete(head);
				head=tail=NULL;
				return;
			}
			Node* t=head;
			tail->next=head->next;
			head=head->next;
			delete(t);
		}
	int front()
	{
		return head->data;
	}
	void print()
		{
		   	if(head==NULL)
			{
				return;
			}
			Node* t=head;
			do
			{
				cout<<t->data<<"->";
                t=t->next;
			}while(t!=head);
			
		}
	};
/*	int main()
	{
		QueueLinkedlist c=QueueLinkedlist();
		int m=1,n;
		while(m)
		{
		cout<<"\n1 to check empty"<<endl;	
		cout<<"2 to insert"<<endl;
		cout<<"3 to delete"<<endl;
		cout<<"4 to print"<<endl;
		cout<<"0 to close"<<endl;
		cin>>m;
		system("CLS");
		switch(m)
		{
			
			case 1:
				c.isempty();
				break;
			case 2:
				cout<<"Enter value-";
				cin>> n;
				c.insert(n);
				break;
			case 3:
			    c.delete_();
				break;
			case 4:
				c.print();
				break;
			case 0:
				cout<<"Closing"<<endl;
				break;
			default:
				cout<<"Choice is wrong"<<endl;
				break;
		
		}
	}
	return 0;
}
*/	
