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

int main() {
	vector<string> grid;
	int red = 0, blue = 0;
	int N = grid.size();
	int M = grid[0].size();
	
	for (int i=0;i<N;i++) {
		bool ongoing = false;
		for (int j=0;j<M;j++) {
			if (grid[i][j] == '.' || grid[i][j] == 'B') ongoing = false;
			else if (!ongoing && (grid[i][j] == 'R' || grid[i][j] == 'G')) {
				red++;
				ongoing = true;
			}
		}
	}

	for (int i=0;i<M;i++) {
		bool ongoing = false;
		for (int j=0;j<N;j++) {
			if (grid[j][i] == '.' || grid[j][i] == 'R') ongoing = false;
			else if (!ongoing && (grid[j][i] == 'B' || grid[j][i] == 'G')) {
				blue++;
				ongoing = true;
			}
		}
	}

	return red + blue;
}
