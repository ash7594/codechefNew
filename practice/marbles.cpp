#include<bits/stdc++.h>
#define gc getchar_unlocked
#define REP(a,b,c) for(unsigned long long a=b;a<c;a++)
#define maxf(a,b) ((a>b)?a:b)
#define minf(a,b) ((a<b)?a:b)
#define nl cout<<endl
using namespace std;

unsigned long long read() {
      char c = gc();
        while(c<'0' || c>'9') c = gc();
          unsigned long long ret = 0;
          while(c>='0' && c<='9') {
                  ret = 10 * ret + c - 48;
                      c = gc();
                        }
            return ret;
}

int main() {
	unsigned long long n,k,k2,t;
	unsigned long long ans = 1;
	t = read();
	while (t--) {
		n = read();
		k = read();
		n--;
		k--;
		k2 = n-k;
		ans = 1;
		if (n == k) ans = 1;
		else {
			k = minf(k,k2);
			for (unsigned long long i=n;i>(n-k);i--) {
				ans = ans*i/(n-i+1);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
