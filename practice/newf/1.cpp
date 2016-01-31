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
#define MOD 1000000007
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
	long long ans;
	for (int j=1;j<=t;j++) {
		string s;
		ans = 1;
		cin>>s;

		if (s.size() == 1) printf("Case #%d: 1\n",j);
		else {
			for (int i=1;i<s.size()-1;i++) {
				if (s[i] != s[i-1] && s[i] != s[i+1] && s[i-1] != s[i+1]) {
					ans *= 3;
				   	ans %= MOD;	
				} else if (s[i] == s[i-1] && s[i] == s[i+1] && s[i-1] == s[i+1]) {
                } else {
					ans *= 2;
					ans %= MOD;
				}
			}
			if (s[0] != s[1]) {
				ans *= 2;
				ans %= MOD;
			}
			if (s[s.size()-1] != s[s.size()-2]) {
			 	ans *= 2;
	            ans %= MOD;
			}
			printf("Case #%d: %lld\n",j,ans);
		}
	}
	return 0;
}
