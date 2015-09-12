#include<bits/stdc++.h>
using namespace std;

int main () {
	long long i, k, s;
	double ai, bi;
	double ak, bk, ans;
	cin>>i>>k>>s>>ai>>bi;
	
	if (i <= k) {
		if ((k-i)%2 == 0) {
			ak = pow(2,(k-i)*2-s)*ai;
			bk = pow(2,(k-i)*2-s)*bi;
			printf("%.5lf", (ak+bk));
		} else {
			k--;
			ak = pow(2,(k-i)*2-s)*(sqrt(2)*(ai+bi)-sqrt(6)*(ai-bi));
            bk = pow(2,(k-i)*2-s)*(sqrt(2)*(ai-bi)+sqrt(6)*(ai+bi));
			printf("%.5lf", (ak+bk));
		}
	} else {
		if ((i-k)%2 == 0) {
            ak = ai/pow(2,(i-k)*2+s);
            bk = bi/pow(2,(i-k)*2+s);
			printf("%.5lf", (ak+bk));
        } else {
            k++;
			ai = ai/pow(2,(i-k)*2+s);
            bi = bi/pow(2,(i-k)*2+s);
			ak = ((ai+bi)-sqrt(3)*(ai-bi))/(8*sqrt(2));
			bk = (sqrt(3)*(ai+bi)+(ai-bi))/(8*sqrt(2));
			printf("%.5lf", (ak+bk));
        }
	}
	return 0;
}
