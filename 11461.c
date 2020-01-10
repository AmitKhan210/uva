# include <stdio.h>
# include <math.h>

int main(void)
{
    int a, b, i, j, s = 0;


    while(1){
        scanf("%d%d", &a, &b);
        s = 0;
        if(a == 0 && b == 0)
            return 0;
        for(i = a; i <= b; i++){
            for(j = 1; j <= i; j++){
                if(pow(j,2)==i)
                    s++;

            }

        }

        printf("%d\n", s);

    }

}
