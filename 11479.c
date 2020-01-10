# include <stdio.h>

int main(void)
{
    int T, i, j, k, transform;
    long long int ara[3];

    scanf("%d", &T);

    for(i = 1; i <= T; i++){

        scanf("%lld %lld %lld", &ara[0], &ara[1], &ara[2]);
        for(j = 0; j < 2; j++){
            for(k = 0; k < 2; k++){
                if(ara[k]>ara[k+1]){
                    transform = ara[k];
                    ara[k] = ara[k+1];
                    ara[k+1] = transform;
                }

            }
        }

        if(ara[2]<ara[0]+ara[1]){

            if(ara[0]==ara[1] && ara[1]==ara[2]){
                printf("Case %d: Equilateral\n", i);
            }
            else if(ara[0]==ara[1] || ara[1]==ara[2]){
                printf("Case %d: Isosceles\n", i);
            }
            else{
                printf("Case %d: Scalene\n", i);
            }
        }
        else{
            printf("Case %d: Invalid\n", i);
        }


    }

    return 0;



}
