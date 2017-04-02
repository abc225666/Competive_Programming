#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli DoCount(char sym, lli a, lli b)
{
	switch(sym)
	{
		case '*':
		return (a*b) % 1000000007;
		case '+':
		return (a+b) % 1000000007;
	}
}

int main()
{
	

	

	char input[3000];

	while(fgets(input,sizeof(input),stdin))
	{
		stack<char> symbol;
		stack<lli> number;

		symbol.push('(');
		strtok(input,"\n");
		int t;

		for(t=0;input[t];t++)
		{
			if(input[t]>='0' && input[t]<='9')
			{
				number.push(input[t]-'0');
			}
			else
			{
				if(input[t]==')')
				{
					// do count until (
					while(symbol.top()!='(')
					{
						int a=number.top();
						number.pop();
						int b=number.top();
						number.pop();
						number.push(DoCount(symbol.top(),a,b));
						symbol.pop();
					}
					symbol.pop();

				}
				else
				{
					switch(input[t])
					{
						case '+':
						{
							while(symbol.top()!='(')
							{
								lli a=number.top();
								number.pop();
								lli b=number.top();
								number.pop();
								number.push(DoCount(symbol.top(),a,b));
								symbol.pop();
							}
							break;
						}
						case '*':
						{
							break;
						}

					}


					symbol.push(input[t]);

				}
			}
		}
		
		while( !symbol.empty() && symbol.top()!='(' && !number.empty())
		{
			int a=number.top();
			number.pop();
			int b=number.top();
			number.pop();
			number.push(DoCount(symbol.top(),a,b));

			symbol.pop();
		}
		if(number.empty()) printf("0\n");
		else printf("%lld\n",number.top());


	}
	return 0;
}