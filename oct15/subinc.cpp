#include<bits/stdc++.h>
using namespace std;

int main () {
	long long t,n;
	long long l,u;
	long long ans;
	cin>>t;
	while(t--) {
		cin>>n;
		long long a[n];
		for (long long i=0;i<n;i++) {
			cin>>a[i];
		}
		l = 0;
		u = 0;
		ans = 0;
		for (long long i=1;i<n;i++) {
			if (a[i-1] > a[i]) {
				u = i-1;
				ans += (u+1-l)*(u+2-l)/2;
				l = i;
			}
		}
		u = n-1;
		ans += (u+1-l)*(u+2-l)/2;
		cout<<ans<<endl;
	}
	return 0;
}
