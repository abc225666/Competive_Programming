#include <bits/stdc++.h>

using namespace std;

int queen[15];
// n row;
// queen[n] col;

int ans;
int r,c;

int isConflict(int row,int col)
{
	
	for(int t=1;t<=9;t++)
	{
		if( queen[row]!=0 || col==queen[t] || (queen[t]!=0 && ( abs(col-queen[t])==abs(row-t) ) ) )
			return 1;

	}

	return 0;
}

int find(int curRow,int queenNum)
{


	
	if(queenNum==9)
	{
		ans++;
		return 0;
	}
	if(curRow==10) return 0;

	if(curRow == r )
	{
		find(curRow+1,queenNum);
	}
	
	for(int t=1;t<=9;t++)
	{
		if(!isConflict(curRow,t))
		{
			queen[curRow]=t;
			find(curRow+1,queenNum+1);
			queen[curRow]=0;
		}
	}

	

	return 0;

}


int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int t=0;t<n;t++)
		{
			memset(queen,0,sizeof(queen));
			ans=0;
			
			scanf("%d %d",&r,&c);

			queen[r]=c;
			find(1,1);

			printf("%d\n",ans);
		}


	}
	return 0;
}