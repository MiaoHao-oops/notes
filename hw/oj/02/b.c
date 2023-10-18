#include <stdio.h>

#define LEN 55
int N[LEN];
long long a[LEN];

int main()
{
    int n;
    int max = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &N[i]);
        if (N[i] > max)
            max = N[i];
    }

    a[1] = 1;

    for (int i = 2; i <= max; i++) {
        a[i] = a[i - 1] + i + (i % 2 == 1 ? 1 : 0);
    }

    for (int i = 0; i < n; i++) {
        printf("%lld\n", a[N[i]]);
    }

    return 0;
}