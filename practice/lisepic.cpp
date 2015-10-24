#include<bits/stdc++.h>
#define gc getchar_unlocked
#define REP(a,b,c) for(long long a=b;a<c;a++)
#define maxf(a,b) ((a>b)?a:b)
#define minf(a,b) ((a<b)?a:b)
#define minf3(a,b,c) ((minf(a,b)<c)?minf(a,b):c)
#define maxf3(a,b,c) ((maxf(a,b)>c)?maxf(a,b):c)
#define nl cout<<endl
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

int main() {
	long long t = read();
	long long maxv,minv;
	while(t--) {
		long long n = read();
		vector<long long> a(n);
		REP(i,0,n) a[i] = read();

		vector<long long> t;
		vector<long long>::iterator it;
		t.push_back(a[0]);
		maxv = a[0];
		minv = a[0];
		bool f = true;
		REP(i,1,n) {
			it = lower_bound(t.begin(),t.end(),a[i]);
			if (it == t.end()) {
				t.push_back(a[i]);
				maxv = a[i];
				if (f) {
					minv = t[0];
					f = false;
				}
			} else {
				*it = a[i];
			}
		}
		printf("%lld\n",maxv-minv);
	}
	return 0;
}
