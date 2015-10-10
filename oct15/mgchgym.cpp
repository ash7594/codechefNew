#include<bits/stdc++.h>
#define nl printf("\n")
#define REP(i,b,c) for(int i=b;i<c;i++)
#define iter vector<int>::iterator
#define gc getchar_unlocked
using namespace std;

int inp() {
      char c = gc();
        while(c<'0' || c>'9') c = gc();
          int ret = 0;
          while(c>='0' && c<='9') {
                  ret = 10 * ret + c - 48;
                      c = gc();
                        }
            return ret;
}

string check(iter l, iter r, int W) {
	vector<bool> v1(W+1);
	vector<int> w(1,0);
	w.insert(w.end(),l,r);
	vector<vector<bool> > v(w.size(),v1);

	REP(i,0,w.size()) {
		v[i][0] = true;
	}
	REP(i,1,W+1) {
		v[0][i] = false;
	}

	REP(i,1,w.size()) {
		REP(j,0,W+1) {
			v[i][j] = v[i-1][j];
			if (j>=w[i])
				v[i][j] = v[i][j] || v[i-1][j-w[i]];
		}
		if (v[i][W]) return "Yes";
	}
	return "No";
}

int main () {
	int n,q,a,l,r,W;
	n = inp();
	q = inp();
	vector<int> w(n+1);
	REP(i,1,n+1) {
		w[i] = inp();
	}
	while (q--) {
		a = inp();
		l = inp();
		r = inp();
		if (a == 1) {
			w[l] = r;
			continue;
		}

		if (a == 2) {
			reverse(w.begin()+l,w.begin()+r+1);
			continue;
		}

		if (a == 3) {
			W = inp();
			printf("%s",check(w.begin()+l,w.begin()+r+1,W).c_str());
			nl;
		}
	}
	return 0;
}
