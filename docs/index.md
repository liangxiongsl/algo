


###  ###

!!! 博客
	- [heyuhhh](https://www.cnblogs.com/heyuhhh)

!!! question
	- sos dp - Sum-Over-Subsets dp 子集求和dp？
	- FMT（快速莫比乌斯变换），FWT（快速沃尔什变换）  $\sum\limits_{j\oplus k=i} A_j\times B_k$  
		- [模板题](https://www.luogu.com.cn/problem/P4717)，[$c_i = \max\limits_{j+k=i}\{a_j+a_k\}$](https://atcoder.jp/contests/arc100/tasks/arc100_c)，[cf2600](https://codeforces.com/contest/1208/problem/F)，[fwt + 题解](https://www.cnblogs.com/heyuhhh/p/11585358.html)
		- Fast Zeta Transform (FZT)
	- dp 怎么转化为数学描述


!!! note "符号 & 约定"
	- mask 掩码，通常出现在 n 位表示的幂集中 ($mask \le n-1$)



###  ###


```title="算法门类"
    - 基础:
        - 基础/index.md
        - 基础/理论.md
        - 基础/枚举.md
        - 基础/模拟.md
        - 基础/递归&递归.md
        - 基础/贪心.md
        - 基础/排序.md
        - 基础/前缀和&差分.md
        - 基础/二分.md
        - 基础/倍增.md
        - 基础/构造.md
    - 搜索:
        - 搜索/index.md
        - 搜索/DFS.md
        - 搜索/BFS.md
        - 搜索/双向搜索.md
        - 搜索/启发式搜索.md
        - 搜索/A※.md
        - 搜索/迭代加深搜索.md
        - 搜索/IDA※.md
        - 搜索/Dancing Links.md
        - 搜索/Alpha-Beta 剪枝.md
        - 搜索/优化搜索.md
    - 动态规划:
        - 动态规划/index.md
        - 动态规划/概论.md
        - 动态规划/记忆化.md
        - 动态规划/背包dp.md
        - 动态规划/区间dp.md
        - 动态规划/dag上的dp.md
        - 动态规划/树形dp.md
        - 动态规划/状压dp.md
        - 动态规划/数位dp.md
        - 动态规划/插头dp.md
        - 动态规划/计数dp.md
        - 动态规划/动态dp.md
        - 动态规划/概率dp.md
        - 动态规划/dp优化.md
    - 字符串:
        - 字符串/index.md
        - 字符串/概述.md
        - 字符串/字符串匹配.md
        - 字符串/字符串哈希.md
        - 字符串/字典树trie.md
        - 字符串/前缀函数&KMP.md
        - 字符串/Boyer-Moore算法.md
        - 字符串/Z函数(ex KMP).md
        - 字符串/自动机.md
        - 字符串/AC自动机.md
        - 字符串/后缀数组.md
        - 字符串/后缀自动机.md
        - 字符串/广义后缀自动机.md
        - 字符串/后缀树.md
        - 字符串/Manacher.md
        - 字符串/回文树.md
        - 字符串/序列自动机.md
        - 字符串/最小表示法.md
        - 字符串/Lyndon分解.md
        - 字符串/Main-Lorentz算法.md
    - 数学:
        - 数学/index.md
        - 数学/概论.md
        - 数学/二进制.md
        - 数学/高精度.md
        - 数学/快速幂.md
        - 数学/线性规划.md
        - 数学/群论.md
        - 数学/概率论.md
        - 数学/博弈论.md
        - 数学/牛顿迭代法.md
        - 数学/数值积分.md
        - 数学/傅里叶-莫茨金消元法.md
        - 数学/序理论.md
        - 数学/杨氏矩阵.md
        - 数学/Schreier–Sims 算法.md
        - 数学/Berlekamp-Massey 算法.md
    - 组合数学:
        - 组合数学/index.md
        - 组合数学/排列组合.md
        - 组合数学/抽屉原理.md
        - 组合数学/容斥原理.md
        - 组合数学/康托展开.md
        - 组合数学/斐波那契数列.md
        - 组合数学/错位排列.md
        - 组合数学/Catalan数.md
        - 组合数学/Stirling数.md
        - 组合数学/Bell数.md
        - 组合数学/Bernoulli数.md
        - 组合数学/Entringer数.md
        - 组合数学/Eulerian数.md
        - 组合数学/分拆数.md
        - 组合数学/Vandermonde卷积.md
    - 线性代数:
        - 线性代数/index.md
        - 线性代数/线性代数简介.md
        - 线性代数/向量.md
        - 线性代数/内积和外积.md
        - 线性代数/矩阵.md
        - 线性代数/初等变换.md
        - 线性代数/行列式.md
        - 线性代数/高斯消元.md
        - 线性代数/线性空间.md
        - 线性代数/线性基.md
        - 线性代数/线性映射.md
        - 线性代数/特征多项式.md
        - 线性代数/对角化.md
        - 线性代数/Jordan标准型.md
    - 数论:
        - 数论/index.md
        - 数论/概论.md
        - 数论/素数.md
        - 数论/最大公约数.md
        - 数论/欧拉函数.md
        - 数论/筛法.md
        - 数论/Messiel-Lehmer.md
        - 数论/分解质因数.md
        - 数论/裴蜀定理.md
        - 数论/欧几里得算法.md
        - 数论/欧拉定理 & 费马小定理.md
        - 数论/乘法逆元.md
        - 数论/线性同余方程.md
        - 数论/中国剩余定理.md
        - 数论/威尔逊定理.md
        - 数论/升幂定理.md
        - 数论/卢卡斯定理.md
        - 数论/拉格朗日定理.md
        - 数论/原根.md
        - 数论/离散对数.md
        - 数论/剩余与单位根.md
        - 数论/二次剩余.md
        - 数论/莫比乌斯反演.md
        - 数论/杜教筛.md
        - 数论/PN筛.md
        - 数论/Min_25筛.md
        - 数论/洲阁筛.md
        - 数论/Stern-Brocot树 & Farey序列.md
        - 数论/循环连分数.md
        - 数论/Pell方程.md
    - 多项式 & 生成函数:
        - 多项式 & 生成函数/index.md
        - 多项式 & 生成函数/概述.md
        - 多项式 & 生成函数/Lagrange插值.md
        - 多项式 & 生成函数/fft.md
        - 多项式 & 生成函数/ntt.md
        - 多项式 & 生成函数/快速复数论变换.md
        - 多项式 & 生成函数/快速沃尔什变换.md
        - 多项式 & 生成函数/Chirp Z 变换.md
        - 多项式 & 生成函数/多项式求逆.md
        - 多项式 & 生成函数/多项式开方.md
        - 多项式 & 生成函数/多项式除法 & 取模.md
        - 多项式 & 生成函数/多项式对数函数 & 指数函数.md
        - 多项式 & 生成函数/多项式牛顿迭代.md
        - 多项式 & 生成函数/多项式多点求值 & 快速插值.md
        - 多项式 & 生成函数/多项式三角函数.md
        - 多项式 & 生成函数/多项式反三角函数.md
        - 多项式 & 生成函数/常系数齐次线性递推.md
        - 多项式 & 生成函数/多项式平移 & 连续点值平移.md
        - 多项式 & 生成函数/符号化方法.md
        - 多项式 & 生成函数/普通生成函数.md
        - 多项式 & 生成函数/指数生成函数.md
        - 多项式 & 生成函数/狄利克雷生成函数.md
```
