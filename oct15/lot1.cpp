#include<bits/stdc++.h>
using namespace std;

double f(double n, double k) {
	if (k==1) return n;
	return (f(n-1,k-1)*f(n,k-1))/(f(n,k-1)-f(n-1,k-1));
}

int gcd(int a, int b) {
	if (b == 0) return a;
	if (b == 1) return 1;
	return gcd(b,a%b);
}

int main () {
	int t,n,k;
	cin>>t;
	//cout<<k<<endl;
	//while (t--) {
		//cin>>n>>k;
		for (double j=1;j<=15;j++) {
			for (double i=1;i<=j;i++) {
				cout<<f(j,i)<<" ";
			}
			cout<<endl;
		}
	//}
	return 0;
}
