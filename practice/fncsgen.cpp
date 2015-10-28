#include<bits/stdc++.h>
using namespace std;

int main () {
	srand(time(NULL));
	int n = 5;
	cout<<n<<endl;
	for (int i=0;i<n;i++) {
		cout<<rand()%100<<" ";
	}
	cout<<endl;
	for (int i=0;i<n;i++) {
		int l = rand()%n+1;
		int r = rand()%(n-l+1)+l;
		cout<<l<<" "<<r<<endl;
	}
	int q = n;
	cout<<q<<endl;
	for (int i=0;i<q;i++) {
		cout<<rand()%2+1<<" ";
		int l = rand()%n+1;
		int r = rand()%(n-l+1)+l;
		cout<<l<<" "<<r<<endl;
	}
}
