#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (a < b) swap(a,b);
	if (b==0) return a;
	if (b == 1) return 1;
	return gcd(b,a%b);
}

int gcdarr(vector<int> a) {
	if (a.size() == 0) return 1;
	int curgcd = a[0];
	for (int i=1;i<a.size();i++) {
		curgcd = gcd(curgcd, a[i]);
	}
	return curgcd;
}

void powerset(vector<int> a, vector<int> b, int c) {
	if (c == a.size()) {
		cout<<gcdarr(b)<<endl;
		return;
	}

	powerset(a,b,c+1);
	b.push_back(a[c]);
	powerset(a,b,c+1);
}

int main () {
	int n;
	cin>>n;
	vector<int> a(n);
	vector<int> b;
	for (int i=0;i<n;i++) {
		cin>>a[i];
	}

	powerset(a,b,0);
	return 0;
}
