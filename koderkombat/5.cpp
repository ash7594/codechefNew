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
	int i;
	char s[2000];
	while(t--) {
		scanf("%s",s);
		vector<int> h(26,0);
		for(i=0;s[i]!='\0';i++) {
			h[s[i]-'a']++;
		}

		sort(h.begin(),h.end(),[](const int &a, const int &b){return a>b;});
		while (h.back() == 0) {
			h.pop_back();
		}

		long long ans = INT_MAX;
		REP(m,1,h.size()+1) {
			if (i%m==0) {
				long long te = i;
				REP(n,0,m) {
					te -= h[n];
				}
				//printf("%lld\n",te);
				ans = min(ans,te);
			}
		}
		printf("%lld\n",ans);	
	}
	return 0;
}
