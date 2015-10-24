#include<bits/stdc++.h>
#include<ext/rope>
#define nl printf("\n")
#define REP(i,b,c) for(int i=b;i<c;i++)
#define iter vector<int>::iterator
#define iter2 rope<int>::iterator
#define gc getchar_unlocked
using namespace std;
using namespace __gnu_cxx;

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

string check(iter2 l, iter2 r, int W) {
	vector<bool> v1(W+1);
	vector<int> w1(1,0);
	w1.insert(w1.end(),l,r);

	vector<int> hash(10001,0);
	REP(i,0,w1.size()) {
		hash[w1[i]]++;
	}
	vector<int> w;
	REP(i,0,10001) {
		if (hash[i] != 0)
			w.push_back(i);
	}

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
			if (j>=w[i]) {
				for (int k=1;k<=hash[w[i]] && j>=k*w[i];k++) {
					v[i][j] = v[i][j] || v[i-1][j-k*w[i]];
				}
			}
		}
		if (v[i][W]) return "Yes";
	}
	return "No";
}

string check1(iter l, iter r, int W) {
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
	rope<int> w(n+1);
	REP(i,1,n+1) {
		w.replace(i,inp());
	}
	while (q--) {
		a = inp();
		l = inp();
		r = inp();
		if (a == 1) {
			w.replace(l,r);
			continue;
		}

		if (a == 2) {
			reverse(w.mutable_begin()+l,w.mutable_begin()+r+1);
			continue;
		}

		if (a == 3) {
			W = inp();
			printf("%s",check(w.mutable_begin()+l,w.mutable_begin()+r+1,W).c_str());
			nl;
		}
	}
	return 0;
}
