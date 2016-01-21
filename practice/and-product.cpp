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

vector<long long> precom(35,0);

void init() {
	precom[0] = 1;
	for (int i=1;i<precom.size();i++) {
		precom[i] = 2*precom[i-1];
	}
}

long long getPreVal(long long A) {
	int i=0;
	while (precom[i] <= A) {
		i++;
	}
	return precom[i-1];
}

int main() {
	init();
	long long ans;
	long long A,B,t;
	t = read();
	while (t--) {
		ans = 0;
		A = read();
		B = read();

		do {
		if (A == 0) {
			printf("%lld\n",ans);
			goto end;
		}
		long long preval = getPreVal(A);
		long long preval2 = getPreVal(B);
		if (preval != preval2) {
			printf("%lld\n",ans);
			goto end;
		}
		ans += preval;
		A = A - preval;
		B = B - preval2;
		} while (1);
		end:;
	}
	return 0;
}
