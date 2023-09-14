#include <stdio.h>
#include <string.h>

int main()
{
    int T, i, N, j, x, y, time, temp, k;
    int used[200];
    scanf("%d", &T);

    for (i = 0; i < T; i++) {
        memset(used, 0, sizeof(int) * 200);
        scanf("%d", &N);
        time = 0;
        for (j = 0; j < N; j++) {
            scanf("%d %d", &x, &y);
            x = (x - 1) / 2;
            y = (y - 1) / 2;

            if (x > y) {
                temp = x;
                x = y;
                y = temp;
            }
            for (k = x; k <= y; k++) 
                used[k]++;
        }
        for (k = 0; k < 200; k++) {
            if (used[k] > time)
                time = used[k];
        }
        printf("%d\n", time * 10);
    }
    return 0;
}