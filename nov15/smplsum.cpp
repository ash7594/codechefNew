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

vector<int> factors(10000001,0);
vector<int> table(10000001,0);
vector<long long> preval(10000001,0);

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

inline void write(long long x){

         register char buffor[35];
         register long long i=0;
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
	int N = 10000000;
	int n = sqrt(10000000);
	long long x,sq;
	for (int i=2;i<=n;i++) {
		if (table[i] != 0) continue;
		factors[i] = i;
		preval[i] = i*(i-1)+1;
		for (int j=i*i;j<=N;j+=i) {
			if (factors[j] == 0) factors[j] = i;
			table[j] = 1;
			//factors[j].push_back(i);
		}
		x = preval[i];
		sq = i*i;
		for (long long j=i*i;j<=N;j*=i) {
			table[j] = 2;
			preval[j] = sq*x-i+1;
			x = preval[j];
		}
	}
//	for (int i=2;i<=N;i++) {
//		if (table[i] == 0) cout<<i<<endl;
//	}
}

int main() {
	init();
	long long t = read(),n,ans,a,count;
	long long inp = 1;
	while(t--) {
		n = read();
		
		if (n == 1) {
			write(1);
		} else if (table[n] == 0 || table[n] == 2) {
			write(preval[n]);
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
				ans *= preval[(long long)(count/n)];
			}
			write(ans);
		}
	}
	return 0;
}
