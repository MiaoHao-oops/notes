## Dynamic Programming 作业
郝淼 202328013229045

### 1 Money Robbing

假设输入为 `a[i]`，用 `dp[i]` 表示前 `i` 个房子最多获得多少钱。显然，`dp[i]` 要么是抢第 `i` 个房子，这样就不能抢第 `i - 1` 个房子，因此再加上 `dp[i - 1]`；要么是不抢第 `i` 个房子，直接为 `dp[i - 1]`。得到贝尔曼方程

$$
dp[i] = \max\{dp[i-1], dp[i-2]+a[i]\}, i>2\\ dp[0]=a[0], dp[1]=\max\{a[0], a[1]\}
$$

伪代码为（Rust 风格）：

```rust
fn solution(a: Vec<usize>) -> usize {
    let mut dp = [0; 2];
    dp[0] = a[0];
    dp[1] = if a[0] > a[1] {
        a[0]
    } else {
        a[1]
    };
    for i in 2..a.len() {
        let tmp = if dp[0] + a[i] > dp[1] {
            dp[0] + a[i]
        } else {
            dp[1]
        };
        dp[0] = dp[1];
        dp[1] = tmp;
    }
    dp[1]
}
```

如果所有房子排成一个环形，则可以在 `a[0]` ~ `a[N - 2]` 和 `a[1]` ~ `a[N - 1]` 上分别跑一遍 `solution()`，两个结果取最大值即可。在 `a[0]` ~ `a[N - 2]` 上跑相当于必定不选 `a[N - 1]`，这样就避免了同时选 `a[0]` 和 `a[N - 1]` 的情景，另一种情况同理。

### 2 Ugly Number

根据 Ugly Number（UN）的定义，可以得出任何一个 UN 必然是由另一个 UN 乘 2 或 3 或 5 得到的，因此可以得到朴素的暴力求解算法。为了得到第 $n$ 个 UN，可以遍历前 $n - 1$ 个 UN，然后将其分别乘 2 或 3 或 5，找到大于第 $n - 1$ 个 UN 的最小的结果，即为第 $n$ 个 UN，该算法的时间复杂度为 $O(n^2)$。

伪代码如下：

```rust
fn solution(n: usize) -> usize {
    let mut un: Vec<usize> = Vec::new();
    un.push(2);
    for i in 2..n {
        let mut tmp: Vec<usize> = Vec::new();
        for j in 0..i {
            tmp.push(un[i] * 2);
            tmp.push(un[i] * 3);
            tmp.push(un[i] * 5);
        }
        un.push(tmp.min());
    }
    un[n - 1]
}
```

通过寻找这个朴素算法中的冗余计算，可以发现，内层循环不需要遍历前 $n - 1$ 项中的每一项。注意到，如果一个新的丑数 $un[i]$ 是由某个丑数 $un[k]$ 乘 2 得到的，那么显然可以得到以下结论：

- 大于 $un[i]$ 的下一个由某个 UN 乘 2 得到的 UN 一定是 $un[k + 1] \times 2$ 

同理，可以推广到 3 和 5 的情况。基于以上结论，可以利用 3 个变量存储下一个乘2（或3、5）得到新 UN 的已有 UN 下标，得到的算法伪码如下：

伪代码如下：

```rust
fn solution(n: usize) -> usize {
    let mut un: Vec<usize> = Vec::new();
    let mut fac = (0, 0, 0);
    un.push(1);
    for i in 1..n {
        un.push(min(
            un[fac.0] * 2,
            un[fac.1] * 3,
            un[fac.2] * 5
        ))
        if un[fac.0] * 2 < un[fac.1] * 3 &&
           un[fac.0] * 2 < un[fac.2] * 5 {
            fac.0 += 1;
        } else if un[fac.0] * 3 < un[fac.1] * 2 &&
                  un[fac.0] * 3 < un[fac.2] * 5 {
            fac.1 += 1;
        } else {
            fac.2 += 1;
        }
    }
    un[n - 1]
}
```

显然，改算法的时间复杂度为 $O(n)$。

### 3 Unique Binary Search Trees

