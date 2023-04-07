###### 1、二分法

![](D:\Document%20And%20Settings2\lx\Desktop\project-梁雄\img\2022-06-22-15-02-40-image.png)

![](D:\Document%20And%20Settings2\lx\Desktop\project-梁雄\img\2022-06-22-15-16-15-image.png)

```cpp
const int N = 1e5+3;
int a[N];
int binarySearch(int lb, int ub, int key){
    int ret = -1;
    int mid;
    while(lb <= ub){
        mid = lb + (ub - lb >> 1);
        if(a[mid] < key) lb = mid + 1;
        else if(a[mid] > key) ub = mid - 1;
        else{
            ret = mid;
            break;
        }
    }
    return ret;
}
```

![](D:\Document%20And%20Settings2\lx\Desktop\project-梁雄\img\2022-06-22-15-20-02-image.png)

+ 最大值最小化、最小值最大化
  
  ![](D:\Document%20And%20Settings2\lx\Desktop\project-梁雄\img\2022-06-22-15-25-05-image.png)

+ 二分答案
  
  [P1873 [COCI 2011/2012 #5] EKO / 砍树(luogu.com.cn)](https://www.luogu.com.cn/problem/P1873)
  
  ```cpp
  #include<iostream>
  using namespace std;
  
  const int N = 1e6+3;
  int n, m, mx;
  int a[N];
  
  bool check(int k){
      long long sum = 0;
      for(int i=1; i<=n; i++) sum += max(0, a[i] - k);
      return sum >= m;
  }
  int find(int lb, int ub){
      while(lb + 1 < ub){
          int mid = lb + ub >> 1;
          if(check(mid)) lb = mid;
          else ub = mid;
      }
      return lb;
  }
  
  int main(){
      cin >> n >> m;
      for(int i=1; i<=n; i++) cin >> a[i], mx = max(mx, a[i]);
  
      cout << find(1, mx + 1) << '\n';
  }
  ```

<img src="file:///D:/Document%20And%20Settings2/lx/Desktop/project-梁雄/img/2022-06-22-16-25-58-image.png" title="" alt="" data-align="right">

+ 总结

1）$while(lb<=ub)$：闭区间，区间至少一个数（区间空时结束）

2）$while(lb~<~ub)$：左闭右开区间，区间至少2个数（剩下1个数时结束）

3）$while(lb+1<ub)$：区间至少3个数（剩下2个数时结束）

研究一下 情况 2) 的分类，可以推出 3） 的分类方法！ （最终版本是情况 3））

```cpp
int a[N];
int l, r, target;

int f(){
    // 左闭右开，升序，右边界（输出与 lb 相关） 
    int lb = l, ub = r+1;
    while(lb < ub){
        int mid = lb+ub>>1;

        // 原始结构 
        if(a[mid] == target) lb = mid + 1;
        else if(a[mid] < target) lb = mid + 1;
        else if(a[mid] > target) ub = mid;

        // 升序，右边界 
        if(a[mid] <= target) lb = mid + 1;
        else ub = mid;

        // 降序，右边界 
        if(a[mid] >= target) lb = mid + 1;
        else ub = mid;
    }
//  lb = mid+1  =>  mid = lb-1
    return lb-1;
}
int g(){
    // 左闭右开，升序，左边界 （输出与 ub 相关）
    int lb = l, ub = r+1;
    while(lb < ub){
        int mid = lb+ub>>1;

        // 原始结构 
        if(a[mid] == target) ub = mid;
        else if(a[mid] < target) lb = mid + 1;
        else if(a[mid] > target) ub = mid;

        // 升序，左边界 
        if(a[mid] >= target) ub = mid;
        else lb = mid + 1;

        // 降序，左边界 
        if(a[mid] <= target) ub = mid;
        else lb = mid + 1;
    }
    return lb;
}
```

```cpp
int l, r, target;
void f(){
    // 升序，右边界 
    if(a[mid] <= target) lb = mid + 1;
    else ub = mid;

    // 降序，右边界（常用）
    if(a[mid] >= target) lb = mid + 1;
    else ub = mid;

    // 升序，左边界（常用）
    if(a[mid] < target) lb = mid + 1;
    else ub = mid;

    // 降序，左边界 
    if(a[mid] > target) lb = mid + 1;
    else ub = mid;
}
```

（二分通常有一个输入 $k$， 一个广义上的输出 $mid$ ，升序 或 降序 指的是 $k$ 与 $mid$ 正**相关 或 负相关**（或者**逻辑上 正相关 或 负相关**））

###### 2、三分法（补）

![](D:\Document%20And%20Settings2\lx\Desktop\project-梁雄\img\2022-06-22-16-27-37-image.png)

![](D:\Document%20And%20Settings2\lx\Desktop\project-梁雄\img\2022-06-22-16-30-04-image.png)

###### 3、分数规划（补）

![](D:\Document%20And%20Settings2\lx\Desktop\project-梁雄\img\2022-06-22-16-41-48-image.png)

![](D:\Document%20And%20Settings2\lx\Desktop\project-梁雄\img\2022-06-22-22-44-03-image.png)

+ 二分法
  
  ![](D:\Document%20And%20Settings2\lx\Desktop\project-梁雄\img\2022-06-22-22-49-43-image.png)
  
  + 模板
    
    ```cpp
    bool check(double mid){
        double sum = 0;
        for(int i=1; i<=n; ++i)
            if(a[i] - mid * b[i] > 0)
                sum += a[i] - mid * b[i];
        return sum > 0;
    }
    
    double find(double lb, double ub){
        while(lb + 1e-7 < ub){
            double mid = (lb + ub) / 2;
            if(check(mid)) lb = mid;
            else ub = mid;
        }
        return lb;
    }
    ```

+ Dinkelbach算法
  
  ![](D:\Document%20And%20Settings2\lx\Desktop\project-梁雄\img\2022-06-22-22-50-17-image.png)

+ 例题

+ + [2976 -- Dropping tests (poj.org)](http://poj.org/problem?id=2976)

```cpp
#include <cstdio>
#include <iostream>
#include <algorithm>
#define eps 1e-7
using namespace std;

const int N = 2e3+3;
int n, m;
double a[N], b[N];
double t[N];

double check(double mid){
    for(int i=0; i<n; i++) t[i] = a[i] - mid*b[i];
    sort(t, t + n);
    double ans = 0;
    for(int i=m;i<n;i++) ans += t[i];
    return ans > 0;
}
int main(){
    while(~scanf("%d%d", &n, &m)){
        if(n + m == 0) break;

        for(int i=0; i<n; i++) scanf("%lf",&a[i]);
        for(int i=0; i<n; i++) scanf("%lf",&b[i]);

        double lb = 0.0, ub = 1.0, mid;
        while(ub - lb > eps){
            mid = (lb+ub) / 2;
            if(check(mid)) lb = mid;
            else ub = mid;
        }
        printf("%1.f\n", lb *100);
    }
}
```

+ + 
