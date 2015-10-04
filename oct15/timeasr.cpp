#include<bits/stdc++.h>
#define e 0.008333333333333333
using namespace std;

void output(int i, int j) {
	if (i<10) {
		printf("0");
	}
	printf("%d:",i);
	if (j<10) {
		printf("0");
	}
	printf("%d\n",j);
}

int main () {
	int t;
	double a;
	double hr,mn;
	cin>>t;
	while (t--) {
		cin>>a;
		hr = 0;
		for (int i=0;i<12;i++) {
			for (int j=0;j<60;j++) {
				mn = j*6;
				if (abs(abs(hr-mn) - a) < e || abs(360 - abs(hr-mn) - a) < e) {
					output(i,j);
				}
				hr+=0.5;
			}
		}
	}
	return 0;
}
