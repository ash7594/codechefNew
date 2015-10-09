#include<bits/stdc++.h>
#define gc getchar_unlocked
using namespace std;

char s[20001];

int hash[500][10][500];

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

int main () {
	for (int i=0;i<500;i++) {
		for (int j=0;j<10;j++) {
			for (int k=0;k<500;k++) {
				hash[i][j][k] = -1;
			}
		}
	}

	scanf("%s",s);
	int q,m,l;
	long long t,t1,t2;
	int mod;
	long long a,b;
	q = read_int();
	while (q--) {
		m = read_int();
		l = read_int();
		a = b = 0;
		int hash2[500] = {0};
		for (int i=0;s[i]!='\0';i++) {
			t = 0;
			for (int j=i;s[j]!='\0';j++) {
				t1 = t;
				t2 = int(s[j] - '0');
				b++;
				if (hash[t1][t2][m] == -1) {
					t = (10*t)%m + t2;
					t %= m;
					hash[t1][t2][m] = t;
				} else {
					a++;
					t = hash[t1][t2][m];
				}
				hash2[t]++;
			}
		}
		cout<<hash2[l]<<endl;
	}
	return 0;
}
