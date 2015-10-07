#include<bits/stdc++.h>
#define gc getchar_unlocked
using namespace std;

int read_int() {
	  char c = gc();
	    while(c<'0' || c>'9') c = gc();
		  int ret = 0;
		  while(c>='0' && c<='9') {
			      ret = 10 * ret + c - 48;
				      c = gc();
					    }
		    return ret;
}

//vector<int> prime;
int table[5000001];

void init () {
	int root = 2236;
	for (int i=2;i<=root;i++) {
		if (table[i] == 1) continue;
		for (int j=i*2;j<=5000000;j+=i) {
			table[j] = 1;
		}
		//if ((i-1)%4 != 0) table[i] = 1;
	}

	//prime.push_back(2);
	for (int i=5;i<=5000000;i+=4) {
		if (table[i] == 0) {
			//if ((i-1)%4 == 0)
				for (int j=i;j<=5000000;j+=i) {
					table[j] = 2;
				}
		}
	}

//	int num1 = 0, num2 = 0;
//	for (int i=0;i<prime.size();i++) {
//		cout<<prime[i]<<endl;
//		num1++;
////		if (((prime[i]-1)%4) == 0) {
////			//cout<<prime[i]<<endl;
////			num2++;
////		}
//	}
	//cout<<prime.size()<<" "<<num1<<" "<<num2<<endl;
}

int main () {
	init();
	int t,n,n2,root,flag;
	t = read_int();
	while (t--) {
		n = read_int();
//		if (n == 1) {
//			printf("NO\n");
//			continue;
//		}
//		n2 = n;
//		flag = 0;
//		root = sqrt(n);
//		for (int i=2;i<=root;i++) {
//			if ((i-1)%4 == 0 && n2%i==0) {
//				flag = 1;
//				goto ans;
//			}
//
//			while (n2%i == 0) {
//				n2/=i;
//			}
//			root = sqrt(n2);
//		}
//		if ((n2-1)%4 == 0 && n2!=1) {
//			flag = 1;
//		}
//		ans:
		if (table[n] == 2) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
