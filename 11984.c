# include <stdio.h>

int main(void)
{
    int T, i, C, d;
    double nc;

    scanf("%d", &T);

    for(i = 1; i <= T; i++){

        scanf("%d %d", &C, &d);

        nc = C +(double)d*5/9;

        printf("Case %d: %.2lf\n", i, nc);

    }

    return 0;

}
