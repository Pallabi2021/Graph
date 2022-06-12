#include<iostream>
#include<stdlib.h>
using namespace std;
class Disjointset{
	int *arr;
	int n;
	public:
		Disjointset(int size)
		{
			n=size;
			arr=(int*)malloc(sizeof(int));
			for(int i=0;i<n;i++)
				arr[i]=i;//Storing index in index position
			
		}
		void connect(int a,int b)
		{
			arr[b]=a;// if connect(1,2) then parent of 2 is 1
		}
		int find(int b)
		{
			if(arr[b]==b)
				return b;//Returning the root
			return find(arr[b]);//Recursively finding root
		}
		bool isconnected(int a, int b)
		{
			return find (a)==find(b); //If a and b's root equal then connected
		}
	};
	/*
int main(void)
{
	int size;
	cin>>size;
	Disjointset obj=Disjointset(size);
	obj.connect(1,2);
	obj.connect(2,3);
	cout<<obj.isconnected(1,3);
}*/