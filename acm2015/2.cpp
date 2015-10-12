#include<bits/stdc++.h>
using namespace std;

int main () {
	int n,q;
	double k;
	long long sum = 0;
	cin>>n;
	vector<int> a(n);
	for (int i=0;i<n;i++) {
		cin>>a[i];
	}
	sort(a.begin(), a.end());
	for (int i=1;i<a.size();i++) {
		a[i] += a[i-1];
	}

	cin>>q;
	while (q--) {
		cin>>k;
		sum = 0;
		int temp = ceil(a.size()/(1+k));
//		for (int i=0;i<temp;i++) {
//			sum += a[i];
//		}
		sum = a[temp-1];
		printf("%lld\n",sum);
	}
	return 0;
}
