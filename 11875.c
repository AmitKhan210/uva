# include <stdio.h>

int main(void)
{
    int T, i, N, j;
    int age[9];

    scanf("%d", &T);

    for(i = 1; i <= T; i++){

        scanf("%d", &N);

        for(j = 1; j <= N; j++){
            scanf("%d", &age[j-1]);
        }

        printf("Case %d: %d\n", i, age[N/2]);

    }

    return 0;

}
