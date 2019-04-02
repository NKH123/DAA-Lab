#include<bits/stdc++.h>
#define trace(x) cout<<#x<<" = "<<x<<"\n"
using namespace std;
vector<int>a;

void combine(int l,int mid,int r){
	vector<int>b;
	int I=0;
	b.resize(mid-l+1+r-(mid+1)+1);
	int L=l; int R=mid+1;
	while(L<=mid and R<=r){
		if(a[L]<a[R]){
			b[I]=a[L];
			L++;
			I++;
		}
		else{
			b[I]=a[R];
			R++;
			I++;
		}
	}
	while(L<=mid){
		b[I]=a[L];
		I++;
		L++;
	}
	while(R<=r){
		b[I]=a[R];
		R++;
		I++;
	}
	for(int i=l;i<=r;i++){
		a[i]=b[i-l];
	}
}

int  solve(int l,int r){
	trace(l);
	trace(r);
	if(l==r){
		return 0;
	}
	int mid=(l+r)/2;
	trace(mid);
	int lans=solve(l,mid);
	int rans=solve(mid+1,r);
	int cans=0;
	trace(lans);
	trace(rans);
	int i;
	int f=0;
	for(i=0;i<=mid;i++){
		if(a[i]>a[mid+1]){
			f=1;
			break;
		}
	}
	if(f==1){
		cans=(mid-i+1)*(r-(mid+1)+1);
	}
	trace(cans);
	//combine
	combine(l,mid,r);
	trace(lans+rans+cans);

	return (lans+rans+cans);
}

int main(){
	int n;
	cin>>n;
	a.resize(n);
	for(int i=0;i<n;i++)cin>>a[i];
	int ans=solve(0,n-1);
	cout<<ans<<"\n";
	return 0;
}