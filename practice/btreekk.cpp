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

long long read() {
      char c = gc();
        while(c<'0' || c>'9') c = gc();
          long long ret = 0;
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

vector<long long> two(1,1);
vector<long long> twosum(1,1);

void powers2() {
	REP(i,0,50) {
		two.push_back(2*two[i]);
		twosum.push_back(twosum[i]+two[i+1]);
	}
}

int main() {
	powers2();
	long long t = read();
	long long tlevel,llnodes,sllnodes;
	while(t--) {
		long long n = read();
		long long x = read();
		
		for(int i=0;i<two.size();i++) {
			if (twosum[i] < n) continue;
			tlevel = i;
			if (i != 0) llnodes = n-twosum[i-1];
			else llnodes = 1;
			break;
		}

		sllnodes = two[tlevel-1] - ((llnodes+1)/2);
		//cout<<llnodes<<" "<<sllnodes<<endl;

		if (tlevel > x) printf("%lld ",two[x]);
		else if (tlevel == x) printf("%lld ",llnodes);
		else printf("0 ");

		if (x>tlevel) {
			printf("0\n");
			continue;
		}
		for(int i=0;i<x;i++) {
			llnodes = (llnodes+1)/2;
			//if (sllnodes != 1 && sllnodes != 0)
			//	sllnodes = (sllnodes+1)/2;
			//else sllnodes = 0;
			sllnodes /= 2;
		}

		printf("%lld\n",llnodes+sllnodes);
	}
	return 0;
}
