#include<bits/stdc++.h>
using namespace std;
#define nl cout<<endl

bool comp (const int &a, const int &b) { return a>b; }

bool operator < (const int &a, const int &b) {
	return a<b;
}

int main () {
	int a[] = {1,5,7,2,4,1,7};
	vector<int> v(a,a+7);
	copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
	nl;
	sort(v.begin(), v.end());
	copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
	nl;	
	return 0;
}
