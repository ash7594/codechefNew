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

	vector<int> sol(n);
	for (int i=0;i<n;i++) {
		sol[i] = a[i];
		for (int j=i-2;j>=0;j--) {
				
		}
	}
}

