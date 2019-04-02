#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int>a(n);
	a.resize(n);
	for(int i=0;i<n;i++)cin>>a[i];
	int f=0;
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
	}
	return 0;
}