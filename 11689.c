# include <stdio.h>

int main(void)
{
    int N, i, e, f, c, total, d, buy;

    scanf("%d", &N);

    for(i = 1; i <= N; i++){
        scanf("%d %d %d", &e, &f, &c);
        total = e + f;
        d = 0;
        while(1){
            buy = total/c;
            total = buy + total % c;
            d += buy;
            if(total < c){
                printf("%d\n", d);
                break;
            }
        }
    }

    return 0;

}
