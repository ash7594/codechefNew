#include<bits/stdc++.h>
#define MAXV 1000000007
#define modinv 500000004
using namespace std;

long long fact[100001];
long long fact2[100001];

void init() {
	fact[0] = 1;
	fact2[0] = 1;
	fact2[1] = 1;
	for (long long i=1;i<=100000;i++) {
		fact[i] = (i*fact[i-1])%MAXV;
	}
	//for (long long i=1;i<=100000;i++) {
	//	fact[i] = (i*fact[i-1])%2;
	//}
}

long long parity(long long arr[], long long n) {
	long long a = 0;
	for (long long i=0;i<n-1;i++) {
		for (long long j=i+1;j<n;j++) {
			if (arr[i] > arr[j]) a++;
		}
	}
	return a%2;
}

long long position(long long q[], long long n) {
	long long a = 0;
	long long temp;
	vector<int> v;
	for (long long i=0;i<n;i++) {
		for (long long j=i;j<n;j++) {
			v.push_back(q[j]);
		}
		sort(v.begin(),v.end());
		//copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
		//cout<<endl;
		temp = ((find(v.begin(),v.end(),q[i])-v.begin())*fact[n-i-1])%MAXV;
		a = (a+temp)%MAXV;
		//cout<<a<<endl;
		v.erase(v.begin(),v.end());
	}
	return a;
}

int main () {
	init();
	long long t,n,k,p1,q1,a,temp;
	cin>>t;
	while (t--) {
		cin>>n>>k;
		a = 0;
		long long p[n],q[n];

		for (long long i=0;i<n;i++) {
			cin>>p[i];
		}

		for (long long i=0;i<n;i++) {
			cin>>q[i];
		}

		if (n == k) {
		for (long long i=0;i<n;i++) {
			if (p[i] == 1) p1 = i;
			if (q[i] == 1) q1 = i;
		}

		for (long long i=0;i<n;i++) {
			if (p[(i+p1)%n] != q[(i+q1)%n]) {
				cout<<"-1\n";
				goto end;
			}
		}
		cout<<q[0]<<endl;
		goto end;
		}

		if (k%2 == 0) {
			a = position(q,n);
			cout<<(a+1)%MAXV<<endl;
			goto end;
		} else {
			p1 = parity(p,n);
			q1 = parity(q,n);
			if (p1 != q1) {
				cout<<"-1\n";
				goto end;
			}
			a = position(q,n);
			if (q[n-2] > q[n-1]) { //even
				a--;
				if (a<0) a += MAXV;
			}

			a = (a*modinv)%MAXV;
			cout<<(a+1)%MAXV<<endl;
		}

		end:;
	}
	return 0;
}
