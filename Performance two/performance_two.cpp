//coding UTF-8
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define inf 0x3f3f3f3f
using namespace std;
const int N = 1010;
class solution {
private:
    char s1[N], s2[N];
    int n;
    int a[N], b[N];
    int f[N][10][10][10];
    bool vis[N][10][10][10];
    /*********************************************
     * 记忆化搜索
     * @param cur 当前位置
     * @param x 当前位置的值
     * @param y 下一位的值
     * @param z 再下一位的值
     * @return 当前状态最少步数
     **********************************************/
    int dp(int cur, int x, int y, int z)
    {
        if (cur >= n) return 0;
        int &res = f[cur][x][y][z];
        if (vis[cur][x][y][z]) return res;
        vis[cur][x][y][z] = true;
        res = inf;
        int delta;
        if (x <= b[cur]) delta = b[cur] - x;
        else delta = b[cur] + 10 - x;
        for (int i = 0; i <= delta; i++) {
            for (int j = 0; j <= i; j++) {
                res=min(res, dp(cur + 1, (y + i) % 10, (z + j) % 10, a[cur + 3]) + delta);
            }
        }
        if (x >= b[cur]) delta = x - b[cur];
        else delta = x + 10 - b[cur];
        for (int i = 0; i <= delta; i++) {
            for (int j = 0; j <= i; j++) {
                res=min(res, dp(cur + 1, (y - i + 10) % 10, (z - j + 10) % 10, a[cur + 3]) + delta);
            }
        }
        return res;
    }
public:
    void solve()
    {
        scanf("%s %s", s1, s2);
        //cout<<s1<<"\t"<<s2<<endl;
        n = strlen(s1);
        for (int i = 0; i < n; i ++) a[i] = s1[i] - '0', b[i] = s2[i] - '0';
        a[n] = a[n + 1] = b[n] = b[n + 1] = 0;//减少结束条件的判断。
        memset(vis,0,sizeof(vis));
        printf("%d\n", dp(0, a[0], a[1], a[2]));
    }
};

solution a;
int main() {
    //freopen("out2.txt","w",stdout);
    a.solve();
    return 0;
}

