#include<bits/stdc++.h>
#define maxv 1000001
#define maxf(a,b) ((a>b)?a:b)
#define minf(a,b) ((a<b)?a:b)
using namespace std;

int t, n, h;
int a[maxv],b[maxv];
int memo[maxv] = {0};

int getFreeGrid(int index) {
	int sum = 0;
	if (memo[index] != 0) {
		return memo[index];
	}
	for (int i=0;i<n;i++) {
		if (index >= a[i] && index <= b[i]) {
			sum++;
		}
	}
	memo[index] = sum;
	return sum;
}

int maxFreeGrid(int index, long long maxgrids, int maxval) {
	int count = 0, count2 = 0;
	int i;
	count = getFreeGrid(index);
	count2 = getFreeGrid(index-h);
	maxgrids = maxgrids - count2 + count;
	if (index != maxval) {
		return maxf(maxgrids, maxFreeGrid(index+1, maxgrids, maxval));
	}
	return maxgrids;
}

int main() {
	int minval, maxval;
	long long count;
	cin>>t;
	while (t--) {
		cin>>n>>h;
		cin>>a[0]>>b[0];
		count = 0;
		minval = a[0];
		maxval = b[0];
		count = b[0] - a[0] + 1;
		for (int i=1;i<n;i++) {
			cin>>a[i]>>b[i];
			minval = minf(minval, a[i]);
			maxval = maxf(maxval, b[i]);
			count += (b[i] - a[i] + 1);
		}
		int differ = maxval - minval + 1;
		if (differ <= h) {
			cout<<(differ*n) - count + (h-differ)*n<<endl;
			continue;
		}

		long long maxgrids = 0;
		for (int i=0;i<h;i++) {
        	maxgrids += getFreeGrid(minval+i);
    	}
		cout<<n*h - maxf(maxFreeGrid(minval+h, maxgrids, maxval), maxgrids)<<endl;
	}
	return 0;
}
