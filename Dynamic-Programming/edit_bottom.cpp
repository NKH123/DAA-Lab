#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
string x,y;
int main(){
		cin>>x>>y;
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<=x.size();i++){
			dp[i][0]=i;
		}
		for(int i=0;i<=y.size();i++){
			dp[0][i]=i;
		}
		for(int i=1;i<=x.size();i++){
			for(int j=1;j<=y.size();j++){
				dp[i][j]=dp[i-1][j-1];
				if(x[i-1]!=y[j-1]){
					dp[i][j]++;
				}
				dp[i][j]=min(dp[i][j],min(1+dp[i-1][j],1+dp[i][j-1]));
			}
		}
		cout<<dp[x.size()][y.size()]<<"\n";
	
	
	return 0;
}
