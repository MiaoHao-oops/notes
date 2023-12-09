#include <cstdio>

int main()
{
    int t, n;
    scanf("%d", &t);
    for (int num = 0; num < t; num++) {
        scanf("%d", &n);
        int sum = 0, x;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            sum += x;
        }
        if (sum == n) {
            printf("0\n");
        } else if (sum <= 0 || sum > 0 && sum < n) {
            printf("1\n");
        } else {
            printf("%d\n", sum - n);
        }
    }
}