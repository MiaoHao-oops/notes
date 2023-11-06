#include <algorithm>
#include <cstdio>
#include <cstring>

long long dp[60];
long long a[60];
int num[60];

int main()
{
    int T, n, t;
    scanf("%d", &T);

    for (int x = 0; x < T; x++) {
        memset(dp, 0, sizeof(dp));
        memset(num, 0, sizeof(num));
        scanf("%d%d", &n, &t);

        for (int i = 0; i < n; i++)
            scanf("%lld", &a[i]);

        dp[0] = a[0] < t ? a[0] : 0;
        num[0] = a[0] < t ? 1 : 0;
        for (int i = 1; i < n; i++) {
            long long max1 = -1, max2 = -1;
            int idx1 = 0, idx2 = 0;
            for (int j = 0; j < i; j++) {
                if (max1 < dp[j]) {
                    max1 = dp[j];
                    idx1 = j;
                }
            }
            for (int j = 0; j < i; j++) {
                if (max2 < dp[j] + a[i] && dp[j] + a[i] < t) {
                    max2 = dp[j] + a[i];
                    idx2 = j;
                }
            }
            if (a[i] > max2 && a[i] < t) {
                max2 = a[i];
                idx2 = i;
            }
            if (max1 > max2) {
                dp[i] = max1;
                num[i] = num[idx1];
            } else {
                dp[i] = max2;
                num[i] = num[idx2] + 1;
            }
        }
        printf("Case %d: %d %lld\n", x + 1, num[n - 1] + 1, dp[n - 1] + 678);
    }
}