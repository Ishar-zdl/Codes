## $ \texttt {sagiri} $

### 题目背景

![](https://cdn.luogu.com.cn/upload/image_hosting/6ayiga50.png)

「焰火在天空绽放」

「在八月的这一个美好的日子放一支烟花」

「拥挤人潮中牵着的手绝不放开」

「给你的汽水下了咒语将我们想法传达给你」

### 题目描述

纱雾这么聪明当然会数学啦！她出了一道题想要考考你。  

定义 $ f(s) $ 表示 $ s $ 最小表示的开头元素的下标。下标从 $ 1 $ 开始，如果有多个满足的元素则取下标最小的那个。例如，$ f(\texttt {aaaa}) = 1, f(\texttt {babc}) = 2, f(\texttt {qweqweqwe}) = 3 $，因为三个字符串的最小表示分别为 $ \texttt {aaaa}, \texttt {abcb}, \texttt {eqweqweqw} $。  

纱雾有 $ n $ 个字符串 $ s_i $，第 $ i $ 个字符串的长度是 $ a_i $。  

纱雾的字符串是有魔力的，只要使用一个咒语，每个 $ s_i $ 会等概率地随机变成所有长度为 $ a_i $ 且只包含小写字母的 $ 26^{a_i} $ 个字符串的其中一个。  

请你求出 $ \sum_{i = 1}^n [f(s_i) = f(s_{(i \bmod n) + 1})] $ 的期望值，纱雾只需要你回答结果对 $ 998244353 $ 取模后的值。  

### 输入格式

从文件 $ \texttt {sagiri.in} $ 中读入数据。  

第 $ 1 $ 行，一个整数 $ \texttt {sub} $，表示该数据满足的 $ \texttt {Subtask} $ 的编号。  

第 $ 2 $ 行，一个正整数 $ n $。  

第 $ 3 $ 行，$ n $ 个正整数 $ a_i $。  

### 输出格式

输出到 $ \texttt {sagiri.out} $ 中。  

仅一行一个整数表示答案。  

### 样例

#### 样例 1

##### 样例 1 输入（$ \texttt {sagiri/sagiri1.in} $）

```plain
1
2
1 2
```

##### 样例 1 输出（$ \texttt {sagiri/sagiri1.ans} $）

```plain
729486259
```

##### 样例 1 解释

显然 $ f(s_1) = 1 $，$ f(s_2) = 1 + [s_{2, 1} > s_{2, 2}] $，所以 $ P(f(s_1) = f(s_2)) = \dfrac {351} {676}$，所以 $ E(\sum\limits_{i = 1}^n [f(s_i) = f(s_{(i \bmod n) + 1})]) = \dfrac {351} {676} + \dfrac {351} {676} = \dfrac {27} {26} = 729486259 \pmod {998244353} $。  

#### 样例 2

##### 样例 2 输入（$ \texttt {sagiri/sagiri2.in} $）

```plain
5
5
3 1 5 2 4
```

##### 样例 2 输出（$ \texttt {sagiri/sagiri2.ans} $）

```plain
727907401
```

#### 样例 3

见下发文件中的 $ \texttt {sagiri/sagiri3.in} $ 和 $ \texttt {sagiri/sagiri3.ans} $。  

该样例满足 $ \texttt {Subtask 2} $ 的限制。  

#### 样例 4

见下发文件中的 $ \texttt {sagiri/sagiri4.in} $ 和 $ \texttt {sagiri/sagiri4.ans} $。  

该样例满足 $ \texttt {Subtask 3} $ 的限制。  

#### 样例 5

见下发文件中的 $ \texttt {sagiri/sagiri5.in} $ 和 $ \texttt {sagiri/sagiri5.ans} $。  

该样例满足 $ \texttt {Subtask 4} $ 的限制。  

#### 样例 6

见下发文件中的 $ \texttt {sagiri/sagiri6.in} $ 和 $ \texttt {sagiri/sagiri6.ans} $。  

该样例满足 $ \texttt {Subtask 5} $ 的限制。  

### 数据范围与提示

**【数据范围】**

对于 $ 100\% $ 的数据：满足 $ 1 \leq n, a_i \leq 10^5 $。  

**【评测方式 & 得分规则】**

对于每个测试点，采用 **全文比较（过滤行末空格及文末回车）** 评测方式。  

**本题采用捆绑测试。** 详情见下表：  

| $ \texttt {Subtask} $ | 测试点编号 | $ n $ | 特殊性质 | 分值 | 子任务依赖 |
|:---:|:---:|:---:|:---:|:---:|:---:|
| $ 1 $ | $ 1 \sim 5 $ | $ = 2 $ | $ a_i \leq 5 $ | $ 5 $ | 无 |
| $ 2 $ | $ 6 \sim 15 $ | $ \leq 10^5 $ | $ a_i \leq 5 $ | $ 5 $ | $ 1 $ |
| $ 3 $ | $ 16 \sim 25 $ | $ \leq 10^5 $ | $ a_i $ 全为质数 | $ 30 $ | 无 |
| $ 4 $ | $ 26 \sim 35 $ | $ \leq 10^5 $ | $ \sum a_i \leq 10^5 $ | $ 15 $ | 无 |
| $ 5 $ | $ 36 \sim 50 $ | $ \leq 10^5 $ | 无 | $ 45 $ | $ 1, 2, 3, 4 $ |
