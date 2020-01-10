# include <stdio.h>

int main(void)
{
    int T, i, t1, t2, f, a, total, j, k, transform;
    int ct[3];

    scanf("%d", &T);

    for(i = 1; i <= T; i++){
        total = 0;
        scanf("%d %d %d %d %d %d %d", &t1, &t2, &f, &a, &ct[0], &ct[1], &ct[2]);

        for(j = 1; j < 3; j++){
            for(k = 1; k < 3; k++){
                if(ct[k-1] > ct[k]){
                    transform = ct[k-1];
                    ct[k-1] = ct[k];
                    ct[k] = transform;
                }
            }
        }

        total = t1 + t2 + f + a + (ct[1]+ct[2])/2;
        total /= 10;

        switch(total)
        {
            case 10:
            case 9:
                printf("Case %d: A\n", i);
                break;
            case 8:
                printf("Case %d: B\n", i);
                break;
            case 7:
                printf("Case %d: C\n", i);
                break;
            case 6:
                printf("Case %d: D\n", i);
                break;
            default:
                printf("Case %d: F\n", i);
                break;

        }


    }

    return 0;

}
