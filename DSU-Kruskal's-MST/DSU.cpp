#include<bits/stdc++.h>
using namespace std;

class DSU{
	private:
		vector<int>p,rank;int n;
	public:
		void makeSet(){
			cout<<"Enter n: ";
			cin>>n;
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
	DSU D;
	D.makeSet();
	D.unionSet(0,1);
	if(D.isSameSet(0,1)){
		cout<<"yes\n";
	}
	D.printSet();

	return 0;
}