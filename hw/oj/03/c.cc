#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

// #define DEBUG

long long grid[11][101];
long long dp[11][101];
// int p[11][101];
std::vector<int> p[11][101];

#define min(a, b) ((cmp(a, b) < 0) ? (a) : (b))

int cmp(std::vector<int> a, std::vector<int>b)
{
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j]) {
            i++, j++;
        } else {
            return a[i] - b[j];
        }
    }

    return (i == a.size() && j == a.size()) ? 0 : a.size() - b.size();
}

int main()
{
    int n, m;
 
    while (scanf("%d%d", &m, &n) != EOF) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%lld", &grid[i][j]);
                p[i][j].clear();
            }
            dp[i][0] = grid[i][0];
            p[i][0].push_back(i + 1);
        }

        for (int j = 1; j < n; j++) {
            for (int i = 0; i < m; i++) {
                long long path[3];
                std::vector<int> row[3];
                path[0] = i == 0 ? dp[m - 1][j - 1] : dp[i - 1][j - 1];
                row[0] = i == 0 ? p[m - 1][j - 1] : p[i - 1][j - 1];
                path[1] = dp[i][j - 1];
                row[1] = p[i][j - 1];
                path[2] = i == (m - 1) ? dp[0][j - 1] : dp[i + 1][j - 1];
                row[2] = i == (m - 1) ? p[0][j - 1] : p[i + 1][j - 1];
                row[0].push_back(i + 1);
                row[1].push_back(i + 1);
                row[2].push_back(i + 1);
                if (path[0] < path[1]) {
                    if (path[0] < path[2]) {
                        dp[i][j] = path[0] + grid[i][j];
                        p[i][j] = row[0];
                    } else if (path[0] == path[2]) {
                        dp[i][j] = path[0] + grid[i][j];
                        p[i][j] = min(row[0], row[2]);
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
                        p[i][j] = min(row[1], row[2]);
                    } else {
                        dp[i][j] = path[2] + grid[i][j];
                        p[i][j] = row[2];
                    }
                } else {
                    if (path[2] == path[0]) {
                        dp[i][j] = path[2] + grid[i][j];
                        p[i][j] = min(row[0], min(row[1], row[2]));
                    } else if (path[2] < path[0]) {
                        dp[i][j] = path[2] + grid[i][j];
                        p[i][j] = row[2];
                    } else {
                        dp[i][j] = path[1] + grid[i][j];
                        p[i][j] = min(row[0], row[1]);
                    }
                }
            }
        }

        long long min = dp[0][n - 1];
        std::vector<int> pmin = p[0][n - 1];
        for (int i = 1; i < m; i++)
            if (min > dp[i][n - 1] || cmp(p[i][n - 1], pmin) < 0 && min == dp[i][n - 1]) {
                min = dp[i][n - 1], pmin = p[i][n - 1];
            }

        for (int i = 0; i < pmin.size() - 1; i++)
            printf("%d ", pmin[i]);
        printf("%d", pmin[pmin.size() - 1]);

        printf("\n%lld\n", min);
    }
}
