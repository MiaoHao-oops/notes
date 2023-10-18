#include <stdio.h>

int main()
{
    int n;
    while(scanf("%d", &n) == 1) {
        printf("%s\n", (n % 4 == 2 ? "yes" : "no"));
    }   

    return 0;
}