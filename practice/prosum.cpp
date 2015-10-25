#include<bits/stdc++.h>
#define gc getchar_unlocked
#define REP(a,b,c) for(long long a=b;a<c;a++)
#define maxf(a,b) ((a>b)?a:b)
#define minf(a,b) ((a<b)?a:b)
#define minf3(a,b,c) ((minf(a,b)<c)?minf(a,b):c)
#define maxf3(a,b,c) ((maxf(a,b)>c)?maxf(a,b):c)
#define nl cout<<endl
using namespace std;

long long read() {
      char c = gc();
        while(c<'0' || c>'9') c = gc();
          long long ret = 0;
          while(c>='0' && c<='9') {
                  ret = 10 * ret + c - 48;
                      c = gc();
                        }
            return ret;
}

int main() {
	long long t = read();
	while(t--) {
		long long n = read();
		vector<long long> a(n);
		REP(i,0,n) a[i] = read();

		long long ans = n*(n-1)/2, no2 = 0, nc = n;
		REP(i,0,n) {
			if (a[i]==1 || a[i]==0) {
				nc--;
				ans -= nc;
			} else if (a[i] == 2) {
				no2++;
			}
		}
		ans -= no2*(no2-1)/2;
		printf("%lld\n",ans);
	}
	return 0;
}
