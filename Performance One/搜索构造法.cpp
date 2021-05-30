#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
typedef long long LL;
bool dh = true;
void dfs(LL ans, int k, int depth,int last)
{
	if (depth == 0)
	{
		if (dh == true)
			dh = false;
		else
			printf(",");
		printf("%lld", ans);
		return;
	}
	if (last - k >= 0)
		dfs(ans * 10 + last - k, k, depth - 1, last - k);
	if (last + k <= 9&&k!=0)
		dfs(ans * 10 + last + k, k, depth - 1, last + k);
	return;
}
int main()
{
	freopen("case1.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	if (n < 2)
		return 0;
	for (int i = 1; i <= 9; i++)
	{
		dfs(i, k, n - 1, i);
	}
	return 0;
}