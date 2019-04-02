#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>val;
vector<int>w;
int dp[2000][2000];
int32_t main(){
	int t;
	cin>>t;
	while(t--){
		int n,W;
		cin>>n>>W;
		val.resize(n+1);
		w.resize(n+1);
		for(int i=1;i<=n;i++){
			cin>>val[i];
		}
		for(int i=1;i<=n;i++){
			cin>>w[i];
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=0;j<=W;j++){
				if(j>=w[i]){
					dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+val[i]);
				}
				else{
					dp[i][j]=dp[i-1][j];
				}
			}
		}
		int ans=-(1e18);
		cout<<dp[n][W]<<"\n";
	}
	return 0;
}