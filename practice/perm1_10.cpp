#include<bits/stdc++.h>
using namespace std;

int main () {
	vector<int> a(10);
	iota(a.begin(),a.end(),1);
	cout<<"3628800\n";
	do {
		cout<<"10\n";
		copy(a.begin(),a.end(),ostream_iterator<int>(cout," "));
		cout<<endl;
	} while(next_permutation(a.begin(),a.end()));
	return 0;
}
