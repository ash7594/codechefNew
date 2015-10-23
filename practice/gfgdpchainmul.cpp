#include<bits/stdc++.h>
#define gc getchar_unlocked
#define REP(a,b,c) for(int a=b;a<c;a++)
#define maxf(a,b) ((a>b)?a:b)
#define minf(a,b) ((a<b)?a:b)
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

vector<int> a;
int dp[100][100];

int prod(int i,int j) {
	if (i+1 == j) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	dp[i][j] = INT_MAX;
	for (int k = i+1;k<j;k++) {
		dp[i][j] = minf(dp[i][j], prod(i,k)+prod(k,j)+a[i]*a[k]*a[j]);
	}
	return dp[i][j];
}

int main() {
	int n = read();
	fill(&dp[0][0],&dp[99][99],-1);
	//vector<int> a;
	copy_n(istream_iterator<int>(cin),n+1,back_inserter(a));

	//vector<vector<int> > p(n+1,vector<int>(n+1,0));
	cout<<prod(0,n)<<endl;
}

