#include<bits/stdc++.h>
#define MAXV 1000000007
using namespace std;

struct node {
	long long ele[1001];
};

int main () {
	int n,m,c,input;
	cin>>n>>m>>c;
	int hash1[c+1], hash2[c+1];
	for (int i=0;i<=c;i++) {
		hash1[i] = 0;
		hash2[i] = 0;
	}

	for (int i=0;i<n;i++) {
		cin>>input;
		hash1[input]++;
	}

	for (int i=0;i<m;i++) {
		cin>>input;
		hash2[input]++;
	}

	////////////////
	//
//	
//	for (int i=1;i<=c;i++) {
//		cout<<hash1[i]<<" ";
//	}
//	cout<<endl;
//	for (int i=1;i<=c;i++) {
//		cout<<hash2[i]<<" ";
//	}
//	cout<<endl;
//
	//
	////////////////
	vector<node> a;
	node tnode;
	long long ele;
	int noe = 0;
	for (int i=1;i<=c;i++) {
		ele = (hash1[i] * hash2[i])%MAXV;
		if (ele != 0) {
			tnode.ele[1] = ele;
			a.push_back(tnode);
			noe++;
		}
	}

	for (int i=0;i<a.size();i++) {
		for (int j=2;j<=noe;j++) {
			a[i].ele[j] = (a[i].ele[j-1] * a[i].ele[1])%MAXV;
		}
	}

	/////////////////
	//    //
//	//
//	for (int i=0;i<a.size();i++) {
//		for (int j=1;j<=a.size();j++) {
//        	cout<<a[i].ele[j]<<" ";
//	    }
//	    cout<<endl;
//	}
	//
	//                                                    //
	//                                                        /////////////////

	vector<long long> p;
	p.push_back(0);
	for (int i=1;i<=noe;i++) {
		ele = 0;
		for (int j=0;j<a.size();j++) {
			ele = (ele + a[j].ele[i])%MAXV;
		}
		p.push_back(ele);
	}

	////////////////
//	//
//	
//	cout<<"p:\n";
//	for (int i=1;i<p.size();i++) {
//		cout<<p[i]<<" ";
//	}
//	cout<<endl;
//
	//
	////////////////

	vector<long long> e;
	e.push_back(1);
	e.push_back(p[1]);
	for (int i=2;i<=noe;i++) {
		ele = 0;
		for (int j=1;j<=i;j++) {
			ele = ele + pow(-1,j-1)*((e[i-j]*p[j])%MAXV);
		}
		ele /= i;
		ele %= MAXV;
		if (ele < 0) ele += MAXV;
		e.push_back(ele);
	}

	for (int i=2;i<e.size();i++) {
		printf("%lld ",e[i]);
		c--;
	}

	for (int i=0;i<c;i++) {
		printf("0 ");
	}
	return 0;
}
