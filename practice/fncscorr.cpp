#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef unsigned long long LL;
#define lowbit(x) ((x)&-(x))
int n;
int a[100005];
LL c[100005];
int L[100005],R[100005];
int Q;
int t[405][100005];
int belong[100005];// (i-1)/B+1
LL sum[405];
int B,NUM;
void add(int x,LL d){
	while(x<=n){
		c[x]+=d;
		x+=lowbit(x);
	}
}
LL ask(int x){
	LL ret=0;
	while(x){
		ret+=c[x];
		x-=lowbit(x);
	}
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d%d",&L[i],&R[i]);
	}
	B=sqrt(n)+1;
//	printf("#%d\n",B);
	NUM=(n-1)/B+1;
	for(int i=1;i<=n;i++) belong[i]=(i-1)/B+1;
	for(int i=1;i<=n;i++) c[i]=a[i];
	for(int i=1;i<=n;i++){
		if(i+lowbit(i)<=n){
			c[i+lowbit(i)]+=c[i];
		}
	}
	for(int i=1;i<=n;i++){
		t[belong[i]][L[i]]++;
		t[belong[i]][R[i]+1]--;
	}
	for(int i=1;i<=NUM;i++){
		for(int j=1;j<=n;j++){
			t[i][j]+=t[i][j-1];
			sum[i]+=t[i][j]*1ULL*a[j];
		}
	}
	scanf("%d",&Q);
	while(Q--){
		int type,x,y;
		scanf("%d%d%d",&type,&x,&y);
		if(type==1){
			for(int i=1;i<=NUM;i++){
				sum[i]-=t[i][x]*1ULL*a[x];
				sum[i]+=t[i][x]*1ULL*y;
			}
			add(x,-a[x]);
			a[x]=y;
			add(x,a[x]);
		}else{
			int Ln,Rn;
			Ln=belong[x],Rn=belong[y];
			LL ans=0;
			if(Ln==Rn){
				for(int i=x;i<=y;i++){
					ans+=ask(R[i])-ask(L[i]-1);
				}
			}else{
				for(int i=Ln+1;i<Rn;i++) ans+=sum[i];
				int lim;
				lim=Ln*B;
				lim=min(lim,y);
				for(int i=x;i<=lim;i++){
					ans+=ask(R[i])-ask(L[i]-1);
				}
				lim=(Rn-1)*B+1;
				lim=max(lim,x);
				for(int i=lim;i<=y;i++){
					ans+=ask(R[i])-ask(L[i]-1);
				}
			}
			printf("%llu\n",ans);
		}
	}
	return 0;
}
 
