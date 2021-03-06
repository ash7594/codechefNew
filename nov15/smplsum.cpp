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

vector<long long> factors(10000001,0);
bitset<10000001> table;
vector<long long> preval(10000001,0);

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

inline void write(long long x){

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

void init() {
	//table[1][1] = 1;
	//cout<<"yo";
	long long N = 10000000;
	long long n = sqrt(10000000);
	long long x,sq,i;
	for (i=2;i<=n;i++) {
		if (table[i] != 0) continue;
		factors[i] = i;
		preval[i] = i*(i-1)+1;
		for (long long j=i*i;j<=N;j+=i) {
			if (factors[j] == 0) factors[j] = i;
			table.set(j);
			//factors[j].push_back(i);
		}
		x = preval[i];
		sq = i*i;
		for (long long j=i*i;j<=N;j*=i) {
			//table[j] = 2;
			preval[j] = sq*x-i+1;
			x = preval[j];
		}
	}

	for (;i<=N;i++) {
		if (table[i] != 0) continue;
		factors[i] = i;
		preval[i] = i*(i-1)+1;
	}
}

int main() {
	init();
	long long t = read(),n,ans,a,count;
	long long inp = 1;
	while(t--) {
		n = read();
		
		if (n == 1) {
			printf("1\n");
		} else if (preval[n] != 0) {
			//write(preval[n]);
			printf("%lld\n",preval[n]);
//		} else if (table[n] == 2) {
//			long long f = factors[n][0];
//			long long x = f*(f-1)+1;
//			write(f*f*x-f+1);
		} else {
			ans = 1;
			while(n>1) {
				a = factors[n];
				count = n;
				while(factors[n] == a) {
					n/=a;
				}
				ans *= preval[(count/n)];
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
