#include<bits/stdc++.h>
using namespace std;
int I,J;
vector<int> a;
//int sum;
vector<int>ret;
vector<int> landr(int l,int r){
	int sum=0;
	int mid=(l+r)/2;
	int maxsum=-(1<<26);
	int I,J;
	I=mid;
	for(int i=mid;i>=l;i--){
		sum+=a[i];
		if(maxsum<sum){
			maxsum=sum;
			I=i;
			J=mid;
		}
	}
	sum=0;
	int maxsumr=-(1<<26);
	for(int i=(mid+1);i<=r;i++){
		sum+=a[i];
		if(maxsumr<sum){
			maxsumr=sum;
			J=i;
		
		}
	}
	vector<int>New;
		New.push_back(maxsumr+maxsum);
		New.push_back(I);
		New.push_back(J);
		return New;
}
vector<int> fun(int l,int r){
	int mid=(l+r)/2;
	if(l>=r){
		vector<int>New;
		New.push_back(a[l]);
		New.push_back(l);
		New.push_back(r);
		return New;

	}
	vector<int> A=fun(l,mid);
	vector<int> B=fun(mid+1,r);
	vector<int> C=landr(l,r);
	if(A[0]<B[0]){
		A[0]=B[0];
		A[1]=B[1];
		A[2]=B[2];
	}
	if(A[0]<C[0]){
		A[0]=C[0];
		A[1]=C[1];
		A[2]=C[2];
	}
	return A;

}
int main(){
	int n;
	cin>>n;
	
	a.resize(n);
	for(int i=0;i<n;i++)cin>>a[i];
	vector<int>A=fun(0,n-1);
	
	cout<<"The max sub sum is "<<A[0]<<" at ("<<A[1]<<","<<A[2]<<")\n";

	
	return 0;
}