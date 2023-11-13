#include <algorithm>
#include <cstdio>

// #define DEBUG

long long grid[11][101];
long long dp[11][101];
int p[11][101];

int main()
{
    int n, m;
 
    while (scanf("%d%d", &m, &n) != EOF) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%lld", &grid[i][j]);
            }
            dp[i][0] = grid[i][0];
        }

        for (int j = 1; j < n; j++) {
            for (int i = 0; i < m; i++) {
                int path[3], row[3];
                path[0] = i == 0 ? dp[m - 1][j - 1] : dp[i - 1][j - 1];
                row[0] = i == 0 ? m - 1 : i - 1;
                path[1] = dp[i][j - 1];
                row[1] = i;
                path[2] = i == (m - 1) ? dp[0][j - 1] : dp[i + 1][j - 1];
                row[2] = i == (m - 1) ? 0 : i + 1;
                if (path[0] < path[1]) {
                    if (path[0] < path[2]) {
                        dp[i][j] = path[0] + grid[i][j];
                        p[i][j] = row[0];
                    } else if (path[0] == path[2]) {
                        dp[i][j] = path[0] + grid[i][j];
                        p[i][j] = std::min(row[0], row[2]);
                    } else {
                        dp[i][j] = path[2] + grid[i][j];
                        p[i][j] = row[2];
                    }
                } else if (path[0] > path[1]) {
                    if (path[1] < path[2]) {
                        dp[i][j] = path[1] + grid[i][j];
                        p[i][j] = row[1];
                    } else if (path[1] == path[2]) {
                        dp[i][j] = path[1] + grid[i][j];
                        p[i][j] = std::min(row[1], row[2]);
                    } else {
                        dp[i][j] = path[2] + grid[i][j];
                        p[i][j] = row[2];
                    }
                } else {
                    if (path[2] == path[0]) {
                        dp[i][j] = path[2] + grid[i][j];
                        p[i][j] = std::min(row[0], std::min(row[1], row[2]));
                    } else if (path[2] < path[0]) {
                        dp[i][j] = path[2] + grid[i][j];
                        p[i][j] = row[2];
                    } else {
                        dp[i][j] = path[1] + grid[i][j];
                        p[i][j] = std::min(row[0], row[1]);
                    }
                }
            }
        }
#ifdef DEBUG
        printf("\n");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                printf("%2lld ", dp[i][j]);
            }
            printf("\n");
        }

        printf("\n");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                printf("%2d ", p[i][j]);
            }
            printf("\n");
        }
#endif

        long long min = 0xffffffff, pmin = 0xffffffff;
        int idx = 0;
        for (int i = 0; i < m; i++)
            if (min > dp[i][n - 1] || pmin > p[i][n - 1] && min == dp[i][n - 1]) {
                min = dp[i][n - 1], idx = i, pmin = p[i][n - 1];
            }

        int path[1001];
        path[n - 1] = idx;
        for (int j = n - 2, i = idx; j >= 0; j--) {
            path[j] = p[i][j + 1];
            i = path[j];
        }

#ifdef DEBUG
        printf("n = %d\n", n);
#endif
        for (int j = 0; j < n - 1; j++)
            printf("%d ", path[j] + 1);

        printf("%d", path[n - 1] + 1);

        printf("\n%lld\n", min);
    }
}
