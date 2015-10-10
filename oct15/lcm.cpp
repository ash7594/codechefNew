#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	if (b == 1) return 1;
	return gcd(b,a%b);
}

int main () {
	int a,b;
	int t;
	cin>>t;
	while (t--) {
	cin>>a>>b;
	cout<<a*b/gcd(a,b)<<endl;
	}
	return 0;
}
