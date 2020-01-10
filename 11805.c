# include <stdio.h>

int main(void)
{
    int T, i, N, K, P, l;

    scanf("%d", &T);

    for(i = 1; i <= T; i++){
        scanf("%d %d %d", &N, &K, &P);

        l = K + P;
        if(l <= N){
            printf("Case %d: %d\n", i, l);
        }

        else if(l%N != 0){
            printf("Case %d: %d\n", i, l%N);
        }
        else{
            printf("Case %d: %d\n", i, N);
        }
    }


    return 0;

}
