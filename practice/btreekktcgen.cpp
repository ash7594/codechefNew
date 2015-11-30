#include<bits/stdc++.h>
using namespace std;

int main () {
	srand(time(NULL));
	int t = rand()%10+1;
	cout<<t<<endl;
	while(t--) {
		long long n = rand()%100+1;
		long long x = rand()%10;
		cout<<n<<" "<<x<<endl;
	}
	return 0;
}
