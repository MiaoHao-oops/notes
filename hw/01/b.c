#include <stdio.h>
#include <math.h>

float calculate_humidex(float t, float d) {
    float e = 6.11 * exp(5417.7530 * ((1/273.16) - (1/(d + 273.16))));
    float h = 0.5555 * (e - 10.0);
    float humidex = t + h;
    return roundf(humidex * 10) / 10; // Round to the nearest tenth
}

float calculate_dewpoint(float t, float h) {
    float e = (h - t) / 0.5555 + 10.0;
    float dewpoint = 1 / (1/273.16 - log(e/6.11) / 5417.7530) - 273.16;
    return roundf(dewpoint * 10) / 10; // Round to the nearest tenth
}

float calculate_temperature(float d, float h) {
    float e = (h - 10.0) / 0.5555;
    float t = h - 0.5555 * e;
    return roundf(t * 10) / 10; // Round to the nearest tenth
}

int main() {
    char type1, type2;
    float value1, value2;

    while (scanf(" %c %f %c %f", &type1, &value1, &type2, &value2) == 4) {
        if (type1 == 'T') {
            if (type2 == 'D') {
                float h = calculate_humidex(value1, value2);
                printf("T %.1f D %.1f H %.1f\n", value1, value2, h);
            } else if (type2 == 'H') {
                float d = calculate_dewpoint(value1, value2);
                printf("T %.1f D %.1f H %.1f\n", value1, d, value2);
            }
        } else if (type1 == 'D') {
            if (type2 == 'T') {
                float h = calculate_humidex(value2, value1);
                printf("T %.1f D %.1f H %.1f\n", value2, value1, h);
            } else if (type2 == 'H') {
                float t = calculate_temperature(value1, value2);
                printf("T %.1f D %.1f H %.1f\n", t, value1, value2);
            }
        } else if (type1 == 'H') {
            if (type2 == 'T') {
                float d = calculate_dewpoint(value2, value1);
                printf("T %.1f D %.1f H %.1f\n", value2, d, value1);
            } else if (type2 == 'D') {
                float t = calculate_temperature(value1, value2);
                printf("T %.1f D %.1f H %.1f\n", t, value1, value2);
            }
        }
    }

    return 0;
}