#include <cstdio>
#include <algorithm>

typedef struct {
    int idx;
    long long T;
    long long S;
} Job_t;

Job_t Jobs[1010];

int comp(const void *a, const void *b)
{
    Job_t *x = (Job_t *)a;
    Job_t *y = (Job_t *)b;
    return (x->T * y->S) - (y->T * x->S);
}

int main()
{
    int n, N;
    scanf("%d", &n);
    for (int case_num = 0; case_num < n; case_num++) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%lld%lld", &Jobs[i].T, &Jobs[i].S);
            Jobs[i].idx = i + 1;
        }

        std::qsort(Jobs, N, sizeof(Job_t), comp);
        for (int i = 0; i < N - 1; i++) {
            printf("%d ", Jobs[i].idx);
        }
        printf("%d", Jobs[N - 1].idx);

        printf("\n");
        if (case_num != n - 1)
            printf("\n");
    }
}