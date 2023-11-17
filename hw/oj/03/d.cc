#include <algorithm>
#include <cstdio>
#include <cstring>

long long a[1010];
long long dp[1010][1010];
int des[1010];
long long tree[1010];

#define MOD 1000000007

// bool cmp(int x, int y)
// {
//     if (a[x] == a[y]) return x > y;
//     return a[x] < a[y];
// }

int main()
{
    int T, M, N;
    scanf("%d", &T);

    for (int case_num = 1; case_num <= T; case_num++) {
        scanf("%d%d", &N, &M);
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= N; i++)
            scanf("%lld", &a[i]), des[i] = a[i], dp[i][1] = 1;

        std::sort(des + 1, des + N + 1);
        for (int i = 1; i <= N; i++)
            a[i] = std::lower_bound(des + 1, des + N + 1, a[i]) - des;

        // std::sort(des + 1, des + N + 1, cmp);

        for (int i = 1; i <= N; i++)
            printf("%lld ", a[i]);

        for (int j = 2; j <= M; j++) {
            memset(tree, 0, sizeof(tree));
            for (int i = 1; i <= N; i++) {
                long long tmp = 0;
                for (int idx = a[i] - 1; idx > 0; idx -= (idx & -idx))
                    tmp = (tmp + tree[idx]) % MOD;
                dp[i][j] = tmp;
                for (int idx = a[i]; idx <= N; idx += (idx & -idx))
                    tree[idx] = (tree[idx] + dp[i][j - 1]) % MOD;
            }
        }

        long long sum = 0;
        for (int i = N; i >= M; i--)
            sum = (sum + dp[i][M]) % MOD;
        printf("Case #%d: %lld\n", case_num, sum % MOD);
    }
}