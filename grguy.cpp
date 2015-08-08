#include<bits/stdc++.h>
#define maxv 1000000
using namespace std;

int main() {
	int t, flag, firstlane;
	long long turn;
	cin>>t;
	char l1[maxv], l2[maxv];
	while (t--) {
		cin>>l1;
		cin>>l2;
		flag = 0;
		firstlane = -1;
		for (int i=0;l1[i] != '\0';i++) {
			if (l1[i] == '#' && l2[i] == '#') {
				cout<<"No\n";
				flag = 1;
				break;
			} else if (!(l1[i] == '.' && l2[i] == '.') && firstlane == -1) {
				if (l1[i] == '#') firstlane = 1;
				else firstlane = 0;
			}
		}
		if (flag == 1) continue;

		cout<<"Yes\n";
		turn = 0;
		for (int i=0;l1[i+1] != '\0';i++) {
			if (firstlane == 0 && l1[i+1] == '#') {
				turn++;
				firstlane = 1;
			} else if (firstlane == 1 && l2[i+1] == '#') {
				turn++;
				firstlane = 0;
			}
		}
		cout<<turn<<endl;
	}
	return 0;
}
