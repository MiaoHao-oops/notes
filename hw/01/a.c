#include <math.h>
#include <stdio.h>

static const double C_a = 0.5555;
static const double C_b = 10.0;
static const double C_c = 6.11;
static const double C_d = 5417.7530;
static const double C_f = 273.16;

#define F(x) ((double)(((double)(int)(my_abs(x) * 10.0 + 0.5)) / 10.0)) * sign(x)

double H(double T, double D)
{
    return T + C_a * (C_c * exp(C_d * (1 / C_f - 1 / (D + C_f))) - C_b);
}

double T(double H, double D)
{
    return H - C_a * (C_c * exp(C_d * (1 / C_f - 1 / (D + C_f))) - C_b);
}

double D(double T, double H)
{
    return 1 / (1 / C_f - (log(((H - T) / C_a + C_b) / C_c)) / C_d) - C_f;
}

int my_atoi(char c)
{
    switch (c)
    {
    case 'T': return 0;
    case 'D': return 1;
    case 'H': return 2;
    }
    return -1;
}

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
    char c[100][2];
    double v[100][2], out[3];
    int index[2], i = 0, j = 0;

    while ((scanf("%c", &c[i][0])) != EOF) {
        if (c[i][0] == 'E') break;

        scanf("%lf %c %lf\n", &v[i][0], &c[i][1], &v[i][1]);
        i++;
    }
    
    for (j = 0; j < i; j++) {
        index[0] = my_atoi(c[j][0]);
        index[1] = my_atoi(c[j][1]);
        out[index[0]] = v[j][0];
        out[index[1]] = v[j][1];

        switch (index[0] + index[1])
        {
        case 1: out[2] = H(out[0], out[1]); break;
        case 2: out[1] = D(out[0], out[2]); break;
        case 3: out[0] = T(out[2], out[1]); break;
        }
        printf("T %.1lf D %.1lf H %.1lf\n", F(out[0]), F(out[1]), F(out[2]));
        if (j < i - 1) putchar('\n');
    }


    return 0;
}
