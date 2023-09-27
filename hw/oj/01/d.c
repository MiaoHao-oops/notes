#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point {
    int x;
    int y;
} point_t;

typedef struct area {
    double central;
    double arm;
} area_t;

int cauculate_area(point_t p, int d, area_t *a)
{
    if (p.y > d)
        return -1;
    a->central = (double)p.x;
    a->arm = sqrt(((double)d * (double)d) - ((double)p.y * (double)p.y));
    return 0;
} 

int compar(const void *a, const void *b)
{
    double x = ((area_t *)a)->central + ((area_t *)a)->arm;
    double y = ((area_t *)b)->central + ((area_t *)b)->arm;

    if (x > y)
        return 1;
    else if (x < y)
        return -1;
    else
        return 0;
}

int main()
{
    int n, d;
    int i, j;
    int flag, case_num = 0, radar_num;
    double end;
    point_t points[1000];
    area_t areas[1000];

    while (scanf("%d %d", &n, &d) == 2 && (n != 0 || d != 0))
    {
        flag = 0;
        radar_num = 1;
        case_num++;
        for (i = 0; i < n; i++) {
            scanf("%d %d", &points[i].x, &points[i].y);
            if (cauculate_area(points[i], d, &areas[i]) == -1) {
                flag = 1;
            }
        }
        if (flag == 1) {
            printf("Case %d: -1\n", case_num);
            continue;
        }
        qsort(areas, n, sizeof(area_t), compar);

        end = areas[0].central + areas[0].arm;
        for (j = 1; j < n; j++) {
            if (areas[j].central - areas[j].arm <= end)
                continue;
            radar_num++;
            end = areas[j].central + areas[j].arm;
        }
        printf("Case %d: %d\n", case_num, radar_num);
        getchar();
    }
    return 0;
}