#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int> >adj[100005];
vector<int> dis;
vector<vector<int>  > P;

int main(){
	int n,m;
	cin>>n>>m;
	dis.resize(n,10000000);
	for(int i=0;i<m;i++){
		int A,B,W;
		cin>>A>>B>>W;
		adj[A].push_back({B,W});
	}
	cout<<"Enter source: ";
	int s;
	P.resize(n);
	cin>>s;
	dis[s]=0;
	for(int i=0;i<n;i++){
		P[i].push_back(dis[i]);
	}
	for(int k=0;k<n-1;k++){
		for(int i=0;i<n;i++){
			for(auto g:adj[i]){
				dis[g.first]=min(dis[g.first],dis[i]+g.second);
			}
		}
		for(int j=0;j<n;j++){
			P[j].push_back(dis[j]);
		}
		
	}
	cout<<"The distance table is \n";
	cout<<"...........................Iteration..............................\n";
	cout<<"Node ";
	for(int i=0;i<n;i++){
		cout<<i<<" ";
	}
	cout<<"\n";
	for(int i=0;i<n;i++){
		cout<<i<<"... ";
		for(int j=0;j<P[i].size();j++){
			cout<<P[i][j]<<" ";
		}
		cout<<"\n";
	}
	for(int i=0;i<n;i++){
			for(auto g:adj[i]){
				if(dis[g.first]<dis[i]+g.second){
					cout<<"Negative cycle exists\n";
					return 0;
				}
				//dis[g.first]=min(dis[g.first],dis[i]+g.second);
			}
		}
		cout<<"No negative cycle found\n";

	return 0;
}