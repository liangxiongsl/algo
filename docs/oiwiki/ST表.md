###### 1，ST表

用于计算可重复贡献操作的区间问题，时空复杂度为 $O(n\times log_{n})$ 

（可重复贡献操作：$max,~min,~gcd~...~$）

**可能其他算法一起出现的算法**：二分（若区间长度满足单调性，则二分区间长度 $len=0..n-1$）


[ACM集训队21级日常训练--ST表 - Virtual Judge (csgrandeur.cn)](https://vjudge.csgrandeur.cn/contest/515025#overview)

###### E，给定序列 $\{a_n\}$，求所有满足如下条件的最长区间 $a_{l..r}$：$\exist i=l..r,~\forall j=l..r,~a_i~\mid~a_j$

（即区间内存在一个数，能整除该区间的所有数）

（tips：区间可以看成是一个数对 $(l,~r),~l\le r$，满足条件的数对有 $\frac{n\times(n+1)}{2}$）

有两种做法：
1）记$L_i$ 为 $a_i$ 能整除到最左边的位置，即 $a_i\mid a_{L_i..i},~a_i\nmid a_{L_i-1}$， $R_i$ 同理

枚举 $i=1..n$ 将 $R_i-L_i$ 取max即可

$L_i$ 的计算：
边界：$L_1=1,~R_n=n$

递推：对于 $i\ge 2$，开始时，$L_i$ 至少为 $i$（因为 $a_i\mid a_i$），置 $ans=i$

若 $a_{i}\mid a_{ans-1}$，则 $a_{i}\mid a_{L_{ans-1}..ans-1}$，此时 $L_{i}$ 至少为 $_{L_{ans-1}}$，置 $ans=L_{ans-1}$

递归如上过程

$R_i$ 的计算同理

```cpp
for(int i=1; i<=n; ++i){
    int ans;
    for(ans=i; ans>1 && !(a[ans-1] % a[i]); ans=l[ans-1]);
    l[i] = ans;
}
for(int i=n; i>=1; --i){
    int ans;
    for(ans=i; ans<n && !(a[ans+1] % a[i]); ans=r[ans+1]);
    r[i] = ans;
}
```

2）观察到一个性质： “最小值 等于 最大公约数”（$min=gcd$）的区间是可能的最优解

用ST表维护 $min$ 和 $gcd$，

二分区间长度（$0..n-1$），并枚举出该长度下满足条件的所有区间，复杂度： $O(n\log_n)$

```cpp

#include<iostream>
using namespace std;
int gcd(int a, int b){ return !b ? a : gcd(b, a % b); }

const int N = 3e5+3;

int f[N][23], g[N][23], lg[N], n;
void init(){
	for(int i=2; i<=n; ++i) lg[i] = lg[i/2] + 1;
	for(int j=1; j<23; ++j){
		for(int i=1; i+(1<<j)-1<=n; ++i){
			f[i][j] = min(f[i][j-1], f[i+(1<<j-1)][j-1]);
			g[i][j] = gcd(g[i][j-1], g[i+(1<<j-1)][j-1]);
		}
	}
}
bool get(int lb, int ub){
	int k = lg[ub-lb+1];
//	printf(" %d %d ", max(f[lb][k], f[ub-(1<<k)+1][k]), gcd(g[lb][k], g[ub-(1<<k)+1][k]));
	return min(f[lb][k], f[ub-(1<<k)+1][k]) == gcd(g[lb][k], g[ub-(1<<k)+1][k]);
}

int ans[N], cnt;

signed main(){
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", &f[i][0]), g[i][0] = f[i][0];
	init();
	
	int lb, ub, mid;
	for(lb=0, ub=n-1; mid=lb+ub>>1, lb<=ub; ){
		int idx = 0;
//		printf(" %d:", mid);
		for(int i=1; i+mid<=n; ++i) if(get(i, i+mid)) ans[ ++ idx] = i;
//		puts("");
		if(idx){
			lb = mid + 1;
			cnt = idx;
		}else ub = mid - 1;
	}
	
	cout << cnt << ' ' << mid << '\n';
	for(int i=1; i<=cnt; ++i) cout << ans[i] << ' ';
}


```

##### F，
