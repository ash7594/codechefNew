#include<iostream>
#include<math.h>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<limits.h>
#include<vector>
#define gc getchar_unlocked
using namespace std;




void fastWrite(int a)
{
	char snum[20];
	int i=0;
	do
	{
		snum[i++]=a%10+48;
		a=a/10;
	}while(a!=0);
	i=i-1;
	while(i>=0)
	putchar_unlocked(snum[i--]);
	putchar_unlocked('\n');
}

void fastin(int &x)
{
	int sign=1;
	register int a=gc();
	x=0;
	for(;a<48 || a>57;a=gc())
	{
		if(a=='-')
		sign=-1;
	}
	for(;a>47 && a<58;a=gc())
		x=(x<<1)+(x<<3)+a-48;	
	
	x=x*sign;
		
}
void fastin(long long int &x)
{
	register int a=gc();
	x=0;
	for(;a<48 || a>57;a=gc());
	for(;a>47 && a<58;a=gc())
		x=(x<<1)+(x<<3)+a-48;	
}

long long int bser(int l,int h,int s,long long int arr[])
{
	if(h<l)
	return l;
	else 
	{
		int mid=(l+h)/2;
		if(arr[mid]<=s)
		return bser(mid+1,h,s,arr);
		else
		return bser(l,mid-1,s,arr);	
	}	
}

int main()
{
	int i,t,len,k,q,j,c_0,c_1;
	char string[100005];
	long long int r,l,sum=0,cfr[100005],limit[100005];
	fastin(t);
	while(t--)
	{
		fastin(len);fastin(k);fastin(q);
		scanf("%s",string);
		c_0=c_1=0;
		if(string[0]=='1') c_1++;
		else c_0++;
		j=0;
		for(i=0;i<len;i++)
		{
			while(j<len && c_0<=k && c_1<=k)
			{
				j+=1;
				if(j>len-1) break;
				if(string[j]=='1') c_1++;
				else c_0++;
			}
			limit[i]=j-1;
			if(string[i]=='1') c_1--;
			else c_0--;
		}		
		
		/*for(i=0;i<len;i++) cout<<limit[i]<<" ";
		cout<<"\n";
		*/
		
		cfr[0]=limit[0];
		for(i=1;i<len;i++)
		cfr[i]=cfr[i-1]+limit[i];
		
		while(q--)
		{
			sum=0;
			fastin(l);fastin(r);
			l--;r--;
			sum+=( (r-l+1)-(  ((r*(r+1))>>1) - ((l*(l-1))>>1) ) );
			/*long long int m=l;
			while(m<=r && limit[m]<=r)
			{
				m++;
			}*/
			long long int m=bser(l,r,r,limit);
			
			if(l==0)
			{
				sum+=cfr[m-1];
				sum+=((r-m+1)*(r));
				
			}
			else
			{
				sum+=cfr[m-1]-cfr[l-1];
				sum+=((r-m+1)*(r));
			}	
			printf("%lld\n",sum);
			
			
		}
	}
	
	return 0;
}

/*while(q--)
		{
			sum=0;
			c_0=c_1=0;
			fastin(l);fastin(r);
			l--;r--;
			j=l;
			if(string[j]=='1') c_1++;
			else c_0++;
			
			for(i=l;i<=r;i++)
			{
				while(j<=r && c_0<=k && c_1<=k)
				{
					j+=1;
					if(j>r) break;
					if(string[j]=='1') c_1++;
					else c_0++;
				}
				sum+=j-i;
				if(string[i]=='1') c_1--;
				else c_0--;
			}
			printf("%lld\n",sum);	
		}*/
