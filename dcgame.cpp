#include<bits/stdc++.h>
#define maxf(a,b) ((a>b)?a:b)
using namespace std;

struct node {
	int freq;
	long long num_permute;
	long long group_add;
	map<int, int> innermap;
};

bool descendingOrder(long long a, long long b) { return a>b; }
typedef map<long long, node>::iterator iter_type;
typedef map<int, int>::iterator iter_type2;
map<long long, node> dumpmap;

vector<int> getMaxIndex(long long arr[], int start, int end) {
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

vector<int> getMaxIndex2(long long arr[], int start, int end, long long sarr[], int sa) {
	vector<int> v;
	if (start == end) {
		v.push_back(start);
		return v;
	}

	loopagain:
	iter_type2 iter = dumpmap[sarr[sa]].innermap.lower_bound(start);
	iter_type2 iterend = dumpmap[sarr[sa]].innermap.end();

	if (iter == iterend) {
		sa++; goto loopagain;
	}
	if (iter->first > end) {
		sa++; goto loopagain;
	}

	iter_type2 itercopy = iter;
	for (;iter != iterend && (iter->first) <= end;iter++) {
		v.push_back(iter->first);
	}
	dumpmap[sarr[sa]].innermap.erase(itercopy, iter);
	return v;
}

void getSubarrayMax(long long arr[], int i, int j, long long sarr[], int sa) {
	if (i > j) return;
	int k;
	vector<int> v = getMaxIndex2(arr, i, j, sarr, sa);
	long long count = 0;//(v[0]-i+1)*(j-v[0]+1);
	for (k=0;k<v.size()-1;k++) {
		count += (v[k]-i+1)*(v[k+1]-v[k]);
	}
	count += (v[k]-i+1)*(j-v[k]+1);
	dumpmap[arr[v[0]]].num_permute += count;

	if (dumpmap[sarr[sa]].innermap.empty()) {
		sa++;
	}
	getSubarrayMax(arr, i, v[0]-1, sarr, sa);
	for (k=0;k<(v.size()-1);k++) {
		getSubarrayMax(arr, v[k]+1, v[k+1]-1, sarr, sa);
	}
	getSubarrayMax(arr, v[v.size()-1]+1, j, sarr, sa);
}

int main() {
	int n,m;
	cin>>n>>m;
	long long arr[n], sarr[n];
	for (int i=0;i<n;i++) {
		cin>>arr[i];
		sarr[i] = arr[i];
		dumpmap[arr[i]].num_permute = 0;
		dumpmap[arr[i]].innermap[i] = 0;
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
	sort(sarr, sarr + n, descendingOrder);
	getSubarrayMax(arr, 0, n-1, sarr, 0);

	iter_type tempIter, endIter;
	int tempval;
	long long count = 1;
	/*
	for (iter_type iter = dumpmap.begin(); iter != dumpmap.end(); iter++) {
		tempval = (iter->second).freq;
		(iter->second).num_permute = ((count+tempval-1)*(count+tempval) - (count-1)*count)/2;
		count += tempval;
	}
	*/
	count = 0;
	for (iter_type iter = dumpmap.begin(); iter != dumpmap.end(); iter++) {
		cout<<iter->first<<" "<<(iter->second).num_permute<<endl;
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
	long long k;
	while (m--) {
		cin>>ch>>k>>starter;
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
