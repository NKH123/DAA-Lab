#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("1.txt","r",stdin);
	int n;
	cin>>n;
	map<string,int>M;
	vector<int> men_pref[n];
	vector<int>women_pref[n];
	vector<int>women_inv_pref[n];
	vector<int>men_inv_pref[n];
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
		men_inv_pref[i].resize(n);
		for(int j=0;j<n;j++){
			string s;
			cin>>s;
			men_pref[i][j]=M[s];
			men_inv_pref[i][M[s]]=j;
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
	vector<int>a;
	for(int i=0;i<n;i++){
		a.push_back(i);
	}
	do{
		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		cout<<"\n";
		int f=1;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				//if(j==i)break;
				/*if(women_inv_pref[a[j]][i]<women_inv_pref[a[j]][j]){
					f=0;
				}*/
				if(men_inv_pref[i][a[i]]>men_inv_pref[i][a[j]] && women_inv_pref[a[j]][i]<women_inv_pref[a[j]][j]){
					f=0;
				}
			}
		}
		if(f==1){
			cout<<"Answer.........\n";
			for(int i=0;i<n;i++){
				cout<<men[i]<<" "<<women[a[i]]<<"\n";

			}
			cout<<"\n\n\n";
		}

	}while(next_permutation(a.begin(),a.end()));
	return 0;
}