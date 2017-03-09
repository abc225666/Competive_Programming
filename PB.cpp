#include <bits/stdc++.h>

using namespace std;

int f[1000001],g[1000001];
int h[1000001],hcount;
int isUsed[1000001];
int isTrue;
int kinds;


int main()
{

	int n;

	
	
	int t;



	while(scanf("%d",&n)==1 && n!=0)
	{
		for(t=0;t<=n;t++)
		{
			f[t]=0;
			g[t]=0;
			h[t]=0;
			isUsed[t]=0;
		}
		isTrue=1;
		hcount=0,kinds=1;

		for(t=1;t<=n;t++)
		{
			int in;
			scanf("%d",&in);
			if(in<=n && isTrue)
			{
				if(!isUsed[in])
				{
					isUsed[in]=kinds++;
					g[t]=isUsed[in];
					f[t]=in;
					h[hcount++]=in;
				}
				else
				{
					g[t]=isUsed[in];
					f[t]=in;
				}
			}
			else
			{

			}
		}
		for(t=0;t<hcount;t++)
		{
			//fprintf(stderr,"%d %d\n",h[t],f[h[t]]);
			if(!(h[t]==f[h[t]]))
			{
				isTrue=0;
			}
		}

		if(isTrue)
		{

			printf("yes\n");

		}
		else
		{
			printf("no\n");
		}

	}

	return 0;
}