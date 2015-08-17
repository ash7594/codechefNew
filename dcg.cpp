#include<bits/stdc++.h>
#define maxf(a,b) ((a>b)?a:b)
#define gc getchar_unlocked
using namespace std;

struct node {
	int num;
	long long num_permute;
	long long group_add;
};

struct lowerval
{
    bool operator ()(node const& a, int const i) const
    {
        return a.num < i;
    }
};

struct upperval
{
    bool operator ()(int const i, node const& a) const
    {
        return a.num > i;
    }
};

node arr[1000001];
int st[1000002][2];
int eleminmax[1000001][2];
char ans[1000001];

bool comp(node a, node b) {return a.num<b.num;};

//bool lowerval(node a, int b) {return a.num<b;};

//bool upperval(node a, int b) {return a.num>b;};

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

void fastRead_char(char *str) {
    register char c = 0;
    register int i = 0;
    while (c < 33)
        c = gc();
    *str = c;
}

void getMaxCount(int n, int top) {
	st[++top][0] = 1000000001;
	for (int i=0;i<n;i++) {
        if (top == 0 || (arr[i].num <= st[top][0])) {
            st[++top][0] = arr[i].num;
            st[top][1] = i;
            continue;
        }
        while (arr[i].num > st[top][0]) {
            eleminmax[st[top][1]][1] = i;
            top--;
        }
        st[++top][0] = arr[i].num;
        st[top][1] = i;
    }

    while (top > 0) {
        eleminmax[st[top][1]][1] = n;
        top--;
    }

    for (int i=n-1;i>=0;i--) {
        if (top == 0 || (arr[i].num < st[top][0])) {
            st[++top][0] = arr[i].num;
            st[top][1] = i;
            continue;
        }
        while (arr[i].num >= st[top][0]) {
            eleminmax[st[top][1]][0] = i;
            top--;
        }
        st[++top][0] = arr[i].num;
        st[top][1] = i;
    }

    while (top > 0) {
        eleminmax[st[top][1]][0] = -1;
        top--;
    }

	for (int i=0;i<n;i++) {
		arr[i].num_permute = (eleminmax[i][1] - i)*(i - eleminmax[i][0]);
	}
}

int main() {
	int n,m;
	n = read_int();
	m = read_int();
	for (int i=0;i<n;i++) {
		arr[i].num = read_int();
	}
	/*
	long long maxval = -1;
	for (int i=0;i<n;i++) {
		maxval = -1;
		for (int j=i;j<n;j++) {
			maxval = maxf(maxval, arr[j]);
			dumpmap[maxval].num_permute++;
		}
	}
	*/
	getMaxCount(n, -1);
	sort(arr,arr+n,comp);
	/*
	typedef map<int, node>::iterator iter_type;
	iter_type tempIter, endIter, moreiter;
	int tempval;
	long long count = 0;
	iter_type dumpbegin, dumpend;
    dumpbegin = dumpmap.begin();
    dumpend = dumpmap.end();
	*/
	//base_check
	/*
	if ((dumpmap.rbegin()->second).group_add != n*(n+1)/2) {
		while (1) {}
	}
	*/

	char ch, starter, waste;
	int k, ansi = -1;
	node *p1, *p2;
	node *pend = (arr+n);
	node *pendm = (arr+n-1);

	long long counterman = 0;
	for (int i=0;i<n;i++) {
		counterman += arr[i].num_permute;
		arr[i].group_add = counterman;
		//cout<<arr[i].num<<" "<<arr[i].num_permute<<" "<<arr[i].group_add<<endl;
	}
	
	/*cin>>k;
	p1 = lower_bound(arr,arr+n,k,lowerval());
    p2 = upper_bound(arr,arr+n,k,upperval());

	cout<<p1->num<<" "<<p2->num;
	return 0;
	*/
	/*
	iter_type dumpbegin, dumpend;
	dumpbegin = dumpmap.begin();
	dumpend = dumpmap.end();
	*/
	long long evalval;
	while (m--) {
		//scanf("%c",&ch);
		fastRead_char(&ch);
		k = read_int();
		//scanf("%c",&starter);
		fastRead_char(&starter);
		//scanf("%c",&waste);
		if (ch == '=') {
			p1 = lower_bound(arr,pend,k,lowerval());
       	 	p2 = upper_bound(arr,pend,k,upperval());
			if (p1 == pend || p1->num!=k) {
				if (starter == 'D') {
					ans[++ansi] = 'C';
				} else {
					ans[++ansi] = 'D';
				}
				continue;
			}

			if (p1 == arr) {
				p2--;
				evalval = p2->group_add;
			} else {
				p1--;
				p2--;
				evalval = p2->group_add - p1->group_add;
			}
			if (evalval%2 == 0) {
				if (starter == 'D') {
					ans[++ansi] = 'C';
				} else {
					ans[++ansi] = 'D';
				}
			} else {
				if (starter == 'D') {
					ans[++ansi] = 'D';
                } else {
            		ans[++ansi] = 'C';
                }
			}
			continue;
		}

		if (ch == '<') {
			p1 = lower_bound(arr,pend,k,lowerval());
			if (p1 == pend || p1 == arr) {
				if (starter == 'D') {
					ans[++ansi] = 'C';
				} else {
					ans[++ansi] = 'D';
				}
				continue;
			}
			
			p1--;
           	evalval = p1->group_add;

			if (evalval%2 == 0) {
				if (starter == 'D') {
                    ans[++ansi] = 'C';
                } else {
                    ans[++ansi] = 'D';
                }
			} else {
				if (starter == 'D') {
                    ans[++ansi] = 'D';
                } else {
                    ans[++ansi] = 'C';
                }
			}
			continue;
		}

		if (ch == '>') {
        	p2 = upper_bound(arr,pend,k,upperval());
            if (p2 == pend) {
                if (starter == 'D') {
                    ans[++ansi] = 'C';
                } else {
                    ans[++ansi] = 'D';
                }
                continue;
            }

			if (p2 == arr) {
                evalval = pendm->group_add;
            } else {
                p2--;
                evalval = pendm->group_add - p2->group_add;
           	}
            if (evalval%2 == 0) {
                if (starter == 'D') {
                    ans[++ansi] = 'C';
                } else {
                    ans[++ansi] = 'D';
                }
            } else {
                if (starter == 'D') {
                    ans[++ansi] = 'D';
                } else {
                    ans[++ansi] = 'C';
                }
            }
            continue;
        }
	}
	ans[++ansi] = '\0';
	printf("%s",ans);
	return 0;
}
