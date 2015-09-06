#include<bits/stdc++.h>
using namespace std;

int main() {
	int t,n,b,size;
	long long count;
	cin>>t;
	while (t--) {
		cin>>n;
		size = n*n+1;
		int a[size][2];
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) {
				cin>>b;
				a[b][0] = i;
				a[b][1] = j;
			}
		}

		count = 0;
		for (int i=2;i<size;i++) {
			count += abs(a[i][0]-a[i-1][0])+abs(a[i][1]-a[i-1][1]);
		}
		cout<<count<<endl;
	}
	return 0;
}
