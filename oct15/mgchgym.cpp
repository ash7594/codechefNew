#include<bits/stdc++.h>
#define nl printf("\n")
#define REP(i,b,c) for(int i=b;i<c;i++)
#define iter vector<int>::iterator
#define gc getchar_unlocked
using namespace std;

//bool comp(const pair<int,int> &a,const pair<int,int> &b) { return a.first < b.first; }

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

bool check(iter l, iter r, int W) {
	vector<bool> v1(W+1);
	vector<int> w1(1,0);
	w1.insert(w1.end(),l,r);

//	map<int,int> hash;
//	map<int,int>::iterator it1;
//	REP(i,0,w1.size()) {
//		it1 = hash.find(w1[i]);
//		if (it1 == hash.end())
//			hash.insert(it1,make_pair(w1[i],1));
//		else
//			(it1->second)++;
//	}
//	vector<pair<int,int> > w;
//	REP(i,0,hash.size()) {
//		if (hash[i] != 0)
//			w.push_back(i);
//	}
	
//	for (iter it=w1.begin(); it!=w1.end(); it++) {
//		cout<<*it<<" ";
//	}
//	nl;

	vector<pair<int,int> > w(1,make_pair(0,1));
	vector<pair<int,int> >::iterator it;
	REP(i,1,w1.size()) {
		it = lower_bound(w.begin(),w.end(),make_pair(w1[i],0));
		if (it!=w.end() && it->first == w1[i])
			it->second++;
		else
			w.insert(it,make_pair(w1[i],1));
	}
	//cout<<w.size()<<endl;
	vector<vector<bool> > v(w.size(),v1);

	REP(i,0,w.size()) {
		v[i][0] = true;
	}
	REP(i,1,W+1) {
		v[0][i] = false;
	}

	//map<int,int>::iterator it = hash.begin();

//	for (it=w.begin(); it!=w.end(); it++) {
//		cout<<it->first<<" "<<it->second;
//		nl;
//	}

	REP(i,1,w.size()) {
		REP(j,0,W+1) {
			v[i][j] = v[i-1][j];
			if (j>=w[i].first) {
				for (int k=1;k<=w[i].second && j>=k*w[i].first;k++) {
					v[i][j] = v[i][j] || v[i-1][j-k*w[i].first];
				}
			}
		}
		if (v[i][W]) return true;
	}
	return false;
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
			if(check(w.begin()+l,w.begin()+r+1,W)) {
				printf("Yes\n");
			} else {
				printf("No\n");
			}
		}
	}
	return 0;
}
