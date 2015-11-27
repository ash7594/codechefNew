#include<bits/stdc++.h>
using namespace std;

struct node {
	int key;
	node *l;
	node *r;
}*ROOT = NULL;

void insert(node *root, int k, node *parent, char dir) {
	if (root == NULL) {
		node *p = new node;
		p->key = k;
		p->l = NULL;
		p->r = NULL;
		if (parent == NULL) {
			ROOT = p;
		} else {
			if (dir == 'l') parent->l = p;
			else parent->r = p;
		}
		return;
	}
	if (root->key > k) insert(root->l, k, root, 'l');
	else if (root->key < k) insert(root->r, k, root, 'r');
	else return;
}

void disp() {
	
}

void inorder(node *root) {
	if (root == NULL) return;
	inorder(root->l);
	cout<<root->key<<" ";
	inorder(root->r);
}

int main() {
	srand(time(NULL));
	for (int i=0;i<10;i++) {
		int key = rand()%50+1;
		cout<<"Key: "<<key<<endl;
		insert(ROOT,key,NULL,'l');
		inorder(ROOT);
		cout<<endl;
	}
	return 0;
}
