#include<bits/stdc++.h>
#define MAXV 1000000007
#define maxf(a,b) ((a>b)?a:b)
#define minf(a,b) ((a<b)?a:b)
using namespace std;

long long table[1005][1005] = {0};
//long long table2[1001][1001];

long long pow(long long a, long long b, long long MOD) {
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

long long modInverse(long long a) {
	if (a == 1) return 1;
	//if (a == 0) while (1) {}
    return pow(a,MAXV-2,MAXV);
}

long long gcd(long long a, long long b) {
	//if (a < b) {
	//	swap(a,b);
	//}
	if (b == 0) return a;
	if (b == 1) return 1;
	return gcd(b,a%b);
}

long long lcm(long long a, long long b) {
	long long prod = (a*b);
	long long gcda = gcd(maxf(a,b),minf(a,b));
	long long l = (prod/gcda);
	return l;
}

void init() {
	for (long long i=1;i<=11;i++) {
		table[i][1] = 1;
	}
	table[2][2] = 1;
	for (long long i=3;i<=11;i++) {
		for (long long j=2;j<i;j++) {
			table[i][j] = (table[i-1][j-1] + table[i-1][j]);
		}
		table[i][i] = 1;
	}
	
	//for (long long i=1;i<=1000;i++) {
	//	table2[i][1] = table[i][1];
	//}
	//table2[2][2] = table[2][2];
	for (long long i=3;i<=11;i++) {
		for (long long j=2;j<=i;j++) {
			table[i][j] = lcm(table[i][j],table[i][j-1]);
		}
	}

//	for (int i=1;i<=10;i++) {
//		for (int j=1;j<=10;j++) {
//			cout<<table2[i][j]<<" ";
//		}
//		cout<<endl;
//	}
}

int main() {
	long long t,n,k,a,b,m;
	cin>>t;
	cin>>n>>k;
	cin>>a>>b>>m;

	//if (a < 0 || b < 0) while(1) {}
	long long c[t],d[t];
	for (long long i=0;i<t-1;i++) {
		cin>>c[i];
		//if (c[i] < 0) while(1) {}
	}
	c[t-1] = 0;
	for (long long i=0;i<t-1;i++) {
	   	cin>>d[i];
		//if (d[i] < 0) while(1) {}
    }
	d[t-1] = 0;
	init();
	long long ans = 0;
	long long count = 0;
	long long temp1,temp2;
	while (t--) {
		ans = (table[n][k]*n);
		//if (ans < 0) {
		//	while(1) {}
		//}
		cout<<ans<<endl;
		temp1 = (a*ans)%m;
		//if (temp1 < 0) temp1 += m;
		n = 1 + (temp1 + c[count])%m;
		temp2 = (b*ans)%n;
		//if (temp2 < 0) temp2 += n;
		k = 1 + (temp2 + d[count])%n;
		if (n<k) {
			while(1) {}
		}
		count++;
	}
	return 0;
}
