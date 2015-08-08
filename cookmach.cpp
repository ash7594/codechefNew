#include<bits/stdc++.h>
#define limit 25
using namespace std;

long long arr[limit];

int powertwo(long long a) {
	for (int i=0;a >= arr[i];i++) {
		if (a == arr[i])
			return i;
	}
	return -1;
}

int main() {
	long long num = 1;
	arr[0] = num;
	for (int i=1;i<limit;i++) {
		num = num << 1;
		arr[i] = num;
	}

	int t, indexa, indexb;
	long long a,b;
	cin>>t;
	while (t--) {
		cin>>a>>b;
		if (a == b) {
			cout<<"0\n";
			continue;
		}
		indexb = powertwo(b);
		if (indexa = (powertwo(a)+1)) {
			indexa--;
			cout<<abs(indexa - indexb)<<endl;
			continue;
		}
		int count = 0;
		int rem = 0;
		do {
			a = a >> 1;
			rem = powertwo(a);
			count++;
		} while (rem == -1);

		cout<<count + abs(rem - indexb)<<endl;
	}
	return 0;
}
