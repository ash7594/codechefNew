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
	int n;
	n = read();
	vector<pair<int, int> > a(n);

	REP(i,0,n) {
		a[i].first = read();
	}

	sort(a.begin(),a.end(),[](const pair<int,int> &a, const pair<int,int> &b){return a.first>b.first;});
	REP(i,0,n) {
		int t = a[i].first;
		a[i].second = 0;
		while (t>0) {
			t >>= 1;
			a[i].second++;
		}
	}

	int nb = a[0].bi
	REP(i,0,n) {
		
	}

}
