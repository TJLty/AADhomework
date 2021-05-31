//
// Created by TJ_Lty on 2021/5/30.
//

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
bool operator <(pair<int,int> a,pair<int,int> b)
{
    return a.second<b.second;
}
vector<pair<int,int> > elm;
bool check[10000];
int main()
{
    int right=-0x3f3f3f;
    int a,b;
    while(cin>>a>>b){
        elm.push_back(pair<int,int>(a,b));
        right=max(right,b);
    }
    sort(elm.begin(),elm.end());
    int end=elm[0].second;
    int ans=1;
    for(int i=1;i<elm.size();i++)
    {
        if(elm[i].first>=end)
        {
            end=elm[i].second;
            ans++;
        }
    }
    cout<<elm.size()-ans;
    return 0;
}