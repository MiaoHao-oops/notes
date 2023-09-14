#include <math.h>
#include <stdio.h>

static const double C_a = 0.5555;
static const double C_b = 10.0;
static const double C_c = 6.11;
static const double C_d = 5417.7530;
static const double C_f = 273.16;

#define F(x) ((double)(((double)(int)(my_abs(x) * 10.0 + 0.5)) / 10.0)) * sign(x)
#define roundd(x) (round(x * 10.0) / 10.0)

double H(double T, double D)
{
    double e = C_c * exp(C_d * (1 / C_f - 1 / (D + C_f)));
    return T + C_a * (e - C_b);
}

double T(double H, double D)
{
    double e = C_c * exp(C_d * (1 / C_f - 1 / (D + C_f)));
    return H - C_a * (e - C_b);
}

double D(double T, double H)
{
    double e = (H - T) / C_a + C_b;
    double x_1 = log(e / C_c);
    double x_2 = x_1 / C_d;
    double x_3 = 1.0 / C_f - x_2;
    double x_4 = 1.0 / x_3;
    return x_4 - C_f;
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
    char c[2];
    double v[2], out[3];
    int index[2];

    while ((scanf(" %c %lf %c %lf", &c[0], &v[0], &c[1], &v[1])) == 4) {
        index[0] = my_atoi(c[0]);
        index[1] = my_atoi(c[1]);
        out[index[0]] = v[0];
        out[index[1]] = v[1];

        switch (index[0] + index[1])
        {
        case 1: out[2] = H(out[0], out[1]); break;
        case 2: out[1] = D(out[0], out[2]); break;
        case 3: out[0] = T(out[2], out[1]); break;
        }

        printf("T %.1lf D %.1lf H %.1lf\n", roundd(out[0]), roundd(out[1]), roundd(out[2]));
    }

    return 0;
}
