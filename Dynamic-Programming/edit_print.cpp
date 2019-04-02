#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
string x,y;
vector<pair< pair<char, char >, int > >ans;
void find(int i, int j){
	if(i==0 || j==0){
		if(i>0){
			for(int I=i-1;I>=0;I--){
				ans.push_back({{x[I],'_'},1});
			}
		}
		else{

			for(int I=j-1;I>=0;I--){
				ans.push_back({{'_',y[I]},1});	
			}
		
		}
		return;
	}
	else{
		int A,B,C;
		int f=1;
		if(x[i-1]==y[j-1]){
			A=dp[i-1][j-1];
		}
		else{
			f=0;
			A=dp[i-1][j-1]+1;
		}
		B=1+dp[i-1][j];
		C=1+dp[i][j-1];
		if(A<=B && A<=C){
			if (f)
			ans.push_back({{x[i-1],y[j-1]},0});
			else{
				ans.push_back({{x[i-1],y[j-1]},1});
			}
			find(i-1,j-1);
		}
		else if(B<=C && B<=A){
			ans.push_back({{x[i-1],'_'},1});
			find(i-1,j);
		}
		else if(C<=A && C<=B){
			ans.push_back({{'_',y[j-1]},1});
			find(i,j-1);
		}
	}
}
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
	find(x.size(),y.size());
	for(int i=ans.size()-1;i>=0;i--){
		cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second<<"\n";
	}
	return 0;
	}