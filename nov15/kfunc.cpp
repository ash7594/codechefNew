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
#define write(a) printf("%lld\n",a)
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

inline void write2(long long x){

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

int main() {
	long long t = read();
	long long a,d,l,r,n,sum,ans;
	while (t--) {
		sum = 0;
		a = read();
		d = read();
		d%=9;
		l = read();
		r = read();
		long long L = (a+(l-1)*d)%9;
		if (L==0) L=9;
		long long N = r-l+1;
		if (d == 0) {
			ans = L*N;
		} else if (d == 3 || d==6) {
			n = 3;
			vector<long long> v;
			long long temp = L;
			v.push_back(temp);
			REP(i,0,2) {
				temp = (temp+d)%9;
				if (temp == 0) temp=9;
				v.push_back(temp);
			}
			sum = v[0]+v[1]+v[2];
			ans = sum*(N/n);
			temp = N%n;
			REP(i,0,temp) {
				ans += v[i];
			}
		} else {
			n = 9;
			vector<long long> v;
			long long temp = L;
			v.push_back(temp);
			REP(i,0,8) {
				temp = (temp+d)%9;
				if (temp == 0) temp=9;
				v.push_back(temp);
			}
			REP(i,0,9) {
				sum += v[i];
			}
			ans = sum*(N/n);
			temp = N%n;
			REP(i,0,temp) {
				ans += v[i];
			}
		}
		write(ans);
	}
	return 0;
}
