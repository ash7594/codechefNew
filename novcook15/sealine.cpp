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

inline void write(int x){

         register char buffor[35];
         register int i=0;
         do{
               buffor[i++]=(x%10)+'0';
               x/=10;
            } while(x);
           i--;
            while(i>=0) pc(buffor[i--]);
            pc('\n');
       }

int main() {
	typedef vector<int>::iterator iter;
	iter it;
	int t = read();
	int ans;
	while(t--) {
		ans = 0;
		int n = read();
		vector<int> a(n);
		vector<int> res;
		REP(i,0,n) {
			a[i] = read();
		}

		REP(i,0,n) {
			if (a[i] == 0) {
				res.insert(res.begin(), i+1);
			} else {
				it = find(res.begin(),res.end(),a[i]);
				it++;
				ans += minf(it-res.begin(),res.size()-(it-res.begin()));
				res.insert(it, i+1);
			}
			//copy(res.begin(),res.end(),ostream_iterator<int>(cout, " "));
			//nl;
		}
		printf("%d\n",ans);
	}
	return 0;
}
