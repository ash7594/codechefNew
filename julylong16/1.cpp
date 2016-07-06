#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
		int N;
		cin>>N;
		vector<float> a(N);
		for (int i=0;i<N;i++)
			cin>>a[i];
		float sum = 0, avg;
		bool check2 = false, done = false;
		for_each(a.begin(), a.end(), [&](int v) {
			if (done) return;
			if (v == 2) {
				cout<<"No\n";
				check2 = false;
				done = true;
			} else if (v == 5) {
				check2 = true;
			}
			sum += v;
		});
		if (check2) {
			avg = sum/N;
			if (avg >= 4) cout<<"Yes\n";
			else cout<<"No\n";
		} else cout<<"No\n";
	}
	return 0;
}
