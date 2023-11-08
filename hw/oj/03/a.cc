#include <algorithm>
#include <cstdio>
#include <cstring>

long long a[60];

int main()
{
    int T, n;
    long long t;
    int *dp;
    long long *time;
    scanf("%d", &T);

    for (int x = 0; x < T; x++) {
        scanf("%d%lld", &n, &t);
        dp = (int*)malloc(sizeof(int) * (t + 1));
        memset(dp, 0, sizeof(int) * (t + 1));
        time = (long long*)malloc(sizeof(long long) * (t + 1));
        memset(time, 0, sizeof(long long) * (t + 1));

        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }

        t--;

        // for (int i = 0; i < n; i++) {
        //     printf("%lld ", a[i]);
        // }
        // printf("\n%lld %d\n", max_time, max_time_idx);

        for (int i = 0; i < n; i++) {
            for (int j = t; j >= a[i]; j--) {
                long long ttime = time[j - a[i]] + a[i];
                int tnum = dp[j - a[i]] + 1;
                if (tnum == dp[j] && time[j] < ttime || dp[j] < tnum)
                    dp[j] = tnum, time[j] = ttime;
            }
        }

        printf("Case %d: %d %lld\n", x + 1, dp[t] + 1, time[t] + 678);
        
        free(dp);
        free(time);
    }
}
