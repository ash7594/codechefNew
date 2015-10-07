#include<bits/stdc++.h>
using namespace std;

int a[1000000001];

int main () {
	for (int i=2;i<=31622;i++) {
		if (a[i] == 1) continue;
		for (int j=i*2;j<=1000000000;j+=i) {
			a[j] = 1;
		}
	}
	return 0;
}
