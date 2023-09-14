#include <stdio.h>
#include <string.h>

int main()
{
    int n, i, j, k;
    char in[3][3][4];
    int d[12], temp[12], w[12];
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        memset(d, 0, sizeof(d));
        memset(w, 0, sizeof(w));
        for (j = 0; j < 3; j++) {
            memset(temp, 0, sizeof(temp));
            scanf("%s %s %s", in[j][0], in[j][1], in[j][2]);
            switch(in[j][2][0])
            {
            case 'e': {
                d[in[j][0][0] - 'A'] = 1;
                d[in[j][0][1] - 'A'] = 1;
                d[in[j][0][2] - 'A'] = 1;
                d[in[j][0][3] - 'A'] = 1;
                d[in[j][1][0] - 'A'] = 1;
                d[in[j][1][1] - 'A'] = 1;
                d[in[j][1][2] - 'A'] = 1;
                d[in[j][1][3] - 'A'] = 1;
                break;
            }
            case 'u': {
                w[in[j][0][0] - 'A'] = temp[in[j][0][0] - 'A'] = 1;
                w[in[j][0][1] - 'A'] = temp[in[j][0][1] - 'A'] = 1;
                w[in[j][0][2] - 'A'] = temp[in[j][0][2] - 'A'] = 1;
                w[in[j][0][3] - 'A'] = temp[in[j][0][3] - 'A'] = 1;
                w[in[j][1][0] - 'A'] = temp[in[j][1][0] - 'A'] = -1;
                w[in[j][1][1] - 'A'] = temp[in[j][1][1] - 'A'] = -1;
                w[in[j][1][2] - 'A'] = temp[in[j][1][2] - 'A'] = -1;
                w[in[j][1][3] - 'A'] = temp[in[j][1][3] - 'A'] = -1;
                for (k = 0; k < 12; k++) {
                    if (temp[k] == 0)
                        d[k] = 1;
                }
                break;
            }
            default: {
                w[in[j][0][0] - 'A'] = temp[in[j][0][0] - 'A'] = -1;
                w[in[j][0][1] - 'A'] = temp[in[j][0][1] - 'A'] = -1;
                w[in[j][0][2] - 'A'] = temp[in[j][0][2] - 'A'] = -1;
                w[in[j][0][3] - 'A'] = temp[in[j][0][3] - 'A'] = -1;
                w[in[j][1][0] - 'A'] = temp[in[j][1][0] - 'A'] = 1;
                w[in[j][1][1] - 'A'] = temp[in[j][1][1] - 'A'] = 1;
                w[in[j][1][2] - 'A'] = temp[in[j][1][2] - 'A'] = 1;
                w[in[j][1][3] - 'A'] = temp[in[j][1][3] - 'A'] = 1;
                for (k = 0; k < 12; k++) {
                    if (temp[k] == 0)
                        d[k] = 1;
                }
            }
            }
        }
        for (j = 0; j < 12; j++) {
            if (d[j] == 0)
                printf("%c is the counterfeit coin and it is %s. ", j + 'A', w[j] == -1 ? "light" : "heavy");
        }
    }
    return 0;
}