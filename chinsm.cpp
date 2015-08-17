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

int main() {
	int n,m;
	n=read_int();
	m=read_int();
	int a[n];
	for (int i=0;i<n;i++) {
		a[i]=read_int();
	}

	long long count = 0;
	for (int i=0;i<n;i++) {
		for (int j=i;j<n;j++) {
			for (int k=i;k<j;k++) {
				if (a[k]%a[j]==m) {
					goto h;
				}
			}
			count++;
		}
		h:;
	}

	printf("%lld",count);
}
