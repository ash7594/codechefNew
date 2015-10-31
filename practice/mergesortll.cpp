#include<bits/stdc++.h>
#define gc getchar_unlocked
#define REP(a,b,c) for(int a=b;a<c;a++)
#define maxf(a,b) ((a>b)?a:b)
#define minf(a,b) ((a<b)?a:b)
#define minf3(a,b,c) ((minf(a,b)<c)?minf(a,b):c)
#define maxf3(a,b,c) ((maxf(a,b)>c)?maxf(a,b):c)
#define nl cout<<endl
using namespace std;

int read() {
      char c = gc();
        while(c<'0' || c>'9') c = gc();
          int ret = 0;
          while(c>='0' && c<='9') {
                  ret = 10 * ret + c - 48;
                      c = gc();
                        }
            return ret;
}

struct node {
	int key;
	node *next;
};

class linkedlist  {
	public:
	node *front;
	
	linkedlist() {
		front = NULL;
	}

	linkedlist(int n) {
		front = new node;
		front->key = 0;
		front->next = NULL;
		node *p,*temp = front;
		REP(i,0,n-1) {
			p = new node;
			p->key = 0;
			p->next = NULL;
			temp->next = p;
			temp = p;
		}
	}

	void merge(linkedlist a, linkedlist b) {
		node *temp = a.front;
		node *temp2 = b.front;
		node *pre = a.front;
		while(temp != NULL) {
        	if (temp->key > temp2->key) {
            	swap(temp->key,temp2->key);
				
				node *curnode = temp2, *trav = temp2->next, *pre2 = temp2;
				if (temp2->next != NULL && temp2->key <= (temp2->next)->key)
					continue;
				if (trav == NULL)
					continue;
				temp2 = trav;
				while(trav != NULL && curnode->key>trav->key) {
					pre2 = trav;
					trav = trav->next;
				}
				curnode->next = trav;
				pre2->next = curnode;

				pre = temp;
            	temp = temp->next;
        	} else {
            	//swap(temp->key,temp2->key);
				pre = temp;
           		temp = temp->next;
        	}
    	}

		pre->next = temp2;
	}

	void mergesort(linkedlist a) {
		if (a.front != NULL) {
			node *t1 = a.front;
			node *t2 = a.front->next;
			if (t1->next == NULL)
				return;
			if (t2->next == NULL) {
				if (t1->key > t2->key) {
					swap(t1->key,t2->key);
				}
				return;
			}
	
			//finding middle
			while(t2 != NULL) {
				t1 = t1->next;
				t2 = t2->next;
				if (t2 != NULL)
					t2 = t2->next;
			}
			t2 = t1->next;
			t1->next = NULL;

			linkedlist b;
			b.front = t2;

			mergesort(a);
			mergesort(b);
			merge(a,b);
		}
	}

	void display() {
		node *temp = this->front;
		while(temp != NULL) {
			cout<<temp->key<<" ";
			temp = temp->next;
		}
	}
};

int main() {
	srand(time(NULL));

	int opt;
	cout<<"\n** MENU **\n";
	cout<<"1. Merge 2 linked lists\n";
	cout<<"2. Mergesort on 1 linked list\n";
	nl;
	cout<<"Enter option: ";
	cin>>opt;

	int m = (rand()%10)+1, n = (rand()%10)+1;

	if (opt == 1) {

	cout<<"Enter size of ll1: "<<m;
	nl;
	cout<<"Enter size of ll2: "<<n;
	nl;

	linkedlist myll1(m);
	linkedlist myll2(n);
	
	cout<<"Linked list 1:\n";

	node *temp = myll1.front;
	int ele = 0;
	while(temp != NULL) {
		temp->key = (rand()%10)+ele;
		ele = temp->key;
		temp = temp->next;
	}
	myll1.display();
	nl;

	cout<<"Linked list 2:\n";

	temp = myll2.front;
	ele = 0;
	while(temp != NULL) {
		temp->key = rand()%10+ele;
		ele = temp->key;
		temp = temp->next;
	}
	myll2.display();
	nl;

	cout<<"Merged ll:\n";
	myll1.merge(myll1,myll2);
	myll1.display();
	nl;
	
	} else if (opt == 2) {
		cout<<"Enter size of ll1: "<<m;
    	nl;
		linkedlist myll1(m);

		cout<<"Linked list 1:\n";
    
    	node *temp = myll1.front;
    	while(temp != NULL) {
        	temp->key = rand()%100;
        	temp = temp->next;
   	 	}
    	myll1.display();
    	nl;

		myll1.mergesort(myll1);
		cout<<"Sorted LL:\n";
		myll1.display();
		nl;
	}
	nl;
	return 0;
}
