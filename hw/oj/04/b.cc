#include <algorithm>
#include <cstdio>
#include <cstdlib>

long long head[20010];
long long knight[20010];

int comp(const void *a, const void *b)
{
    long long *x = (long long *)a;
    long long *y = (long long *)b;
    return *x - *y;
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) && n != 0 || m != 0) {
        for (int i = 0; i < n; i++)
            scanf("%lld", &head[i]);
        for (int i = 0; i < m; i++)
            scanf("%lld", &knight[i]);

        if (m < n) {
            printf("Loowater is doomed!\n");
            continue;
        }

        std::qsort(head, n, sizeof(long long), comp);
        std::qsort(knight, m, sizeof(long long), comp);

        int i = 0, j = 0;
        long long sum = 0;
        while (i < n && j < m) {
            if (knight[j] >= head[i]) {
                sum += knight[j];
                i++;
                j++;
            } else {
                j++;
            }
        }
        if (i != n) {
            printf("Loowater is doomed!\n");
        } else {
            printf("%lld\n", sum);
        }
    }
}