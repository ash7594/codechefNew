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
	int n = read();
	vector<int> a;
	a.push_back(0);
	copy_n(istream_iterator<int>(cin),n,back_inserter(a));
	sort(a.begin(),a.end());
	int sum = read();

	vector<vector<int> > sol(n+1,vector<int>(sum+1,0));
	sol[0][0] = 1;
	for (int i=1;i<=n;i++) {
		for (int j=0;j<=sum;j++) {
			sol[i][j] = sol[i-1][j];
			if (j>=a[i])
			sol[i][j] += sol[i][j-a[i]];
		}
	}
	cout<<sol[n][sum]<<endl;
}
