#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
string x,y;
int edit(int i,int j){
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	if(i==0 || j==0){
		//if(i==0 && j==0)return dp[i][j]=0;
		return dp[i][j]=i+j;
	}
	else{
		dp[i][j]=x[i-1]==y[j-1]?edit(i-1,j-1):1+edit(i-1,j-1);
		dp[i][j]=min(dp[i][j],min(1+edit(i,j-1),1+edit(i-1,j)));
		return dp[i][j];
	}
}
int main(){
	
	cin>>x>>y;
	memset(dp,-1,sizeof(dp));
	cout<<edit(x.size(),y.size());

	return 0;
	}