#include<bits/stdc++.h>
using namespace std;
vector<int>adj[1000];
vector<int>par;
int main(){
	int n,m;
	cin>>n>>m;
	par.resize(n+1);

	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		par[b]++;
	}
	vector<int>s;
	for(int i=1;i<=n;i++){
		if(par[i]==0){
			s.push_back(i);
		}
	}

	vector<int>S;
	int ans=0;
	while(!s.empty()){
		ans++;
		cout<<"Courses taken "<<ans<<" semester: ";
		for(auto g:s){
			cout<<g<<" ";
			for(auto G:adj[g]){
				par[G]--;
				if(par[G]==0){
					S.push_back(G);
				}
			}
		}
		cout<<"\n";
		s=S;
		S.clear();
	}
	cout<<"The total number of semesters is "<< ans<<"\n";
	return 0;
}