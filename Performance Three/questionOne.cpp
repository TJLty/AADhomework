//
// Created by TJ_Lty on 2021/5/30.
//

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if (n==0) return 1;
    else if (n==1) return 10;

    int sum = 10;
    int dp = 9;
    for (int i = 2; i <= n; i++)
    {
        dp *= 11 - i;
        sum += dp;
    }
    cout<<sum;
}
