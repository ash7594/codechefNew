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
	while(t--) {
		string s;
		cin>>s;
		vector<int> h(26,0);
		REP(i,0,s.length()) {
			h[s[i]-'A']++;
		}
		if (h['L'-'A']>1 && h['T'-'A']>1 && h['I'-'A']>1 && h['M'-'A']>1) {
			if (h['E'-'A'] > 1 || (h['E'-'A']>0 && s.length()==9)) {
				printf("YES\n");
			} else printf("NO\n");
		} else printf("NO\n");
	}
	return 0;
}
