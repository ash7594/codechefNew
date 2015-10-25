#include<bits/stdc++.h>
#define gc getchar_unlocked
#define REP(a,b,c) for(long long a=b;a<c;a++)
#define maxf(a,b) ((a>b)?a:b)
#define minf(a,b) ((a<b)?a:b)
#define minf3(a,b,c) ((minf(a,b)<c)?minf(a,b):c)
#define maxf3(a,b,c) ((maxf(a,b)>c)?maxf(a,b):c)
#define nl cout<<endl
#define MAXV 1000000007
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

vector<long long> p(2000000);
void init() {
	p[0] = 1;
	for (long long i=1;i<2000000;i++)
		p[i] = (23*p[i-1])%MAXV;
}

int main() {
	init();

	long long t = read();
	long long n,d,sq,sc,orem,temp,ans,siz,t2;
	while(t--) {
		n = read();
		d = read();
		vector<long long> s(2*n);
		sq = d*d;
		sc = 0;
		orem = 0;
		for (long long i=0;i<n;i++) {
			sc += sq;
			temp = sc + orem;
			s[i] += (temp%10);
			temp /= 10;
			orem = temp;
		}
		for (long long i=0;i<n-1;i++) {
			sc -= sq;
			temp = sc + orem;
            s[i+n] += (temp%10);
            temp /= 10;
            orem = temp;
		}
		if (orem != 0) {
			s[2*n-1] = orem;
		} else s.pop_back();
		//reverse(s.begin(),s.end());
		//copy(s.begin(),s.end(),ostream_iterator<long long>(cout));
		//nl;
		ans = 0;
		siz = s.size()-1;
		REP(i,0,s.size()) {
			t2 = (s[i]*p[siz-i])%MAXV;
			ans = (ans+t2)%MAXV;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
