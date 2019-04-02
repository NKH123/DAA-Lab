#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100005];
vector<pair< int ,pair<int,int> > >Edges;
class DSU{
	private:
		vector<int>p,rank;int n;
	public:
		void makeSet(int pp){
			n=pp;
			cout<<"\n";
			rank.resize(n);
			p.resize(n);

	
			for(int i=0;i<n;i++){
				p[i]=i;
			}
		}
		int findSet(int pp){
			return p[pp]==pp?( pp):( p[pp]=findSet(p[pp]));
		}
		bool isSameSet(int i,int j){
			return findSet(i)==findSet(j);
		}
		void unionSet(int pp,int qq){
			if(isSameSet(pp,qq))return;

			int x=findSet(pp),y=findSet(qq);
			if(rank[x]>rank[y]){
				p[y]=x;
			}	
			else{
				p[x]=y;
				if(rank[x]==rank[y]){
					rank[y]++;
				}
			}	
		}
		void printSet(){
			vector<vector<int> >aaa;
			aaa.resize(n);
			for(int i=0;i<n;i++){
				int pp=findSet(i);
				aaa[pp].push_back(i);
			}
			for(int i=0;i<n;i++){
				if(aaa[i].size()!=0){
					cout<<"Elements in set "<<i<<"........... \n";
					for(auto g:aaa[i]){
						cout<<g<<" ";
					}
					cout<<"\n";
				}
			}
		}
};

int main(){
	cout<<"Enter number of nodes\n";
	int n,m;
	cin>>n;
	cout<<"Enter number of edges\n";
	cin>>m;

	cout<<"Enter edges with weights\n";
	for(int i=0;i<m;i++){
		int A,B,C;
		cin>>A>>B>>C;
		Edges.push_back({C,{A,B}});
	}
	sort(Edges.begin(),Edges.end());
	DSU D;
	D.makeSet(n);
	long long minCost=0;
	vector<pair< int ,pair<int,int> > >Edges1;
	for(auto g:Edges){
		int A=g.second.first;
		int B=g.second.second;
		int C=g.first;
		if(!D.isSameSet(A,B)){
			D.unionSet(A,B);
			minCost+=C;
			Edges1.push_back({C,{A,B}});
		}
	}
	cout<<"The graph has following edges\n";
	for(auto g:Edges1){
		cout<<g.second.first<<" ---- "<<g.second.second<<" with weight "<<g.first<<"\n";
	}

	cout<<"Minimum cost is " <<minCost<<"\n";

	return 0;
}