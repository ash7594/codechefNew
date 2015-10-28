#include<bits/stdc++.h>
#define gc getchar_unlocked
#define REP(a,b,c) for(ull a=b;a<c;a++)
#define maxf(a,b) ((a>b)?a:b)
#define minf(a,b) ((a<b)?a:b)
#define minf3(a,b,c) ((minf(a,b)<c)?minf(a,b):c)
#define maxf3(a,b,c) ((maxf(a,b)>c)?maxf(a,b):c)
#define nl cout<<endl
#define ull unsigned long long
using namespace std;

ull read() {
      char c = gc();
        while(c<'0' || c>'9') c = gc();
          ull ret = 0;
          while(c>='0' && c<='9') {
                  ret = 10 * ret + c - 48;
                      c = gc();
                        }
            return ret;
}

struct node {
	ull l;
	ull r;
	ull sum;
	node *lc;
	node *rc;
};

node p[1000000];
int globalarr;

ull segment_tree(vector<ull> a,ull l,ull r,node *t) {
	t->l = l;
	t->r = r;
	if (l==r) {
		t->lc = NULL;
		t->rc = NULL;
		return t->sum = a[l];
	}
	node *lc = &p[globalarr++];
	node *rc = &p[globalarr++];

	t->lc = lc;
	t->rc = rc;
	ull mid = (l+r)/2;
	return t->sum = segment_tree(a,l,mid,lc) + segment_tree(a,mid+1,r,rc);
}

void update_segment_tree(node *t,ull ov,ull p,ull v) {
	if (t == NULL) return;
	if (p<t->l || p>t->r) return;
	t->sum += (v - ov);
	update_segment_tree(t->lc,ov,p,v);
	update_segment_tree(t->rc,ov,p,v);
}

ull segment_tree_get_sum(node *t,ull l,ull r) {
	if (!(l>=t->l && r<=t->r)) return 0;
	if (l == t->l && r == t->r) return t->sum;
	ull mid = (t->l + t->r)/2;
	if (!(mid>=l && mid<r)) {
		if (mid<l) return segment_tree_get_sum(t->rc,l,r);
		else return segment_tree_get_sum(t->lc,l,r);
	} else {
		return segment_tree_get_sum(t->lc,l,mid)+segment_tree_get_sum(t->rc,mid+1,r);
	}
}

void lot(node *t) {
	if (t == NULL) return;
	lot(t->lc);
	cout<<t->l<<" "<<t->r<<" "<<t->sum<<endl;
	lot(t->rc);
}

int main() {
	globalarr = 0;
	ull n = read();
	ull m1,m2;
	vector<ull> a(n);
	REP(i,0,n) {
		a[i] = read();
	}

	vector<pair<ull,ull> > f(n);
	REP(i,0,n) {
		m1 = read();
		m2 = read();
		m1--;
		m2--;
		f[i] = make_pair(m1,m2);
	}

	vector<ull> asum(n);
	asum[0] = a[0];
	REP(i,1,n) {
		asum[i] = a[i] + asum[i-1];
	}
	
	//
//	copy(asum.begin(),asum.end(),ostream_iterator<ull>(cout," "));
//	nl;
	//

	node *root = &p[globalarr++];
	ull totsum = segment_tree(a,0,n-1,root);

	//
//	lot(root);
	//
	
	vector<ull> fval(n);
	REP(i,0,n) {
		if (f[i].first == 0) fval[i] = asum[f[i].second];
		else fval[i] = asum[f[i].second] - asum[f[i].first-1];
	}

	//
//	copy(fval.begin(),fval.end(),ostream_iterator<ull>(cout," "));
//	nl;
	//
	
	ull buckets = ceil(sqrt(n));
	vector<ull> sqrtdec(buckets,0);
	
	for (ull i=0;i<buckets;i++) {
		for (ull j=i*buckets,k=0;k<buckets && j<n;k++,j++) {
			sqrtdec[i] += fval[j];
		}
	}

	//
//	copy(sqrtdec.begin(),sqrtdec.end(),ostream_iterator<ull>(cout," "));
//	nl;
	//

	vector<vector<ull> > freq(buckets,vector<ull>(n+1,0));
	for (ull i=0;i<buckets;i++) {
		for (ull j=i*buckets,k=0;k<buckets && j<n;k++,j++) {
			freq[i][f[j].first]++;
			freq[i][f[j].second+1]--;
		}
	}

	for (ull i=0;i<buckets;i++) {
		for (ull j=1;j<n;j++) {
			freq[i][j] += freq[i][j-1];
		}
	}
		
	//
//	nl;
//	REP(i,0,buckets) {
//		copy(freq[i].begin(),freq[i].end(),ostream_iterator<ull>(cout," "));
//		nl;
//	}
	//

	ull q = read();
	ull type,b,c;
	ull ans = 0;
	while(q--) {
		ans = 0;
		type = read();
		b = read();
		c = read();

		if (type == 1) {
			b--;
			update_segment_tree(root,a[b],b,c);
			//update buckets
			for (ull i=0;i<buckets;i++) {
				sqrtdec[i] += freq[i][b]*(c - a[b]);
			}
			a[b] = c;
		} else {
			b--;
			c--;
			ull sb = ceil(b*1.0/buckets);
			ull eb = (c/buckets);

			if (sb>=eb) {
				for (int i=b;i<=c;i++) {
					ans += segment_tree_get_sum(root,f[i].first,f[i].second);
				}
				printf("%lld\n",ans);
				continue;
			}

			for (ull i=sb;i<eb;i++) {
				ans += sqrtdec[i];
			}
			sb *= buckets;
			eb *= buckets;
			for (ull i=b;i<sb;i++) {
				ans += segment_tree_get_sum(root,f[i].first,f[i].second);
			}
			for (ull i=eb;i<=c;i++) { 
				ans += segment_tree_get_sum(root,f[i].first,f[i].second);
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
