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
	int t,n,tem;
	t = read();
	while (t--) {
		n = read();
		int po = pow(2,n);
		vector<int> g(po);
		map<int, vector<int> > mapper;
		map<int, vector<int> >::iterator iter;
		REP(i,0,po) {
			g[i] = read();
		}
		sort(g.begin(),g.end());
		g.erase(g.begin());

		po--;	
		REP(i,0,po) {	
			iter = mapper.find(g[i]);
			if (iter == mapper.end()) {		
				vector<int> temv;
				temv.push_back(i);
				mapper.insert(make_pair(g[i],temv));
			} else {
				(iter->second).push_back(i);
			}
		}

		vector<int> ans;
		vector<int> as(1,0);
		REP(i,0,po) {
			if (g[i] == -1) continue;
			ans.push_back(g[i]);
			int size = as.size();
			while (size--) {
				as.push_back(g[i]+as[size]);
				iter = mapper.find(g[i] + as[size]);
				g[(iter->second).front()] = -1;
				(iter->second).erase((iter->second).begin());
			}
		}
		
		copy(ans.begin(),ans.end(),ostream_iterator<int>(cout," "));
		nl;
	}
	return 0;
}
