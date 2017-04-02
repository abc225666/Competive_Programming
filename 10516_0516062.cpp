#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

struct seg_node
{
	
	seg_node(int l,int r);
	void initial();
	int nth(int k);
	int l,r;
	int rest;
	seg_node *l_node, *r_node;
};

seg_node::seg_node(int l, int r)
{
	this->l=l;
	this->r=r;
	this->rest=r-l+1;
	this->l_node=NULL;
	this->r_node=NULL;
	initial();
}

void seg_node::initial()
{
	int mid=(l+r)/2;
	if(l!=r)
	{
		seg_node* new_l=new seg_node(l,mid);
		seg_node* new_r=new seg_node(mid+1,r);
		this->l_node=new_l;
		this->r_node=new_r;
	}
	return;
}

int seg_node::nth(int k)
{
	//find target
	int output=0;
	if(l==r)
	{
		this->rest=0;
		return this->l;
	}
	
	if(this->l_node->rest >= k)
		output=this->l_node->nth(k);
	else
		output=this->r_node->nth(k - this->l_node->rest);

	if(output) this->rest--;
	return output;
}

int store[100005];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,k;
		int ans;
		scanf("%d %d",&n,&k);
		seg_node* start_node=new seg_node(1,n);
		for(int t=1;t<=n;t++)
		{
			scanf("%d",&store[t]);

			//printf("%d ",store[t]);

		}
		//printf("\n");

		int step=k+1;
		int next=1;

		for(;n;n--)
		{
			step=(step+next-1)%n;
			// step==0
			if(!step) step=n;

			ans=start_node->nth(step);

			next=store[ans];

			//printf("%d\n",next);
		}

		printf("%d\n",next);

	}
	return 0;
}