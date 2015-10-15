#include<bits/stdc++.h>
#define inp(b,a,c) cin>>a;b+=a;((a==0)?c+=1:c+=0)
using namespace std;

int main() {
	int t,a,c;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int b = 0;
		c=0;
		for (int i=0;i<n;i++) {
			inp(b,a,c);
		}
		if (b>=100 && b<(100+n-c)) {
			cout<<"YES\n";
		} else {
			cout<<"NO\n";
		}
	}
	return 0;
}
