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
#define MAXV 100000000000000
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
	int q = read();
	int A,B;
	typedef pair<int,pair<int,int>> vtype;
	vector<vtype> arr(n);
	vector<vtype>::iterator iter;
	REP(i,0,n) {
		arr[i].first = i;
		arr[i].second.first = read();
	}
	REP(i,0,n) {
		arr[i].second.second = read();
	}

	sort(arr.begin(),arr.end(),[](const vtype &a, const vtype &b){return a.second.first<b.second.first;});

 	long long minval,minvali;
	while (q--) {
		minvali = -1;
		minval = MAXV;
		A = read();
		B = read();
		iter = lower_bound(arr.begin(),arr.end(),make_pair(0,make_pair(A,0)),[](const vtype &a, const vtype &b){return a.second.first<b.second.first;});
		if (iter == arr.end()) {
			printf("-1\n");
			continue;
		}
		
		for (;iter<arr.end();iter++) {
			if (iter->second.second >= B) {
				if (iter->second.second+iter->second.first < minval) {
					minval = iter->second.second+iter->second.first;
					minvali = iter->first;
				} else if (iter->second.second+iter->second.first == minval && iter->first < minvali) {
					minvali = iter->first;
				}
			}
		}
		
		printf("%lld\n",minvali);
	}
	return 0;
}
