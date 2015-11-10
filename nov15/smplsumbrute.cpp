#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b) {
	if (b==1) return 1;
	if (b==0) return a;
	return gcd(b,a%b);
}

int main() {
	long long n=100;
	long long ans = 0;
	for (long long j=1;j<=n;j++) {
	ans = 0;
	for(long long i=1;i<=j;i++) {
		ans += j/gcd(j,i);
		//cout<<gcd(j,i)<<" ";
	}
	cout<<j<<" -> "<<ans<<endl;
	//cout<<endl;
	}
}
