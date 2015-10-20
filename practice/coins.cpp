#include<bits/stdc++.h>
#define gc getchar_unlocked
#define REP(a,b,c) for(long long a=b;a<c;a++)
#define maxf(a,b) ((a>b)?a:b)
#define nl cout<<endl
using namespace std;

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

map<long long, long long> mapper;
map<long long, long long>::iterator iter;

long long func(long long n) {
	iter = mapper.find(n);
	if (n < 12) {
		return n;
	}
	if (iter != mapper.end()) {
		return iter->second;
	}

	long long a = func(n/2);
	long long b = func(n/3);
	long long c = func(n/4);
	long long sum = a+b+c;

	mapper.insert(make_pair(n,sum));
	return sum;
}

int main() {
	long long n;
	long long sum = 0;
	while (scanf("%lld",&n)>0) {
		printf("%lld\n",func(n));
	}
	return 0;
}
