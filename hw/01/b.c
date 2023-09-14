#include <stdio.h>

#define F(x) ((double)(((double)(int)(my_abs(x) * 10.0 + 0.5)) / 10.0)) * sign(x)

double my_abs(double x)
{
    return x >= 0.0 ? x : x * -1.0;
}

double sign(double x)
{
    return x >= 0.0 ? 1.0 : -1.0;
}

int main()
{
    double x = -2.45;
    printf("%lf\n", (-x * 10 + 0.5) / 10.0 * -1.0);
    printf("%lf\n", F(x));
    printf("%.1lf\n", F(x));
    return 0;
}