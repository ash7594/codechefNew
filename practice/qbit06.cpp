#include<bits/stdc++.h>
#define gc getchar_unlocked
#define REP(a,b,c) for(long long a=b;a<c;a++)
#define maxf(a,b) ((a>b)?a:b)
#define minf(a,b) ((a<b)?a:b)
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
	long long t;
	t = read();
	while(t--) {
		vector<long long> c(3);
		REP(i,0,3) {
			c[i] = read();
		}
		
		sort(c.begin(),c.end());
		long long ans = c.front();
		c[1] -= ans;
		c[2] -= ans;

		c.erase(c.begin());

		while (c[0]!=0 && c[1]!=0 && c[1]>=2) {
			long long r = c[1]/2;
			r = minf(r,c[0]);
			ans += r;
			c[0] -= r;
			c[1] -= 2*r;
			sort(c.begin(),c.end());
		}
		printf("%lld\n",ans);
	}
	return 0;
}
