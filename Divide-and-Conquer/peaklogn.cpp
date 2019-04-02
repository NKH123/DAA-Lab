#include<bits/stdc++.h>
#define trace(x) cout<<#x<<" = "<<x<<"\n"
using namespace std;
vector<int>a;
int f=0;
int solve(int l,int r){
	
	int mid=(l+r)/2;
	if(l>=r){
		return 0;
	}
	if(a[mid]>a[mid-1]&&a[mid]>a[mid+1]){
		f=1;
		return a[mid];
	}
	else if(a[mid]>a[mid-1] && a[mid]<a[mid-1]){
		return solve(mid,r);
	}
	else{
		return solve(l,mid);
	}
}
int main(){
	int n;
	cin>>n;
	
	a.resize(n);
	for(int i=0;i<n;i++)cin>>a[i];
	int ans=solve(0,a.size()-1);
	if(f!=0){
		cout<<"Peak is "<<ans<<"\n";
	}
	else{
		cout<<"No peak\n";
	}
	/*int f=0;
	int i;
	for( i=1;i<n-1;i++){
		if(a[i]>a[i-1]&&a[i]>a[i+1]){
			f=1;
			break;
		}
	}
	if(f==1){
		cout<<"Peak is "<<a[i]<<"\n";
	}
	else{
		cout<<"No peak\n";
	}*/
	return 0;
}