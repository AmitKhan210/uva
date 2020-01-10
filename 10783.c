# include <stdio.h>

int main(void)
{
    int T, i, a, b, j, sum;

    scanf("%d", &T);

    for(i = 1; i <= T; i++){
        sum = 0;
        scanf("%d", &a);
        scanf("%d", &b);

        for(j = a; j <= b; j++){
            if(j % 2 != 0){
                sum += j;
            }
        }

        printf("Case %d: %d\n", i, sum);

    }

    return 0;
}











