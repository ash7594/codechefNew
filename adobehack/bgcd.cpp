#include<bits/stdc++.h>
#include<ext/rope>
#define gc getchar_unlocked
#define REP(a,b,c) for(int a=b;a<c;a++)
#define maxf(a,b) ((a>b)?a:b)
#define minf(a,b) ((a<b)?a:b)
#define minf3(a,b,c) ((minf(a,b)<c)?minf(a,b):c)
#define maxf3(a,b,c) ((maxf(a,b)>c)?maxf(a,b):c)
#define nl cout<<endl
#define ull unsigned long long
#define MOD 1000000007
using namespace std;
using namespace __gnu_cxx;

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

inline void write(ull x){

         register char buffor[35];
         register int i=0;
         do{
               buffor[i++]=(x%10)+'0';
               x/=10;
            } while(x);
           i--;
            while(i>=0) putchar_unlocked(buffor[i--]);
            putchar_unlocked('\n');
       }

int main() {
	int n = read();
	vector<int> a(n);
	vector<long long> p(n+1);
	p[0] = 1;
	REP(i,1,n+1) {
		p[i] = (2*p[i-1])%MOD;
	}

	vector<int> b(n+1,0);
	vector<long long> gcd(n+1);

	REP(i,0,n) {
		a[i] = read();
		b[a[i]]++;
	}

	long long sum;
	REP(i,1,n+1) {
		sum = 0;
		for (int j=i;j<=n;j+=i) {
			sum += b[j];
		}
		gcd[i] = p[sum] - 1;
	}

	for(int i=n;i>=1;i--) {
		for (int j=2*i;j<=n;j+=i) {
			gcd[i] -= gcd[j];
			if (gcd[i] < 0) gcd[i] += MOD;
		}
	}

	REP(i,0,a.size()) {
		printf("%lld ",gcd[a[i]]);
	}
	nl;
	return 0;
}
