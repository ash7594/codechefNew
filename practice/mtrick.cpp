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

unsigned long long read() {
      char c = gc();
        while(c<'0' || c>'9') c = gc();
          unsigned long long ret = 0;
          while(c>='0' && c<='9') {
                  ret = 10 * ret + c - 48;
                      c = gc();
                        }
            return ret;
}

inline void write(unsigned long long x){

         register char buffor[35];
         register int i=0;
         do{
               buffor[i++]=(x%10)+'0';
               x/=10;
            } while(x);
           i--;
            while(i>=0) pc(buffor[i--]);
            //pc('\n');
       }

unsigned long long mul(unsigned long long k, unsigned long long b, unsigned long long c) {
	if (b == 1) return k;
	unsigned long long ans;
	if (b%2==0) {
		ans = mul(k,b/2,c);
	} else return (mul(k,b-1,c)+k)%c;
	return (ans+ans)%c;
}

int main() {
	int t = read();
	unsigned long long a,b,c;
	unsigned long long k,d,ans;
	int begin,end;
	while(t--) {
		int op = 1;
		int n = read();
		vector<unsigned long long> ar(n);
		char s[n];
		k = 1;
		d = 0;
		begin = 0;
		end = n-1;
		REP(i,0,n) {
			ar[i] = read();
		}

		a = read();
		b = read();
		c = read();
		scanf("%s",s);

		int t1,t2;
		for (int i=0,si=0;si<n;i+=op,si++) {
			if (s[si] == 'A') {
				d = (d+a)%c;
			} else if (s[si] == 'M') {
				k = mul(k,b,c);
				d = mul(d,b,c);
			} else if (s[si] == 'R') {
				if (op > 0) {
					i = end;
					end--;
				} else {
					i = begin;
					begin++;
				}
				op *= -1;
			}
			ans = (mul(ar[i],k,c)+d)%c;
			write(ans);
			pc(' ');
		}
		pc('\n');
	}
	return 0;
}
