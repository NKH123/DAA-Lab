#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int,int> pi;
#define trace(x) cerr<<#x<<"="<<x<<"\n";
#define llp 1000000007
#define mod 1000000007

template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
	return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
	os << "{";
	typename vector< T > :: const_iterator it;
	for( it = v.begin(); it != v.end(); it++ ) {
		if( it != v.begin() ) os << ", ";
		os << *it;
	}
	return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
	os << "[";
	typename set< T > :: const_iterator it;
	for ( it = v.begin(); it != v.end(); it++ ) {
		if( it != v.begin() ) os << ", ";
		os << *it;
	}
	return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
	os << "[";
	typename map< F , S >::const_iterator it;
	for( it = v.begin(); it != v.end(); it++ ) {
		if( it != v.begin() ) os << ", ";
		os << it -> first << " = " << it -> second ;
	}
	return os << "]";
}

#define deb(x) cerr << #x << " = " << x << endl;
vector<int>a;
int cans;

void combine(int l,int mid,int r){
	cans=0;
	vector<int>b;
	int I=0;
	b.resize(mid-l+1+r-(mid+1)+1);
	int L=l; int R=mid+1;
	while(L<=mid and R<=r){
		if(a[L]<=a[R]){
			b[I]=a[L];
			L++;
			I++;
		}
		else{
			b[I]=a[R];
			R++;
			I++;
			cans+=(mid-L+1);
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
	if(l==r){
		return 0;
	}
	int mid=(l+r)/2;
	// trace(mid);
	int lans=solve(l,mid);
	int rans=solve(mid+1,r);
	combine(l,mid,r);
	return (lans+rans+cans);
}


int32_t main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		a.resize(n);
		for(int i=0;i<n;i++)cin>>a[i];
			int ans=solve(0,n-1);
		cout<<ans<<"\n";
	}



	return 0;
}
