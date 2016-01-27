#include<bits/stdc++.h>
#include<ext/rope>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define REP(a,b,c) for(int a=b;a<c;a++)
#define maxf(a,b) ((a>b)?a:b)
#define minf(a,b) ((a<b)?a:b)
#define minf3(a,b,c) ((minf(a,b)<c)?minf(a,b):c)
#define maxf3(a,b,c) ((maxf(a,b)>c)?maxf(a,b):c)
#define nl cout<<endl
using namespace std;
using namespace __gnu_cxx;

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

bool comp(pair<int,int> &a, pair<int,int> &b) {
	if (a.second == b.second) {
		return a.first > b.first;
	}
	return a.second > b.second;
}

int main() {
	vector<int> a;

	vector<pair<int,int> > b;
	for (int i=0;i<a.size();i++) {
		int temp = a[i];
		int count = 0;
		while (temp > 0) {
			if (temp % 2 != 0) count++;
		   	temp = temp >> 1;
		}
		b.push_back(make_pair(a[i],count));
	}

	sort(b.begin(),b.end(),comp);
	for (int i=0;i<b.size();i++) {
		cout<<b[i].first<<endl;
	}
}
