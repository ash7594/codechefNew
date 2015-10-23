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

int sol(int i,int j,int k,vector<vector<int> > a) {
	if (i<0 || j<0) return 0;
	if (i==0 && j==0 && k==a[i][j]) return 1;
	int ways = sol(i,j-1,k-a[i][j],a) + sol(i-1,j,k-a[i][j],a);
	return ways;
}

int main() {
	int m = read();
	int n = read();
	int k = read();
	vector<vector<int> > a(m,vector<int>(n));

	REP(i,0,m)
		REP(j,0,n)
			a[i][j] = read();

	cout<<sol(m-1,n-1,k,a)<<endl;
}
