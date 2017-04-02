#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

void multi(int* output, int* f, int* g, int count)
{
	//memset(output,0,sizeof(int)*(count+2));

	if(count<32)
	{
		for(int t=0;t<=count;t++)
		{
			for(int t1=0;t1<=count;t1++)
			{
				output[t+t1]+=f[t]*g[t1];
			}
		}
	}
	else
	{
		int a[count/2+1];
		int c[count/2+1];
		int b[count/2+1];
		int d[count/2+1];

		int ac[count+1];
		int bd[count+1];

		int mid[count+1];

		memset(ac,0,sizeof(ac));
		memset(bd,0,sizeof(bd));
		memset(mid,0,sizeof(mid));


		for(int t=0;t<=count/2;t++)
		{
			b[t]=f[t];
			d[t]=g[t];
		}
		for(int t=0;t<=count-count/2-1;t++)
		{
			a[t]=f[t+count/2+1];
			c[t]=g[t+count/2+1];
		}

		multi(bd,b,d,count/2);
		multi(ac,a,c,count-count/2-1);

		for(int t=0;t<=count-count/2-1;t++)
		{
			b[t]+=a[t];
			d[t]+=c[t];
		}

		multi(mid,b,d,count/2);

		for(int t=0;t<=count/2*2+1;t++)
			mid[t]-=bd[t];
		for(int t=0;t<=(count-count/2-1)*2+1;t++)
			mid[t]-=ac[t];

		for(int t=0;t<=count/2*2+1;t++)
		{
			output[t]+=bd[t];
			output[t+count/2+1]+=mid[t];
		}
		for(int t=0;t<=2*(count-count/2-1)+1;t++)
			output[t+2*(count/2+1)]+=ac[t];

	}
	return ;
}

int main()
{
	int in_a[32769], in_b[32769];

	int T;
	int n;
	scanf("%d",&T);
	while(T--)
	{

		scanf("%d",&n);
		
		for(int t=0;t<n;t++)
			scanf("%d",&in_a[t]);
		for(int t=0;t<n;t++)
			scanf("%d",&in_b[t]);
		
		int output[2*(n-1)+1];

		memset(output,0,sizeof(output));

		multi(output,in_a,in_b,n-1);
		for(int t=0;t<(n-1)*2+1;t++)
			printf("%d ",output[t]);
		printf("\n");
	}
	return 0;
}

