#include<bits/stdc++.h>
#define maxv 1000001
#define maxf(a,b) ((a>b)?a:b)
#define minf(a,b) ((a<b)?a:b)
using namespace std;

int t, n, h;

int main() {
	int a,b;
	cin>>t;
	long long memo[maxv];
	while (t--) {
		cin>>n>>h;

		for (int i=0;i<n;i++) {
			memo[i] = 0;
		}

		for (int i=0;i<n;i++) {
			cin>>a>>b;
			memo[a]++;
			if (b < (n-1)) {
				memo[b+1]--;
			}
		}
		
		for (int i=1;i<n;i++) {
			memo[i] += memo[i-1];
		}
		for (int i=0;i<n;i++) {
			memo[i] = n-memo[i];
		}
		
		long long count = 0, count2 = 0;
		for (int i=0;i<h;i++) {
			count += memo[i];
		}
		count2 = count;
		for (int i=h;i<n;i++) {
			count2 = count2+memo[i]-memo[i-h];
			count = minf(count, count2);
		}
		cout<<count<<endl;
	}
	return 0;
}
