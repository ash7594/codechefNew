#include <bits/stdc++.h>

using namespace std;

typedef long long L;

int main()
{
  int t;
  scanf("%d", &t);
  while(t--) {
    L n;
    int x, h = 0;
    scanf("%lld %d", &n, &x);
    L nn = n, p2 = 1;
    while(nn - p2 > 0) {
      nn -= p2;
      p2 = 2LL * p2;
      h++;
    }
    p2 /= 2;
    if(x > h) {
      printf("0 ");
    } else if(x == h) {
      printf("%lld ", nn);
    } else {
      printf("%lld ", (1LL << x));
    }
    if(x > h) {
      printf("0\n");
    } else if(x == h) {
      printf("1\n");
    } else {
      L res = nn + p2 - (nn + 1)/2;
      while(x--) {
        p2 /= 2;
        nn = (nn + 1)/2LL;
        res = nn + p2 - (nn + 1)/2;
      }
      printf("%lld\n", res);
    }
  }
  return(0);
}
