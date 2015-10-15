#include<bits/stdc++.h>
#define maxf(a,b) ((a>b)?a:b)
using namespace std;

int main () {
	long long t,temp;
	cin>>t;
	while(t--) {
		long long n,k;
		cin>>n>>k;
		vector<long long> a(n), b(n);

		for (long long i=0;i<n;i++) {
			cin>>a[i];
		}
		
		for (long long i=0;i<n;i++) {
			cin>>b[i];
		}
		temp = -1;
		for (long long i=0;i<n;i++) {
			temp = maxf(temp,k/a[i]*b[i]);
		}
		cout<<temp<<endl;
	}
	return 0;
}
