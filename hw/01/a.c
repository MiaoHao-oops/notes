#include <math.h>
#include <stdio.h>

static const double C_a = 0.555;
static const double C_b = 10.0;
static const double C_c = 6.11;
static const double C_d = 5417.7530;
static const double C_f = 273.16;

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

int main()
{
    char c[2];
    double v[2];

    while ((scanf("%c", &c[0])) != EOF) {
        if (c[0] == 'E') break;

        scanf("%lf %c %lf\n", &v[0], &c[1], &v[1]);
        
        switch (my_atoi(c[0]) + my_atoi(c[1]))
        {
        case 1: 
        case 2:
        case 3: 
        }
    }

    return 0;
}
