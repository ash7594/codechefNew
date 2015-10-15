#include<bits/stdc++.h>
#define gc getchar_unlocked
#define minf(a,b) ((a<b)?a:b)
using namespace std;

int read_int() {
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
	int t,b1,b2;
	t = read_int();

	while (t--) {
		int n;
		n = read_int();

		vector<pair<int, int> > a;
		while (n--) {
			b1 = read_int();
			b2 = read_int();
			a.push_back(make_pair(b1, b2));
		}

		sort(a.begin(), a.end(), [](const pair<int,int> &a,const pair<int,int> &b) {
			if (a.first == b.first) return a.second<b.second; return a.first < b.first;
		});

		//for_each(a.begin(), a.end(), [](pair<int,int> a) { cout<<a.first<<" "<<a.second;});

		int count = 0;
		int minv = a.front().second;
		//int current = a.front().first;
		for (int i=1;i<a.size();i++) {
			if (a[i].first <= minv) {
				minv = minf(minv, a[i].second);
			} else {
				count++;
				minv = a[i].second;
			}
		}
		count++;
		printf("%d\n",count);
	}
	return 0;
}
