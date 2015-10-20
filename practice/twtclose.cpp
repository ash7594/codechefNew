#include<bits/stdc++.h>
#define gc getchar_unlocked
#define REP(a,b,c) for(int a=b;a<c;a++)
#define maxf(a,b) ((a>b)?a:b)
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
	int n,k;
	n = read();
	k = read();
	string a;
	vector<int> maper(n+1,0);
	int b;
	int ans = 0;
	REP(i,0,k) {
		cin>>a;
		if (a == "CLOSEALL") {
			ans = 0;
			fill(maper.begin(),maper.end(),0);
		}
		else {
			cin>>b;
			maper[b] = (maper[b]+1)%2;
			if (maper[b] == 1) ans++;
			else ans--;
		}
		printf("%d\n",ans);
	}
	return 0;
}
