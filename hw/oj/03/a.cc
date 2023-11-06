#include <algorithm>
#include <cstdio>
#include <cstring>

long long dp[60];
long long a[60];

int main()
{
    int T, n, t;
    scanf("%d", &T);

    for (int x = 0; x < T; x++) {
        memset(dp, 0, sizeof(dp));
        scanf("%d%d", &n, &t);

        for (int i = 0; i < n; i++)
            scanf("%lld", &a[i]);

        dp[0] = a[0] < t ? a[0] : 0;
        for (int i = 1; i < n; i++) {
            long long max1 = -1, max2 = -1;
            for (int j = 0; j < i; j++) {
                if (max1 < dp[j])
                    max1 = dp[j];
            }
            for (int j = 0; j < i; j++) {
                if (max2 < dp[j] + a[i] && dp[j] + a[i] < t)
                    max2 = dp[j] + a[i];
            }
            max1 = std::max(max1, a[i]);
            dp[i] = std::max(max1, max2);
        }
        printf("%lld\n", dp[n - 1] + 678);
    }
}