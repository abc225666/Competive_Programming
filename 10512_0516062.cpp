#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli series[100005];

lli c(lli n)
{

	return (n*(n-1))/2; 
}

int  cmp(lli a, lli b)
{
	return a<b;
}


int main()
{
	int n;
	while(scanf("%d",&n) && n!=0)
	{
		series[0]=0;
		int t;
		lli in;
		for(t=1;t<=n;t++)
		{
			scanf("%lld",&in);
			series[t]=in+series[t-1];
		}


		
		sort(series,series+n+1,cmp);

		lli now=series[0];
		lli number=1;
		lli ans=0;

		for(t=1;t<=n;t++)
		{
			
			if(series[t]==now)
			{
				number++;
			}
			else
			{
				if(number>=2)
				{
					ans+=c(number);
				}

				number=1;
				now=series[t];
			}
		}

		if(number>=2)
		{
			ans+=c(number);
		}

		printf("%lld\n",ans);


	}

	return 0;
}