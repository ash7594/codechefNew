#include<bits/stdc++.h>
using namespace std;

int main () {
	int t,n,n2,root,flag;
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		n2 = n;
		flag = 0;
		root = sqrt(n);
		for (int i=2;i<=root;) {
			if (n2%i == 0) {
				if ((i-1)%4 == 0) {
					flag = 1;
					break;	
				}
				n2/=i;
				root = sqrt(n2);
			} else i++;
		}
		if ((n2-1)%4 == 0) {
			flag = 1;
		}
		if (flag == 1) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
