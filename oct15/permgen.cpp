#include<bits/stdc++.h>
using namespace std;

int a[100000];

int main() {
	int k = 3, t;
	int n[] = {1,2,3,4};
	
	for (int l=0;l<100;l++) {
		t = n[2];
		n[2] = n[1];
		n[1] = n[0];
		n[0] = t;
		for (int i=0;i<3;i++) {
			if (i != 0) {
				t = n[3];
	        	n[3] = n[2];
	        	n[2] = n[1];
				n[1] = t;
			}
			t = 0;
			for (int j=0;j<4;j++) {
				t = (t*10)+n[j];
			}
			if (a[t] == 0) {
				cout<<t<<endl;
				a[t] = 1;
			}
		}
	}
	return 0;
}
