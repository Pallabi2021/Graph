#include<bits/stdc++.h>
#include "disjointset.cpp"
using namespace std;
class edge {

	public:
		char s;//source vertex
		char d;//destination vertex
		int w;//weight of edge
		edge(char a,char b,int wt) {
			s=a;
			d=b;
			w=wt;
		}
		void show() {
			cout<<s<<d<<"->"<<w<<endl;
		}
};
		bool comp(edge a, edge b){
			if(a.w<b.w) return true;
			return false;
		}
class graph {
		int v;//no of vertex
		vector<char> vset;
		vector<edge> eset;
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
		void add_vertex_set(vector<char> vsett){
			for(int i=0;i<v;i++)
				vset.push_back(vsett[i]);
			
		}
		void add_adj_mat() {
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
		}
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
		void show_eset(){
			for(int i=0;i<eset.size();i++)
				eset[i].show();
			cout<<endl;
		}
		void add_mat(vector<vector<int > >ar)
		{
			for(int i=0;i<v;i++)
			{
				vector<int> t;
				for(int j=0; j<v; j++){
					t.push_back(ar[i][j]);
					int data =ar[i][j];
					if(data!=0 && j>=i){
						char s=vset[i];
						char d=vset[j];
						int wt=data;
						edge e=edge(s,d,wt);
						eset.push_back(e);
					}
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
		graph kruskal()
		{
			sort(eset.begin(),eset.end(),comp);//sorting the edges acc to weight
			graph k=graph(v);//extra graph for kruskal
			k.add_vertex_set(vset);
			show_eset();
			vector<vector<int > >mat;//matrix that is to be stored in k graph
			for(int i=0;i<v;i++)
			{
				vector<int> t;
				for(int j=0;j<v;j++)
				{
					t.push_back(0);//initialissing the mat with 0
					
				}
				mat.push_back(t);
			}
			int ei=0,c=0;//index of edge set is ei and counter is c
			Disjointset ob=Disjointset(v);
			while(c!=v-1 )
			{
				if(c==0)//when no edge inserted
				{
					int i=find(eset[ei].s);//Returns index of source of the edge
					int j=find(eset[ei].d);//Returns index of destination
					int wt=eset[ei].w;
					mat[i][j]=wt;//Inserting the weight in matrix
					mat[j][i]=wt;
					ob.connect(i,j);//vertex of i and vertex of j connected
					c++;
				}
				else
				{
					int i=find(eset[ei].s);
					int j=find(eset[ei].d);
					int wt=eset[ei].w;
					if(!ob.isconnected(i,j)){
						mat[i][j]=wt;
						mat[j][i]=wt;
						ob.connect(i,j);
						c++;		
					}
					//	continue;

				}
				ei++;
			}
			k.add_mat(mat);//matrix stored in k graph
			return k;//returns graph
		}

};
int main(void) {
	graph G=graph(6);
	G.add_vset();
	G.add_adj_mat();
	system("pause");
	G.show_vertex();
	system("color f4");
	G.print_adj_mat();
	//cout<<G.degree_of('B')<<endl;
	//G.DFS('A');
	//G.BFS('A');
	G.show_eset();
	graph k=G.kruskal();
	k.show_vertex();
	k.print_adj_mat();
	k.show_eset();
}
