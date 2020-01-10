# include <stdio.h>

int main(void)
{
    int t, i, n, f, k;

    scanf("%d", &t);

    for(i = 1; i <= t; i++){

        scanf("%d", &n);
        f = n*315+36962;
        k = abs(f);

        printf("%d\n", (k%100)/10);

    }

    return 0;


}
