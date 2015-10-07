#include<bits/stdc++.h>
#define gc getchar_unlocked
using namespace std;

int hash[5000001] = {0};

int read_int() {
		  char c = gc();
		  	    while(c<'0' || c>'9') c = gc();
						  int ret = 0;
						  while(c>='0' && c<='9') {
							  			      ret = 10 * ret + c - 48;
											  				      c = gc();
																  					    }
						  		    return ret;
}

int main () {
		int t,n,n2,root,flag;
			t = read_int();
				while (t--) {
							n = read_int();
									if (hash[n] == 2) {
													printf("YES\n");
																continue;
																		} else if (hash[n] == 1) {
																						printf("NO\n");
																									continue;
																											}
											if (n == 1) {
															printf("NO\n");
																		hash[n] = 1;
																					continue;
																							}
													n2 = n;
															flag = 0;
																	root = sqrt(n);
																			for (int i=2;i<=root;i++) {
																							if ((i-1)%4 == 0 && n2%i==0) {
																												flag = 1;
																																goto ans;
																																			}

																										while (n2%i == 0) {
																															n2/=i;
																																		}
																													root = sqrt(n2);
																															}
																					if ((n2-1)%4 == 0 && n2!=1) {
																									flag = 1;
																											}
																							ans:
																							if (flag == 1) {
																											printf("YES\n");
																														hash[n] = 2;
																																} else {
																																				printf("NO\n");
																																							hash[n] = 1;
																																									}
																								}
					return 0;
}
