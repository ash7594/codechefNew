#include<bits/stdc++.h>
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

int main () {
	int t;
	t = read_int();
	while (t--) {
		int n,k;
		n = read_int();
		k = read_int();
		vector<int> arr(k);
		//copy_n(istream_iterator<int>(cin), k, back_inserter(arr));
		for_each(arr.begin(), arr.end(), [](int &a) {a = read_int();});

		sort(arr.begin(), arr.end());
		if(arr.front() == 1) {
			printf("Chef\n");
			continue;
		}

		long long sum = 0;
		
		for (int i=0;i<arr.end();i++) {
			if (a[i] <= sum + 1) {
				sum += a[i];
			} else
			
		}

	}	
	return 0;
}
