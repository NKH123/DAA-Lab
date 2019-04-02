#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	unordered_map<int,int>m;
	for(auto g:a){
		m[g]++;
	}
	int f=0;
	int ans;
	for(auto g:m){
		if(g.second>(n/2)){
			f=1;
			ans=g.first;
		}
	}
	if(f==1){
		cout<<"The majority is "<<ans<<" it occurs "<<m[ans]<<" times.\n";
	}
	else{
		cout<<"No majority\n";
	}
	return 0;
}
