#include<bits/stdc++.h>
#include<queue>
using namespace std;
class vertex
{	public:
	char v1;//name of vertex
	int sd;//distance frm source
	
		vertex(char v,int d)
		{
			v1=v;
			sd=d;
		}
		void show()
		{
			cout<<v1<<"-"<<sd<<endl;
		}
};
class graph {
		int v;//no of vertex
		vector<char> vset;
		vector< vector<int> > a;//adjacency matrix
	public:
		graph(int n) { //no of vertex
			v=n;
		}
		void add_vset() {

			for(int i=0; i<v; i++) {
				char t; //temporary character
				cin>>t;//inputting character t
				vset.push_back(t);//Inserting each character(vertex) in vset one by one
			}
		}
		void add_adj_mat() {
			for(int i=0; i<v; i++) {
				vector<int> t;//Rows of matrix
				for(int j=0; j<v; j++) {
					//Inputting data in each row of matrix
					int data;
					cin>>data;
					t.push_back(data);
				}
				a.push_back(t);//Inserting the rows into the matrix
			}
		}
		void show_vertex() { //Printing each vertex
			for(int i=0; i<v; i++) {
				cout<<vset[i]<<" ";
			}
			/*for(auto vertex: vset)
				cout<<vertex<<" ";*/
			cout<<endl;
		}
		void print_adj_mat() {
			for(int i=0; i<v; i++) {
				for(int j=0; j<v; j++) {
					cout<<a[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		int degree_of(char v1) {
			int pos,s=0;
			for(int i=0; i<v; i++) {
				if(vset[i]==v1)//Linearly searching the vertex
					pos=i;

			}
			for(int i=0; i<v; i++) {
				s=s+a[pos][i];//counting degree of the vertex
			}
			return s;
		}
		int find(char t)
		{
				int pos;
				for(int i=0; i<v; i++) {
				if(vset[i]==t)//Linearly searching
					pos=i;
			}
			return pos;
		}
		void print_path(vector<int> arr,int i)//parent array, index of the taken vertex
		{
			if(arr[i]==i)//if it is root prints it
			{
				cout<<vset[i];
				return;
			}
			//else finds parent of the vertex
			print_path(arr,arr[i]);
			cout<<"->"<<vset[i];
		}
		//using pair to return 2 values simultaneously. in one single entity storing 2 vectors
		pair<vector<vertex>,vector<int> > dijkstra(char s)//s=source vertex
		{
			vector<vertex> vwd;//returns vertex set and their shortest path
			int dist[v];
			bool p[v];//array to store permanent
			vector<int> par(v,0);//storing parent of all vertices
			for(int i=0;i<v;i++)
			{
				dist[i]=INT_MAX;//initialising the array with max value
				p[i]=false;
				par[i]=-1;
			}	
			int si=find(s);//index of source
			dist[si]=0;//storing source vertex in dist array as 0
			p[si]=true;//source vertex is permanent
			par[si]=si;//parent of source vertex is source itself
			int c=1;//counter
			vertex temp=vertex(s,0);
			vwd.push_back(temp);
			while(c<v)
			{
				for(int i=0;i<v;i++)//traversing to find the vertices attached with the current v ertex
				{
					if(dist[si]+a[si][i]<dist[i] and a[si][i]!=0)//if shortest path from source vertex less than value initialised
						{
						dist[i]=dist[si]+a[si][i];//shortest path updated
						par[i]=si;
						}
				}
				int min=INT_MAX,pos=0;
				for(int i=0;i<v;i++)
				{
					if(dist[i]<min and !p[i])//finding the min out of all the updated values of vertex in dist array
					{
						min=dist[i];
						pos=i;//index of the min
					
						//par[pos]=si;
					}										
				}
				vertex temp=vertex(vset[pos],min);//vset[pos]=vertex and min=its shortest path
				vwd.push_back(temp);
				//par[pos]=si;
				
				p[pos]=true;//the min is now permanent
				si=pos;//source vertex is now the min 
				c++;
			}
			pair<vector<vertex>,vector<int>> t;//t=pair
			t.first=vwd;//first ele of pair stores vwd and second stores par
			t.second=par;
			return t;
		}


};
int main(void) {
	graph G=graph(5);
	G.add_vset();
	G.add_adj_mat();
	system("pause");
	G.show_vertex();
	system("color f4");
	G.print_adj_mat();
	char ch;
	cout<<"Enter source:"<<endl;
	cin>>ch;
	pair<vector<vertex>,vector<int>> t=G.dijkstra(ch);
	vector<vertex> vwd=t.first;

	for(auto it:vwd){
		it.show();
		
		//cout<<endl;
	}
	vector<int> par=t.second;//parent array
	for(auto it:vwd){
		
		int i=G.find(it.v1);//index of each vertex
		G.print_path(par,i);//shortest path is being printed
		cout<<endl;
	}		
	
}
/*
S B C D E
7 0 0 2 0
0 0 1 2 0
0 0 0 0 4
0 3 8 0 5
0 0 5 0 0

*/