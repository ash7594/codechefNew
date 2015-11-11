#include<bits/stdc++.h>
#include<ext/rope>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define REP(a,b,c) for(unsigned long long a=b;a<c;a++)
#define maxf(a,b) ((a>b)?a:b)
#define minf(a,b) ((a<b)?a:b)
#define minf3(a,b,c) ((minf(a,b)<c)?minf(a,b):c)
#define maxf3(a,b,c) ((maxf(a,b)>c)?maxf(a,b):c)
#define nl cout<<endl
using namespace std;
using namespace __gnu_cxx;

vector<int> factors(10000001,0);
bitset<10000001> table;
//vector<unsigned long long> preval(10000001,0);

unsigned long long read() {
      char c = gc();
        while(c<'0' || c>'9') c = gc();
          unsigned long long ret = 0;
          while(c>='0' && c<='9') {
                  ret = 10 * ret + c - 48;
                      c = gc();
                        }
            return ret;
}

inline void write(unsigned long long x){

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

void init() {
	//table[1][1] = 1;
	//cout<<"yo";
	int N = 10000000;
	int n = sqrt(10000000);
	int x,sq,i;
	for (i=2;i<=n;i++) {
		if (table[i] != 0) continue;
		factors[i] = i;
		//preval[i] = i*(i-1)+1;
		for (int j=i*i;j<=N;j+=i) {
			if (factors[j] == 0) factors[j] = i;
			table.set(j);
			//factors[j].push_back(i);
		}
		//x = preval[i];
//		for (unsigned long long j=i*i;j<=N;j*=i) {
//			table[j] = 2;
//			//preval[j] = sq*x-i+1;
//			//x = preval[j];
//		}
	}

	for (;i<=N;i++) {
		if (table[i] != 0) continue;
		factors[i] = i;
		//preval[i] = i*(i-1)+1;
	}
}

unsigned long long lpow(unsigned long long x, unsigned long long y) {
	unsigned long long temp;
	if (y==0) return 1;
	temp = lpow(x,y/2);
	if (y%2 == 0) return temp*temp;
	else return x*temp*temp;
}

int main() {
	init();
	unsigned long long t = read(),n;
	unsigned long long ans,a,count;
	int inp = 1;
	while(t--) {
		n = read();
		
		if (n == 1) {
			printf("1\n");
		} else if (table[n] == 0) {
			//write(preval[n]);
			printf("%llu\n",n*(n-1)+1);
//		} else if (table[n] == 2) {
//			unsigned long long f = factors[n][0];
//			unsigned long long x = f*(f-1)+1;
//			write(f*f*x-f+1);
		} else {
			ans = 1;
			while(n>1) {
				a = factors[n];
				count = 0;
				while(factors[n] == a) {
					n/=a;
					count++;
				}
				ans = ans * ((lpow(a,2*count+1)+1)/(a+1));
			}
			printf("%llu\n",ans);
			//cout<<ans<<endl;
		}
	}
	return 0;
}
