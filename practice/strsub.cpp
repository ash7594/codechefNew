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

typedef vector<pair<int,int> >::iterator iti;
typedef vector<long long>::iterator itl;

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

inline void write(long long x){

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
	int t = read();
	int n,k,q,l,r;
	int no1, no0;
	while(t--) {
		n = read();
		k = read();
		q = read();
		char s[n];
		scanf("%s",s);

		if (n==1) {
			while(q--) {
				l = read();
				r = read();
				printf("1\n");
			}
			continue;
		}
		
		no1=no0=0;
		int m = 0;
		int cause = -1;
		while(no1 <= k && no0 <= k && m<n) {
			if (s[m] == '0') no0++;
			else no1++;
			m++;
			//cout<<no0<<" "<<no1<<" "<<m;
			//nl;
		}
		if (no1 > k) {
			cause = 1;
			no1--;
		} else if (no0 > k) {
			cause = 0;
			no0--;
		}
		vector<pair<int,int> > a;
		m-=2;
		if (cause == -1) {
			int z = 0;
			while (z<n) {
				a.push_back(make_pair(z++,n-1));
			}
			goto h;
		}
		else
			a.push_back(make_pair(0,m));

		for (int i=1,j=m+1;i<n;i++,j++) {
			if (s[i-1] == '0') no0--;
			else no1--;

			while(no1<=k && no0<=k && j<n) {
				if (s[j] == '0') no0++;
				else no1++;
				j++;
			}

			if (no1 > k) {
				cause = 1;
				no1--;
			} else if (no0 > k) {
				cause = 0;
				no0--;
			} else cause = -1;

			if (cause == -1) {
				//if (a.back().second != n-1)
				while(i<n)
					a.push_back(make_pair(i++,n-1));
				break;
			} else {
				j-=2;
				//if (a.back().second != j)
					a.push_back(make_pair(i,j));
			}
		}

		h:;
		vector<long long> subseq(a.size()),ss(a.size()),common(a.size()-1,0),scommon(a.size()-1);
//		REP(i,0,a.size()) {
//			cout<<"("<<a[i].first<<","<<a[i].second<<")";
//			nl;
//		}

		long long count;
		REP(i,0,subseq.size()) {
			count = (a[i].second-a[i].first+1);
			subseq[i] = count*(count+1)/2;
		}

		ss[0] = subseq[0];
		REP(i,1,ss.size()) {
//			count = 0;
//			if (a[i].first <= a[i-1].second)
//				count = (a[i-1].second-a[i].first+1);
			ss[i] = ss[i-1] + subseq[i];// - count*(count+1)/2;
		}

		REP(i,0,common.size()) {
			if (a[i+1].first <= a[i].second) {
				count = a[i].second - a[i+1].first + 1;
				common[i] = count*(count+1)/2;
			}
		}

		scommon[0] = common[0];
		REP(i,1,scommon.size()) {
			scommon[i] = scommon[i-1] + common[i];
		}

//		copy(ss.begin(),ss.end(),ostream_iterator<long long>(cout," "));
//		nl;
//		copy(common.begin(),common.end(),ostream_iterator<long long>(cout," "));
//		nl;
//		copy(scommon.begin(),scommon.end(),ostream_iterator<long long>(cout," "));
//		nl;

		long long ans;
		while(q--) {
			l = read();
			r = read();
			l--;
			r--;

			iti iter1 = lower_bound(a.begin(),a.end(),make_pair(l,0),[](const pair<int,int> &a, const pair<int,int> &b)->bool{return a.first<b.first;});
			iti iter2 = upper_bound(a.begin(),a.end(),make_pair(0,r),[](const pair<int,int> &a, const pair<int,int> &b)->bool{return a.second<b.second;});

			if (iter2 == a.begin()) {
				ans = (r-l+1)*(r-l+2)/2;
				printf("%lld\n",ans);
				continue;
			}
			iter2--;

			if (iter1->second >= r) {
				ans = (r-l+1)*(r-l+2)/2;
				printf("%lld\n",ans);
				continue;
			}

			if ((iter1-a.begin()-1) < 0) {
				if (iter2-a.begin()-1 >= 0)
					ans = ss[iter2-a.begin()] - scommon[iter2-a.begin()-1];
				else
					ans = ss[iter2-a.begin()];
			} else {
				if (iter2-a.begin()-1 >= 0) ans = ss[iter2-a.begin()] - ss[iter1-a.begin()-1] - (scommon[iter2-a.begin()-1] - scommon[iter1-a.begin()-1]);
				else ans = ss[iter2-a.begin()] - ss[iter1-a.begin()-1];// - (0 - scommon[iter1-a.begin()-1]);
			}

//			if (iter1->first != l) {
//				iter1--;
//				count = iter1->second - l + 1;
//				ans += count*(count+1)/2;
//			}

			if (iter2->second != r) {
				iter2++;
				count = r-iter2->first+1;
				ans += count*(count+1)/2;
				iti iter3 = iter2;
				iter3--;
				if (iter2 != a.begin() && iter2->first <= iter3->second) {
					count = iter3->second-iter2->first+1;
					ans -= count*(count+1)/2;
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
