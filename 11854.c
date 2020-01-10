# include <stdio.h>

int main(void)
{
    int i, j, k;

    while(1){
        scanf("%d %d %d", &i, &j, &k);

        if(i == 0 && j == 0 && k == 0){
            return 0;
        }

        if(i > j && i > k){
            if(i*i == j*j + k*k){
                printf("right\n");
            }
            else
                printf("wrong\n");
        }

        if(j > i && j > k){
            if(j*j == i*i + k*k){
                printf("right\n");
            }
            else
                printf("wrong\n");
        }

        if(k > i && k > j){
            if(k*k == i*i + j*j){
                printf("right\n");
            }
            else
                printf("wrong\n");
        }

    }

    return 0;




}
