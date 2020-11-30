# Pow(x, n)

先附上 LeetCode 相应题目链接 [Pow(x, n)](https://leetcode.com/problems/powx-n/)



## 理论讲解

### 题意分析 

> Implement [pow(*x*, *n*)](http://www.cplusplus.com/reference/valarray/pow/), which calculates *x* raised to the power *n* (i.e. xn).

题目要求实现 x^n^，注意到 n 的取值范围为 -2^31^ ~ 2^31^ - 1，故有：

- 当 n = 0，x^0^ = 1
- 当 n > 0，x^n^ 即 n 个 x 相乘
- 当 n < 0，x^n^ = 1 / x^-n^ 

由于 n < 0 可以用倒数的方式转化为 n > 0，故下面只讨论 n > 0 的情况。



### 举个栗子

$$
2^{10} = 1 * 2^2 * 2^8, 10 = 0*1 + 1*2 + 0*4 + 1*8, 10 = 01010_b
$$

$$
3.5^{15} = 1*3.5^1*3.5^2*3.5^4*3.5^8，15=1*1 + 1*2 + 1*4 + 1*8，15=01111_b
$$

$$
x^{46}=1*x^2*x^4*x^8*x^{32},4=0*1+1*2+1*4+1*8+0*16+1*32,46=0101110_b
$$



### 例子分析

​		相信聪明的你已经找到规律啦，这道题的技巧就在于利用 n 在计算机中以二进制存储的特性。由于二进制与平方有着说不清道不明但又十分巧妙的关系，假设 n 的二进制中第 i 位为 1 那么就将底数的 2^i^ 次方乘起来，将所有二进制中为 1 的位对应的数乘起来，就能得到最终的结果啦，是不是又简单又巧妙呢？

*注: x 的 2^i^ 次方即是将 x 平方 i 次。* 



## 具体实现

### 编程技巧

​		C 语言支持位运算操作（即直接对数据的二进制位进行操作），但由于并非讲解重点，此处只针对 C 语言初学者展示本题相关的位运算技巧，并作出简单解释。（熟悉位运算的小伙伴可以直接跳过）

- `N & 1` 取出 N 的最低位（最后一位），结果与 N 的最低位相同，若 N 的最低位为 1 则结果为 1，否则为 0，效果相当于 `N % 2` （常用于判断奇偶性），但位运算操作的效率远高于求模操作。
- `N >>= 1` 为 `N = N >> 1` 的简写形式，其效果为将 N 右移一位并将值赋给 N，例如 `0110 1001` 右移一位为 `0011 0100`，效果相当于将 `N / 2`，但位运算操作的效率远高于除法操作。



### Talk is cheap. Show me the code.

``` c
double myPow(double x, int n) {
    if (n == 0) return 1; // 当指数为 0，直接返回 1
    long long N = n;
    double result = 1, multiple = x;
    if (N < 0) { // 如果指数为负数
        N = -N; // N 取相反数
        multiple = 1 / x; // 底数取倒数
    }
    while (N) {	// 相当于 N != 0
        if (N & 1) // 取 N 二进制的最后一位
            result *= multiple; // 相当于 result = result * multiple
        N >>= 1; // 将 N 右移一位（舍弃最右边的一位）
        multiple *= multiple; // 平方, 等效于 multiple = multiple * multiple
    }
    return result;
}
```



## 附

最后附上分治法递归实现，原理较为通俗易懂，就不多废话了。

```c
double myPower(double x, unsigned int n) {
    if (n == 1) return x;
    double result = myPower(x, n >> 1);
    return n & 1 ? x * result * result : result * result;
}

double myPow(double x, int n) {
    if (n == 0 || x == 1) return 1;
    if (x == 0) return 0;
    if (n == INT_MIN) return 1 / (x * myPower(x, INT_MAX));
    if (n < 0) return 1 / myPower(x, -n);
    return myPower(x, n);
}
```





