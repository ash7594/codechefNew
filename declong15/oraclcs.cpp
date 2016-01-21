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
	int a,b,tota = 200,totb = 200;
	while (t--) {
		tota = totb = 200;
		int n = read();
		while (n--) {
			a = b = 0;
			string s;
			cin>>s;
			for (int i=0;i<s.length();i++) {
				if (s[i] == 'a') a++;
				else b++;
			}
			tota = minf(a,tota);
			totb = minf(b,totb);
		}
		printf("%d\n",minf(tota,totb));
	}
	return 0;
}
