#include<bits/stdc++.h>
#include<ext/rope>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define REP(a,b,c) for(long long a=b;a<c;a++)
#define maxf(a,b) ((a>b)?a:b)
#define minf(a,b) ((a<b)?a:b)
#define minf3(a,b,c) ((minf(a,b)<c)?minf(a,b):c)
#define maxf3(a,b,c) ((maxf(a,b)>c)?maxf(a,b):c)
#define nl cout<<endl
using namespace std;
using namespace __gnu_cxx;

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
	long long ans;
	while(t--) {
		long long n1 = read();
		long long n2 = read();
		long long m = read();
		m = m*(m+1)/2;
		if (minf(n1,n2) >= m) {
			ans = n1-m+n2-m;
		} else {
			ans = n1-minf(n1,n2)+n2-minf(n1,n2);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
