#include<bits/stdc++.h>
#include<ext/rope>
#define gc getchar_unlocked
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

int main() {
	int n,q,t,l,r;
	n = read();
	q = read();

	rope<int> a;
	REP(i,0,n) {
		a.push_back(read());
	}

	while(q--) {
		t = read();
		l = read();
		r = read();
		l--;
		r--;
		rope<int> b = a.substr(l,r-l+1);
		a.erase(l,r-l+1);
		if (t==1) {
			a.insert(a.mutable_begin(),b);
		} else {
			a.insert(a.mutable_end(),b);
		}
		//copy(a.mutable_begin(),a.mutable_end(),ostream_iterator<int>(cout," "));
		//nl;
	}
	copy(a.mutable_begin(),a.mutable_end(),ostream_iterator<int>(cout," "));
	nl;
}
