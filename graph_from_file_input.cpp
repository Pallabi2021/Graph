#include<bits/stdc++.h>
#include "queue_using_linkedlist.cpp"
using namespace std;

class graph {
		int v;//no of vertex
		vector<char> vset;
		
		vector< vector<int> > a;//adjacency matrix
	public:
		graph(int n) { //no of vertex
			v=n;
		}
	/*	void add_vset() {

			for(int i=0; i<v; i++) {
				char t; //temporary character
				cin>>t;//inputting character t
				vset.push_back(t);//Inserting each character(vertex) in vset one by one
			}
		}*/
		void add_vertex_set(vector<char> vsett){
			for(int i=0;i<v;i++)
				vset.push_back(vsett[i]);
			
		}
	/*	void add_adj_mat() {
			for(int i=0; i<v; i++) {
				vector<int> t;//Rows of matrix
				for(int j=0; j<v; j++) {
					//Inputting data in each row of matrix
					int data;
					cin>>data;
					t.push_back(data);
					if(data!=0 && j>=i){
						char s=vset[i];
						char d=vset[j];
						int wt=data;
						edge e=edge(s,d,wt);
						eset.push_back(e);
					}
				}
				a.push_back(t);//Inserting the rows into the matrix
			}
		}*/
		void show_vertex() { //Printing each vertex
			for(int i=0; i<v; i++) {
				cout<<vset[i]<<" ";
			}
			/*for(auto e:eset)
				e.show();*/
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

		void add_mat(vector<vector<int>>ar)
		{
			for(int i=0;i<v;i++)
			{
				vector<int> t;
				for(int j=0; j<v; j++) 
				{
					t.push_back(ar[i][j]);
				}
				a.push_back(t);
			}
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
		void DFS(char f,/*vertex for which dfs to be done*/bool visit[]) //visit array
		{
			int pos;
			for(int i=0; i<v; i++) {
				if(vset[i]==f)//Linearly searching the vertex
					pos=i;

			}
			if(visit[pos]==true)//if already visited then breaks
				return;
			cout<<vset[pos]<<" ";//if not already visited then prints
			visit[pos]=true;//now when visited it stores 1

			for(int j=0; j<v; j++) {
				if(a[pos][j]!=0)
					DFS(vset[j],visit);//traverses each vertex for the ones connected to vertex it calls for dfs
			}
		}
		//method overloading
		void DFS(char f) {
			cout<<".......DFS........."<<endl;
			bool visit[v];
			for(int i=0; i<v; i++) {
				visit[i]==false;//initialising the array
			}
			DFS(f,visit);
			cout<<endl;
		}
		void BFS(char root) {
			cout<<"...........BFS.........."<<endl;
			int pos;
			vector<bool> visit(v,false);//creating vect of size v(no of vertices). initialising with false
			QueueLinkedlist q=QueueLinkedlist();
			for(int i=0; i<v; i++) {
				if(vset[i]==root)//Linearly searching for root
					pos=i;
			}
			q.push(pos);//in queue pushing index of root
			visit[pos]=true;//true as root inserted
			while(!q.isempty()) {//runs until queue empty
				int t=q.front();//front of queue
				cout<<vset[t]<<" ";//prints ele of vset which is front of queue
				for(int j=0; j<v; j++) {
					if(a[t][j] and !visit[j]) {//if for vset the ones which are 1 and not already visited
						q.push(j);//pushing index of vertices of those connected to concerned vertices to queue
						visit[j]=true;
					}
				}
				q.pop();
			}
			cout<<endl;
		}

	void DFS_itr(char root){
		int pos=find(root);
		vector<bool> visit(v,false);
		stack<int> st;
		visit[pos]=true;//in visit arr pos of root is true
		st.push(pos);//INDEX OF ROOT INSERTED IN STACK
		while(!st.empty()){//until stack empty
			cout<<vset[st.top()]<<" ";//top of stack printed
			pos=st.top();
			st.pop();
			for(int i=0;i<v;i++){//row for the corresponding ele
				if(a[pos][i]==1 and visit[i]==false){//if connected and not already visited
					st.push(i);//then pushed to stack
					visit[i]=true;
				}
			}
			
		}
		cout<<endl;
	}
};
graph read_file(){
	int n;
	fstream g;
	g.open("grapg_file.txt",ios::in);
	g>>n;//first line of file inputted in n //n=no of vertex
	graph A=graph(n);
	vector<char> k;
	for(int i=0;i<n;i++){
		char f;
		g>>f;
		k.push_back(f);//vset
	}
	A.add_vertex_set(k);//vset inputted in graph	
	//int **a=(int **)malloc(n*sizeof(int*));
	vector<vector<int > > a;//matrix
	for(int i=0;i<n;i++){//for each row
		//int *f=(int *)malloc(n*sizeof(int));
		vector<int> f;
		for(int j=0;j<n;j++){//inputting each ele in each row
			int t;
			g>>t;
			f.push_back(t);
		}
			
		a.push_back(f);//inputting row in matrix
	}

	A.add_mat(a);//inputting matrix in graph	
	return A;
}
int main(void) {
	graph G=read_file();
	
	G.show_vertex();
	system("color f4");
	G.print_adj_mat();
	//cout<<G.degree_of('B')<<endl;
	G.DFS('A');
	G.BFS('A');
	G.DFS_itr('A');

}