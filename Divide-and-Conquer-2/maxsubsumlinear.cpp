#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> a;
	a.resize(n);
	for(int i=0;i<n;i++)cin>>a[i];
	vector<int>b(n);
	b[0]=a[0];
	int Max=-1;
	int I,J;

	for(int i=1;i<(n);i++){
		if((b[i-1]+a[i])>=a[i]){
			b[i]=b[i-1]+a[i];
			
		}
		else{
			b[i]=a[i];
		}
		//Max=max(Max,b[i]);
		if(Max<b[i]){
			J=i;
			Max=b[i];
		}
	}
	int sum=0;
	for(int i=J;i>=0;i--){
		sum+=a[i];
		if(sum==b[J]){
			I=i;
			break;
		}
	}
	cout<<"The max sub sum is "<<b[J]<<" at ("<<I<<","<<J<<")\n";

	
	return 0;
}