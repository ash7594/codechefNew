#include<bits/stdc++.h>
#define gc getchar_unlocked
#define REP(a,b,c) for(long long a=b;a<c;a++)
#define maxf(a,b) ((a>b)?a:b)
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
	long long t,n;
	t = 1;
	while(t--) {
		n = read();
		vector<long long> a(n);
		REP(i,0,n) {
			a[i] = read();
		}

		vector<pair<long long,long long> > sol(n);
		pair<long long,long long> maxv = make_pair(0,0);
		for (long long i=0;i<n;i++) {
			sol[i] = make_pair(1,0);
			for (long long j=i-1;j>=0;j--) {
				if (a[i] > a[j])
					if (sol[i].first < sol[j].first+1) {
						sol[i] = make_pair(sol[j].first+1,sol[j].second+a[i]-a[j]);
					}
			}
			if (sol[i].first > maxv.first || (sol[i].first == maxv.first && sol[i].second > maxv.second)) {
				maxv = sol[i];
			}
		}
		printf("%lld\n",maxv.first);
	}	
}
