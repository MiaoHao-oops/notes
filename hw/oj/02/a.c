#include <inttypes.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define LEN 500010
unsigned long a[LEN], b[LEN];

long long inv(int, int);
long long merge(int, int, int);

int main()
{
    int n;
    long long ans;
    while (scanf("%d", &n) && n != 0) {
        for (int i = 0; i < n; i++)
            scanf("%lu", &a[i]);
        ans = inv(0, n - 1);
        printf("%lld\n", ans);
    }
}

long long inv(int begin, int end)
{
    if (begin >= end)
        return 0;
    int mid;
    long long left, right;
    mid = (begin + end) / 2;
    left = inv(begin, mid);
    right = inv(mid + 1, end);
    return left + right + merge(begin, mid, end);
}

long long merge(int begin, int mid, int end)
{
    int i = begin, j = mid + 1, k = begin;
    long long ret = 0;
    while (i != mid + 1 && j != end + 1) {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else {
            ret += (mid + 1 - i);
            b[k++] = a[j++];
        }
    }
    while (i != mid + 1)
        b[k++] = a[i++];
    while (j != end + 1)
        b[k++] = a[j++];
    for (i = begin; i <= end; i++)
        a[i] = b[i];
    return ret;
}