#include<bits/stdc++.h>
using namespace std;

int main () {
	srand(time(NULL));
	int n = rand()%10+1;
	int m = rand()%10+1;
	int c = rand()%10+1;
	cout<<n<<" "<<m<<" "<<c<<"\n";
	for (int i=0;i<n;i++) {
		cout<<rand()%c + 1<<" ";
	}
	cout<<endl;
	for (int i=0;i<m;i++) {
		cout<<rand()%c + 1<<" ";
	}
	return 0;
}
