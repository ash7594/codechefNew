#include<bits/stdc++.h>
#define maxf(a,b) ((a>b)?a:b)
using namespace std;

int main() {
	int t,n,correct,ans,cash;
	cin>>t;
	while (t--) {
		cin>>n;
		char a[n];
		char b;
		correct = 0;
		for (int i=0;i<n;i++) {
			cin>>a[i];
		}
		for (int i=0;i<n;i++) {
			cin>>b;
			if (b == a[i]) {
				correct++;
			}
		}

		ans = -1;
		for (int i=0;i<=correct;i++) {
			cin>>cash;
			ans = maxf(ans, cash);
		}
		for (int i=correct+1;i<=n;i++) {
			cin>>cash;
		}
		cout<<ans<<endl;
	}
	return 0;
}
