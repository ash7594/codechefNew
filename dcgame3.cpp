#include<bits/stdc++.h>
#define maxf(a,b) ((a>b)?a:b)
#define gc getchar_unlocked
using namespace std;

struct node {
	long long num_permute;
	long long group_add;
};

map<int, node> dumpmap;

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

vector<int> getMaxIndex(int arr[], int start, int end) {
	long long ele = -1;
	vector<int> v;
	for (int i=start;i<=end;i++) {
		if (ele < arr[i]) {
			ele = arr[i];
			v.clear();
			v.push_back(i);
		} else if (ele == arr[i]) {
			v.push_back(i);
		}
	}
	return v;
}

void getSubarrayMax(int arr[], int i, int j) {
	if (i > j) return;
	int k;
	vector<int> v = getMaxIndex(arr, i, j);
	long long count = 0;//(v[0]-i+1)*(j-v[0]+1);
	for (k=0;k<v.size()-1;k++) {
		count += (v[k]-i+1)*(v[k+1]-v[k]);
	}
	count += (v[k]-i+1)*(j-v[k]+1);
	dumpmap[arr[v[0]]].num_permute += count;
	getSubarrayMax(arr, i, v[0]-1);
	for (k=0;k<(v.size()-1);k++) {
		getSubarrayMax(arr, v[k]+1, v[k+1]-1);
	}
	getSubarrayMax(arr, v[v.size()-1]+1, j);
}

int main() {
	int n,m;
	n = read_int();
    m = read_int();
	int arr[n];
	for (int i=0;i<n;i++) {
		arr[i] = read_int();
		dumpmap[arr[i]].num_permute = 0;
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
	getSubarrayMax(arr, 0, n-1);

	typedef map<int, node>::iterator iter_type;
	iter_type tempIter, endIter;
	int tempval;
	long long count = 0;
	/*
	for (iter_type iter = dumpmap.begin(); iter != dumpmap.end(); iter++) {
		tempval = (iter->second).freq;
		(iter->second).num_permute = ((count+tempval-1)*(count+tempval) - (count-1)*count)/2;
		count += tempval;
	}
	*/
	for (iter_type iter = dumpmap.begin(); iter != dumpmap.end(); iter++) {
		//cout<<iter->first<<" "<<(iter->second).num_permute<<endl;
		count += (iter->second).num_permute;
		(iter->second).group_add = count;
	}

	//base_check
	/*
	if ((dumpmap.rbegin()->second).group_add != n*(n+1)/2) {
		while (1) {}
	}
	*/

	char ch, starter;
	int k;
	while (m--) {
		fastRead_char(&ch);
        k = read_int();
        //scanf("%c",&starter);
        fastRead_char(&starter);

		if (ch == '=') {
			if (dumpmap.find(k) == dumpmap.end()) {
				if (starter == 'D') {
					cout<<"C";
				} else {
					cout<<"D";
				}
				continue;
			}

			if (dumpmap[k].num_permute%2 == 0) {
				if (starter == 'D') {
					cout<<"C";
				} else {
					cout<<"D";
				}
			} else {
				if (starter == 'D') {
					cout<<"D";
                } else {
            		cout<<"C";
                }
			}
			continue;
		}

		if (ch == '<') {
			tempIter = dumpmap.lower_bound(k);
			if (tempIter == dumpmap.end() || tempIter == dumpmap.begin()) {
				if (starter == 'D') {
					cout<<"C";
				} else {
					cout<<"D";
				}
				continue;
			}
			tempIter--;
			if ((tempIter->second).group_add%2 == 0) {
				if (starter == 'D') {
                    cout<<"C";
                } else {
                    cout<<"D";
                }
			} else {
				if (starter == 'D') {
                    cout<<"D";
                } else {
                    cout<<"C";
                }
			}
			continue;
		}

		if (ch == '>') {
            tempIter = dumpmap.upper_bound(k);
			endIter = dumpmap.end();
			endIter--;
            if (tempIter == dumpmap.end()) {
                if (starter == 'D') {
                    cout<<"C";
                } else {
                    cout<<"D";
                }
                continue;
            }

			long long differ = (endIter->second).group_add - (tempIter->second).group_add;
            if ((differ + (tempIter->second).num_permute)%2 == 0) {
                if (starter == 'D') {
                    cout<<"C";
                } else {
                    cout<<"D";
                }
            } else {
                if (starter == 'D') {
                    cout<<"D";
                } else {
                    cout<<"C";
                }
            }
            continue;
        }
	}
	return 0;
}
