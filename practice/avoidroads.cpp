#include<bits/stdc++.h>
#define gc getchar_unlocked
#define REP(a,b,c) for(long long a=b;a<c;a++)
#define maxf(a,b) ((a>b)?a:b)
#define nl cout<<endl
using namespace std;

typedef pair<pair<long long,long long>,pair<long long,long long> > brtype;

long long read() {
      char c = gc();
        while(c<'0' || c>'9') c = gc();
          long long ret = 0;
          while(c>='0' && c<='9') {
                  ret = 10 * ret + c - 48;
                      c = gc();
                        }
            return ret;
}

bool check(long long a,long long b,long long c,long long d,vector<brtype> br) {
	pair<long long,long long> a1 = make_pair(a,b);
	pair<long long,long long> a2 = make_pair(c,d);
	brtype g = make_pair(a1,a2);
	REP(i,0,br.size()) {
		if (g == br[i])
			return false;
	}
	return true;
}

int main() {
	long long w,h,a1,a2,a3,a4;
	w = read();
	h = read();
	pair<long long,long long> dest(w,h);
	long long b;
	b = read();

	vector<brtype> br(b);
	REP(i,0,b) {
		a1 = read();
		a2 = read();
		a3 = read();
		a4 = read();
		br[i] = make_pair(make_pair(a1,a2),make_pair(a3,a4));
	}

	vector<vector<long long> > sol(w+1,vector<long long>(h+1,0));
	sol[0][0] = 1;
	for (long long i=1;i<=h;i++) {
		if (check(0,i-1,0,i,br))
			sol[0][i] = 1;
		else break;
	}

	for (long long i=1;i<=w;i++) {
		if (check(i-1,0,i,0,br))
			sol[i][0] = 1;
		else break;
	}
	
	for (long long i=1;i<=w;i++) {
		for (long long j=1;j<=h;j++) {
			if (check(i-1,j,i,j,br))
				sol[i][j] += sol[i-1][j];
			if (check(i,j-1,i,j,br))
				sol[i][j] += sol[i][j-1];
		}
	}
	
//	REP(i,0,w+1) {
//		REP(j,0,h+1) {
//			cout<<sol[j][i]<<" ";
//		}
//		nl;
//	}
	cout<<sol[w][h]<<endl;	
	return 0;
}
