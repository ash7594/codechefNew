#include<bits/stdc++.h>
#define billion 1000000000
using namespace std;

int main() {
	int t;
	cin>>t;
	double p;
	int m;
	double rob, robx, roby;
	while (t--) {
		rob = billion;
		scanf("%d",&m);
		scanf("%lf",&p);

		if (m == 1) {
			robx = rob;
			roby = 0;
			printf("%.3f %.3f\n",robx,roby);
			continue;
		}

		if (m%2 == 1){
            robx = (1+pow(p,m))/(1+p) * billion;
			roby = billion - robx;
            printf("%.3f %.3f\n",robx,roby);
            continue;
		} else {
			robx = (1-pow(p,m))/(1+p) * billion;
            roby = billion - robx;
			printf("%.3f %.3f\n",robx,roby);
            continue;
		}	
	}
	return 0;
}
