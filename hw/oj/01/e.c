#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int p[2];
    int len;
    int selected;
} edge_t;

int diff(const char *s1, const char *s2)
{
    int i, ret = 0;
    for (i = 0; i < 7; i++) {
        if (s1[i] != s2[i])
            ret++;
    }
    return ret;
}

int compar(const void *x, const void *y)
{
    int a = ((edge_t *)x)->len;
    int b = ((edge_t *)y)->len;

    if (a < b)
        return -1;
    else if (a > b)
        return 1;
    else
        return 0;;
}

int full(int * a, int len)
{
    int i;
    for (i = 0; i < len; i++)
        if (a[i] == 0)
            return -1;
    return 1;
}

edge_t e[4000001];
int selected[2001];

int main()
{
    char s[2010][8];
    int N, i, j, sum, ind, current;

    while (scanf("%d", &N) == 1 && N != 0) {
        sum = 0;
        ind = 0;
        memset(selected, 0, sizeof(int) * N);
        for (i = 0; i < N; i++) {
            scanf("%s", s[i]);
        }
        for (i = 0; i < N - 1; i++) {
            for (j = i + 1; j < N; j++) {
                e[ind].len = diff(s[i], s[j]);
                e[ind].p[0] = i;
                e[ind].p[1] = j;
                e[ind].selected = 0;
                ind++;
            }
        }
        qsort(e, ind, sizeof(edge_t), compar);
        selected[0] = 1;
        while (full(selected, N) == -1) {
            for (i = 0; i < ind; i++) {
                if (selected[e[i].p[0]] == 1 && selected[e[i].p[1]] == 0 && e[i].selected == 0) {
                    sum += e[i].len;
                    selected[e[i].p[1]] = 1;
                    e[i].selected = 1;
                    break;
                } else if (selected[e[i].p[0]] == 0 && selected[e[i].p[1]] == 1 && e[i].selected == 0) {
                    sum += e[i].len;
                    selected[e[i].p[0]] = 1;
                    e[i].selected = 1;
                    break;
                }
            }
        }

        printf("The highest possible quality is 1/%d.\n", sum);
    }
    return 0;
}