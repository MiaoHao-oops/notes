#include <algorithm>
#include <cstdio>
#include <cstring>

bool is_rev(char *s, int begin, int end)
{
    while (s[begin] == s[end] && begin <= end) {
        begin++;
        end--;
    }

    if (begin < end)
        return false;
    else
        return true;
}

int main()
{
    int n;
    char s[1010];
    int dp[1010];

    s[0] = 'b';
    
    scanf("%d", &n);
    for (int num = 0; num < n; num++) {
        scanf("%s", &s[1]);
        memset(dp, 0, sizeof(dp));

        dp[1] = 1;
        for (int i = 2; i < strlen(s); i++) {
            int min = 10000;
            for (int j = i - 1; j >= 1; j--) {
                if (is_rev(s, j, i) && dp[j - 1] + 1 < min) {
                    min = dp[j - 1] + 1;
                }
            }
            dp[i] = std::min(dp[i - 1] + 1, min);
        }
        printf("%d\n", dp[strlen(s) - 1]);
    }
}