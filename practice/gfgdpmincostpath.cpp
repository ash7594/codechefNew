#include<bits/stdc++.h>
#define gc getchar_unlocked
#define REP(a,b,c) for(int a=b;a<c;a++)
#define maxf(a,b) ((a>b)?a:b)
#define minf(a,b) ((a<b)?a:b)
#define minf3(a,b,c) ((minf(a,b)<c)?minf(a,b):c)
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
	int m,n;
	m = read();
	n = read();

	vector<vector<int> > cost(m,vector<int>(n));
	
	REP(i,0,m) {
		REP(j,0,n) {
			cost[i][j] = read();
		}
	}

	REP(i,1,m) {
		cost[i][0] += cost[i-1][0];
	}

	REP(i,1,n) {
		cost[0][i] += cost[0][i-1];
	}

	for(int i=1;i<m;i++) {
		for(int j=1;j<n;j++) {
			cost[i][j] += minf3(cost[i-1][j],cost[i][j-1],cost[i-1][j-1]);
		}
	}
	cout<<cost[m-1][n-1]<<endl;
}
