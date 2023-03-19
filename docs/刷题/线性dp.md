1、[CWXU-暑期集训-线性dp（应用） - Virtual Judge (csgrandeur.cn)](https://vjudge.csgrandeur.cn/contest/502047#problem/A)

```cpp
for(int i=1; i<=n; ++i) scanf("%s", a[i] + 1);

int ans = 1;
for(int i=1; i<=n; ++i){
    for(int j=n; j>=1; --j){
        f[i][j] = 1;
        if(i == 1 || j == n) continue;
        for(int s = 1; s <= f[i-1][j+1]; ++ s)
            if(a[i - s][j] == a[i][j + s]) ++ f[i][j];
            else break;
        ans = ans > f[i][j] ? ans : f[i][j];
    }
}
cout << ans << '\n';
```

6、[CWXU-暑期集训-线性dp（应用） - Virtual Judge (csgrandeur.cn)](https://vjudge.csgrandeur.cn/contest/502047#problem/F)

分析：$a[]、b[]$均为单射函数，求lcs

数据：$n=6e4$

复杂度：$O(N\times logN)$

```cpp
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 250*250+3;
int a[N], b[N];
int f[N];

int main(){
    int T, TEST = 0;
    cin >> T;
    while(T--){
        int n, p, q;
        cin >> n >> p >> q;
        for(int i=1, x; i<=p+1; ++i) cin >> x, a[x] = i;
        for(int i=1, x; i<=q+1; ++i) cin >> x, b[i] = a[x];

        int ans = 0;
        for(int i=1; i<=q+1; ++i){
            if(!b[i]) continue;
            if(b[i] > f[ans]) f[++ ans] = b[i];
            else *lower_bound(f + 1, f + ans + 1, b[i]) = b[i];
        }
        printf("Case %d: %d\n", ++TEST, ans);
    }
}
```

（博客：[(5条消息) uva 10635 - Prince and Princess_GAUSS_CLB的博客-CSDN博客](https://blog.csdn.net/gauss_acm/article/details/38437799)，[UVA10635 Prince and Princess - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/solution/UVA10635)）

7、[CWXU-暑期集训-线性dp（应用） - Virtual Judge (csgrandeur.cn)](https://vjudge.csgrandeur.cn/contest/502047#problem/G)

分析：给定n个字符串最大循环字符串长度$max\{\sum\limits_{i\in~ans}{ans_i.length}\}$（$ans[]$为这字符串数组的子数组序列，其中$ans_i.end == ans_{i+1}.begin$，$ans_1.begin == ans_m.end$）

```cpp
#include<iostream>
#include<cstring>
using namespace std;

const int N = 5e5+3;
int n;
char s[13];
int f[26][26];

int main(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        scanf("%s", s + 1);
        int len = strlen(s + 1), lb = s[1] - 'a', ub = s[len] - 'a';
        for(int j=0; j<26; ++j)
            if(f[j][lb]) f[j][ub] = max(f[j][ub], f[j][lb] + len);    
        f[lb][ub] = max(f[lb][ub], len);
    }

    int ans = 0;
    for(int i=0; i<26; ++i) ans = max(ans, f[i][i]);
    cout << ans << '\n';
}
```
