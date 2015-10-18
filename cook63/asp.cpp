#include<bits/stdc++.h>
#define gc getchar_unlocked
#define REP(a,b,c) for(int a=b;a<c;a++)
#define pass printf("YES\n")
#define fail printf("NO\n")
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

int main () {
	int t,n;
	t = read();
	while(t--) {
		n = read();
		vector<int> a;
		REP(i,0,n) a.push_back(read());
		REP(i,1,a.size()) {
			if (a[i] < a[i-1]) {
				if (i>1 && a[i] < a[i-2]) {
					fail;
					goto end;
				}
			}
		}
		pass;
		end:;
	}	
}
