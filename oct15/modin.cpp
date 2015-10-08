#include<bits/stdc++.h>
#define m 1000000007
using namespace std;

int pow(int a, int b, int MOD) {
    long long x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}
 
int modInverse(int a) {
    return pow(a,m-2,m);
}

int main () {
	int i=2;
	while (i<=1000) {		
		cout<<modInverse(i)<<endl;
		i++;
	}
	return 0;
}
