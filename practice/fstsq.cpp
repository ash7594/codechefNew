#include<bits/stdc++.h>
#define gc getchar_unlocked
#define REP(a,b,c) for(unsigned long long a=b;a<c;a++)
#define maxf(a,b) ((a>b)?a:b)
#define minf(a,b) ((a<b)?a:b)
#define minf3(a,b,c) ((minf(a,b)<c)?minf(a,b):c)
#define maxf3(a,b,c) ((maxf(a,b)>c)?maxf(a,b):c)
#define nl cout<<endl
#define MAXV 1000000007
using namespace std;

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

vector<unsigned long long> p(2000000);
void init() {
	p[0] = 1;
	for (unsigned long long i=1;i<2000000;i++)
		p[i] = (23*p[i-1])%MAXV;
}

int main() {
	init();

	unsigned long long t = read();
	unsigned long long n,d,sq,sc,orem,temp,ans,siz,t2;
	vector<unsigned long long> s(2000000);
	while(t--) {
		//fill(s.begin(),s.end(),0);
		n = read();
		d = read();
		sq = d*d;
		sc = 0;
		orem = 0;
		for (unsigned long long i=0;i<n;i++) {
			sc += sq;
			temp = sc + orem;
			s[i] = (temp%10);
			temp /= 10;
			orem = temp;
		}
		for (unsigned long long i=0;i<n-1;i++) {
			sc -= sq;
			temp = sc + orem;
            s[i+n] = (temp%10);
            temp /= 10;
            orem = temp;
		}
		if (orem != 0) {
			s[2*n-1] = orem;
			siz = 2*n-1;
		} else siz = 2*n-2;
		//reverse(s.begin(),s.end());
		//copy(s.begin(),s.end(),ostream_iterator<unsigned long long>(cout));
		//nl;
		ans = 0;
		//siz = s.size()-1;
		REP(i,0,siz+1) {
			t2 = (s[i]*p[siz-i]);
			ans = (ans+t2)%MAXV;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
