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
#define trace(x) cout<<#x<<"="<<x<<"\n";
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


struct FFT
{
    vector<complex<double> > org, res, tmp,e;
    int n;
    vector<complex<double> > compute_inverse( vector<complex<double> > x)
    {
        // x's length must be a power of 2
        org=x;
        n=x.size();
        res =vector<complex<double > > (n);
        tmp =vector<complex<double > > (n);
        e =vector<complex<double > > (n);
        for (int i=0;i<n;i++)
            e[i] = exp((2*M_PI*i*complex<double> (0,1))/(double)n);
        fft(n);
        for(int i=0;i<n;i++)
            res[i]/=n;
        return res;
    }
    vector<complex<double> > poly_mult(vector<complex<double> > u, vector<complex < double > > v)
    {
        int s = u.size()+v.size();
        u.resize(s);
        v.resize(s);
        while((((int)u.size())&((-(int)u.size()))) != (int)u.size())
        {
            u.push_back(0);
            v.push_back(0);
        }
        vector<complex<double> > dftu = compute(u), dftv = compute(v),res;
        for(int i=0;i<(int)dftu.size();i++)
            res.push_back(dftu[i]*dftv[i]);
        return compute_inverse(res);
    }
    vector<complex<double> > compute( vector<complex<double> > x)
    {
        // x's length must be a power of 2
        org=x;
        n=x.size();
        res =vector<complex<double > > (n);
        tmp =vector<complex<double > > (n);
        e =vector<complex<double > > (n);
        for (int i=0;i<n;i++)
            e[i] = exp(-(2*M_PI*i*complex<double> (0,1))/(double)n);
        fft(n);
        return res;
    }

    void fft(int l, int p=0,int s=1,int q=0)
    {
        if(l==1)
        {
            res[q]=org[p];
            return;
        }
        int pt = 0;
        fft(l/2,p,2*s,q);
        fft(l/2,p+s,2*s,q+l/2);
        for(int i=0;i<l/2;i++)
        {
            tmp[i] = res[q+i]+e[pt]*res[q+l/2+i];
            tmp[i+l/2] = res[q+i] - e[pt]*res[q+l/2+i];
            pt+=s;
            pt%=n;
        }
        for(int i=0;i<l;i++)
            res[q+i]=tmp[i];
    }
};


int32_t main(){
	ios::sync_with_stdio(false);
     int n;
    cout<<"Enter the number of intervals: ";
    cin>>n;
    vector<pair<int,int> >intervals;
    REP(i,0,n){
        int A,B;
        cin>>A>>B;
        intervals.push_back({A,B});
    }
    sort(intervals.begin(),intervals.end());
    //deb(intervals);
    vector<vector<pair<int,int>>>ss(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(ss[j].size()==0 || (ss[j][ss[j].size()-1].S)<=intervals[i].F){
                ss[j].PB({intervals[i].F,intervals[i].S});
                break;
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(ss[i].size()!=0)ans++;
        else break;
    }
    cout<<"Minimum number of resources: "<<ans<<"\n";
    for(int i=0;i<ans;i++){
        cout<<"Resource "<<i+1<<" jobs: ";
        for(auto g: ss[i]){
            cout<<"["<<g.F<<","<<g.S<<"] ";
        }
        cout<<"\n";
    }



	return 0;
}