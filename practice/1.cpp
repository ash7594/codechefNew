#include<bits/stdc++.h>
using namespace std;

int main() {
	string a;
	cin>>a;
	for (int i=0;i<a.length();i++) {
		a[i] -= '0';
	}
	if (a[0] == 1) cout<<"yes";
	return 0;
}
