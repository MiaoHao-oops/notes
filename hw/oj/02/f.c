#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int m, n;
        scanf("%d %d", &m, &n);
        if (m * n % 2 == 0)
            printf("Scenario #%d:\n%.2f\n\n", i + 1, (double)(m * n));
        else
            printf("Scenario #%d:\n%.2f\n\n", i + 1, (double)(m * n - 1) + sqrt(2.0));
    }
}