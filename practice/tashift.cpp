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
int n;
pair<int,int> func(string a, string b, int ai, int bi, int size) {
	if (size == n) return make_pair(size,bi-size);
	if (b[bi%n] == a[ai%n]) {
		return func(a,b,ai+1,bi+1,size+1);
	} else {
		return make_pair(size,bi-size);
	}
}

int main() {
	n = read();
	string a,b;
	cin>>a>>b;

	int maxv = 0;
	int ans = 0;
	for (int i=0;i<n;i++) {
		pair<int,int> val(func(a,b,0,i,0));
		if (val.first > maxv) {
			maxv = val.first;
			ans = val.second;
		}
	}
	printf("%d\n",ans);
	return 0;
}
