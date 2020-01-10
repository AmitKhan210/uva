# include <stdio.h>

int GCD(int i, int j);

int main(void)
{
    int N, i, j, G;

    while(1){
        scanf("%d", &N);
        G = 0;
        if(N==0){
            break;
        }

        for(i = 1; i < N; i++){
            for(j = i+1; j <= N; j++){
                G += GCD(i,j);
            }
        }

        printf("%d\n", G);

    }

    return 0;


}

int GCD(int i, int j)
{

    int k;
    for(k = j/2; k >= 1; k--){
        if(j%k==0 && i%k==0){
            return k;
        }
    }

}
