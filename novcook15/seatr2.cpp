#include<bits/stdc++.h>
#include<ext/rope>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define REP(a,b,c) for(int a=b;a<c;a++)
#define maxf(a,b) ((a>b)?a:b)
#define minf(a,b) ((a<b)?a:b)
#define minf3(a,b,c) ((minf(a,b)<c)?minf(a,b):c)
#define maxf3(a,b,c) ((maxf(a,b)>c)?maxf(a,b):c)
#define nl cout<<endl
using namespace std;
using namespace __gnu_cxx;

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

inline void write(int x){

         register char buffor[35];
         register int i=0;
         do{
               buffor[i++]=(x%10)+'0';
               x/=10;
            } while(x);
           i--;
            while(i>=0) pc(buffor[i--]);
            pc('\n');
       }

struct node {
	int a;
	vector<node *> p;
};
node *root = NULL;

void createNodes(node *nodes[], int n) {
	REP(i,0,n) {
		nodes[i] = new node;
		nodes[i]->a = i+1;
	}
	root = nodes[0];
}

void addedge(int a, int b) {
	if () {

	}
}

int main() {
	int t = read();
	int a,b;
	while(t--) {
		int n = read();
		node *nodes[n];
		createNodes(nodes,n);
		int m = read();
		REP(i,0,n-1) {
			a = read();
			b = read();

		}
	}	
}
