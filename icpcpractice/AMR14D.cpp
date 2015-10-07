#include<stdio.h>
#include<string.h>

int main(){
	int t,flag,i,n,num;
	int h[1001];
	scanf("%d",&t);
	while(t--){
		flag = 0;
		memset(h,0,sizeof(h));
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&num);
			if(h[num])
				flag = 1;
			else
				h[num]=1;
		}
		if(flag)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}