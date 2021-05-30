#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long LL;
/*
LL abs(LL _Source)
{
	return _Source < 0 ? -_Source : _Source;
}
*/
bool check(LL _Source,int k)
{
	int pos=_Source%10;
	_Source /= 10;
	while (_Source > 0)
	{
		if (abs(_Source % 10 - pos) != k)
			return false;
		pos = _Source % 10;
		_Source /= 10;
	}
	return true;
}
LL fastpow(LL n, LL multi)
{
	LL ans = 1, base = n;
	while (multi)
	{
		if (multi & 1) ans = (ans * base);
		base = (base * base);
		multi >>= 1;
	}
	return ans;
}
int main()
{
	freopen("case1.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	if (n < 2)
		return 0;
	LL start = fastpow( 10,n-1);
	LL end = fastpow(10,n);
	LL ans = 0;
	for (LL i = start; i < end; i++)
	{
		if (check(i,k)) {
			if (ans != 0)
				printf(",");
			printf("%lld",i);
			ans++;
		}
	}
	return 0;
}