题目来源：[「CF825G」Tree Queries](https://codeforces.com/contest/825/problem/G)  

### 算法一 $ n \leq 10^3 $ 且 $ q \leq 10^3 $

每次询问时暴力跑答案。  

期望得分 $ 25 $ 分。  

### 算法二 $ n \leq 10^3 $

注意到每个投票装置第一次启动才有贡献，每次启动时暴力更新所有点的答案，询问的时候 $ \mathcal O (1) $ 回答。  

期望得分 $ 55 $ 分。  

### 算法三

把第一次 **启动的点** 定为根 $ t $，设查询的点为 $ x $，某个启动的点为 $ y $。  

则 $ ans = \min\limits_{y} \{ dis(x, y) \} $，其中 $ dis(x, y) $ 表示 $ x \to y $ 路径上编号最小的点。  

设 $ x $ 和 $ y $ 的 LCA 为 $ z $，则 $ dis(x, y) = \min (dis(x, z), dis(z, y)) $。  

因为 $ dis(x, t) \leq dis(x, z) $，所以 $ ans = \min\limits_{y} \{ dis(x, y) \} = \min(dis(x, t), \min \{ dis(z, y) \}) $。  

当 $ dis(x, t) \leq dis(z, y) $ 时，又 $ dis(x, t) = \min(dis(x, z), dis(z, t)) \leq dis(z, t) $，则 $ dis(t, y) = \min\limits (dis(t, z), dis(z, y)) \geq dis(x, t) $，此时 $ x \to t $ 更优。  

当 $ dis(x, t) > dis(z, y) $ 时，$ dis(t, y) = dis(z, y) $，此时 $ t \to y $ 更优。  

所以 $ ans = \min(dis(x, t), \min\limits_{y} \{ dis(t, y) \}) $。  

只需要维护 $ \min\limits_{y} \{ dis(t, y) \} $ 即可。  

时间复杂度 $ \mathcal O (n + q) $。  

期望得分 $ 100 $ 分。  

### 算法四

考虑以 $ 1 $ 为根，且所有 $ i $ 的父亲的编号都小于 $ i $ 的情况。  

第一次启动后，可能成为答案的点显然是一条链，每次启动后，新的答案点也只可能是原来的链的前缀。  

如果这条链是 $ 1 \to now $，答案显然就是 $ LCA(now, x) $，只需要维护这条链即可，答案可以用倍增（不知道能不能过）或者并查集计算。  

因为题目没保证这个性质，所以我们需要对树重构，像点分树那样，每次找重心变成找编号最小的。就叫重构后的树为 $ \texttt {djt} $ 吧。  

容易发现重构后答案不变，这里就不证明了。  

暴力重构的复杂度是 $ \mathcal O (n^2) $ 的，我们试着优化它。  

重构的过程类似于：选择一个连通块并找到这个连通块中的最小编号，断掉与最小编号的点的所有边。  

我们倒着模拟这个过程，一开始所有点各为一个连通块。  

从大到小枚举点 $ u $，每次加入一条边 $ (u, v) $，，如果 $ u < v $，说明 $ v $ 当前所在的连通块是被 $ u $ 断的，那么重构后连通块的父亲就是 $ u $；最后再把 $ u $ 和所有 $ v $ 所在的连通块合并。  

重构成 $ \texttt {djt} $ 后，按照一开始讲的方法维护即可。  

时间复杂度 $ \mathcal O (n \alpha (n)) $ 或者 $ \mathcal O (n \log_2 n) $。  

期望得分 $ 100 $ 分。  
