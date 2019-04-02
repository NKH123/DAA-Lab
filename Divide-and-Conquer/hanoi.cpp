#include<bits/stdc++.h>
using namespace std;

void print(int n,char from, char to){
	cout<<"Move disc "<<n<<" from "<<from<<" to "<<to<<"\n";
}
void solve(int n,char s,char t, char i){{
	if(n==1){
		print(n,s,t);
	}
	else{
		solve(n-1,s,i,t);
		print(n,s,t);
		solve(n-1,i,t,s);
	}
}

}
int main(){
	int n;
	cout<<"Enter number of disks: ";
	cin>>n;
	solve(n,'S','T','I');
	return 0;
}