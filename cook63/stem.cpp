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

vector<string> gsets;
int strsize;

void func(string str, vector<string> big, int ind) {
	int r = str.length()+1;
	int c = big[ind].length()+1;

	vector<vector<int> > a(r,vector<int>(c));
//	for_each(a[0].begin(),a[0].end(),[](int &a) {a=0;});
//	REP(i,0,str.length()+1) {
//		a[i][0] = 0;
//	}

	int maxv = 0, index = -1;
	REP(i,0,r)
		fill(a[i].begin(),a[i].end(),0);
	for (int i=1;i<r;i++) {
		for (int j=1;j<c;j++) {
			if (str[i-1] == big[ind][j-1]) {
				a[i][j] = a[i-1][j-1] + 1;
				//maxv = maxf(maxv, a[i][j], index);
				if (a[i][j] > maxv) {
					maxv = a[i][j];
					index = j;
				}
			}
		}
	}

	if (maxv == 0) return;
	if (strsize != -1 && maxv < strsize) return;

	if ((ind+1) == big.size()) {
		if (maxv > strsize) {
			if (gsets.size() != 0)
				gsets.erase(gsets.begin(),gsets.end());
			strsize = maxv;
		}
	}
	//vector<string> sets;
	for (int i=0;i<r;i++) {
		for (int j=0;j<c;j++) {
			if (a[i][j] == maxv) {
				if ((ind+1) == big.size()) {
					gsets.push_back(big[ind].substr(j-maxv,maxv));
				} else {
					func(big[ind].substr(j-maxv,maxv),big,ind+1);
				}
			}
		}
	}
	//return sets;
}

int main () {
	int t,n;
	t = read();
	while(t--) {
		n = read();
		vector<string> a;
		strsize = -1;
		if (gsets.size() != 0)
			gsets.erase(gsets.begin(),gsets.end());

		copy_n(istream_iterator<string>(cin),n,back_inserter(a));

		sort(a.begin(),a.end(),[](const string &a, const string &b) {return a.length() < b.length();});

		string mystr(a[0]);
		//a.erase(a.begin());
		func(mystr, a, 0);

		sort(gsets.begin(), gsets.end());

		cout<<gsets[0]<<endl;
	}	
}
