
###  ###


!!! note "vp——tag"
	- 2023/4/26 19:23:33：[867 (Div. 3)](https://codeforces.com/contest/1822)
	- 2023/4/28 13:14:03：[868 (div2)](https://codeforces.com/contest/1823)



### 牛客69 ###
1.	[E/F](https://ac.nowcoder.com/acm/contest/52441/E)：给定 n 个二维坐标（任意两点互不相同），输出等腰三角形个数
	- 判断三点共线：
		- 必要条件：$\frac {y_i-y_j}{x_i-x_j} = \frac {y_i-y_k}{x_i-x_k}, x_i\ne x_j, x_i\ne x_k$
		- 充要条件：$(x_i-x_j)(y_i-y_k) = (x_i-x_k)(y_i-y_j)$
	- 判断不共线的三点构成等腰三角形(边分别为 a, b, c) $\iff$ $a=b || a=c || b==c$ $\iff$ $a^2=b^2 || a^2=c^2 || b^2==c^2$ （若题目给出的是整数点，那么后者不会有浮点精度问题）
	- 枚举计算：$\sum\limits_{i=1}^n\sum\limits_{j=1}^{i-1}\sum\limits_{k=1}^{j-1}[d_{i,j}=d_{j,k}或d_{k,i}=d_{i,k}或d_{k,i}=d_{i,j} ~~\&~~三点不共线 ]$
	- 优化为 $\sum\limits_{i=1}^n\sum\limits_{j=1}^n[i\ne j]\sum\limits_{k=1}^{j-1}[d_{i,j}=d_{i,k}] - \frac 12\sum\limits_{i=1}^n\sum\limits_{j=1}^n[i\ne j]\sum\limits_{k=1}^{j-1}[\exist~ x_k=2\cdot x_i-x_j, y_k=2\cdot y_i-y_j]$
2.	[G](https://ac.nowcoder.com/acm/contest/52441/G)：`(ax+by)^n%p` 大模拟

