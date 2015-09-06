#include<bits/stdc++.h>
#define maxf(a,b) ((a>b)?a:b)
using namespace std;

struct node {
	int num;
	node *l;
	node *r;
}*root1,*root2;

void trie_push(int num, node *root) {
	vector<int> a;
	while (num>0) {
		
	}
}

int main() {
	int n;
	cin>>n;
	int a[n],b[n];
	int xored = 0;
	int maxval = -1;
	for (int i=0;i<n;i++) {
		cin>>a[i];
		xored = xored^a[i];
		b[i] = xored;
		maxval = maxf(maxval, a[i]);
	}

	root1 = new node;
	root1->l = NULL;
	root1->r = NULL;
	root2 = new node;
    root2->l = NULL;
    root2->r = NULL;

	for (int i=1;i<n;i++) {
		trie_push(b[i], root2);
	}
	
	
}
