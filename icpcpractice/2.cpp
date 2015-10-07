#include<bits/stdc++.h>
#define minf(a,b) ((a<b)?a:b)
#define maxf(a,b) ((a>b)?a:b)
using namespace std;

int main () {
	int t,n,m,s,p,q,p1,q1,p2,q2;
	int s1, s2, t1, t2, c;
	long long ans;
	cin>>t;
	while(t--) {
		cin>>n>>m>>s>>p>>q;
		c = n-m+1;
		p2 = p;
		q2 = q;

		p1 = minf(p,q);
		q1 = maxf(p,q);
		p = p1;
		q = q1;

		s1 = (m-1)%p;
		t1 = (m-1)/p;
		if (s1 != 0) {
			s1 = p-s1;
			t1++;
		}

		s2 = (m-1)%q;
		t2 = (m-1)/q;
		if (s2 != 0) {
			s2 = q-s2;
			t2++;
		}

		s2 = (s2 + (t1 - t2)*q)%c;
		ans = 0;
		//cout<<s1+1<<" "<<s2+1<<endl;
		if (s1 == s2 && t1!=0) ans++;
		for (int i=t1+1;i<=s;i++) {
			s1 = (s1+p)%c;
			//if (s1 == s2) ans++;
			s2 = (s2+q)%c;
			//cout<<s1+1<<" "<<s2+1<<endl;
			if (s1 == s2) ans++;
		}
		cout<<ans<<endl;
	}
}
