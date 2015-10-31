#include<bits/stdc++.h>
#include<ext/rope>
#define gc getchar_unlocked
#define REP(a,b,c) for(int a=b;a<c;a++)
#define maxf(a,b) ((a>b)?a:b)
#define minf(a,b) ((a<b)?a:b)
#define minf3(a,b,c) ((minf(a,b)<c)?minf(a,b):c)
#define maxf3(a,b,c) ((maxf(a,b)>c)?maxf(a,b):c)
#define nl cout<<endl
#define ull unsigned long long
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

inline void write(ull x){

         register char buffor[35];
         register int i=0;
         do{
               buffor[i++]=(x%10)+'0';
               x/=10;
            } while(x);
           i--;
            while(i>=0) putchar_unlocked(buffor[i--]);
            putchar_unlocked('\n');
       }

int main() {
	int n = read();
	vector<int> a(n);
	vector<pair<int,int> > e,o;
	REP(i,0,n) {
		cin>>a[i];
		if (a[i]%2 == 0)
			e.push_back(make_pair(a[i],i));
		else
			o.push_back(make_pair(a[i],i));
	}

	sort(e.begin(),e.end(),[](const pair<int,int> &a, const pair<int,int> &b){return a.first<b.first;});
	sort(o.begin(),o.end(),[](const pair<int,int> &a, const pair<int,int> &b){return a.first<b.first;});

	vector<int> b(n);
	iota(b.begin(),b.end(),1);
	REP(i,0,o.size()) {
		a[o[i].second] = 2*i+1;
	}
	REP(i,0,e.size()) {
		a[e[i].second] = 2*(i+1);
	}

//	REP(i,0,a.size()) cout<<a[i]<<" ";
//	nl;
//	REP(i,0,b.size()) cout<<b[i]<<" ";
//	nl;

	long long ans = 0;
	REP(i,0,b.size()) {
		if (a[i] == b[i] || b[i] == -1)
			continue;
		b[i] = -1;
		int c = a[i] - 1;
		while(c != i) {
			b[c] = -1;
			c = a[c] - 1;
			ans++;
		}
	}

	printf("%lld\n",ans);

	return 0;
}
