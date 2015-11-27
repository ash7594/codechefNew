#include<bits/stdc++.h>
#include<ext/rope>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define REP(a,b,c) for(int a=b;a<c;a++)
#define maxf(a,b) ((a>b)?a:b)
#define minf(a,b) ((a<b)?a:b)
#define minf3(a,b,c) ((minf(a,b)<c)?minf(a,b):c)
#define maxf3(a,b,c) ((maxf(a,b)>c)?maxf(a,b):c)
#define nl cout<<endl
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

inline void write(int x){

         register char buffor[35];
         register int i=0;
         do{
               buffor[i++]=(x%10)+'0';
               x/=10;
            } while(x);
           i--;
            while(i>=0) pc(buffor[i--]);
            pc('\n');
       }

int calcbit(int a) {
	int b = 0;
	while(a > 0) {
		b++;
		a = a>>1;
	}
	return b;
}

int main() {
	long long ans;
	int t = read();
	int maxv = -1,t1,t0;
	while(t--) {
		ans = 0;
		long long tot1;
		tot1 = 0;
		long long one, zero;
		one = zero = 0;
		int curb;
		int n = read();
		vector<int> a(n);
		REP(i,0,n) {
			a[i] = read();
			maxv = maxf(maxv,a[i]);
		}

		int nob = calcbit(maxv);
		int t3 = nob;
		while (t3--) {
			tot1 = 0;
			one = zero = 0;
			for (int i = 0; i<n; i++) {
				curb = a[i]%2;
				a[i] = a[i]>>1;
				if (curb == 1) {
					t0 = one;
					t1 = zero;
					t1++;
				} else {
					t0 = zero;
					t1 = one;
					t0++;
				}
				zero = t0;
				one = t1;
				tot1 += one;
			}
			//cout<<tot1<<endl;
			ans += tot1*pow(2,nob-t3-1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
