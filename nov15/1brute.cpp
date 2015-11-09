#include<bits/stdc++.h>
using namespace std;

int main() {
	int n=100;
	for (int i=1;i<=n;i++) {
		for (int j=0;j<i;j++) {
			//cout<<"("<<i<<" "<<j<<") ";
			vector<int> a(i);
			iota(a.begin(),a.end(),1);
			a.erase(a.begin(),a.begin()+j);
			for (int k=1;k<=j;k++) {
				a.push_back(k);
			}
			//copy(a.begin(),a.end(),ostream_iterator<int>(cout," "));
			//cout<<endl;
			int count = 0;
			int m = 0;
			while(a[m] != -1) {
				int tem = a[m]-1;
				a[m] = -1;
				m = tem;
				count++;
			}
			if (count == i) cout<<"Yes\n";
			else cout<<"No "<<count<<endl;
		}
	}
}
