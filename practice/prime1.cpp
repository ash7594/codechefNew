#include<bits/stdc++.h>
#define gc getchar_unlocked
#define REP(a,b,c) for(int a=b;a<c;a++)
#define maxf(a,b) ((a>b)?a:b)
#define nl cout<<endl
#define maxv 1000000000
using namespace std;

int read() {
      char c = gc();
        while(c<'0' || c>'9') c = gc();
          int ret = 0;
          while(c>='0' && c<='9') {
                  ret = 10 * ret + c - 48;
                      c = gc();
                        }
            return ret;
}

vector<int> primes;
vector<int> sieve;

void init() {
	int r = sqrt(maxv);
	primes.resize(r+1);
	fill(primes.begin(),primes.end(),0);
	primes[0] = primes[1] = 1;
	REP(i,2,r+1) {
		if (primes[i] == 1) continue;
		sieve.push_back(i);
		for (int j=2*i;j<=r;j+=i) {
			primes[j] = 1;
		}
	}
}

int main() {
	init();
	int t;
	t = read();
	while(t--) {
		int m,n;
		m = read();
		n = read();
		vector<int> p(n-m+1);
		iota(p.begin(),p.end(),m);

		if (m==1) p[0] = 0;
		REP(i,0,sieve.size()) {
			int r = (m-1)/sieve[i] + 1;
			if (r == 1) r = 2;
			int s = r*sieve[i] - m;
			for (int j=s;j<p.size();j+=sieve[i]) {
				p[j] = 0;
			}
		}

		REP(i,0,p.size()) {
			if (p[i] != 0) printf("%d\n",p[i]);
		}
		printf("\n");
	}
	return 0;
}
