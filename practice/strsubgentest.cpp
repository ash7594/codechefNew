#include<bits/stdc++.h>
using namespace std;

int main() {
	srand(time(NULL));
	cout<<"1\n";
	int n = rand()%10000 + 1;
	int k = rand()%n + 1;
	int q = 10;
	cout<<n<<" "<<k<<" "<<q<<endl;
	for (int i=0;i<n;i++) {
		cout<<rand()%2;
	}
	cout<<endl;
	while(q--) {
		int a = rand()%n + 1;
		int b = a + rand()%(n-a+1);
		cout<<a<<" "<<b<<endl;
	}
}
