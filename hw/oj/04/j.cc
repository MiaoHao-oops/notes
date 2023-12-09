#include <cstdio>

int x[1010], y[1010];

int main()
{
    int s, n;
    scanf("%d%d", &s, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x[i], &y[i]);
    }

    int win = 0;
    while (win < n) {
        int max = -1, idx;
        for (int i = 0; i < n; i++) {
            if (x[i] < s && x[i] != -1 && y[i] > max) {
                max = y[i];
                idx = i;
            }
        }
        if (max == -1) {
            printf("NO\n");
            return 0;
        }
        s += max;
        x[idx] = -1;
        win += 1;
    }
    printf("YES\n");
}