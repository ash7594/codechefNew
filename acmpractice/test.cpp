#include<bits/stdc++.h>
using namespace std;

int main () {
	srand(time(NULL));
	for (int i=0;i<20000;i++) {
		cout<<rand()%10;
	}
	cout<<endl;
	cout<<"5\n";
	int temp;
	for (int i=0;i<5;i++) {
		temp = rand()%499 + 1;
		cout<<temp<<" "<<rand()%temp<<endl;
	}
	return 0;
}
