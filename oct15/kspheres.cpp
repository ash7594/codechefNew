#include<bits/stdc++.h>
#define MAXV 1000000007
using namespace std;

struct node {
	long long ele[1001];
};

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
    return pow(a,MAXV-2,MAXV);
}

long long modinv[1001];

void init(long long c) {
	long long i=2;
	while (i<=c) {
		modinv[i] = modInverse(i);
		i++;
	}
}

int main () {
	long long n,m,c,input;
	cin>>n>>m>>c;
	long long hash1[c+1], hash2[c+1];
	for (long long i=0;i<=c;i++) {
		hash1[i] = 0;
		hash2[i] = 0;
	}

	for (long long i=0;i<n;i++) {
		cin>>input;
		hash1[input]++;
	}

	for (long long i=0;i<m;i++) {
		cin>>input;
		hash2[input]++;
	}

	////////////////
	//
//	
//	for (long long i=1;i<=c;i++) {
//		cout<<hash1[i]<<" ";
//	}
//	cout<<endl;
//	for (long long i=1;i<=c;i++) {
//		cout<<hash2[i]<<" ";
//	}
//	cout<<endl;
//
	//
	////////////////
	vector<node> a;
	node tnode;
	long long ele;
	long long noe = 0;
	for (long long i=1;i<=c;i++) {
		ele = (hash1[i] * hash2[i])%MAXV;
		if (ele != 0) {
			tnode.ele[1] = ele;
			a.push_back(tnode);
			noe++;
		}
	}

	for (long long i=0;i<a.size();i++) {
		for (long long j=2;j<=1000;j++) {
			a[i].ele[j] = (a[i].ele[j-1] * a[i].ele[1])%MAXV;
		}
	}

	/////////////////
	//    //
//	//
//	for (long long i=0;i<a.size();i++) {
//		for (long long j=1;j<=a.size();j++) {
//        	cout<<a[i].ele[j]<<" ";
//	    }
//	    cout<<endl;
//	}
	//
	//                                                    //
	//                                                        /////////////////

	vector<long long> p;
	p.push_back(0);
	for (long long i=1;i<=1000;i++) {
		ele = 0;
		for (long long j=0;j<a.size();j++) {
			ele = (ele + a[j].ele[i])%MAXV;
		}
		p.push_back(ele);
	}

	////////////////
//	//
//	
//	cout<<"p:\n";
//	for (long long i=1;i<p.size();i++) {
//		cout<<p[i]<<" ";
//	}
//	cout<<endl;
//
	//
	////////////////

	vector<long long> e;
	e.push_back(1);
	e.push_back(p[1]);
	long long tempv;

	init(1000);

	for (long long i=2;i<=a.size();i++) {
		ele = 0;
		for (long long j=1;j<=i;j++) {
			if (j%2 == 1) {
				tempv = (e[i-j]*p[j])%MAXV;
			} else {
				tempv = (e[i-j]*p[j])%MAXV;
				tempv = MAXV - tempv;
			}
			//if (tempv < 0) tempv += MAXV;
			ele = (ele + tempv)%MAXV;
		}
		ele = (ele * modinv[i])%MAXV;
		//if (ele <= 0) {
		//	while (1) {}
		//}
		//if (ele < 0) ele += MAXV;
		//if (ele%i != 0 && i==2) {
		//	while(1) {}
		//}
		//ele = ele%MAXV;
		e.push_back(ele);
	}

	for (long long i=2;i<e.size();i++) {
		printf("%lld ",e[i]);
		c--;
	}

	//if (e.size() > 1000) {
 	//	while (1) {}
	//}
	for (long long i=0;i<c;i++) {
		printf("0 ");
	}
	return 0;
}
