#include<bits/stdc++.h>
using namespace std;

int main() {
	long long t, n;
	long long table[90];
	table[1] = 1;
	table[2] = 2;
	for (int i=3;i<90;i++) {
		table[i] = table[i-1] + table[i-2];
	}
	cin>>t;
	while (t--) {
		cin>>n;
		for (int i=1;i<90;i++) {
			if (n == table[i]) {
				cout<<i<<endl;
				break;
			} else if (n < table[i]) {
				cout<<i-1<<endl;
				break;
			}
		}
	}
	return 0;
}
