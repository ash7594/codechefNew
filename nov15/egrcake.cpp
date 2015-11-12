#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (b==1) return 1;
	if (b==0) return a;
	return gcd(b,a%b);
}

int main () {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n,m;
		scanf("%d",&n);
		scanf("%d",&m);
		int ans = gcd(n,m);
		if (ans == 1) printf("Yes\n");
		else printf("No %d\n",n/ans);
	}
	return 0;
}
