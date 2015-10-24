#include<bits/stdc++.h>
#define gc getchar_unlocked
#define REP(a,b,c) for(int a=b;a<c;a++)
#define maxf(a,b) ((a>b)?a:b)
#define minf(a,b) ((a<b)?a:b)
#define minf3(a,b,c) ((minf(a,b)<c)?minf(a,b):c)
#define maxf3(a,b,c) ((maxf(a,b)>c)?maxf(a,b):c)
#define nl cout<<endl
using namespace std;

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
	int t = read();
	int m,n;
	while(t--) {
		n = read();
		m = read();
		vector<int> a(n);
		REP(i,0,n) a[i] = read();

		long long sol = 0;
		REP(i,0,m) sol+=a[i];

		REP(i,m,n) {
			if (a[i]%2!=0) a[i]++;
			sol -= ceil(a[i]/2);
		}
		if (sol >= 0) {
		printf("VICTORY\n");
		} else {
		printf("DEFEAT\n");
		}
	}	
	return 0;
}
