#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j, k, max, fake;
    char in[3][4];
    int d[12], w[12];
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        memset(d, 0, sizeof(d));
        memset(w, 0, sizeof(w));
        for (j = 0; j < 3; j++) {
            scanf("%s %s %s", in[0], in[1], in[2]);
            for (k = 0; k < 4; k++) {
                switch(in[2][0])
                {
                case 'e': {
                    d[in[0][k] - 'A'] = 1;
                    d[in[1][k] - 'A'] = 1;
                    break;
                }
                case 'u': {
                    if (d[in[0][k] - 'A'] == 0)
                        w[in[0][k] - 'A']++;
                    if (d[in[1][k] - 'A'] == 0)
                        w[in[1][k] - 'A']--;
                    break;
                }
                case 'd': {
                    if (d[in[0][k] - 'A'] == 0)
                        w[in[0][k] - 'A']--;
                    if (d[in[1][k] - 'A'] == 0)
                        w[in[1][k] - 'A']++;
                    break;
                }
                }
            }
        }
        max = -1;
        fake = 0;
        
        for (j = 0; j < 12; j++) {
            // printf("%d", w[j]);
            if (d[j] != 0)
                continue;
            if (abs(w[j]) > max) {
                max = abs(w[j]);
                fake = j;
            }
        }
        printf("%c is the counterfeit coin and it is %s.\n", fake + 'A', w[fake] <= 0 ? "light" : "heavy");
    }
    return 0;
}