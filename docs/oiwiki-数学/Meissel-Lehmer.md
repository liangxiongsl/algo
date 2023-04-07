Meissel-Lehmer求出$1..n$内质数个数的亚线性算法

$亚线性算法：T(n)=a+b\times n^k, j\in (0, 1)$

$P_i：表示第k个质数，P_1=2$

$\delta_n、P_n^+为n的最小、最大质因子，\delta_n\le P_i\le P_n^+$

$\pi_n：1..n内的质数个数，\pi_n=\sum\limits_{i=1}^n[i=p]$

$\phi_{n,a}$为所有小于 $n$ 的正整数中满足其所有质因子都大于 $p_a$ 的数的个数

$\phi_{n,a}=\#\{i\le n|(p | i=>p>p_a)\}$

$=\sum\limits_{i=1}^{n-1}[~\forall~p\in~i,~p|i,~p~>~p_a]$

$P_{k, n, a}$为所有小于 $n$ 的正整数中满足可重质因子恰好有 $k$ 个且所有质因子都大于  的数的个数

$P_{k, n, a}=\#\{i\le n|i=p_1\times p_2\times ..\times p_k=>\forall j, p_j>p_a\}$

$=\sum\limits_{i=1}^{n-1}[~n=p_1\times p_2\times ..\times p_k,~p> p_a~]$

$(p_a^k>n~~=>~~P_{k,n,a}=0)$

$记：P_{0,n,a}=1$

$\phi_{n,a}=\sum\limits_{i=0}^{+\infty}P_{i,n,a}（实际上是有限的合式）$

$1)计算\pi_n$

$取x\in[n^\frac13,n^\frac12]$

$P_{1,n,\pi_{x}}=\pi_n-\pi_{x}$

$k\ge 3时,~P_{k,n,\pi_{x}}=0$

$=>~~\pi_n=\pi_x+\phi_{n,\pi_x}-P_{0,n,\pi_x}-P_{2,n,\pi_x}+P_{k\ge3,n,\pi_x}$

$~~~~~~~~~~~~~~=\pi_x+\phi_{n,\pi_x}-1-P_{2,n,\pi_x}$

$2)计算P_{2,n,\pi_x}$
