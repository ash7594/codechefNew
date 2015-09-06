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

int main () {
	int t,m;
	int n,ans;
	t = read_int();
	while (t--) {
		n = read_int();
		m = read_int();
		int a[m];
		for (int i=0;i<m;i++) {
			a[i] = read_int();
		}

		sort(a,a+m);
		int temp = m-1;
		ans = m-1;
		for (int i=0;i<m;i++) {
			if (a[i] < temp) {
				temp-=(a[i]+1);
				ans--;
			} else {
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
