#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b) {
	if (b==1) return 1;
	if (b==0) return a;
	return gcd(b,a%b);
}

int main() {
	int n=20;
	int ans = 0;
	for (int j=1;j<=n;j++) {
	ans = 0;
	for(int i=1;i<=j;i++) {
		cout<<gcd(j,i)<<" ";
	}
	cout<<endl;
	}
}