每一棵 BST 都可以拆分成 3 个部分：根、左子树和右子树。 由于 BST 结点之间具有序关系，当选定某个数作为根结点时，它的左右子树分别具有的结点数就确定了。因此，可以用 $dp[i]$ 表示有 $i$ 个结点的不同的 BST 有多少。注意，我们并不要求这 $i$ 个结点的数值为 $1, 2, ..., i$，只要是 $i$ 个互不相同的正整数即可。这是因为只要保持了这一特点，对于同一个 $i$，$dp[i]$ 总是不变的。贝尔曼方程为：

$$
dp[i] = \Sigma_{root = 1}^{i}(dp[root - 1] + dp[i - root])
$$

得到算法伪代码：

```rust
fn solution(n: usize) -> usize {
    let mut dp: Vec<usize> = Vec::new();
    dp.push(0);
    dp.push(1);
    for i in 2..(n + 1) {
        let mut sum: usize = 0;
        for root in 1..(i + 1) {
            sum += (dp[root - 1] + dp[i - root]);
        }
        dp.push(sum);
    }
    dp[n]
}
```

该算法的时间复杂度为 $O(n^2)$。

### 4 Largest Divisible Subset

对于每一个 Divisible Subset（DS），若对其中的元素进行排序，得到 $\{a_1, a_2, ..., a_n\}$，则根据定义，必然有 $a_{i + 1} \% a_{i} = 0$。因此，可以对原集合排序，再求最大 DS。

用 $dp[i]$ 表示以 $a[i]$ 作为 DS 中最大元素时，DS 的大小。贝尔曼方程为：

$$
dp[i] = \max\{dp[k]\ |\ a[i] \% a[k] = 0\} + 1
$$

得到伪代码为：

```rust
fn solution(a: Vec<usize>) -> usize {
    let mut dp: Vec<usize> = Vec::new();
    a.sort();

    dp.push(1);
    for i in 1..(a.len() + 1) {
        let mut max = 0;
        for k in 0..i {
            if (a[i] % a[k] == 0 && dp[k] > max) {
                max = dp[k];
            }
        }
        dp.push(max + 1);
    }
    dp.max();
}
```

该算法的时间复杂度为 $O(n^2)$。

### 5 Target Sum

对于给定的顺序数组 $a[0], a[1], ..., a[n-1]$，任意填写正负号，能得到的最大和显然为 $\Sigma_{k=0}^{n-1}a[k]$，最小和为 $-\Sigma_{k=0}^{n-1}a[k]$。因此，定义一个 $n\times (2\Sigma_{k=0}^{n-1}a[k] + 1)$ 的数组 $dp$，$dp[i][j]$ 表示 $a[0]$ 到 $a[i]$ 填写正负号，得到结果为 $j-\Sigma_{k=0}^{n-1}a[k]$ 的方案数。在每一步决策 $dp[i][j]$ 时，想要得到结果 $j-\Sigma_{k=0}^{n-1}a[k]$，可以看前 $i - 1$ 个元素得到结果 $j-\Sigma_{k=0}^{n-1}a[k] - a[i]$ 或 $j-\Sigma_{k=0}^{n-1}a[k] + a[i]$ 的方案数，然后再求和。即 $dp[i - 1][j - a[i]]$ 表示在 $a[i]$ 前写正号， $dp[i - 1][j + a[i]]$ 表示在 $a[i]$ 前写负号。得到贝尔曼方程：

$$
dp[i][j] = dp[i - 1][j - a[i]] + dp[i - 1][j + a[i]]
$$

伪代码如下：

```rust
fn sulution(a: Vec<usize>, target: usize) -> usize {
    let mut dp: Vec<Vec<usize>> = Vec::new();
    for i in 0..a.len() {
        dp.push(Vec::new());
    }
    for j in 0..(2 * a.sum() + 1) {
        if j - a.sum() == a[0] || j - a.sum() == -a[0] {
            dp[0].push(1);
        } else {
            dp[0].push(0);
        }
    }

    for i in 1..a.len() {
        for j in 0..(2 * a.sum() + 1) {
            dp[i].push(
                j - a[i] < 0 ? 0 : dp[i - 1][j - a[i]] +
                j + a[i] > 2 * a.sum() ? 0 : dp[i - 1][j + a[i]]
            );
        }
    }
    dp[a.len() - 1][target]
}
```

该算法的时间复杂度为 $O(mn)$，其中 $m$ 为 $a[]$ 数组所有元素的和。
