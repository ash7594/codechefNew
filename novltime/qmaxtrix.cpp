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
	int n = read();
	long long sum = 0,sum2;
	vector<int> rows(n+2,0),cols(n+2,0);
	vector<pair<int,int> > inp(n+1);
	int a,b;
	REP(i,1,n+1) {
		a = read();
		b = read();
		inp[i] = make_pair(a,b);
		rows[i] = b-a+1;
		sum += rows[i];
		cols[a]++;
		cols[b+1]--;
	}
	REP(i,1,n+1) {
		cols[i] += cols[i-1];
	}

//	copy(rows.begin(),rows.end(),ostream_iterator<int>(cout, " "));
//	nl;
//	copy(cols.begin(),cols.end(),ostream_iterator<int>(cout, " "));
//	nl;

	int q = read();
	while (q--) {
		sum2 = sum;
		a = read();
		b = read();
		sum2 -= rows[a];
		sum2 -= cols[b];
		if (b>=inp[a].first && b<=inp[a].second) sum2++;
		if (sum2 % 2 == 0) printf("E\n");
		else printf("O\n");
	}
	return 0;
}
