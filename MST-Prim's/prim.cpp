#include<bits/stdc++.h>
using namespace std;
bool taken[100005];
vector<pair<int,int> > adj[100005];
priority_queue<pair<int,int> >pq;
void process(int vtx){
	taken[vtx]=true;
	for(auto g:adj[vtx]){
		if(!taken[g.first]){
			pq.push_back(-g.first,-g.second);
		}
	}
}
int main(){
	cout<<"Enter number of vertices: \n";
	int n;
	cin>>n;
	memset(taken,false,sizeof(taken));
	cout<<"Enter number of edges: \n";
	int m;
	cin>>m;
	cout<<"Enter edges: \n";
	for(int i=0;i<m;i++){
		int A,B,C;
		cin>>A>>B>>C;
		adj[A].push_back({B,C});
		adj[B].push_back({A,C});
	}	
	process(0);
	int take=1;
	while(take<=n){
		auto gg=pq.top();
		pq.pop();
		taken[-gg.first]=true;
		take++;
	}

	return 0;
}