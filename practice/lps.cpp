#include<bits/stdc++.h>
#define gc getchar_unlocked
#define REP(a,b,c) for(int a=b;a<c;a++)
#define maxf(a,b) ((a>b)?a:b)
#define minf(a,b) ((a<b)?a:b)
#define minf3(a,b,c) ((minf(a,b)<c)?minf(a,b):c)
#define maxf3(a,b,c) ((maxf(a,b)>c)?maxf(a,b):c)
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

string a;
int sol(int i, int j) {
	if (i == j) return 1;
	if (i>j) return 0;
	if (a[i] == a[j])
		return sol(i+1,j-1) + 2;
	return maxf(sol(i+1,j),sol(i,j-1));
}

int main() {
	cin>>a;
	
	cout<<sol(0,a.size()-1);nl;
	return 0;
}
