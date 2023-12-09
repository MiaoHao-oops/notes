#include <cstdio>

int a[110][110];

int main()
{
    int N;
    int sum, max = -0xfffffff;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] > max)
                max = a[i][j];
            a[i][j] += a[i - 1][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            sum = -0xfffffff;
            for (int k = 1; k <= N; k++) {
                int sub_sum = a[j][k] - a[i - 1][k];
                if(sum + sub_sum < sub_sum) {
                    sum = sub_sum;
                } else {
                    sum += sub_sum;
                }
                
                if(sum > max)
                    max = sum;
            }
        }
    }

    printf("%d\n", max);
}