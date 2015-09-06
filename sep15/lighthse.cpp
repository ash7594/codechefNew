#include<bits/stdc++.h>
#define maxf(a,b) ((a>b)?a:b)
#define minf(a,b) ((a<b)?a:b)
using namespace std;

int main () {
	int t,n;
	int left, right, top, down, top2;
	int topi, top2i;
	int top2right, topleft;
	cin>>t;
	while (t--) {
		cin>>n;
		int p[n][2];
		for (int i=0;i<n;i++) {
			cin>>p[i][0]>>p[i][1];
		}

		left = right = p[0][0];
		top = down = p[0][1];

		for (int i=1;i<n;i++) {
			left = minf(left, p[i][0]);
			right = maxf(right, p[i][0]);
			top = maxf(top, p[i][1]);
			down = minf(down, p[i][1]);
		}

		for (int i=0;i<n;i++) {
			if (left == p[i][0] && top == p[i][1]) {
				cout<<"1\n"<<i+1<<" SE\n"; goto endp;
			} else if (left == p[i][0] && down == p[i][1]) {
                cout<<"1\n"<<i+1<<" NE\n"; goto endp;
            } else if (right == p[i][0] && top == p[i][1]) {
                cout<<"1\n"<<i+1<<" SW\n"; goto endp;
            } else if (right == p[i][0] && down == p[i][1]) {
                cout<<"1\n"<<i+1<<" NW\n"; goto endp;
            }
		}
		
		top2 = down;
		for (int i=0;i<n;i++) {
			if (p[i][1] >= top2 && p[i][1] != top) {
				top2 = p[i][1];
				//top2i = i;
			}
		}

		topleft = right;
		for (int i=0;i<n;i++) {
			if (p[i][1] == top) {
				if (p[i][0] <= topleft) {
					topi = i;
					topleft = p[i][0];
				}
			}
		}

		top2right = left;
		for (int i=0;i<n;i++) {
            if (p[i][1] == top2) {
                if (p[i][0] >= top2right) {
                    top2i = i;
                    top2right = p[i][0];
                }
            }
        }

		if (p[topi][0] > p[top2i][0]) {
			topleft = left;
        	for (int i=0;i<n;i++) {
            	if (p[i][1] == top) {
                	if (p[i][0] >= topleft) {
                    	topi = i;
                    	topleft = p[i][0];
                	}
            	}
        	}

        	top2right = right;
        	for (int i=0;i<n;i++) {
            	if (p[i][1] == top2) {
                	if (p[i][0] <= top2right) {
                    	top2i = i;
                    	top2right = p[i][0];
                	}
           		}
        	}

			cout<<"2\n";
        	cout<<top2i+1<<" SE\n";
        	cout<<topi+1<<" SW\n";
		} else {
			cout<<"2\n";
			cout<<topi+1<<" SE\n";
			cout<<top2i+1<<" SW\n";
		}
		endp:;
	}
	return 0;
}
