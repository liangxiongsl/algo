1、[CWXU-暑期集训-区间dp - Virtual Judge (csgrandeur.cn)](https://vjudge.csgrandeur.cn/contest/503596#problem/A)

题意：给定要删除的序列，每次能删除一个回文子串，求删除次数的最小值

2、[CWXU-暑期集训-区间dp - Virtual Judge (csgrandeur.cn)](https://vjudge.csgrandeur.cn/contest/503596#problem/B)

题意：参加n场派对，每场派对需要穿对应衣服，参加一场派对前有两种选择：脱掉多件衣服（脱掉的不可重用）或穿上对应的衣服，求需要的最少衣服数

更形象的描述：你有一个空栈。从明天开始的 n 天，你都要保证栈顶元素为 ai​。你可以在每一天的前天晚上对栈进行任意的入栈、出栈操作。请问：你至少需要入栈多少次？

```cpp
for(int d=0; d<n; ++d){
    for(int lb = 1, ub; (ub = lb + d) <= n; ++ lb){
        if(!d) { f[lb][ub] = 1; continue; }
        f[lb][ub] = f[lb + 1][ub] + 1;
//                f[lb][ub] = f[lb][ub - 1] + 1;
        for(int mid = lb; mid < ub; ++mid){
            if(a[lb] == a[mid + 1]) f[lb][ub] = min(f[lb][ub], f[lb + 1][mid] + f[mid + 1][ub]);
//                    if(a[mid] == a[ub]) f[lb][ub] = min(f[lb][ub], f[lb][mid] + f[mid + 1][ub - 1]);
        }
    }
}
```

3，[CWXU-暑期集训-区间dp - Virtual Judge (csgrandeur.cn)](https://vjudge.csgrandeur.cn/contest/503596#problem/C)

题意：最长子括号子序列

```cpp
for(int d=0; d<s.size(); ++d){
    for(int lb = 0, ub; (ub = lb + d) < s.size(); ++lb){
        if(!d){ f[lb][ub] = 0; continue; }
        f[lb][ub] = (s[lb] == '(' && s[ub] == ')' || s[lb] == '[' && s[ub] == ']') ? 
            f[lb + 1][ub - 1] + 2 : 0;
        for(int mid = lb; mid < ub; ++ mid){
            f[lb][ub] = max(f[lb][ub], f[lb][mid] + f[mid + 1][ub]);
        }
    }
}
```

4，[CWXU-暑期集训-区间dp - Virtual Judge (csgrandeur.cn)](https://vjudge.csgrandeur.cn/contest/503596#problem/D)（区间dp + 状态机 + 括号序列处理）

题意：

给出一个配对的括号序列（如 “(())()”、“()” 等，“)()”、“(()”是不符合要求的），对该序列按照以下方法染色。

1. 一个括号可以染成红色、蓝色或者不染色。
2. 一对匹配的括号需要且只能将其中一个染色。
3. 相邻两个括号颜色不能相同（但都可以不染色）。

求符合条件的染色方案数，对 1000000007 取模。

```cpp
#include<iostream>
#include<string>
using namespace std;

int P = 1e9+7;
string s;
int st[700], tt, mat[700];

long long f[700][700][3][3];
#define rep(i, lb, ub) for(int i=lb; i<ub; ++i)
#define f0 f[lb][ub]
#define f1 f[lb+1][ub-1]
#define f2 f[lb][ mat[lb] ]
#define f3 f[ mat[lb] + 1][ub]
void dfs(int lb, int ub){
    if(lb >= ub){
        puts("WA");
        return ;
    }
    if(lb + 1 == ub){
        f0[0][1] = f0[0][2] = f0[1][0] = f0[2][0] = 1;
        return ;
    }
    if(mat[lb] == ub){
        dfs(lb + 1, ub - 1);
        rep(i, 0, 3) rep(j, 0, 3){
            if(i != 1) f0[1][0] = (f0[1][0] + f1[i][j]) % P;
            if(i != 2) f0[2][0] = (f0[2][0] + f1[i][j]) % P;
            if(j != 1) f0[0][1] = (f0[0][1] + f1[i][j]) % P;
            if(j != 2) f0[0][2] = (f0[0][2] + f1[i][j]) % P;
        }
        return ;
    }
    dfs(lb, mat[lb]), dfs(mat[lb] + 1, ub);
    rep(i, 0, 3) rep(j, 0, 3) rep(u, 0, 3) rep(v, 0, 3){
        if(j == u && j + u) continue;
        // 合并两个区间，使用乘法原理 
        f0[i][v] = (f0[i][v] + f2[i][j] * f3[u][v] % P ) % P;
    }
}


int main(){
    cin >> s;
    rep(i, 0, s.size())
        if(s[i] == '(') st[ ++ tt] = i;
        else mat[ st[tt--] ] = i;

    dfs(0, s.size()-1);

    long long ans = 0;
    rep(i, 0, 3) rep(j, 0, 3)
        ans = (ans + f[0][s.size() - 1][i][j]) % P;

    cout << ans << '\n';
}
```

5，[CWXU-暑期集训-区间dp - Virtual Judge (csgrandeur.cn)](https://vjudge.csgrandeur.cn/contest/503596#problem/E)

由于序列两端不能取数，故将区间定义为开区间

```cpp
#include<iostream>
using namespace std;

const int N = 1e2+3, inf = 0x3f3f3f3f;
int n, a[N], f[N][N];

int main(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];

    for(int d=2; d<n; ++d){
        for(int lb = 1, ub; (ub = lb + d) <= n; ++ lb){
            f[lb][ub] = inf;
            for(int mid = lb + 1; mid < ub; ++ mid){
                f[lb][ub] = min(f[lb][ub], f[lb][mid] + f[mid][ub] + a[lb] * a[mid] * a[ub]);
            }
        }
    }
    cout << f[1][n] << '\n';
}
```

6，[CWXU-暑期集训-区间dp - Virtual Judge (csgrandeur.cn)](https://vjudge.csgrandeur.cn/contest/503596#problem/F)

题意：快递员一开始在x处，其送快递速度为 $v^{-1}$（速度v的逆元），有n名顾客同时下单，顾客有参数：坐标x 和 每分钟的不高兴指标b，求不高兴指标之和的最小值

思路：快递不会忽略路过的并且未吃上饭的顾客，否则不会获得最优解

因此送快递可以抽象为一个“有向区间”，仅枚举区间的左右端点以转移状态（即状态机）

```cpp
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

const int N = 1e3+3, inf = 0x3f3f3f3f;
int n, v, x, f[N][N][2];
struct nd{
    int x, b;
    bool operator<(const nd &t)const{ return x < t.x; }
}a[N];


int main(){
    while(cin >> n >> v >> x){
        for(int i=1; i<=n; ++i) cin >> a[i].x >> a[i].b;

        sort(a + 1, a + n + 1);
        for(int i=1; i<=n; ++i) a[i].b += a[i-1].b;

        #define f0 f[lb][ub]
        #define f1 f[lb + 1][ub]
        #define f2 f[lb][ub - 1]
        for(int d=0; d<n; ++d){
            for(int lb=1, ub; (ub = lb + d) <= n; ++ lb){
                auto val = [a, lb, ub](int u, int v){
                    return abs(a[u].x - a[v].x) * (a[n].b - (a[ub].b - a[lb+1 -1].b));
                };
                auto val1 = [a, lb, ub](int u, int v){
                    return abs(a[u].x - a[v].x) * (a[n].b - (a[ub-1].b - a[lb -1].b));
                };

                if(!d) { f0[0] = f0[1] = abs(a[lb].x - x) * a[n].b; continue; }
                // 快递员最后到达 lb ， 将 lb 与 [lb + 1, ub] 合并
                // 有两个路线：lb+1 -> lb 或  ub -> lb
                f0[0] = min(f1[0] + val(lb + 1, lb), f1[1] + val(ub, lb));
                f0[1] = min(f2[0] + val1(lb, ub), f2[1] + val1(ub - 1, ub));
            }
        }
        cout << min(f[1][n][0], f[1][n][1]) * v << '\n';
    }
}
```

7、[CWXU-暑期集训-区间dp - Virtual Judge (csgrandeur.cn)](https://vjudge.csgrandeur.cn/contest/503596#problem/G)

题意：

8、[CWXU-暑期集训-区间dp - Virtual Judge (csgrandeur.cn)](https://vjudge.csgrandeur.cn/contest/503596#problem/H)
