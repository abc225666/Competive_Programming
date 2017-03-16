#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int cut[100005];
int cut_index;

int n,k;

lli series[100005];

lli max(lli a,lli b)
{
	if(a>=b)
		return a;
	return b;
}


lli min(lli a,lli b)
{
	if(a<=b)
		return a;
	return b;
}

int isOK(int k, lli max_v)
{
	lli U,L;
	U=L=series[0];
	lli m;

	for(int t=0;t<n;t++)
	{
		m=(max(U,series[t])-min(L,series[t]));
		if( ( m >>1) +(m&1) >= max_v  )
		{
			U=L=series[t];
			k--;
		}
		U=max(series[t],U);
		L=min(series[t],L);
	}
	return !(k>0);
}

int findCut(lli max_dist)
{
	lli U,L;
	U=L=series[0];
	lli m;
	for(int t=0;t<n;t++)
	{
		m=( max(U,series[t]) - min(L,series[t]) );
		if( ( ( (m>>1) + (m&1) ) ) > max_dist) //need cut
		{
			cut[cut_index++]=t-1;
			U=L=series[t];
		}
		U=max(series[t],U);
		L=min(series[t],L);
	}
}


int main()
{
	while(scanf("%d %d",&n,&k)==2)
	{
		cut_index=0;

		for(int t=0;t<n;t++)
		{
			scanf("%lld",&series[t]);
		}

		lli max_dist=0;
		lli step=(lli)1<<33;

		while(step)
		{
			//printf("a %lld\n",step);
			if(isOK(k,max_dist+step))
			{
				//printf("a %lld\n",step);
				max_dist+=step;
			}
			step >>= 1;
		}

		// printf("%lld\n",max_dist);

		findCut(max_dist);
		int startPoint=1;
		int endPoint;
		int extraCutting=(k-1)-cut_index;
		lli U,L;
		lli m=0;
		int cur_cut_index=0;
		m=U=L=series[0];

		int t;
		
		for(t=0;t<n && (k-1)>0;t++)
		{
			m= (max(U,series[t])+min(L,series[t]))>>1;
			U=max(series[t],U);
			L=min(series[t],L);
			// if meet new interval's head
			if(t==cut[cur_cut_index])
			{
				printf("%d %d %lld\n",startPoint,t+1,m);
				startPoint=t+2;
				cur_cut_index++;
				U=L=series[t+1];
				k--;
			}
			else if(extraCutting)
			{
				printf("%d %d %lld\n",startPoint,t+1,m);
				startPoint=t+2;
				extraCutting--;
				U=L=series[t+1];
				k--;
			}
		}

		for(;t<n;t++)
		{
			m= (max(U,series[t])+min(L,series[t]))>>1;
			U=max(series[t],U);
			L=min(series[t],L);
		}
		printf("%d %d %lld\n",startPoint,n,m);

	}
}