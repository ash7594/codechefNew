#include<bits/stdc++.h>
#define gc getchar_unlocked
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

int gcd (int a, int b) {
	if (a < b) swap(a,b);
	if (b == 1) return 1;
	if (b == 0) return a;
	return gcd(b,a%b);
}

void func(int &a) {
	a = read_int();
}

int main() {
	int t,l,r;
	cin>>t;
	while (t--) {
		int n,q;
		n = read_int();
		q = read_int();
		vector<int> a(n),p(n+1),s(n+1);

		for_each(a.begin(),a.end(),func);
		//copy_n(istream_iterator<int>(read_int()),n,back_inserter(a));
		//generate_n(back_inserter(a),n,[](){int val; cin>>val; return val;});
		//p.resize(a.size()+1);
		//s.resize(a.size()+1);

		p[0] = 0;
		for (int i=1;i<=a.size();i++) {
			p[i] = gcd(p[i-1],a[i-1]);
		}
		s[n] = 0;
		for (int i=a.size()-1;i>=0;i--) {
			s[i] = gcd(s[i+1],a[i]);
		}
		
		while (q--) {
			l = read_int();
			r = read_int();
			l--;
			printf("%d\n",gcd(p[l],s[r]));
		}
	}
	return 0;
}
