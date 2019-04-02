#include<bits/stdc++.h>
using namespace std;
vector<int>a;
int dp[100005];
int main(){
	int n;
	cin>>n;
	a.resize(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	memset(dp,-1,sizeof(dp));
	dp[0]=1;
	int ans=-1;
	for(int i=0;i<n;i++){
		dp[i]=1;
		for(int j=i-1;j>=0;j--){
			if(a[j]<a[i])
			dp[i]=max(dp[i],1+dp[j]);
		}
		ans=max(ans,dp[i]);
	}
	vector<int>LIS;
	int ini=ans;
	for(int i=n-1;i>=0;i--){
		if(dp[i]==ini){
			LIS.push_back(a[i]);
			ini--;
		}
	}
	for(int i=LIS.size()-1;i>=0;i--){
		cout<<LIS[i]<<" ";
	}
	cout<<"\n";
	return 0;
}