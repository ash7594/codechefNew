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

string a,b;

int dp[100][100];

int sol(int i,int j) {
	if (i == -1) return j+1;
	if (j == -1) return i+1;

	if (dp[i][j] != -1) return dp[i][j];

	if (a[i] == b[j]) {
		dp[i][j] = sol(i-1,j-1);
	} else {
		dp[i][j] = 1 + minf3(sol(i,j-1),sol(i-1,j),sol(i-1,j-1));
	}
	return dp[i][j];
}

int main() {
	fill(&dp[0][0],&dp[99][99],-1);
	cin>>a>>b;
	
	cout<<sol(a.size()-1,b.size()-1);
	nl;
	return 0;
}

