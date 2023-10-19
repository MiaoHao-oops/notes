#include <limits.h>
#include <stdio.h>

#define LEN 200010
#define max(a, b) ((a) > (b) ? (a) : (b))
long long a[LEN];

long long merge(int begin, int mid, int end)
{
    long long lmax = -INT_MAX, rmax = -INT_MAX, sum;
    sum = 0;
    for (int i = mid; i >= begin; i--) {
        sum += a[i];
        if (sum > lmax)
            lmax = sum;
    }

    sum = 0;
    for (int i = mid + 1; i <= end; i++) {
        sum += a[i];
        if (sum > rmax)
            rmax = sum;
    }
    return lmax + rmax;
}

long long max_subarray_sum(int begin, int end)
{
    if (begin >= end)
        return a[begin];
    long long left, right;
    left = max_subarray_sum(begin, (begin + end) / 2);
    right = max_subarray_sum((begin + end) / 2 + 1, end);
    return max(max(left, right), merge(begin, (begin + end) / 2, end));
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);

    printf("%lld", max_subarray_sum(0, n - 1));

    return 0;
}