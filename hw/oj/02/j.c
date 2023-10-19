#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int main()
{
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        long long a, b;
        long long x, y;
        scanf("%lld %lld", &a, &b);
        x = (a + b);
        y = (a - b);
        if (x < 0 || y < 0 || x % 2 != 0 || y % 2 != 0) {
            printf("impossible\n");
            continue;
        }
        printf("%lld %lld\n", x / 2, y / 2);
    }
}