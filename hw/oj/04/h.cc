#include <cstdio>
#include <cstring>

int b[26];

int main()
{
    int t;
    scanf("%d\n", &t);
    for (int num = 0; num < t; num++) {
        char c;
        memset(b, 0, sizeof(b));
        for (int i = 0; i < 4; i++) {
            if (i == 1 || i == 3) {
                scanf("%c\n", &c);
            } else {
                scanf("%c", &c);
            }
            b[c - 'a']++;
        }

        int max = 0, idx;
        for (int i = 0; i < 26; i++) {
            if (b[i] > max) {
                max = b[i];
                idx = i;
            }
        }

        if (max == 1) {
            printf("3\n");
        } else if (max == 3) {
            printf("1\n");
        } else if (max == 4) {
            printf("0\n");
        } else {
            b[idx] = 0;
            max = 0;
            for (int i = 0; i < 26; i++) {
                if (b[i] > max) {
                    max = b[i];
                    idx = i;
                }
            }
            if (max == 2) {
                printf("1\n");
            } else {
                printf("2\n");
            }
        }
    }
}