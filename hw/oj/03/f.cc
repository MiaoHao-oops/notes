#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define DEBUG

typedef struct rect {
    long long x, y, z;
} rect_t;


static inline void set_order(long long *a, long long *b)
{
    if (*a < *b) return;
    long long tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

int cmp(const void *a, const void *b)
{
    rect_t *x = (rect_t *)a;
    rect_t *y = (rect_t *)b;
    if (x->x < y->x) return -1;
    if (x->x > y->x) return 1;
    if (x->y < y->y) return -1;
    if (x->y > y->y) return 1;
    return x->z - y->z;
}

int main()
{
    int n;
    int case_num = 1;
    rect_t *rects;
    long long *dp;

    while (scanf("%d", &n) && n != 0) {
        rects = (rect_t *)malloc(sizeof(rect_t) * n * 3);
        dp = (long long *)malloc(sizeof(long long) * n * 3);
        memset(dp, 0, sizeof(long long) * n * 3);

        for (int i = 0; i < n; i++) {
            rect_t *in[3] = {
                &rects[i * 3],
                &rects[i * 3 + 1],
                &rects[i * 3 + 2],
            };
            scanf("%lld%lld%lld", &in[0]->x, &in[0]->y, &in[0]->z);
            set_order(&in[0]->x, &in[0]->y);
            *in[1] = {
                in[0]->x,
                in[0]->z,
                in[0]->y,
            };
            set_order(&in[1]->x, &in[1]->y);
            *in[2] = {
                in[0]->y,
                in[0]->z,
                in[0]->x,
            };
            set_order(&in[2]->x, &in[2]->y);
        }

        std::qsort(rects, n * 3, sizeof(rect_t), cmp);

#ifdef DEBUG
        for (int i = 0; i < n; i++) {
            rect_t *in[3] = {
                &rects[i * 3],
                &rects[i * 3 + 1],
                &rects[i * 3 + 2],
            };
            for (int j = 0; j < 3; j++)
                printf("%lld %lld %lld\n", in[j]->x, in[j]->y, in[j]->z);
        }
#endif

        rect_t base = rects[0];
        dp[0] = rects[0].z;
        for (int i = n * 3 - 1; i >= 0; i--) {
            if (rects[i].x == base.x || rects[i].y == base.y) {
                if (rects[i].z > dp[i - 1]) {
                    base = rects[i];
                    dp[i] = rects[i].z;
                } else {
                    dp[i] = dp[i - 1];
                }
            }
            else if (rects[i].x > base.x && rects[i].y > base.y) {
                base = rects[i];
                dp[i] = dp[i - 1] + rects[i].z;
            } else {
                dp[i] = dp[i - 1];
            }
#ifdef DEBUG
            printf("dp[%d]: %lld base:(%lld, %lld)\n", i, dp[i], base.x, base.y);
#endif
        }

        printf("Case %d: maximum height = %lld\n", case_num++, dp[n * 3 - 1]);

        free(rects);
        free(dp);
    }
}
