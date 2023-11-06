#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cstdio>

#define MAX_N 10010

int father[MAX_N], dp[MAX_N][3];
std::vector<int>son[MAX_N];

int f(int u, int s)
{
    if (dp[u][s] != -1)
        return dp[u][s];
    switch (s) {
    case 0:
        dp[u][s] = 1;
        for (auto i = son[u].begin(); i != son[u].end(); i++) {
            dp[u][s] += std::min(f(*i, 0), f(*i, 1));
        }
        break;
    case 1:
        dp[u][s] = 0;
        for (auto i = son[u].begin(); i != son[u].end(); i++) {
            dp[u][s] += f(*i, 2);
        }
        break;
    case 2:
        dp[u][s] = 10010;
        for (auto i = son[u].begin(); i != son[u].end(); i++) {
            dp[u][s] = std::min(dp[u][s], f(u, 1) - f(*i, 2) + f(*i, 0));
        }
        break;
    }
    return dp[u][s];
}

int main()
{
    int N, a, b;

    while (scanf("%d", &N) == 1) {
        memset(father, 0, sizeof(father));
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < N; i++)
            son[i].clear();
        for (int i = 1; i < N; i++) {
            scanf("%d%d", &a, &b);
            if (father[a] == 0) {
                father[a] = b;
                son[b].push_back(a);
            } else {
                father[b] = a;
                son[a].push_back(b);
            }
        }

        scanf("%d", &N);
        int root = 1;
        while (father[root] != 0)
            root++;
        printf("%d\n", std::min(f(root, 0), f(root, 2)));
        if (N == -1)
            break;
    }
    return 0;
}