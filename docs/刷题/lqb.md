
[参考](https://blog.csdn.net/kiwi_berrys/article/details/111186204)

[真题](http://oj.ecustacm.cn/viewnews.php?id=1021)

[分析](https://blog.csdn.net/m0_58367586/article/details/123985357)

!!! 注意点
	- 预定义模板：`tools -> editor options -> snippets -> default source`：
		- 头：`<bits/stdc++.h>, <vector>, <map>, <algorithm>, <sstream>`
		- 循环：`FOR(i, bg, ed) for(int i=bg; i<=ed; ++i)`，`IFOR(i, bg, ed) for(int i=ed; i>=bg; --i)`
		- 高精度：`int long long` 或 `int __int128`
		- 快读/写：`void prt(__int128 x){ if(!x) return ; if(x) prt(x/10); putchar(x%10+'0'); }`，`ios::sync_with_stdio(false);`，`cin.tie(0), cout.tie(0);`
		- solve()
	- 技巧
		- 不要老想着 ac，数据规模大可以试试暴力算法，狗些部分分也行
		- 注意变量的范围限制，如 $x\in[low_bound, up_bound]$ $\implies$ $\max\{low_bound, \min\{ up_bound, x \}\}$
		- 2022 B类 细节题多，注意细节问题，喜欢卡常，卡精度，喜欢考无关的常识(每月的天数，闰年, 文学)
	- dev：
		- 添加 c++11：`-std=c++11`
		- 

!!! 日期
	- 计算 0001-01-00 与 a-b-c 之间的时间差：
		```
		int f[13] = {0, 31, 28, 31, 30, 31, 30, 
				 	  31, 31, 30, 31, 30, 31};
		bool ok(int y){ return y%400==0 || y%100 && y%4==0; }
		int to(int a, int b, int c){
			int ans = 0;
			for(int i=1; i<a; ++i) ans += (365 + ok(i));
			for(int i=1; i<b; ++i) ans += f[i];
			ans += c;
			if(b > 2 && ok(a)) ++ ans;
			return ans;
		}
		```
	- 输入 0001-01-00 与 a-b-c 之间的时间差 x，得到 a，b，c
		```
		void ot(int x){
			int a = 0, y;
			for(y=0; ++a, y += 365 + ok(a), y<=x; );
			x -= y -= 365 + ok(a);
			
			int b = 0;
			for(y=0; ++b, y += f[b] + (b==2&&ok(a)), y<=x; );
			x -= y -= f[b] + (b==2&&ok(a));
			
			cout << a << ' ' << b << ' ' << x << '\n';
		}
		```
	- 

!!! note "13年"
	- [A]()：给定初始日期 a-b-c，以及 末时间 a'-b'-c' 与 初始日期 之间的天数 delta，计算 末日期
		- 末日期 - 初始日期 + 1 = delta $\implies$ 末日期 = delta + 初始日期 - 1
	- [B]()：找到如下满足条件的 6 位十进制数 x ：x 上的每个数位都不同，$x^2$ 的数位集合 与 x 的数位集合 不相交，即 $S_x \cap S_{x^2} = \emptyset$
		- n的数位集合遍历：`for(int i=n; i; i/=10) i%10`
	- [C]()：给定 一个字符矩阵($n\times m$) 和 一个字符串 s(长为 $n+m-1$)；计算从左上角 (1, 1) 开始跳跃到右下角 (n, m) 的方案数，限制：只能 往下 或 往右 跳跃，跳跃路径与字符串 s 匹配
	- [D]()：$\Delta_a = a'-a \in (-300, -200], \Delta_b = b'-b \in [800, 900), \Delta_a + \Delta_b = 558$，$a \in [10^3, 10^4)$，其中 a' 为满足 a 的各位数字 左右 和 上下 都翻转后，没有前缀 0 并且 倒着读合法(注：数位 0, 1, 2, 5, 6, 8, 9 都可倒着读) 的数字
	- [E]()：给定字符串前缀判断的程序，补全代码
		- 注：设计c++特有的骚操作
	- [F]()：逆波兰表达式补全
	- [G]()：给 n 行长度不定的整数，找出这些整数中 重复的整数 x 和 满足 $y\in[\min\{ a_i \}, \max\{ a_i \}]$ 但不在给定的整数集合中 的整数 y，其中 $y \ne \min\{ a_i \}, y \ne \max\{ a_i \}$
	- [H]()：求出 a 和 b 最大不能凑出的数，即 $a\cdot x + b\cdot y \ne ans, \max\{ ans \}$ ($a, b, x, y \in N^+$)
		- `a * b - a - b`
	- [I]()：给定$m\times n$矩阵，分割两个连通块 A 和 B ，使得两个连通块权值之和相等 并 最小化其中之一的元素数量，即 $\sum\limits_{x\in A} a_x = \sum\limits_{y\in B} a_y, ans = \min\{ |A| \} 或 n\time m -\max\{ |A| \}$
		- 从 (1, 1) 出发，划分这个图为两个子图即可，其中子图内部的点必须连通（意味着可以从 4 相邻的点延伸搜索）
	- [J]()：

!!! note "22A"
	- [A](http://oj.ecustacm.cn/problem.php?id=2021)：
	- [B](http://oj.ecustacm.cn/problem.php?id=2022)：给定一个先手第一次转移后的局面（即后手的局面），判断先手必胜还是必败（游戏双方都是选择最优策略）
		- 定理(用于{==深搜-扩展==})：若 当前状态 能转移到的{==至少一个==} 必败态，那么先手必胜，否则先手必败
		- 推论(用于答案的判断)：对于题目所给的局面，若是必败态(即 后手必败态)，则先手必胜，否则先手必败
		- 若题目指出 必败态 或 必胜态 的标志，则暗示 {==深搜的出口==}
	- [C](http://oj.ecustacm.cn/problem.php?id=2023)：计算 $\sum\limits_{i=1}^n\sum\limits_{j=1}^{i-1} a_i\cdot a_j$
	- [D](http://oj.ecustacm.cn/problem.php?id=2024)：给定 n 个数 $a_i$，一个数 x，以及 m 次查询 $[l_i, r_i]$ 中 是否存在 任取两个数 $a_i, a_j$，使得 $a ^ b = x$
	- [E](http://oj.ecustacm.cn/problem.php?id=2025)：有 n+1 个位置 $x=i, i\in[0,n]$，刚开始位于 $x = 0$ 处，假设从 $x = i-1$ 处跳跃到 $x = i$ 的概率为 $p_i$（$p_i \equiv \frac {a_i}{b_i} \pmod {998244353}$），否则会跳回 $x = 0$ 处；计算从 $x=0$ 处跳跃到 $x_n$ 的跳跃期望
		- 有待分析
	- [F](http://oj.ecustacm.cn/problem.php?id=2026)：给定 n-1 个连续点以及边界点 id=0, id=n，除边界点外点的高度为 $h_i, i\in[0,n)$ ($h_i > 0$ 时合法)，每次能跳跃的最大距离为 m (未知)，而且除了边界点外 跳跃起点的高度减 1；在 id=0 和 id=n 处往返 2x 次，最小化一次能跳跃的最大距离 m
		- 
	- [G](http://oj.ecustacm.cn/problem.php?id=2027)：LIS
		- [相关题](https://www.luogu.com.cn/problem/U288991)
	- [H](http://oj.ecustacm.cn/problem.php?id=2028)：
	- [I](http://oj.ecustacm.cn/problem.php?id=2029)：给定 n 个数 $a[ ]$，判断是否满足 $a_i = x_1^{y_1}\cdot x_2^{y_2}, y_1,y_2\ge 2, s\le 10^{18}$
		- 结论？：$a_i$ 满足 $a_i = x^2\cdot y^3, x,y>1$
	- [J](http://oj.ecustacm.cn/problem.php?id=2030)：假设数组 $a[ ]$ 长度为 n，给定 m 个区间和 $\sum\limits_{i=l}^l a_i = v$，查询 q 次 区间和 $[l, r]$
		- 带权并查集维护区间和关系，l 和 r+1 在同一个并查集上则表示 [l, r] 的区间和可以推理出


!!! note "22B"
	- [A](http://oj.ecustacm.cn/problem.php?id=2031)：九进制转十进制
		- `for(int i=n, x=1; i; i/=10, x*=9) m += i%10 * x;`
		- 注意：给定的正整数要用 10 来做除法或取余
	- [B](http://oj.ecustacm.cn/problem.php?id=2032)：日期构成的 8 位字符串中，存在 3 位连续递增 或 连续递减 子串称为顺子日期，求 2022年这 365 天中顺子日期的个数
		- 注意：对于日期填空题，建议 用 3 个变量存日期的各个“子日期”来方便{==迭代==}，手动让日期进位，{==暴力差分成字符串来记录信息==}
		- 倒着来不算“顺子”
	- [C](http://oj.ecustacm.cn/problem.php?id=2033)：周一到周五每天贡献为 a，周六周日每天贡献为 b；从周一开始，计算满足贡献之和不小于 n 时最少经过的天数
		- 性质：假设 x 为经过的周数，y 和 z 分别为最后 x+1 周 工作日 或 双休日 经过的天数，那么 $(5a+2b)\cdot x + a\cdot y + b\cdot z \ge n$，答案为 $7x+y+z$
			- $x = \lceil \frac {n}{5a+2b} \rceil, y = \lceil \frac {n-(5a+2b)\cdot x}{a} \rceil, z = \lceil \frac {n-(5a+2b)\cdot x - a\cdot y}{b} \rceil, y\in [0, 5], z\in [0, 2]$
		- 注意：向上取整，范围限制
	- [D](http://oj.ecustacm.cn/problem.php?id=2034)：刚开始有 n 个高度为 0 的灌木，灌木每天 早上 会突然长高 1米，每天 晚上 会对这些灌木从左到右开始循环往复修剪，每次修剪都会使灌木 $h_i = 0$；假设刚开始在最左侧修剪，计算对于 id=i 的灌木，$\max\{ h_i \}$ 为多少
		- 注意：每天有 早上 和 晚上 两个状态，分别用于 生长 和 修剪
		- 我们发现只要计算对于 id=i 的灌木，最近两次修剪该灌木的夜晚之间经过的早晨数量的最大值即为答案
			- id=i 的左侧模拟会得到 $h_i = \sum\limits_{j=i-1}^1 1 + \sum\limits_{j=2}^{i} 1 = 2(i-1)$
			- 同理，向左侧模拟则有 $h_i = \sum\limits_{j=i+1}^n 1 + \sum\limits_{j=n-1}^i = 2(n-i)$
	- [E](http://oj.ecustacm.cn/problem.php?id=2035)：某种进制数可表示为 $n = \sum\limits_{i=1}^n a_i\cdot \prod\limits_{j=1}^{i-1}x_j$（对比一下十进制：$n = \sum\limits_{i=1}^n a_i\cdot 10^{i-1}$），其中 $x_j \in[2, k]$；最小化 $a - b$ 的值
		- 贪心：$x_j = \max\{2, \min\{k, \max\{a_j, b_j\}+1\}\}$
	- [F](http://oj.ecustacm.cn/problem.php?id=2036)：给定 $n\times m$ 的**非负**矩阵，计算矩阵内元素和不大于 k 的子矩阵个数
		- 用 l，r 枚举子矩阵左右边界 ($l\le r$)，x 和 y 枚举上下边界 ($x\le y$)，复杂度为 $O(n^4)$
		- 注意到矩阵内的元素是非负的，所以减小某个矩阵的宽度，会使得矩阵和单调不增，对最后一个变量的枚举使用双指针降低 $O(n)$ 的复杂度
	- [G](http://oj.ecustacm.cn/problem.php?id=2037)：给定 $2\times n$ 的积木画，以及若干 I 型 和 L 型积木 (可以旋转 $0/90/180/270°$)，计算积木填满积木画的方案数
		- 观察规律 $f_i = f_{i-1} + f_{i-2} + 2\sum\limits_{j=i-3}^0 f_j$，$f_{i-1} = f_{i-2} + f_{i-3} + 2\sum\limits_{j=i-4}^0 f_j$
		- 得到：$f_i = 2f_{i-1} + f_{i-1}$
	- [H](http://oj.ecustacm.cn/problem.php?id=2038)：
		- 哈希：离线处理，以快速查找特定“值”（如：整数，浮点数，点坐标） 对于的 相关信息（如：id，多个id(如果原函数不是单射函数)，符合条件的数量，）
	- [I](http://oj.ecustacm.cn/problem.php?id=2039)：有 n + m 天，若第 i($i\ge 1$) 天遇到状态 A，则贡献倍增 (乘2)，若遇到状态 B，则贡献 -1；假设第 0 天贡献为 2，求第 n+m 天 状态为 B，贡献为 0 的方案数
		- 记 $f_{i, j, k}$ 为前 i 天遇到过 j 个 B 状态，贡献为 k 的方案数；但是{==当前状态是不显然的==}，然而但我们分析出转移方程后，自然可以知道 (i, j, k) 方案由哪些状态的选择转移而来（我们过滤出满足我们需要的转移数量即可）
		- $f_{i, j, k} = CNT\begin{cases} f_{i-1,j-1,k+1} & 由状态 B 转移而来 \\ f_{i-1,j,k/2} [2\mid k] & 由状态 A 转移而来 \end{cases}$
			- 我们需要的是 $f_{n+m, m, 0}$ 中从状态 A 转移的那一部分，根据转移方程可知：这一部分为 $f_{n+m-1, m-1, 1}$
		- 注意：求方案数的 dp 需要关注边界的方案数（这里 $f_{0,0,2}$ 显然是 1）
	- [J](http://oj.ecustacm.cn/problem.php?id=2040)：给定 n 个竹子，高度为 $h_i(\le 10^{18})$，每次将一段连续的 高度相同 的竹子进行长度的变换即 $h_i = \lfloor\sqrt {\lfloor\frac {h_i}2\rfloor + 1}\rfloor$；求能使竹子长度都变换为 1 中，最少的变换次数
		- 性质：$10^{18}$ 最多可经过 6 次变换


