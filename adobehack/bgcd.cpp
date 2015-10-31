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

long long power(int a) {
	if (a == 1) return 2;
	if (a%2 == 1) {
		return 2*power(a-1);
	} else {
		return power(a/2)*power(a/2);
	}
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

	REP(i,0,n) {
		a[i] = read();
	}

	long long ans,count,count2;
	REP(i,0,n) {
		count = 0;
		count2 = 0;
		if (b[a[i]] != 0) {
			printf("%d ",b[a[i]]);
			continue;
		}

		REP(j,0,n) {
			if (a[j]%a[i] == 0) count++;
			if (a[j] == a[i]) count2++;
		}
		count--;
		count2--;
		
		ans = p[count--];
		REP(j,0,count2) {
			ans = (ans + p[count--])%MOD;
		}

		b[a[i]] =  ans;
		printf("%lld ",ans);
	}
	return 0;
}
