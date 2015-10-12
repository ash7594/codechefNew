#include<bits/stdc++.h>
using namespace std;

vector<int> hash(100001,0);

int gcd(int a, int b) {
    if (a < b) swap(a,b);
    if (b==0) return a;
    if (b == 1) return 1;
    return gcd(b,a%b);
}

int prod(vector<int> a, int n) {
	int val;
	//cout<<n<<endl;
	if (n == -1) return 1;
	if (hash[n] == 0) {
		val = prod(a,n-1);
		val = a[n]*val*gcd(a[n],val);
//		for (int i=0;i<n;i++)
//			val *= gcd(hash[i], a[n]);
//		for (int i=2;i<n;i++) {
//			val *= gcd(a[n],a[i]);
//		}

		

		hash[n] = val;
		cout<<hash[n]<<endl;
		return val;
	} else {
		return hash[n];
	}
}

int main () {
	int t, n;
	cin>>t;
	while (t--) {
		cin>>n;
		for (int i=0;i<hash.size();i++) hash[i] = 0;
		vector<int> a(n);
		for (int i=0;i<n;i++) {
			cin>>a[i];
		}
		cout<<prod(a,n-1)<<endl;
	}	
}
