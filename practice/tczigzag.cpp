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

int main() {
	int n;
	n = read();
	vector<int> a;

	copy_n(istream_iterator<int>(cin),n,back_inserter(a));

	vector<pair<int, int> > sol(n);

	int ans = 1;
	for(int i=0;i<n;i++) {
		sol[i] = make_pair(1,1);
		for(int j=i-1;j>=0;j--) {
			if (a[i] > a[j]) {
				if (sol[i].first < sol[j].second + 1) {
					sol[i].first = sol[j].second + 1;
				}
			}
		}
		for(int j=i-1;j>=0;j--) {
			if (a[i] < a[j]) {
				if (sol[i].second < sol[j].first + 1) {
					sol[i].second = sol[j].first + 1;
				}
			}
		}
		ans = maxf(ans,sol[i].first);
		ans = maxf(ans,sol[i].second);
	}
	//typedef pair<int,int> pa;
	//copy(sol.begin(),sol.end(),ostream_iterator<pa>(cout," "));
	for (int i=0;i<sol.size();i++) {
		cout<<sol[i].first<<" "<<sol[i].second<<endl;	
	}
	cout<<ans<<endl;
	return 0;
}
