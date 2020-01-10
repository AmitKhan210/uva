# include <stdio.h>

int main(void)
{
    int N, i, p, Case = 0;

    while(1){
        scanf("%d", &N);
        p = 0;
        i = 1;
        Case++;
        if(N < 0){
            break;
        }

        while(1){
            p++;
            i *= 2;
            if(i >= N){
                break;
            }
        }

        printf("Case %d: %d\n", Case, p);

    }

    return 0;

}
