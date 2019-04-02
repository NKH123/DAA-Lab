#include<bits/stdc++.h>
#define trace(x) cout<<#x<<" = "<<x<<"\n"
using namespace std;
bool free(vector<bool>men){
	
	for(int i=0;i<men.size();i++){
		if(men[i]){
			
			return true;
		}
	}
	return false;
}
int main(){
	freopen("1.txt","r",stdin);
	int n;
	cin>>n;
	map<string,int>M;
	vector<int> men_pref[n];
	vector<int>women_pref[n];
	vector<int>women_inv_pref[n];
	vector<string>men(n);
	vector<string>women(n);
	vector<bool>men_free(n,true);
	vector<bool>women_free(n,true);

	vector<int>match(n,-1);
	vector<int>matchinv(n,-1);
	for(int i=0;i<n;i++){
		cin>>men[i];
		M[men[i]]=i;
	}
	for(int i=0;i<n;i++){
		cin>>women[i];
		M[women[i]]=i;
	}
	for(int i=0;i<n;i++){
		men_pref[i].resize(n);
		for(int j=0;j<n;j++){
			string s;
			cin>>s;
			men_pref[i][j]=M[s];
		}
	}
	for(int i=0;i<n;i++){
		women_pref[i].resize(n);
		women_inv_pref[i].resize(n);
		for(int j=0;j<n;j++){
			string s;
			cin>>s;
			women_pref[i][j]=M[s];
			women_inv_pref[i][M[s]]=j;
		}
	}
	while(1){
		int mani=-1;
		for(int i=0;i<men_free.size();i++){
			if(men_free[i]==true){
				mani=i;
				break;
			}
		}
	
		if(mani==-1){
			break;
		}
		for(int i=0;i<n;i++){
			
			if(women_free[men_pref[mani][i]]==true){
				match[mani]=men_pref[mani][i];
				matchinv[men_pref[mani][i]]=mani;
				men_free[mani]=false;
				women_free[men_pref[mani][i]]=false;
				
				break;
			}
			else{
				
				int cur_part=matchinv[men_pref[mani][i]];
				int a,b;
				
				/*for(int j=0;j<n;j++){
					if(women_pref[men_pref[mani][i]][j]==cur_part){
						b=j;
					}
					if(women_pref[men_pref[mani][i]][j]==mani){
						a=j;
					}
				}*/
				a=women_inv_pref[men_pref[mani][i]][mani];
				b=women_inv_pref[men_pref[mani][i]][cur_part];
				if(a<b){
					match[mani]=men_pref[mani][i];
					match[cur_part]=-1;
					matchinv[men_pref[mani][i]]=mani;
					men_free[cur_part]=true;
					men_free[mani]=false;
					break;
				}
			}
		}
	}

	for(int i=0;i<n;i++){
		cout<<men[i]<<" "<<women[match[i]]<<"\n";
	}

	return 0;
}