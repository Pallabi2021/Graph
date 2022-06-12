#include "linkedlist.cpp"
class stack
{
	Linkedlist c=Linkedlist();
	int top;
	public:
	stack()
	{
		top=0;
	}

	void isEmpty()
	{
		if(top==0)
		cout<<"Empty"<<endl;
		else
		cout<<"Not Empty"<<endl;
	}
	void push(int n)
	{
		if(top==5){
			cout<<"overflow"<<endl;
			return;
		}
			
		c.insertNodeAtHead(n);
	}
	void pop()
	{
		if(top==0){
			cout<<"Underflow"<<endl;
			return;
		}
		top--;
		c.delNodeAtHead();
	}
	void display()
	{
		c.print();
	}
	
};
int main()
{
	stack c=stack();
	int m=1,n;
	while(m)
	{
	    cout<<"1 to check full"<<endl;
		cout<<"2 to check empty"<<endl;	
		cout<<"3 to push"<<endl;
		cout<<"4 to pop"<<endl;
		cout<<"5 to peek"<<endl;
		cout<<"6 to print"<<endl;
		cout<<"0 to close"<<endl;
		cin>>m;
		system("CLS");
		switch(m)
		{
			case 1:
				c.isFull();
				break;
			case 2:
				c.isEmpty();
				break;
			case 3:
				cout<<"Enter value-";
				cin>> n;
				c.push(n);
				break;
			case 4:
			    c.pop();
				break;
			case 5:
				c.peek();
				break;
			case 6:
				c.display();
				break;
			case 0:
				cout<<"Closing"<<endl;
				break;
			default:
				cout<<"Choice is wrong"<<endl;
			
		
		}
	}
 
}
