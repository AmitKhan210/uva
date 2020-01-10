# include <stdio.h>

int main(void)
{
    long long int i, j, k, n, cl, maximum;
    int index;
    long long ca[100000];

    while(1){
        scanf("%lld %lld", &i, &j);
        index=0;

        for(n = i; n <= j; n++){
            cl = 1;

            if(n==1){
                ca[index]=1;

            }
            else{
                while(n!=1){
                    if(n%2==0){
                        n=n/2;
                    }
                    else{
                        n=3*n+1;
                    }
                    cl++;

                }
                ca[index]=cl;

            }
            index++;
        }

        maximum=ca[0];
        for(k=1; k<=4; k++){
            if(ca[k]>maximum){
                maximum=ca[k];
            }
        }


        printf("%lld %lld %lld\n", i, j, maximum);



    }

    return 0;





}
