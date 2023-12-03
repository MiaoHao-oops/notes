## Greedy 作业
郝淼 202328013229045

### 1. Commando War

显然，最终的任务完成时间一定大于 $\Sigma B[i]$，因此，从直觉上讲，更倾向于将更长的 $J[i]$ 安排在前面。

**命题1**：假设已经得到了一个任意的顺序安排，且最长的 $J[i]$，记为 $J[max]$ 不是最先执行的任务，那么交换 $J[max]$ 和 $J[1]$ 的顺序，总时间不增。

**证明**：最终的完成时间 $t$ 可以等价地表述为“完成所有任务所需时间的最大值”，即$\max\{t_i|t_i为完成第i个任务的时间\}$。

根据已知，有 $t_1=B[1]+J[1]$，$t_{max}=\Sigma_{i=1}^{max}B[i]+J[max]$，$J[1]\le J[max]$。交换 $J[1]$ 和 $J[max]$ 后，有 $t_1^{\prime}=B[max]+J[max]$，$t_{max}^{\prime}=\Sigma_{i=1}^{max}B[i]+J[1]$。

因此，$t_1^{\prime}\le t_{max}$，$t_{max}^{\prime}\le t_{max}$，对于其他下标 $j$，若 $j < max$，则 $t_j^{\prime} = B[max] + \Sigma_{i=2}^j B[i] + J[j] < B[max] + \Sigma_{i=2}^j B[i] + B[1] + \Sigma_{i=j+1}^{max-1} B[i] + J[max] =  t_{max}$，若 $j > max$，则 $t_j^{\prime} = t_j$ 没有改变，从而 $t$ 不增，证毕。

根据**命题1**，只需要按照 $J[i]$ 从大到小的顺序选择，就可以保证总用时最小。

算法伪码如下：

```c
// 假设 B，J 下标均从 1 开始
int solution(B, J, N)
{
    sort_by_J(B, J);
    int MAX = J[1], sum = B[1];
    for i in 2 to N {
        sum += B[i];
        MAX = max(MAX, B[i] + J[i]);
    }
    return sum + MAX;
}
```

算法时间复杂度为 $O(n\log n)$。

### 2. DNA Consensus String

我们想找到一个字符串 $s$，使得 $ce = \Sigma_{i=1}^m dist(s, s_i)$，最小，其中 $dist(s, s_i) = \Sigma_{j=1}^n (s[j] == s_i[j] ? 0 : 1)$ 为 $s$ 和 $s_i$ 的汉明距离。

利用定义，$ce = \Sigma_{i=1}^m \Sigma_{j=1}^n (s[j] == s_i[j] ? 0 : 1) = \Sigma_{j=1}^n \Sigma_{i=1}^m (s[j] == s_i[j] ? 0 : 1)$。其中 $\Sigma_{i=1}^m (s[j] == s_i[j] ? 0 : 1)$ 表示 $s$ 的第 $j$ 个字符和每个 $s_i$ 的第 $j$ 个字符的汉明距离之和。因此，可以以每个 $s_i$ 的第 $j$ 个字符为单位，构成 $n$ 列。为了得到最小 $ce$，只需要选择第 $j$ 列中出现次数最多的字符作为 $s[j]$ 即可，依据题意，若出现次数最多的字符有多个，则选择字典序最小的。这样就可以保证每一个 $\Sigma_{i=1}^m (s[j] == s_i[j] ? 0 : 1)$ 都是最小的，从而它们的和也最小。

算法伪代码如下：

```c
int solution({s_1, s_2, ..., s_m}, n)
{
    int sum = 0;
    for j in 1 to n {
        找到{s_1[j], s_2[j], ..., s_m[j]}中出现次数最多、字典序最小的字母c;
        它的出现次数为x;
        s[j] = c;
        sum += x;
    }
    return (s, m * n - sum)
}
```

算法时间复杂度为 $O(mn)$。

### 3. Opponents

这题只需要将 $d \times n$ 的矩阵遍历一遍即可，因为要求连续天数，所以一旦遇到某一天全为 1，就需要重新计数。

算法伪代码如下：

```c
int solution(s[d][n])
{
    int cont = 0, ret = 0;
    for i in 1 to d {
        flag = 0;
        for j in 1 to n {
            if s[i][j] == '0' {
                flag = 1;
                break;
            }
        }
        if flag == 0 {
            cont = 0;
        } else {
            cont++;
        }
        ret = max(ret, cont);
    }
    return ret;
}
```

算法时间复杂度为 $O(dn)$。
