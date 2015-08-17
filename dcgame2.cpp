#include<bits/stdc++.h>
#define maxf(a,b) ((a>b)?a:b)
#define gc getchar_unlocked
using namespace std;

struct node {
	long long num_permute;
	long long group_add;
};

map<int, node> dumpmap;
int arr[1000001], st[1000002][2];
int eleminmax[1000001][2];
char ans[1000001];

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
        if (top == 0 || (arr[i] <= st[top][0])) {
            st[++top][0] = arr[i];
            st[top][1] = i;
            continue;
        }
        while (arr[i] > st[top][0]) {
            eleminmax[st[top][1]][1] = i;
            top--;
        }
        st[++top][0] = arr[i];
        st[top][1] = i;
    }

	/*
    while (top > 0) {
        eleminmax[st[top][1]][1] = n;
        top--;
    }
	*/

    for (int i=n-1;i>=0;i--) {
        if (top == 0 || (arr[i] < st[top][0])) {
            st[++top][0] = arr[i];
            st[top][1] = i;
            continue;
        }
        while (arr[i] >= st[top][0]) {
            eleminmax[st[top][1]][0] = i;
            top--;
        }
        st[++top][0] = arr[i];
        st[top][1] = i;
    }

    while (top > 0) {
        eleminmax[st[top][1]][0] = -1;
        top--;
    }

	for (int i=0;i<n;i++) {
		if (eleminmax[i][1] != 0) {
			dumpmap[arr[i]].num_permute += (eleminmax[i][1] - i)*(i - eleminmax[i][0]);
		} else {
			dumpmap[arr[i]].num_permute += (n - i)*(i - eleminmax[i][0]);
		}
	}
}

int main() {
	int n,m;
	n = read_int();
	m = read_int();
	for (int i=0;i<n;i++) {
		//scanf("%d",&arr[i]);
		arr[i] = read_int();
		//dumpmap[arr[i]].num_permute = 0;
		/*
		if (dumpmap.find(arr[i]) == dumpmap.end()) {
			dumpmap[arr[i]].freq = 1;
		} else {
			dumpmap[arr[i]].freq++;
		}
		*/
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
	//getSubarrayMax(arr, 0, n-1);
	getMaxCount(n, -1);

	typedef map<int, node>::iterator iter_type;
	iter_type tempIter, endIter, moreiter;
	int tempval;
	long long count = 0;
	iter_type dumpbegin, dumpend;
    dumpbegin = dumpmap.begin();
    dumpend = dumpmap.end();
	/*
	for (iter_type iter = dumpmap.begin(); iter != dumpmap.end(); iter++) {
		tempval = (iter->second).freq;
		(iter->second).num_permute = ((count+tempval-1)*(count+tempval) - (count-1)*count)/2;
		count += tempval;
	}
	*/
	for (iter_type iter = dumpbegin; iter != dumpend; iter++) {
		//cout<<iter->first<<" "<<(iter->second).num_permute<<endl;
		count += (iter->second).num_permute;
		(iter->second).group_add = count;
	}
	long long maxpos = (dumpmap.rbegin()->second).group_add;
	//base_check
	/*
	if ((dumpmap.rbegin()->second).group_add != n*(n+1)/2) {
		while (1) {}
	}
	*/

	char ch, starter, waste;
	int k, ansi = -1;
	/*
	iter_type dumpbegin, dumpend;
	dumpbegin = dumpmap.begin();
	dumpend = dumpmap.end();
	*/
	while (m--) {
		//scanf("%c",&ch);
		fastRead_char(&ch);
		k = read_int();
		//scanf("%c",&starter);
		fastRead_char(&starter);
		//scanf("%c",&waste);
		if (ch == '=') {
			moreiter = dumpmap.find(k);
			if (moreiter == dumpend) {
				if (starter == 'D') {
					ans[++ansi] = 'C';
				} else {
					ans[++ansi] = 'D';
				}
				continue;
			}

			if ((moreiter->second).num_permute%2 == 0) {
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
			tempIter = dumpmap.lower_bound(k);
			if (tempIter == dumpend || tempIter == dumpbegin) {
				if (starter == 'D') {
					ans[++ansi] = 'C';
				} else {
					ans[++ansi] = 'D';
				}
				continue;
			}
			tempIter--;
			if ((tempIter->second).group_add%2 == 0) {
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
            tempIter = dumpmap.upper_bound(k);
            if (tempIter == dumpend) {
                if (starter == 'D') {
                    ans[++ansi] = 'C';
                } else {
                    ans[++ansi] = 'D';
                }
                continue;
            }

			count = maxpos;
			tempIter--;
			count -= (tempIter->second).group_add;
            if (count%2 == 0) {
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
