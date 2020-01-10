# include <stdio.h>

int main(void)
{
    int t, i, n, l, k;

    scanf("%d", &t);

    for(i = 1; i <= t; i++){

        scanf("%d", &n);

        if(n >= 0){
            l = (5*n)%10+2;
            k = 6+n%10+(5*n)%100/10;
            if(l>=10){

                if(k+1<10){
                    printf("%d\n",k+1);
                }
                else{
                    printf("%d\n", (k+1)%10);

                }

            }

            else{
                if(k<10){
                    printf("%d\n",k);
                }
                else{
                    printf("%d\n", k%10);

                }

            }
        }
        else if(n<0){
            l = 2+(5*n)%10;

            if(l<0){
                k = 6+n%10+(5*n)%100/10+1;
                if(k >= 0){
                    printf("%d\n", k);
                }
                else{
                    printf("%d\n",k+10);
                }


            }
            else{
                k = 6+n%10+(5*n)%100/10;
                if(k >= 0){
                    printf("%d\n", k);
                }
                else{

                    printf("%d\n", k+10);
                }

            }

        }

    }

    return 0;


}
